#include "ha/MqttService.h"

#include <stdio.h>
#include <string.h>

#include "config/BuildConfig.h"

namespace lgcl::ha {

#ifdef ARDUINO
MqttService* MqttService::instance_ = nullptr;
#endif

bool MqttService::begin(const config::RuntimeSettings& settings, uint32_t nowMs) {
  settings_ = settings;
  snapshot_ = MqttSnapshot{};
  nextWifiAttemptMs_ = nowMs;
  nextMqttAttemptMs_ = nowMs;
  mqttBackoffMs_ = 1000;
  wifiBackoffMs_ = 1000;
  hasPendingCommand_ = false;
#ifdef ARDUINO
  instance_ = this;
  mqtt_.setServer(settings_.mqttHost, settings_.mqttPort);
  mqtt_.setBufferSize(6144);
  mqtt_.setCallback(staticCallback);
#endif
  snapshot_.lastError = "OK";
  return true;
}

void MqttService::tick(uint32_t nowMs) {
  if (!settings_.mqttEnabled) {
    return;
  }
  if (!ensureWifi(nowMs)) {
    return;
  }
  if (!ensureMqtt(nowMs)) {
    return;
  }
#ifdef ARDUINO
  mqtt_.loop();
  snapshot_.mqttConnected = mqtt_.connected();
  snapshot_.wifiRssiDbm = WiFi.RSSI();
#endif
}

bool MqttService::popCommand(MqttCommand& out) {
  if (!hasPendingCommand_) {
    return false;
  }
  out = pendingCommand_;
  hasPendingCommand_ = false;
  return true;
}

bool MqttService::publishDiscovery() {
  if (!settings_.mqttEnabled) {
    return false;
  }
  char topicBuf[128];
  char payload[6144];
  if (!makeDiscoveryTopic(settings_, topicBuf, sizeof(topicBuf)) ||
      !buildDiscoveryPayload(settings_, payload, sizeof(payload))) {
    snapshot_.lastError = "discovery payload too large";
    return false;
  }
  return publishText(topicBuf, payload, true);
}

bool MqttService::publishState(const lg::ClimateState& climate,
                               const sensors::Bme280Snapshot& bme,
                               const health::HealthSnapshot& health,
                               uint32_t uptimeSec,
                               uint8_t digipotCode,
                               float digipotOhms,
                               bool force) {
  if (!settings_.mqttEnabled) {
    return false;
  }
#ifdef ARDUINO
  if (!mqtt_.connected()) {
    return false;
  }
#endif
  const uint32_t nowMs = uptimeSec * 1000UL;
  if (!force && (nowMs - lastStatePublishMs_) < config::kMqttStateMinPeriodMs) {
    return false;
  }
  lastStatePublishMs_ = nowMs;
  seq_++;

  char tClimate[128];
  char tBme[128];
  char tHealth[128];
  char tLgAvailability[128];
  char tBmeAvailability[128];
  char payload[768];
  if (!topic(tClimate, sizeof(tClimate), "state/climate") ||
      !topic(tBme, sizeof(tBme), "state/bme280") ||
      !topic(tHealth, sizeof(tHealth), "state/health") ||
      !topic(tLgAvailability, sizeof(tLgAvailability), "availability/lg_bus") ||
      !topic(tBmeAvailability, sizeof(tBmeAvailability), "availability/bme280")) {
    return false;
  }
  if (buildClimateStatePayload(climate, uptimeSec, seq_, digipotCode, digipotOhms,
                               payload, sizeof(payload))) {
    (void)publishText(tClimate, payload, false);
  }
  if (buildBmeStatePayload(bme, payload, sizeof(payload))) {
    (void)publishText(tBme, payload, false);
  }
  if (buildHealthStatePayload(health, snapshot_.wifiRssiDbm, uptimeSec, payload, sizeof(payload))) {
    (void)publishText(tHealth, payload, false);
  }
  const health::HealthItem& lgHealth =
      health.items[static_cast<uint8_t>(health::ComponentId::LgBus)];
  const bool lgOnline = !lgHealth.fault && !lgHealth.degraded;
  const bool bmeOnline = bme.initialized && !bme.stale;
  (void)publishText(tLgAvailability, lgOnline ? "online" : "offline", true);
  (void)publishText(tBmeAvailability, bmeOnline ? "online" : "offline", true);
  return true;
}

bool MqttService::ensureWifi(uint32_t nowMs) {
#ifdef ARDUINO
  snapshot_.wifiConnected = WiFi.status() == WL_CONNECTED;
  if (snapshot_.wifiConnected) {
    wifiBackoffMs_ = 1000;
    return true;
  }
  if (settings_.wifiSsid[0] == '\0') {
    snapshot_.lastError = "WiFi SSID not configured";
    return false;
  }
  if ((int32_t)(nowMs - nextWifiAttemptMs_) < 0) {
    return false;
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(settings_.wifiSsid, settings_.wifiPassword);
  snapshot_.wifiAttempts++;
  nextWifiAttemptMs_ = nowMs + wifiBackoffMs_;
  if (wifiBackoffMs_ < 60000) {
    wifiBackoffMs_ *= 2;
  }
  snapshot_.lastError = "WiFi connecting";
  return false;
#else
  (void)nowMs;
  return false;
#endif
}

bool MqttService::ensureMqtt(uint32_t nowMs) {
#ifdef ARDUINO
  snapshot_.mqttConnected = mqtt_.connected();
  if (snapshot_.mqttConnected) {
    mqttBackoffMs_ = 1000;
    return true;
  }
  if (settings_.mqttHost[0] == '\0') {
    snapshot_.lastError = "MQTT host not configured";
    return false;
  }
  if ((int32_t)(nowMs - nextMqttAttemptMs_) < 0) {
    return false;
  }
  char availability[128];
  (void)makeAvailabilityTopic(settings_, availability, sizeof(availability));
  snapshot_.mqttAttempts++;
  const bool ok = mqtt_.connect(settings_.deviceId,
                                settings_.mqttUser[0] ? settings_.mqttUser : nullptr,
                                settings_.mqttPassword[0] ? settings_.mqttPassword : nullptr,
                                availability,
                                1,
                                true,
                                "offline");
  if (ok) {
    publishText(availability, "online", true);
    clearRetainedCommands();
    subscribeCommands();
    publishDiscovery();
    snapshot_.mqttConnected = true;
    snapshot_.lastError = "OK";
    return true;
  }
  nextMqttAttemptMs_ = nowMs + mqttBackoffMs_;
  if (mqttBackoffMs_ < 60000) {
    mqttBackoffMs_ *= 2;
  }
  snapshot_.lastError = "MQTT connect failed";
  return false;
#else
  (void)nowMs;
  return false;
#endif
}

bool MqttService::publishText(const char* topic, const char* payload, bool retain) {
#ifdef ARDUINO
  if (!mqtt_.connected()) {
    return false;
  }
  const bool ok = mqtt_.publish(topic, payload, retain);
  if (ok) {
    snapshot_.publishes++;
    snapshot_.lastError = "OK";
  } else {
    snapshot_.lastError = "MQTT publish failed";
  }
  return ok;
#else
  (void)topic;
  (void)payload;
  (void)retain;
  return false;
#endif
}

bool MqttService::topic(char* out, size_t outLen, const char* suffix) const {
  char base[96];
  if (!makeBaseTopic(settings_, base, sizeof(base))) {
    return false;
  }
  const int n = snprintf(out, outLen, "%s/%s", base, suffix);
  return n > 0 && static_cast<size_t>(n) < outLen;
}

void MqttService::clearRetainedCommands() {
  static constexpr const char* suffixes[] = {
      "cmd/mode", "cmd/target_temp", "cmd/fan_mode", "cmd/swing_mode",
      "cmd/swing_horizontal_mode", "cmd/thermistor_mode", "cmd/digipot_wiper"};
  char t[128];
  for (const char* suffix : suffixes) {
    if (topic(t, sizeof(t), suffix)) {
      (void)publishText(t, "", true);
    }
  }
}

void MqttService::subscribeCommands() {
#ifdef ARDUINO
  char base[96];
  char filter[128];
  if (makeBaseTopic(settings_, base, sizeof(base))) {
    snprintf(filter, sizeof(filter), "%s/cmd/#", base);
    mqtt_.subscribe(filter, 1);
  }
  mqtt_.subscribe("homeassistant/status", 1);
#endif
}

#ifdef ARDUINO
void MqttService::staticCallback(char* topic, uint8_t* payload, unsigned int length) {
  if (instance_ != nullptr) {
    instance_->callback(topic, payload, length);
  }
}

void MqttService::callback(char* topic, uint8_t* payload, unsigned int length) {
  if (topic != nullptr && strcmp(topic, "homeassistant/status") == 0) {
    if (length == 6 && memcmp(payload, "online", 6) == 0) {
      (void)publishDiscovery();
    }
    return;
  }
  char body[128];
  if (length >= sizeof(body)) {
    snapshot_.rejectedCommands++;
    snapshot_.lastError = "MQTT payload too long";
    return;
  }
  memcpy(body, payload, length);
  body[length] = '\0';
  DecodeResult decoded = decodeCommand(settings_, topic, body, false);
  if (!decoded.accepted) {
    snapshot_.rejectedCommands++;
    snapshot_.lastError = decoded.reason;
    char errorTopic[128];
    char errorPayload[256];
    if (this->topic(errorTopic, sizeof(errorTopic), "event/error")) {
      snprintf(errorPayload,
               sizeof(errorPayload),
               "{\"topic\":\"%s\",\"reason\":\"%s\"}",
               topic,
               decoded.reason);
      (void)publishText(errorTopic, errorPayload, false);
    }
    return;
  }
  pendingCommand_ = decoded.command;
  hasPendingCommand_ = true;
  snapshot_.acceptedCommands++;
  snapshot_.lastError = "OK";
}
#endif

}  // namespace lgcl::ha

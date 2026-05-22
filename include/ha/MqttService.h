#pragma once

#include "config/RuntimeSettings.h"
#include "ha/HaDiscovery.h"
#include "health/HealthMonitor.h"
#include "lg/LgTypes.h"
#include "sensors/Bme280Service.h"

#ifdef ARDUINO
#include <PubSubClient.h>
#include <WiFi.h>
#endif

namespace lgcl::ha {

struct MqttSnapshot {
  bool wifiConnected = false;
  bool mqttConnected = false;
  uint32_t wifiAttempts = 0;
  uint32_t mqttAttempts = 0;
  uint32_t rejectedCommands = 0;
  uint32_t acceptedCommands = 0;
  uint32_t publishes = 0;
  int wifiRssiDbm = 0;
  const char* lastError = "not initialized";
};

class MqttService {
 public:
  bool begin(const config::RuntimeSettings& settings, uint32_t nowMs);
  void tick(uint32_t nowMs);
  bool popCommand(MqttCommand& out);
  bool publishDiscovery();
  bool publishState(const lg::ClimateState& climate,
                    const sensors::Bme280Snapshot& bme,
                    const health::HealthSnapshot& health,
                    uint32_t uptimeSec,
                    uint8_t digipotCode,
                    float digipotOhms,
                    bool force);
  const MqttSnapshot& snapshot() const { return snapshot_; }

 private:
#ifdef ARDUINO
  static void staticCallback(char* topic, uint8_t* payload, unsigned int length);
  void callback(char* topic, uint8_t* payload, unsigned int length);
#endif
  bool ensureWifi(uint32_t nowMs);
  bool ensureMqtt(uint32_t nowMs);
  bool publishText(const char* topic, const char* payload, bool retain);
  void clearRetainedCommands();
  void subscribeCommands();
  bool topic(char* out, size_t outLen, const char* suffix) const;

  config::RuntimeSettings settings_;
  MqttSnapshot snapshot_;
  uint32_t nextWifiAttemptMs_ = 0;
  uint32_t nextMqttAttemptMs_ = 0;
  uint32_t mqttBackoffMs_ = 1000;
  uint32_t wifiBackoffMs_ = 1000;
  uint32_t lastStatePublishMs_ = 0;
  uint32_t seq_ = 0;
  MqttCommand pendingCommand_;
  bool hasPendingCommand_ = false;

#ifdef ARDUINO
  WiFiClient wifiClient_;
  PubSubClient mqtt_{wifiClient_};
  static MqttService* instance_;
#endif
};

}  // namespace lgcl::ha

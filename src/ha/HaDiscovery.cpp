#include "ha/HaDiscovery.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "config/BuildConfig.h"
#include "lg/LgClimateModel.h"

namespace lgcl::ha {

namespace {

bool writeChecked(char* out, size_t outLen, const char* fmt, ...) {
  if (out == nullptr || outLen == 0) {
    return false;
  }
  va_list args;
  va_start(args, fmt);
  const int n = vsnprintf(out, outLen, fmt, args);
  va_end(args);
  return n > 0 && static_cast<size_t>(n) < outLen;
}

bool payloadEquals(const char* payload, const char* value) {
  return payload != nullptr && strcmp(payload, value) == 0;
}

bool parseFloatPayload(const char* payload, float& out) {
  if (payload == nullptr || payload[0] == '\0') {
    return false;
  }
  char* end = nullptr;
  const float value = strtof(payload, &end);
  if (end == payload || *end != '\0' || !isfinite(value)) {
    return false;
  }
  out = value;
  return true;
}

bool parseU8Payload(const char* payload, uint8_t& out) {
  if (payload == nullptr || payload[0] == '\0' || payload[0] == '-') {
    return false;
  }
  char* end = nullptr;
  const unsigned long value = strtoul(payload, &end, 10);
  if (end == payload || *end != '\0' || value > 255UL) {
    return false;
  }
  out = static_cast<uint8_t>(value);
  return true;
}

bool topicIs(const config::RuntimeSettings& settings,
             const char* topic,
             const char* suffix) {
  char expected[128];
  if (!makeBaseTopic(settings, expected, sizeof(expected))) {
    return false;
  }
  const size_t used = strlen(expected);
  if (used + 1 + strlen(suffix) + 1 > sizeof(expected)) {
    return false;
  }
  expected[used] = '/';
  strcpy(expected + used + 1, suffix);
  return topic != nullptr && strcmp(topic, expected) == 0;
}

const char* actionForState(const lg::ClimateState& state) {
  if (state.mode == lg::HvacMode::Off) {
    return "off";
  }
  if (state.defrost || state.preheat) {
    return "idle";
  }
  switch (state.mode) {
    case lg::HvacMode::Cool:
      return state.outdoorActive ? "cooling" : "idle";
    case lg::HvacMode::Heat:
      return state.outdoorActive ? "heating" : "idle";
    case lg::HvacMode::Dry:
      return state.outdoorActive ? "drying" : "idle";
    case lg::HvacMode::FanOnly:
      return "fan";
    case lg::HvacMode::Auto:
      return state.outdoorActive ? "cooling" : "idle";
    case lg::HvacMode::Off:
    default:
      return "off";
  }
}

const char* thermistorHaMode(lg::ThermistorMode mode) {
  switch (mode) {
    case lg::ThermistorMode::Unit:
      return "lg_internal";
    case lg::ThermistorMode::Controller:
      return "bme280";
    case lg::ThermistorMode::TwoThermistor:
      return "2th";
    default:
      return "unknown";
  }
}

const char* swingHaMode(lg::SwingMode mode) {
  switch (mode) {
    case lg::SwingMode::Off:
      return "off";
    case lg::SwingMode::Vertical:
    case lg::SwingMode::Horizontal:
    case lg::SwingMode::Both:
      return "on";
    default:
      return "off";
  }
}

const char* swingHorizontalHaMode(lg::SwingMode mode) {
  return (mode == lg::SwingMode::Horizontal || mode == lg::SwingMode::Both) ? "on" : "off";
}

}  // namespace

bool makeBaseTopic(const config::RuntimeSettings& settings, char* out, size_t outLen) {
  return writeChecked(out, outLen, "%s/%s", settings.mqttBaseTopic, settings.deviceId);
}

bool makeAvailabilityTopic(const config::RuntimeSettings& settings, char* out, size_t outLen) {
  char base[96];
  if (!makeBaseTopic(settings, base, sizeof(base))) {
    return false;
  }
  return writeChecked(out, outLen, "%s/availability", base);
}

bool makeDiscoveryTopic(const config::RuntimeSettings& settings, char* out, size_t outLen) {
  return writeChecked(out, outLen, "homeassistant/device/%s/config", settings.deviceId);
}

bool buildDiscoveryPayload(const config::RuntimeSettings& settings, char* out, size_t outLen) {
  char base[96];
  if (!makeBaseTopic(settings, base, sizeof(base))) {
    return false;
  }
  return writeChecked(
      out,
      outLen,
      "{\"~\":\"%s\","
      "\"dev\":{\"ids\":[\"%s\"],\"name\":\"%s\",\"mf\":\"LGClimateLink\","
      "\"mdl\":\"ESP32-S2 LG HVAC Controller\",\"sw\":\"%s\",\"hw\":\"esp32-s2\"},"
      "\"o\":{\"name\":\"lgclimatelink\",\"sw\":\"%s\"},"
      "\"avty\":[{\"t\":\"~/availability\"}],\"pl_avail\":\"online\","
      "\"pl_not_avail\":\"offline\",\"qos\":1,"
      "\"cmps\":{"
      "\"climate\":{\"p\":\"climate\",\"name\":null,\"uniq_id\":\"%s_climate\","
      "\"avty\":[{\"t\":\"~/availability\"},{\"t\":\"~/availability/lg_bus\"}],"
      "\"avty_mode\":\"all\",\"modes\":[\"off\",\"cool\",\"heat\",\"dry\",\"fan_only\",\"auto\"],"
      "\"mode_cmd_t\":\"~/cmd/mode\",\"mode_stat_t\":\"~/state/climate\","
      "\"mode_stat_tpl\":\"{{ value_json.mode }}\","
      "\"act_t\":\"~/state/climate\",\"act_tpl\":\"{{ value_json.action }}\","
      "\"temp_cmd_t\":\"~/cmd/target_temp\",\"temp_stat_t\":\"~/state/climate\","
      "\"temp_stat_tpl\":\"{{ value_json.target_temp_c }}\","
      "\"curr_temp_t\":\"~/state/climate\",\"curr_temp_tpl\":\"{{ value_json.current_temp_c }}\","
      "\"curr_hum_t\":\"~/state/climate\",\"curr_hum_tpl\":\"{{ value_json.current_humidity_pct }}\","
      "\"min_temp\":16,\"max_temp\":30,\"temp_step\":0.5,\"precision\":0.1,"
      "\"temp_unit\":\"C\",\"fan_modes\":[\"auto\",\"low\",\"medium\",\"high\",\"slow\"],"
      "\"fan_mode_cmd_t\":\"~/cmd/fan_mode\",\"fan_mode_stat_t\":\"~/state/climate\","
      "\"fan_mode_stat_tpl\":\"{{ value_json.fan_mode }}\","
      "\"swing_modes\":[\"off\",\"on\"],\"swing_mode_cmd_t\":\"~/cmd/swing_mode\","
      "\"swing_mode_stat_t\":\"~/state/climate\","
      "\"swing_mode_stat_tpl\":\"{{ value_json.swing_mode }}\","
      "\"json_attr_t\":\"~/state/climate\"},"
      "\"bme280_temperature\":{\"p\":\"sensor\",\"name\":\"BME280 temperature\","
      "\"uniq_id\":\"%s_bme280_temperature\",\"stat_t\":\"~/state/bme280\","
      "\"val_tpl\":\"{{ value_json.temperature_c }}\",\"dev_cla\":\"temperature\","
      "\"unit_of_meas\":\"°C\",\"stat_cla\":\"measurement\",\"exp_aft\":120},"
      "\"bme280_humidity\":{\"p\":\"sensor\",\"name\":\"BME280 humidity\","
      "\"uniq_id\":\"%s_bme280_humidity\",\"stat_t\":\"~/state/bme280\","
      "\"val_tpl\":\"{{ value_json.humidity_pct }}\",\"dev_cla\":\"humidity\","
      "\"unit_of_meas\":\"%%\",\"stat_cla\":\"measurement\",\"exp_aft\":120},"
      "\"bme280_pressure\":{\"p\":\"sensor\",\"name\":\"BME280 pressure\","
      "\"uniq_id\":\"%s_bme280_pressure\",\"stat_t\":\"~/state/bme280\","
      "\"val_tpl\":\"{{ value_json.pressure_hpa }}\",\"dev_cla\":\"pressure\","
      "\"unit_of_meas\":\"hPa\",\"stat_cla\":\"measurement\",\"exp_aft\":120},"
      "\"thermistor_mode\":{\"p\":\"select\",\"name\":\"Thermistor mode\","
      "\"uniq_id\":\"%s_thermistor_mode\",\"ent_cat\":\"config\","
      "\"ops\":[\"lg_internal\",\"bme280\",\"manual_digipot\",\"safe_fixed\"],"
      "\"cmd_t\":\"~/cmd/thermistor_mode\",\"stat_t\":\"~/state/climate\","
      "\"val_tpl\":\"{{ value_json.thermistor_mode }}\"},"
      "\"digipot_ohms\":{\"p\":\"sensor\",\"name\":\"Digipot resistance\","
      "\"uniq_id\":\"%s_digipot_ohms\",\"ent_cat\":\"diagnostic\","
      "\"stat_t\":\"~/state/climate\",\"val_tpl\":\"{{ value_json.digipot_ohms }}\","
      "\"unit_of_meas\":\"Ω\",\"stat_cla\":\"measurement\"},"
      "\"fault\":{\"p\":\"binary_sensor\",\"name\":\"Fault\",\"uniq_id\":\"%s_fault\","
      "\"ent_cat\":\"diagnostic\",\"dev_cla\":\"problem\",\"stat_t\":\"~/state/health\","
      "\"val_tpl\":\"{{ 'ON' if value_json.fault else 'OFF' }}\"},"
      "\"lg_bus_online\":{\"p\":\"binary_sensor\",\"name\":\"LG bus online\","
      "\"uniq_id\":\"%s_lg_bus_online\",\"ent_cat\":\"diagnostic\","
      "\"dev_cla\":\"connectivity\",\"stat_t\":\"~/state/health\","
      "\"val_tpl\":\"{{ 'ON' if value_json.lg_bus_online else 'OFF' }}\"},"
      "\"error_code\":{\"p\":\"sensor\",\"name\":\"LG error code\","
      "\"uniq_id\":\"%s_error_code\",\"ent_cat\":\"diagnostic\","
      "\"stat_t\":\"~/state/climate\",\"val_tpl\":\"{{ value_json.error_code }}\"},"
      "\"defrost\":{\"p\":\"binary_sensor\",\"name\":\"Defrost\","
      "\"uniq_id\":\"%s_defrost\",\"ent_cat\":\"diagnostic\","
      "\"stat_t\":\"~/state/climate\",\"val_tpl\":\"{{ 'ON' if value_json.defrost else 'OFF' }}\"},"
      "\"preheat\":{\"p\":\"binary_sensor\",\"name\":\"Preheat\","
      "\"uniq_id\":\"%s_preheat\",\"ent_cat\":\"diagnostic\","
      "\"stat_t\":\"~/state/climate\",\"val_tpl\":\"{{ 'ON' if value_json.preheat else 'OFF' }}\"},"
      "\"outdoor_active\":{\"p\":\"binary_sensor\",\"name\":\"Outdoor unit active\","
      "\"uniq_id\":\"%s_outdoor_active\",\"ent_cat\":\"diagnostic\","
      "\"stat_t\":\"~/state/climate\",\"val_tpl\":\"{{ 'ON' if value_json.outdoor_active else 'OFF' }}\"}"
      "}}",
      base,
      settings.deviceId,
      settings.deviceName,
      config::kFirmwareVersion,
      config::kFirmwareVersion,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId,
      settings.deviceId);
}

bool buildClimateStatePayload(const lg::ClimateState& state,
                              uint32_t uptimeSec,
                              uint32_t seq,
                              uint8_t digipotCode,
                              float digipotOhms,
                              char* out,
                              size_t outLen) {
  return writeChecked(
      out,
      outLen,
      "{\"mode\":\"%s\",\"action\":\"%s\",\"target_temp_c\":%.1f,"
      "\"current_temp_c\":%.2f,\"current_humidity_pct\":null,"
      "\"fan_mode\":\"%s\",\"swing_mode\":\"%s\",\"swing_horizontal_mode\":\"%s\","
      "\"thermistor_mode\":\"%s\",\"digipot_wiper\":%u,\"digipot_ohms\":%.1f,"
      "\"error_code\":%u,\"defrost\":%s,\"preheat\":%s,\"outdoor_active\":%s,"
      "\"seq\":%lu,\"uptime_s\":%lu}",
      lg::modeName(state.mode),
      actionForState(state),
      static_cast<double>(state.targetTemperatureC),
      static_cast<double>(state.currentTemperatureC),
      lg::fanModeName(state.fan),
      swingHaMode(state.swing),
      swingHorizontalHaMode(state.swing),
      thermistorHaMode(state.thermistor),
      static_cast<unsigned>(digipotCode),
      static_cast<double>(digipotOhms),
      static_cast<unsigned>(state.errorCode),
      state.defrost ? "true" : "false",
      state.preheat ? "true" : "false",
      state.outdoorActive ? "true" : "false",
      static_cast<unsigned long>(seq),
      static_cast<unsigned long>(uptimeSec));
}

bool buildBmeStatePayload(const sensors::Bme280Snapshot& bme, char* out, size_t outLen) {
  if (!bme.sample.valid) {
    return writeChecked(out, outLen, "{\"temperature_c\":null,\"humidity_pct\":null,"
                                    "\"pressure_hpa\":null,\"stale\":true}");
  }
  return writeChecked(out,
                      outLen,
                      "{\"temperature_c\":%.2f,\"humidity_pct\":%.2f,"
                      "\"pressure_hpa\":%.2f,\"stale\":%s}",
                      static_cast<double>(bme.sample.temperatureC),
                      static_cast<double>(bme.sample.humidityPct),
                      static_cast<double>(bme.sample.pressurePa / 100.0f),
                      bme.stale ? "true" : "false");
}

bool buildHealthStatePayload(const health::HealthSnapshot& health,
                             int wifiRssiDbm,
                             uint32_t uptimeSec,
                             char* out,
                             size_t outLen) {
  const bool fault = health.level == health::HealthLevel::Fault;
  const bool lgOnline = !health.items[static_cast<uint8_t>(health::ComponentId::LgBus)].fault;
  return writeChecked(out,
                      outLen,
                      "{\"level\":\"%s\",\"fault\":%s,\"lg_bus_online\":%s,"
                      "\"watchdog_quorum\":%s,\"first_failing\":\"%s\","
                      "\"wifi_rssi_dbm\":%d,\"uptime_s\":%lu}",
                      health::healthLevelName(health.level),
                      fault ? "true" : "false",
                      lgOnline ? "true" : "false",
                      health.watchdogQuorum ? "true" : "false",
                      health.firstFailingComponent,
                      wifiRssiDbm,
                      static_cast<unsigned long>(uptimeSec));
}

DecodeResult decodeCommand(const config::RuntimeSettings& settings,
                           const char* topic,
                           const char* payload,
                           bool retained) {
  DecodeResult result;
  if (retained) {
    result.ignored = true;
    result.reason = "retained command ignored";
    return result;
  }
  if (topicIs(settings, topic, "cmd/mode")) {
    result.command.kind = MqttCommandKind::Mode;
    if (!lg::parseModeName(payload, result.command.mode)) {
      result.reason = "invalid mode";
      return result;
    }
  } else if (topicIs(settings, topic, "cmd/target_temp")) {
    result.command.kind = MqttCommandKind::TargetTemperature;
    if (!parseFloatPayload(payload, result.command.temperatureC) ||
        result.command.temperatureC < 16.0f || result.command.temperatureC > 30.0f) {
      result.reason = "invalid target temperature";
      return result;
    }
    const float doubled = result.command.temperatureC * 2.0f;
    if (fabsf(doubled - roundf(doubled)) > 0.001f) {
      result.reason = "target temperature must be 0.5C step";
      return result;
    }
  } else if (topicIs(settings, topic, "cmd/fan_mode")) {
    result.command.kind = MqttCommandKind::FanMode;
    if (!lg::parseFanModeName(payload, result.command.fan)) {
      result.reason = "invalid fan mode";
      return result;
    }
  } else if (topicIs(settings, topic, "cmd/swing_mode")) {
    result.command.kind = MqttCommandKind::SwingMode;
    if (payloadEquals(payload, "off")) {
      result.command.swing = lg::SwingMode::Off;
    } else if (payloadEquals(payload, "on")) {
      result.command.swing = lg::SwingMode::Vertical;
    } else {
      result.reason = "invalid swing mode";
      return result;
    }
  } else if (topicIs(settings, topic, "cmd/thermistor_mode")) {
    result.command.kind = MqttCommandKind::ThermistorMode;
    if (!lg::parseThermistorModeName(payload, result.command.thermistor)) {
      result.reason = "invalid thermistor mode";
      return result;
    }
  } else if (topicIs(settings, topic, "cmd/digipot_wiper")) {
    result.command.kind = MqttCommandKind::DigipotWiper;
    if (!parseU8Payload(payload, result.command.wiper)) {
      result.reason = "invalid digipot wiper";
      return result;
    }
  } else {
    result.reason = "unknown topic";
    return result;
  }
  result.accepted = true;
  result.reason = "OK";
  return result;
}

}  // namespace lgcl::ha

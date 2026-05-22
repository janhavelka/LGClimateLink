#pragma once

#include <stddef.h>
#include <stdint.h>

#include "config/RuntimeSettings.h"
#include "health/HealthMonitor.h"
#include "lg/LgTypes.h"
#include "sensors/Bme280Service.h"

namespace lgcl::ha {

enum class MqttCommandKind : uint8_t {
  None = 0,
  Mode,
  TargetTemperature,
  FanMode,
  SwingMode,
  ThermistorMode,
  DigipotWiper,
};

struct MqttCommand {
  MqttCommandKind kind = MqttCommandKind::None;
  lg::HvacMode mode = lg::HvacMode::Off;
  lg::FanMode fan = lg::FanMode::Auto;
  lg::SwingMode swing = lg::SwingMode::Off;
  lg::ThermistorMode thermistor = lg::ThermistorMode::Controller;
  float temperatureC = 0.0f;
  uint8_t wiper = 0;
};

struct DecodeResult {
  bool accepted = false;
  bool ignored = false;
  const char* reason = "no match";
  MqttCommand command;
};

bool makeBaseTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);
bool makeAvailabilityTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);
bool makeDiscoveryTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);
bool buildDiscoveryPayload(const config::RuntimeSettings& settings, char* out, size_t outLen);
bool buildClimateStatePayload(const lg::ClimateState& state,
                              uint32_t uptimeSec,
                              uint32_t seq,
                              uint8_t digipotCode,
                              float digipotOhms,
                              char* out,
                              size_t outLen);
bool buildBmeStatePayload(const sensors::Bme280Snapshot& bme, char* out, size_t outLen);
bool buildHealthStatePayload(const health::HealthSnapshot& health,
                             int wifiRssiDbm,
                             uint32_t uptimeSec,
                             char* out,
                             size_t outLen);
DecodeResult decodeCommand(const config::RuntimeSettings& settings,
                           const char* topic,
                           const char* payload,
                           bool retained);

}  // namespace lgcl::ha

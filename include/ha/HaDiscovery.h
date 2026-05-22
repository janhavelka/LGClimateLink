#pragma once

/**
 * @file HaDiscovery.h
 * @brief Home Assistant MQTT Discovery payload and command parsing helpers.
 */

#include <stddef.h>
#include <stdint.h>

#include "config/RuntimeSettings.h"
#include "health/HealthMonitor.h"
#include "lg/LgTypes.h"
#include "sensors/Bme280Service.h"

namespace lgcl::ha {

/// Command kind accepted from MQTT command topics.
enum class MqttCommandKind : uint8_t {
  None = 0,
  Mode,
  TargetTemperature,
  FanMode,
  SwingMode,
  ThermistorMode,
  DigipotWiper,
};

/// Validated MQTT command ready for application-level handling.
struct MqttCommand {
  MqttCommandKind kind = MqttCommandKind::None;
  lg::HvacMode mode = lg::HvacMode::Off;
  lg::FanMode fan = lg::FanMode::Auto;
  lg::SwingMode swing = lg::SwingMode::Off;
  lg::ThermistorMode thermistor = lg::ThermistorMode::Controller;
  float temperatureC = 0.0f;
  uint8_t wiper = 0;
};

/// Result of decoding one MQTT topic/payload pair.
struct DecodeResult {
  bool accepted = false;
  bool ignored = false;
  const char* reason = "no match";
  MqttCommand command;
};

/// Build `<mqtt_base>/<device_id>`.
bool makeBaseTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);

/// Build the primary MQTT availability topic.
bool makeAvailabilityTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);

/// Build the Home Assistant device discovery topic.
bool makeDiscoveryTopic(const config::RuntimeSettings& settings, char* out, size_t outLen);

/// Build the retained Home Assistant MQTT Discovery device payload.
bool buildDiscoveryPayload(const config::RuntimeSettings& settings, char* out, size_t outLen);

/// Build JSON state for the climate entity and LG diagnostics.
bool buildClimateStatePayload(const lg::ClimateState& state,
                              uint32_t uptimeSec,
                              uint32_t seq,
                              uint8_t digipotCode,
                              float digipotOhms,
                              char* out,
                              size_t outLen);

/// Build JSON state for BME280 sensor entities.
bool buildBmeStatePayload(const sensors::Bme280Snapshot& bme, char* out, size_t outLen);

/// Build JSON state for health and connectivity diagnostics.
bool buildHealthStatePayload(const health::HealthSnapshot& health,
                             int wifiRssiDbm,
                             uint32_t uptimeSec,
                             char* out,
                             size_t outLen);

/// Decode and validate one inbound MQTT command.
DecodeResult decodeCommand(const config::RuntimeSettings& settings,
                           const char* topic,
                           const char* payload,
                           bool retained);

}  // namespace lgcl::ha

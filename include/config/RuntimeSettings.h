#pragma once

/**
 * @file RuntimeSettings.h
 * @brief Persistent runtime configuration and validation helpers.
 */

#include <stdint.h>

#include "digipot/NtcEmulator.h"

namespace lgcl::config {

/// Supported physical LED wiring options.
enum class LedTopology : uint8_t {
  /// One data output drives a two-pixel chain.
  OneChainTwoPixels = 0,
  /// Two data outputs each drive an independent LED/pixel chain.
  TwoIndependentOutputs = 1,
};

/**
 * @brief User and hardware settings loaded from NVS.
 *
 * The struct is intentionally plain data so it can be validated, copied, and
 * tested without Arduino dependencies. All fields must pass validate() before
 * they are used to reconfigure services.
 */
struct RuntimeSettings {
  char deviceId[32] = "lgclimatelink";
  char deviceName[48] = "LG Climate Link";

  char wifiSsid[64] = "";
  char wifiPassword[64] = "";
  char mqttHost[64] = "";
  uint16_t mqttPort = 1883;
  char mqttUser[48] = "";
  char mqttPassword[64] = "";
  char mqttBaseTopic[64] = "lgclimatelink";

  bool mqttEnabled = false;
  bool lgSlaveController = false;
  bool fahrenheitMode = false;
  bool externalThermistorControl = true;

  uint8_t bmeAddress = 0x76;
  uint32_t bmePollMs = 5000;
  uint32_t bmeStaleMs = 30000;

  uint8_t mcp45hvx1Address = 0x3C;
  digipot::NtcCalibration ntc;
  digipot::DigipotCalibration digipot;

  LedTopology ledTopology = LedTopology::OneChainTwoPixels;
  uint8_t ledBrightness = 32;

  uint32_t watchdogTimeoutSec = 15;
  uint32_t settingsCommitDelayMs = 5000;
};

/// Result of validating a settings object.
struct ValidationResult {
  bool ok = true;
  const char* message = "OK";
};

/// Validate ranges, topic tokens, and safety limits in a settings object.
ValidationResult validate(const RuntimeSettings& settings);

/// Return firmware defaults used on first boot or after config reset.
RuntimeSettings defaults();

/// Return true when a value is safe for use as one MQTT topic path segment.
bool isSafeTopicToken(const char* value);

}  // namespace lgcl::config

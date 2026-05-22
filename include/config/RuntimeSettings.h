#pragma once

#include <stdint.h>

#include "digipot/NtcEmulator.h"

namespace lgcl::config {

enum class LedTopology : uint8_t {
  OneChainTwoPixels = 0,
  TwoIndependentOutputs = 1,
};

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

struct ValidationResult {
  bool ok = true;
  const char* message = "OK";
};

ValidationResult validate(const RuntimeSettings& settings);
RuntimeSettings defaults();
bool isSafeTopicToken(const char* value);

}  // namespace lgcl::config

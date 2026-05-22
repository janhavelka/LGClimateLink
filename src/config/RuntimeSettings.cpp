#include "config/RuntimeSettings.h"

#include <string.h>

#include "config/BuildConfig.h"

namespace lgcl::config {

namespace {

bool empty(const char* s) {
  return s == nullptr || s[0] == '\0';
}

bool validAddress7(uint8_t addr) {
  return addr >= 0x08 && addr <= 0x77;
}

}  // namespace

RuntimeSettings defaults() {
  RuntimeSettings s;
  s.bmePollMs = kBmePollMs;
  s.bmeStaleMs = kBmeStaleMs;
  s.ledBrightness = kDefaultLedBrightness;
  s.watchdogTimeoutSec = kWatchdogTimeoutSec;
  s.settingsCommitDelayMs = kStorageCommitDelayMs;
  s.ntc = digipot::NtcCalibration{};
  s.digipot = digipot::DigipotCalibration{};
  return s;
}

bool isSafeTopicToken(const char* value) {
  if (empty(value)) {
    return false;
  }
  if (value[0] == '/' || value[strlen(value) - 1] == '/') {
    return false;
  }
  for (const char* p = value; *p != '\0'; ++p) {
    const char c = *p;
    const bool ok = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                    (c >= '0' && c <= '9') || c == '_' || c == '-' || c == '/';
    if (!ok) {
      return false;
    }
    if (c == '/' && p[1] == '/') {
      return false;
    }
  }
  return true;
}

ValidationResult validate(const RuntimeSettings& settings) {
  if (empty(settings.deviceId)) {
    return {false, "deviceId is required"};
  }
  if (!isSafeTopicToken(settings.deviceId)) {
    return {false, "deviceId must be MQTT-safe"};
  }
  if (!isSafeTopicToken(settings.mqttBaseTopic)) {
    return {false, "mqttBaseTopic must be MQTT-safe"};
  }
  if (settings.mqttPort == 0) {
    return {false, "mqttPort must be non-zero"};
  }
  if (!validAddress7(settings.bmeAddress)) {
    return {false, "BME280 I2C address is invalid"};
  }
  if (settings.bmePollMs < 500) {
    return {false, "BME280 poll interval is too low"};
  }
  if (settings.bmeStaleMs <= settings.bmePollMs) {
    return {false, "BME280 stale timeout must exceed poll interval"};
  }
  if (settings.watchdogTimeoutSec < 5 || settings.watchdogTimeoutSec > 120) {
    return {false, "watchdog timeout out of range"};
  }
  if (settings.settingsCommitDelayMs < 1000) {
    return {false, "settings commit delay too low"};
  }
  if (!digipot::validate(settings.ntc).ok) {
    return {false, "NTC calibration invalid"};
  }
  if (!digipot::validate(settings.digipot).ok) {
    return {false, "digipot calibration invalid"};
  }
  return {};
}

}  // namespace lgcl::config

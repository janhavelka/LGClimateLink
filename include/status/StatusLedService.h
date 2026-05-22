#pragma once

/**
 * @file StatusLedService.h
 * @brief Nonblocking status LED state mapping.
 */

#include "config/RuntimeSettings.h"
#include "health/HealthMonitor.h"

#ifdef ARDUINO
#include <StatusLed/StatusLed.h>
#endif

namespace lgcl::status {

/// High-level device states shown through the status LEDs.
enum class DeviceLedState {
  Booting,
  WifiConnecting,
  MqttDisconnected,
  LgBusOffline,
  Normal,
  Degraded,
  ConfigMode,
  Fatal,
};

/// Owns StatusLED instances and applies high-level device-state patterns.
class StatusLedService {
 public:
  /// Initialize one-chain or two-output LED topology.
  bool begin(config::LedTopology topology, uint8_t brightness);
  /// Advance LED animation without blocking.
  void tick(uint32_t nowMs, DeviceLedState state);
  /// Return the currently applied state.
  DeviceLedState currentState() const { return state_; }
  /// Override the LED with a test color.
  bool setTestColor(uint8_t r, uint8_t g, uint8_t b);
  /// Last adapter or initialization error.
  const char* lastError() const { return lastError_; }

 private:
  void applyState(DeviceLedState state);

  config::LedTopology topology_ = config::LedTopology::OneChainTwoPixels;
  DeviceLedState state_ = DeviceLedState::Booting;
  const char* lastError_ = "not initialized";

#ifdef ARDUINO
  StatusLed::StatusLed chain_;
  StatusLed::StatusLed pair_;
#endif
};

/// Human-readable LED state name for CLI and logs.
const char* ledStateName(DeviceLedState state);

}  // namespace lgcl::status

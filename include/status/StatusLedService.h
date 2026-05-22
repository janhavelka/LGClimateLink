#pragma once

#include "config/RuntimeSettings.h"
#include "health/HealthMonitor.h"

#ifdef ARDUINO
#include <StatusLed/StatusLed.h>
#endif

namespace lgcl::status {

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

class StatusLedService {
 public:
  bool begin(config::LedTopology topology, uint8_t brightness);
  void tick(uint32_t nowMs, DeviceLedState state);
  DeviceLedState currentState() const { return state_; }
  bool setTestColor(uint8_t r, uint8_t g, uint8_t b);
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

const char* ledStateName(DeviceLedState state);

}  // namespace lgcl::status

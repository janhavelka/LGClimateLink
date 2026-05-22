#include "status/StatusLedService.h"

#include "config/BuildConfig.h"

namespace lgcl::status {

const char* ledStateName(DeviceLedState state) {
  switch (state) {
    case DeviceLedState::Booting:
      return "booting";
    case DeviceLedState::WifiConnecting:
      return "wifi_connecting";
    case DeviceLedState::MqttDisconnected:
      return "mqtt_disconnected";
    case DeviceLedState::LgBusOffline:
      return "lg_bus_offline";
    case DeviceLedState::Normal:
      return "normal";
    case DeviceLedState::Degraded:
      return "degraded";
    case DeviceLedState::ConfigMode:
      return "configuration_mode";
    case DeviceLedState::Fatal:
      return "fatal";
    default:
      return "unknown";
  }
}

bool StatusLedService::begin(config::LedTopology topology, uint8_t brightness) {
  topology_ = topology;
  state_ = DeviceLedState::Booting;
#ifdef ARDUINO
  StatusLed::Config cfg;
  cfg.dataPin = config::kStatusLedPin;
  cfg.ledCount = topology == config::LedTopology::OneChainTwoPixels ? 2 : 1;
  cfg.colorOrder = StatusLed::ColorOrder::GRB;
  cfg.rmtChannel = 0;
  cfg.globalBrightness = brightness;
  StatusLed::Status st = chain_.begin(cfg);
  if (!st.ok()) {
    lastError_ = st.msg;
    return false;
  }
  if (topology == config::LedTopology::TwoIndependentOutputs) {
    StatusLed::Config pairCfg = cfg;
    pairCfg.dataPin = config::kPairLedPin;
    pairCfg.ledCount = 1;
    pairCfg.rmtChannel = 1;
    st = pair_.begin(pairCfg);
    if (!st.ok()) {
      lastError_ = st.msg;
      return false;
    }
  }
  lastError_ = "OK";
  applyState(DeviceLedState::Booting);
  return true;
#else
  (void)brightness;
  lastError_ = "OK";
  return true;
#endif
}

void StatusLedService::tick(uint32_t nowMs, DeviceLedState state) {
  if (state != state_) {
    applyState(state);
  }
#ifdef ARDUINO
  chain_.tick(nowMs);
  if (topology_ == config::LedTopology::TwoIndependentOutputs) {
    pair_.tick(nowMs);
  }
#else
  (void)nowMs;
#endif
}

bool StatusLedService::setTestColor(uint8_t r, uint8_t g, uint8_t b) {
#ifdef ARDUINO
  const StatusLed::RgbColor color(r, g, b);
  StatusLed::Status st = chain_.setAllColor(color);
  if (st.ok()) {
    st = chain_.setAllMode(StatusLed::Mode::Solid);
  }
  if (!st.ok()) {
    lastError_ = st.msg;
    return false;
  }
  if (topology_ == config::LedTopology::TwoIndependentOutputs) {
    st = pair_.setAllColor(color);
    if (st.ok()) {
      st = pair_.setAllMode(StatusLed::Mode::Solid);
    }
    if (!st.ok()) {
      lastError_ = st.msg;
      return false;
    }
  }
#else
  (void)r;
  (void)g;
  (void)b;
#endif
  lastError_ = "OK";
  return true;
}

void StatusLedService::applyState(DeviceLedState state) {
  state_ = state;
#ifdef ARDUINO
  StatusLed::StatusPreset preset = StatusLed::StatusPreset::Info;
  switch (state) {
    case DeviceLedState::Booting:
      preset = StatusLed::StatusPreset::Updating;
      break;
    case DeviceLedState::WifiConnecting:
      preset = StatusLed::StatusPreset::Connecting;
      break;
    case DeviceLedState::MqttDisconnected:
      preset = StatusLed::StatusPreset::Warning;
      break;
    case DeviceLedState::LgBusOffline:
      preset = StatusLed::StatusPreset::HazardAmber;
      break;
    case DeviceLedState::Normal:
      preset = StatusLed::StatusPreset::Ready;
      break;
    case DeviceLedState::Degraded:
      preset = StatusLed::StatusPreset::Warning;
      break;
    case DeviceLedState::ConfigMode:
      preset = StatusLed::StatusPreset::Maintenance;
      break;
    case DeviceLedState::Fatal:
      preset = StatusLed::StatusPreset::Critical;
      break;
  }
  StatusLed::Status st = chain_.setAllPreset(preset);
  if (st.ok() && topology_ == config::LedTopology::TwoIndependentOutputs) {
    st = pair_.setAllPreset(preset);
  }
  lastError_ = st.ok() ? "OK" : st.msg;
#endif
}

}  // namespace lgcl::status

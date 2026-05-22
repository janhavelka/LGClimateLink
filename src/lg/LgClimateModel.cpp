#include "lg/LgClimateModel.h"

#include <math.h>
#include <string.h>

#include "lg/LgProtocol.h"

namespace lgcl::lg {

namespace {

bool sameState(const ClimateState& a, const ClimateState& b) {
  return a.mode == b.mode && a.fan == b.fan && a.swing == b.swing &&
         a.thermistor == b.thermistor &&
         fabsf(a.targetTemperatureC - b.targetTemperatureC) < 0.01f &&
         fabsf(a.currentTemperatureC - b.currentTemperatureC) < 0.01f &&
         a.currentTemperatureValid == b.currentTemperatureValid &&
         a.purifier == b.purifier && a.autoDry == b.autoDry &&
         a.autoDryActive == b.autoDryActive && a.defrost == b.defrost &&
         a.preheat == b.preheat && a.outdoorActive == b.outdoorActive &&
         a.errorCode == b.errorCode;
}

uint8_t modeToLgCode(HvacMode mode) {
  switch (mode) {
    case HvacMode::Cool:
      return 0;
    case HvacMode::Dry:
      return 1;
    case HvacMode::FanOnly:
      return 2;
    case HvacMode::Auto:
      return 3;
    case HvacMode::Heat:
      return 4;
    case HvacMode::Off:
    default:
      return 0;
  }
}

HvacMode modeFromLgCode(uint8_t code, bool on) {
  if (!on) {
    return HvacMode::Off;
  }
  switch (code) {
    case 0:
      return HvacMode::Cool;
    case 1:
      return HvacMode::Dry;
    case 2:
      return HvacMode::FanOnly;
    case 3:
      return HvacMode::Auto;
    case 4:
      return HvacMode::Heat;
    default:
      return HvacMode::Off;
  }
}

uint8_t fanToLgCode(FanMode fan) {
  switch (fan) {
    case FanMode::Low:
      return 0;
    case FanMode::Medium:
      return 1;
    case FanMode::High:
      return 2;
    case FanMode::Auto:
      return 3;
    case FanMode::Slow:
      return 4;
    case FanMode::LowMedium:
      return 5;
    case FanMode::MediumHigh:
      return 6;
    case FanMode::Power:
      return 7;
    default:
      return 3;
  }
}

FanMode fanFromLgCode(uint8_t code) {
  switch (code) {
    case 0:
      return FanMode::Low;
    case 1:
      return FanMode::Medium;
    case 2:
      return FanMode::High;
    case 3:
      return FanMode::Auto;
    case 4:
      return FanMode::Slow;
    case 5:
      return FanMode::LowMedium;
    case 6:
      return FanMode::MediumHigh;
    case 7:
      return FanMode::Power;
    default:
      return FanMode::Auto;
  }
}

int8_t pipeTempFromByte(uint8_t value) {
  static constexpr int8_t X = INT8_MIN;
  static constexpr int8_t table[256] = {
      X, X, X, X, X, X, X, X, X, X, 108, 104, 101, 100, 98, 95,
      93, 91, 89, 87, 85, 84, 82, 81, 79, 78, 76, 75, 74, 73, 72, 71,
      70, 68, 68, 67, 66, 65, 64, 63, 62, 61, 60, 60, 59, 58, 57, 57,
      56, 55, 55, 54, 53, 53, 52, 52, 51, 50, 50, 49, 49, 48, 47, 47,
      46, 46, 45, 45, 44, 44, 43, 43, 42, 42, 41, 41, 40, 40, 39, 39,
      39, 38, 38, 37, 37, 36, 36, 36, 35, 35, 34, 34, 33, 33, 33, 32,
      32, 31, 31, 31, 30, 30, 30, 29, 29, 29, 28, 28, 27, 27, 27, 26,
      26, 26, 25, 25, 24, 24, 24, 23, 23, 23, 22, 22, 22, 21, 21, 21,
      20, 20, 20, 19, 19, 19, 18, 18, 18, 17, 17, 17, 16, 16, 16, 15,
      15, 15, 14, 14, 14, 13, 13, 13, 12, 12, 12, 11, 11, 11, 10, 10,
      10, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 6, 5, 5, 5, 4,
      4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, -1,
      -1, -2, -2, -2, -3, -3, -4, -4, -5, -5, -5, -6, -6, -7, -7, -8,
      -8, -9, -9, -9, -10, -10, -11, -11, -12, -12, -13, -14, -14, -15,
      -15, -16,
      -16, -17, -18, -18, -19, -20, -20, -21, -22, -22, -23, -24, -25,
      -26, -27, -28,
      -29, X, X, X, X, X, X, X, X, X, X, X, X, X, X, X};
  return table[value];
}

void parseCapabilities(const FrameBytes& b, LgCapabilities& c) {
  c.known = true;
  c.verticalSwing = (b[1] & 0x80U) != 0;
  c.horizontalSwing = (b[1] & 0x40U) != 0;
  c.fanAuto = (b[3] & 0x01U) != 0;
  c.fanHigh = true;  // High fan is supported by all known 13-byte AC units.
  c.fanMedium = (b[3] & 0x08U) != 0;
  c.fanLow = (b[3] & 0x10U) != 0;
  c.fanSlow = (b[3] & 0x20U) != 0;
  c.fanLowMedium = (b[6] & 0x08U) != 0;
  c.fanMediumHigh = (b[6] & 0x10U) != 0;
  c.purifier = (b[2] & 0x02U) != 0;
  c.autoMode = (b[2] & 0x08U) != 0;
  c.heat = (b[2] & 0x40U) != 0;
  c.fanOnly = (b[2] & 0x80U) != 0;
  c.dry = (b[2] & 0x80U) != 0;
  c.autoDry = (b[4] & 0x80U) != 0;
  c.espFanSetting = (b[4] & 0x02U) != 0;
  c.overHeatingSetting = (b[7] & 0x80U) != 0;
  c.halfDegrees = (b[5] & 0x20U) == 0;
  c.minSetpointC = (b[6] & 0x20U) ? 16 : 18;
  if ((b[5] & 0x40U) != 0) {
    c.vaneCount = 1;
  } else if ((b[5] & 0x80U) != 0) {
    c.vaneCount = 2;
  } else if ((b[4] & 0x01U) != 0) {
    c.vaneCount = 4;
  }
}

}  // namespace

const char* modeName(HvacMode mode) {
  switch (mode) {
    case HvacMode::Off:
      return "off";
    case HvacMode::Auto:
      return "auto";
    case HvacMode::Cool:
      return "cool";
    case HvacMode::Heat:
      return "heat";
    case HvacMode::Dry:
      return "dry";
    case HvacMode::FanOnly:
      return "fan_only";
    default:
      return "unknown";
  }
}

const char* fanModeName(FanMode fan) {
  switch (fan) {
    case FanMode::Low:
      return "low";
    case FanMode::Medium:
      return "medium";
    case FanMode::High:
      return "high";
    case FanMode::Auto:
      return "auto";
    case FanMode::Slow:
      return "slow";
    case FanMode::LowMedium:
      return "low_medium";
    case FanMode::MediumHigh:
      return "medium_high";
    case FanMode::Power:
      return "power";
    default:
      return "unknown";
  }
}

const char* swingModeName(SwingMode swing) {
  switch (swing) {
    case SwingMode::Off:
      return "off";
    case SwingMode::Vertical:
      return "vertical";
    case SwingMode::Horizontal:
      return "horizontal";
    case SwingMode::Both:
      return "both";
    default:
      return "unknown";
  }
}

const char* thermistorModeName(ThermistorMode mode) {
  switch (mode) {
    case ThermistorMode::Unit:
      return "unit";
    case ThermistorMode::Controller:
      return "controller";
    case ThermistorMode::TwoThermistor:
      return "2th";
    default:
      return "unknown";
  }
}

bool parseModeName(const char* value, HvacMode& out) {
  if (strcmp(value, "off") == 0) out = HvacMode::Off;
  else if (strcmp(value, "auto") == 0 || strcmp(value, "heat_cool") == 0) out = HvacMode::Auto;
  else if (strcmp(value, "cool") == 0) out = HvacMode::Cool;
  else if (strcmp(value, "heat") == 0) out = HvacMode::Heat;
  else if (strcmp(value, "dry") == 0) out = HvacMode::Dry;
  else if (strcmp(value, "fan_only") == 0 || strcmp(value, "fan-only") == 0) out = HvacMode::FanOnly;
  else return false;
  return true;
}

bool parseFanModeName(const char* value, FanMode& out) {
  if (strcmp(value, "low") == 0) out = FanMode::Low;
  else if (strcmp(value, "medium") == 0) out = FanMode::Medium;
  else if (strcmp(value, "high") == 0) out = FanMode::High;
  else if (strcmp(value, "auto") == 0) out = FanMode::Auto;
  else if (strcmp(value, "slow") == 0 || strcmp(value, "quiet") == 0) out = FanMode::Slow;
  else if (strcmp(value, "low_medium") == 0) out = FanMode::LowMedium;
  else if (strcmp(value, "medium_high") == 0) out = FanMode::MediumHigh;
  else if (strcmp(value, "power") == 0) out = FanMode::Power;
  else return false;
  return true;
}

bool parseSwingModeName(const char* value, SwingMode& out) {
  if (strcmp(value, "off") == 0) out = SwingMode::Off;
  else if (strcmp(value, "vertical") == 0 || strcmp(value, "on") == 0) out = SwingMode::Vertical;
  else if (strcmp(value, "horizontal") == 0) out = SwingMode::Horizontal;
  else if (strcmp(value, "both") == 0) out = SwingMode::Both;
  else return false;
  return true;
}

bool parseThermistorModeName(const char* value, ThermistorMode& out) {
  if (strcmp(value, "unit") == 0 || strcmp(value, "lg_internal") == 0) out = ThermistorMode::Unit;
  else if (strcmp(value, "controller") == 0 || strcmp(value, "bme280") == 0) out = ThermistorMode::Controller;
  else if (strcmp(value, "2th") == 0) out = ThermistorMode::TwoThermistor;
  else return false;
  return true;
}

float clampTargetTemperature(float temperatureC, const LgCapabilities& capabilities) {
  const float minT = static_cast<float>(capabilities.minSetpointC);
  const float maxT = static_cast<float>(capabilities.maxSetpointC);
  if (!isfinite(temperatureC)) {
    return minT;
  }
  if (temperatureC < minT) {
    return minT;
  }
  if (temperatureC > maxT) {
    return maxT;
  }
  return temperatureC;
}

float roundToLgStep(float temperatureC, const LgCapabilities& capabilities) {
  const float step = capabilities.halfDegrees ? 0.5f : 1.0f;
  return roundf(clampTargetTemperature(temperatureC, capabilities) / step) * step;
}

ApplyResult applyFrameToState(const LgFrame& frame, uint32_t nowMs, ClimateState& state) {
  ClimateState before = state;
  state.online = true;
  state.lastFrameMs = nowMs;
  const FrameBytes& b = frame.bytes;

  if (frame.type == FrameType::Capabilities) {
    if (frame.sender != Sender::Unit) {
      return {false, false, "capabilities not from unit"};
    }
    parseCapabilities(b, state.capabilities);
    return {true, !sameState(before, state), "capabilities applied"};
  }

  if (frame.type == FrameType::Status) {
    const bool on = (b[1] & 0x02U) != 0;
    state.mode = modeFromLgCode((b[1] >> 2U) & 0x07U, on);
    state.fan = fanFromLgCode(b[1] >> 5U);
    const bool horiz = (b[2] & 0x40U) != 0;
    const bool vert = (b[2] & 0x80U) != 0;
    state.swing = horiz && vert ? SwingMode::Both
                                : (horiz ? SwingMode::Horizontal
                                         : (vert ? SwingMode::Vertical : SwingMode::Off));
    state.purifier = (b[2] & 0x04U) != 0;
    state.defrost = (b[3] & 0x04U) != 0;
    state.preheat = (b[3] & 0x08U) != 0;
    state.outdoorActive = (b[5] & 0x04U) != 0;
    state.targetTemperatureC = static_cast<float>((b[6] & 0x0FU) + 15U) +
                               ((b[5] & 0x01U) ? 0.5f : 0.0f);
    state.thermistor = static_cast<ThermistorMode>((b[6] >> 4U) & 0x03U);
    state.currentTemperatureC = static_cast<float>(b[7] & 0x3FU) * 0.5f + 10.0f;
    state.currentTemperatureValid = true;
    state.errorCode = frame.sender == Sender::Unit ? b[11] : state.errorCode;
    state.autoDryActive = ((b[10] & 0x10U) != 0) && !on;
    if (((b[8] >> 3U) & 0x07U) == 3U) {
      state.sleepTimerMinutes = static_cast<uint16_t>(((b[8] & 0x07U) << 8U) | b[9]);
    }
    return {true, !sameState(before, state), "status applied"};
  }

  if (frame.type == FrameType::TypeASettings) {
    state.fanInstallerValue[0] = b[2];
    state.fanInstallerValue[1] = b[3];
    state.fanInstallerValue[2] = b[4];
    state.fanInstallerValue[3] = b[5];
    state.vanePosition[0] = b[7] & 0x0F;
    state.vanePosition[1] = (b[7] >> 4U) & 0x0F;
    state.vanePosition[2] = b[8] & 0x0F;
    state.vanePosition[3] = (b[8] >> 4U) & 0x0F;
    state.autoDry = (b[11] & 0x08U) != 0;
    return {true, !sameState(before, state), "type A applied"};
  }

  if (frame.type == FrameType::TypeBSettings) {
    state.overHeating = (b[2] >> 3U) & 0x07U;
    state.pipeInC = pipeTempFromByte(b[3]);
    state.pipeOutC = pipeTempFromByte(b[4]);
    state.pipeMidC = pipeTempFromByte(b[5]);
    return {true, true, "type B applied"};
  }

  return {false, false, "unsupported frame type"};
}

FrameBytes buildStatusFrame(const DesiredClimate& desired,
                            const ClimateState& observed,
                            bool slaveController,
                            bool markChanged) {
  FrameBytes frame = {};
  frame[0] = slaveController ? 0x28 : 0xA8;
  frame[1] = markChanged ? 0x01 : 0x00;
  if (desired.mode != HvacMode::Off) {
    frame[1] |= 0x02U;
  }
  frame[1] |= static_cast<uint8_t>(modeToLgCode(desired.mode) << 2U);
  frame[1] |= static_cast<uint8_t>(fanToLgCode(desired.fan) << 5U);
  if (desired.purifier) {
    frame[2] |= 0x04U;
  }
  if (desired.swing == SwingMode::Horizontal || desired.swing == SwingMode::Both) {
    frame[2] |= 0x40U;
  }
  if (desired.swing == SwingMode::Vertical || desired.swing == SwingMode::Both) {
    frame[2] |= 0x80U;
  }
  if (desired.sleepTimerMinutes > 0) {
    frame[3] |= 0x10U;
    frame[8] = static_cast<uint8_t>(0x18U | ((desired.sleepTimerMinutes >> 8U) & 0x07U));
    frame[9] = static_cast<uint8_t>(desired.sleepTimerMinutes & 0xFFU);
  }
  const float target = roundToLgStep(desired.targetTemperatureC, observed.capabilities);
  const uint8_t whole = static_cast<uint8_t>(floorf(target));
  frame[6] = static_cast<uint8_t>((whole - 15U) & 0x0FU);
  if (fabsf(target - static_cast<float>(whole)) >= 0.25f) {
    frame[5] |= 0x01U;
  }
  frame[6] |= static_cast<uint8_t>((static_cast<uint8_t>(desired.thermistor) & 0x03U) << 4U);
  const float room = observed.currentTemperatureValid ? observed.currentTemperatureC : target;
  const int roomCode = static_cast<int>(roundf((room - 10.0f) * 2.0f));
  frame[7] = static_cast<uint8_t>(roomCode < 0 ? 0 : (roomCode > 0x3F ? 0x3F : roomCode));
  frame[10] = 0x04U;
  if (desired.autoDry) {
    frame[10] |= 0x10U;
  }
  frame[12] = calcChecksum(frame);
  return frame;
}

FrameBytes buildTypeASettingsFrame(const ClimateState& state, bool slaveController) {
  FrameBytes frame = {};
  frame[0] = slaveController ? 0x2A : 0xAA;
  frame[2] = state.fanInstallerValue[0];
  frame[3] = state.fanInstallerValue[1];
  frame[4] = state.fanInstallerValue[2];
  frame[5] = state.fanInstallerValue[3];
  frame[7] = static_cast<uint8_t>((state.vanePosition[0] & 0x0FU) |
                                  ((state.vanePosition[1] & 0x0FU) << 4U));
  frame[8] = static_cast<uint8_t>((state.vanePosition[2] & 0x0FU) |
                                  ((state.vanePosition[3] & 0x0FU) << 4U));
  frame[10] = 0xF1U;
  frame[11] = state.autoDry ? 0x08U : 0x00U;
  frame[12] = calcChecksum(frame);
  return frame;
}

FrameBytes buildTypeBSettingsFrame(const ClimateState& state,
                                   bool slaveController,
                                   bool timedRequest) {
  FrameBytes frame = {};
  frame[0] = slaveController ? 0x2B : 0xAB;
  frame[1] = timedRequest ? 0x80U : 0x00U;
  frame[2] = static_cast<uint8_t>((state.overHeating & 0x07U) << 3U);
  frame[12] = calcChecksum(frame);
  return frame;
}

}  // namespace lgcl::lg

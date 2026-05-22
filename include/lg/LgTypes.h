#pragma once

#include <array>
#include <stdint.h>

namespace lgcl::lg {

static constexpr uint8_t kFrameLength = 13;
static constexpr uint32_t kInterByteTimeoutMs = 15000;

using FrameBytes = std::array<uint8_t, kFrameLength>;

enum class FrameType : uint8_t {
  Status = 0,
  Capabilities = 1,
  TypeASettings = 2,
  TypeBSettings = 3,
  TypeCStatus = 4,
  TypeDAdvanced = 5,
  TypeEExtended = 6,
  TypeFPower = 7,
};

enum class Sender : uint8_t {
  Unknown = 0,
  Unit,
  MasterController,
  SlaveController,
};

enum class HvacMode : uint8_t {
  Off = 0,
  Auto,
  Cool,
  Heat,
  Dry,
  FanOnly,
};

enum class FanMode : uint8_t {
  Low = 0,
  Medium,
  High,
  Auto,
  Slow,
  LowMedium,
  MediumHigh,
  Power,
};

enum class SwingMode : uint8_t {
  Off = 0,
  Vertical,
  Horizontal,
  Both,
};

enum class ThermistorMode : uint8_t {
  Unit = 0,
  Controller = 1,
  TwoThermistor = 2,
};

struct LgFrame {
  FrameBytes bytes = {};
  FrameType type = FrameType::Status;
  Sender sender = Sender::Unknown;
};

struct LgCapabilities {
  bool known = false;
  bool heat = true;
  bool fanOnly = true;
  bool autoMode = true;
  bool dry = true;
  bool fanAuto = true;
  bool fanSlow = true;
  bool fanLow = true;
  bool fanMedium = true;
  bool fanHigh = true;
  bool fanLowMedium = false;
  bool fanMediumHigh = false;
  bool verticalSwing = true;
  bool horizontalSwing = true;
  bool purifier = false;
  bool autoDry = false;
  bool espFanSetting = false;
  bool overHeatingSetting = false;
  uint8_t vaneCount = 4;
  uint8_t minSetpointC = 16;
  uint8_t maxSetpointC = 30;
  bool halfDegrees = true;
};

struct ClimateState {
  bool online = false;
  uint32_t lastFrameMs = 0;
  HvacMode mode = HvacMode::Off;
  FanMode fan = FanMode::Auto;
  SwingMode swing = SwingMode::Off;
  ThermistorMode thermistor = ThermistorMode::Controller;
  float targetTemperatureC = 22.0f;
  float currentTemperatureC = 22.0f;
  bool currentTemperatureValid = false;
  bool purifier = false;
  bool autoDry = false;
  bool autoDryActive = false;
  bool defrost = false;
  bool preheat = false;
  bool outdoorActive = false;
  uint8_t errorCode = 0;
  int8_t pipeInC = INT8_MIN;
  int8_t pipeMidC = INT8_MIN;
  int8_t pipeOutC = INT8_MIN;
  uint16_t sleepTimerMinutes = 0;
  uint8_t vanePosition[4] = {0, 0, 0, 0};
  uint8_t fanInstallerValue[4] = {0, 0, 0, 0};
  uint8_t overHeating = 0;
  LgCapabilities capabilities;
};

struct DesiredClimate {
  HvacMode mode = HvacMode::Off;
  FanMode fan = FanMode::Auto;
  SwingMode swing = SwingMode::Off;
  ThermistorMode thermistor = ThermistorMode::Controller;
  float targetTemperatureC = 22.0f;
  bool purifier = false;
  bool autoDry = false;
  uint16_t sleepTimerMinutes = 0;
};

struct ProtocolError {
  bool ok = true;
  const char* message = "OK";
};

}  // namespace lgcl::lg

#pragma once

/**
 * @file LgTypes.h
 * @brief Shared LG protocol and climate-state data types.
 */

#include <array>
#include <stdint.h>

namespace lgcl::lg {

/// Number of bytes in the modern LG wired-controller frame.
static constexpr uint8_t kFrameLength = 13;

/// Parser reset interval for very slow or interrupted byte streams.
static constexpr uint32_t kInterByteTimeoutMs = 15000;

/// Raw LG frame bytes including checksum.
using FrameBytes = std::array<uint8_t, kFrameLength>;

/// Low three-bit LG message type from the frame header.
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

/// Logical sender decoded from the LG frame header.
enum class Sender : uint8_t {
  Unknown = 0,
  Unit,
  MasterController,
  SlaveController,
};

/// HVAC operating mode exposed to CLI, MQTT, and Home Assistant.
enum class HvacMode : uint8_t {
  Off = 0,
  Auto,
  Cool,
  Heat,
  Dry,
  FanOnly,
};

/// Fan-speed mode from the LG protocol model.
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

/// Simplified vane/swing mode exposed by the controller.
enum class SwingMode : uint8_t {
  Off = 0,
  Vertical,
  Horizontal,
  Both,
};

/// LG installer thermistor source setting.
enum class ThermistorMode : uint8_t {
  Unit = 0,
  Controller = 1,
  TwoThermistor = 2,
};

/// Parsed and classified LG frame.
struct LgFrame {
  FrameBytes bytes = {};
  FrameType type = FrameType::Status;
  Sender sender = Sender::Unknown;
};

/// Feature flags learned from LG capability frames.
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

/**
 * @brief Latest observed LG unit state.
 *
 * This state is derived from accepted bus frames and local room-temperature
 * updates. It is the source for CLI status and MQTT state publishing.
 */
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

/// Desired controller state that is serialized into outbound LG frames.
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

/// Result used by protocol helpers that can reject unsupported input.
struct ProtocolError {
  bool ok = true;
  const char* message = "OK";
};

}  // namespace lgcl::lg

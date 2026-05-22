#pragma once

/**
 * @file LgClimateModel.h
 * @brief Pure LG frame-to-climate mapping and outbound frame builders.
 */

#include "lg/LgTypes.h"

namespace lgcl::lg {

/// Result of applying one accepted frame to the climate model.
struct ApplyResult {
  bool accepted = false;
  bool stateChanged = false;
  const char* message = "ignored";
};

/// Stable lower-case mode name used by CLI and Home Assistant MQTT.
const char* modeName(HvacMode mode);
/// Stable lower-case fan mode name used by CLI and Home Assistant MQTT.
const char* fanModeName(FanMode fan);
/// Stable lower-case swing mode name used by CLI and Home Assistant MQTT.
const char* swingModeName(SwingMode swing);
/// Stable lower-case thermistor mode name used by CLI and MQTT.
const char* thermistorModeName(ThermistorMode mode);

/// Parse a mode name from CLI or MQTT payload.
bool parseModeName(const char* value, HvacMode& out);
/// Parse a fan mode name from CLI or MQTT payload.
bool parseFanModeName(const char* value, FanMode& out);
/// Parse a swing mode name from CLI or MQTT payload.
bool parseSwingModeName(const char* value, SwingMode& out);
/// Parse a thermistor mode name from CLI or MQTT payload.
bool parseThermistorModeName(const char* value, ThermistorMode& out);

/// Clamp a target setpoint to the capability range reported by the LG unit.
float clampTargetTemperature(float temperatureC, const LgCapabilities& capabilities);
/// Round a target setpoint to the LG-supported step size.
float roundToLgStep(float temperatureC, const LgCapabilities& capabilities);

/// Apply one parsed LG frame to the current climate state.
ApplyResult applyFrameToState(const LgFrame& frame, uint32_t nowMs, ClimateState& state);
/// Build an outbound status frame from desired and observed state.
FrameBytes buildStatusFrame(const DesiredClimate& desired,
                            const ClimateState& observed,
                            bool slaveController,
                            bool markChanged);
/// Build an outbound type-A settings frame.
FrameBytes buildTypeASettingsFrame(const ClimateState& state, bool slaveController);
/// Build an outbound type-B settings/request frame.
FrameBytes buildTypeBSettingsFrame(const ClimateState& state,
                                   bool slaveController,
                                   bool timedRequest);

}  // namespace lgcl::lg

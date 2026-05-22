#pragma once

#include "lg/LgTypes.h"

namespace lgcl::lg {

struct ApplyResult {
  bool accepted = false;
  bool stateChanged = false;
  const char* message = "ignored";
};

const char* modeName(HvacMode mode);
const char* fanModeName(FanMode fan);
const char* swingModeName(SwingMode swing);
const char* thermistorModeName(ThermistorMode mode);

bool parseModeName(const char* value, HvacMode& out);
bool parseFanModeName(const char* value, FanMode& out);
bool parseSwingModeName(const char* value, SwingMode& out);
bool parseThermistorModeName(const char* value, ThermistorMode& out);

float clampTargetTemperature(float temperatureC, const LgCapabilities& capabilities);
float roundToLgStep(float temperatureC, const LgCapabilities& capabilities);

ApplyResult applyFrameToState(const LgFrame& frame, uint32_t nowMs, ClimateState& state);
FrameBytes buildStatusFrame(const DesiredClimate& desired,
                            const ClimateState& observed,
                            bool slaveController,
                            bool markChanged);
FrameBytes buildTypeASettingsFrame(const ClimateState& state, bool slaveController);
FrameBytes buildTypeBSettingsFrame(const ClimateState& state,
                                   bool slaveController,
                                   bool timedRequest);

}  // namespace lgcl::lg

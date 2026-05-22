#pragma once

#include "lg/LgBus.h"
#include "lg/LgClimateModel.h"

namespace lgcl::lg {

struct LgControllerSnapshot {
  ClimateState state;
  DesiredClimate desired;
  bool pendingEcho = false;
  uint32_t lastStatusSendMs = 0;
  uint32_t lastTypeBRequestMs = 0;
  uint32_t missedEchoes = 0;
  uint32_t acceptedFrames = 0;
  uint32_t rejectedFrames = 0;
  bool traceEnabled = false;
};

class LgControllerService {
 public:
  explicit LgControllerService(LgBus& bus) : bus_(bus) {}

  void begin(bool slaveController, uint32_t nowMs);
  void tick(uint32_t nowMs);
  void setDesired(const DesiredClimate& desired);
  void setLocalRoomTemperature(float temperatureC, bool valid);
  DesiredClimate desired() const { return desired_; }
  ClimateState state() const { return state_; }
  const LgControllerSnapshot& snapshot() const { return snapshot_; }
  void setTraceEnabled(bool enabled) { snapshot_.traceEnabled = enabled; }
  bool traceEnabled() const { return snapshot_.traceEnabled; }
  bool sendRaw(const FrameBytes& frame, uint32_t nowMs);

 private:
  enum class PendingKind : uint8_t { None, Status, TypeA, TypeB, Raw };

  bool sendPending(uint32_t nowMs);
  void handleFrame(const LgFrame& frame, uint32_t nowMs);
  void queueStatus(bool changed);

  LgBus& bus_;
  ClimateState state_;
  DesiredClimate desired_;
  LgControllerSnapshot snapshot_;
  FrameBytes pendingFrame_ = {};
  PendingKind pendingKind_ = PendingKind::None;
  bool pendingChanged_ = false;
  bool slaveController_ = false;
  uint32_t pendingSinceMs_ = 0;
};

}  // namespace lgcl::lg

#pragma once

/**
 * @file LgControllerService.h
 * @brief LG climate-controller state machine built on top of LgBus.
 */

#include "lg/LgBus.h"
#include "lg/LgClimateModel.h"

namespace lgcl::lg {

/// Diagnostic snapshot for CLI, MQTT health, and tests.
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

/**
 * @brief Coordinates LG receive parsing, desired state, and scheduled transmit.
 *
 * This service owns climate state and pending outbound frames. It keeps bus
 * timing inside tick() and leaves hardware byte I/O to LgBus.
 */
class LgControllerService {
 public:
  /// Create the controller service with an already-owned bus adapter.
  explicit LgControllerService(LgBus& bus) : bus_(bus) {}

  /// Initialize desired state, snapshot counters, and controller role.
  void begin(bool slaveController, uint32_t nowMs);
  /// Run bounded receive/transmit work for the current loop iteration.
  void tick(uint32_t nowMs);
  /// Update desired LG state and queue a status frame if it changed.
  void setDesired(const DesiredClimate& desired);
  /// Inject local room temperature from the BME280 path.
  void setLocalRoomTemperature(float temperatureC, bool valid);
  /// Return the current desired state.
  DesiredClimate desired() const { return desired_; }
  /// Return the latest observed climate state.
  ClimateState state() const { return state_; }
  /// Return service counters and trace state.
  const LgControllerSnapshot& snapshot() const { return snapshot_; }
  /// Enable or disable protocol trace capture/printing at the application layer.
  void setTraceEnabled(bool enabled) { snapshot_.traceEnabled = enabled; }
  /// Return whether trace is enabled.
  bool traceEnabled() const { return snapshot_.traceEnabled; }
  /// Queue a raw frame. Caller must apply any guardrails before calling.
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

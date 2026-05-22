#include "lg/LgControllerService.h"

#include "config/BuildConfig.h"

namespace lgcl::lg {

void LgControllerService::begin(bool slaveController, uint32_t nowMs) {
  slaveController_ = slaveController;
  state_ = ClimateState{};
  desired_ = DesiredClimate{};
  desired_.mode = HvacMode::Off;
  desired_.targetTemperatureC = 22.0f;
  desired_.fan = FanMode::Auto;
  desired_.thermistor = ThermistorMode::Controller;
  snapshot_ = LgControllerSnapshot{};
  snapshot_.state = state_;
  snapshot_.desired = desired_;
  snapshot_.lastStatusSendMs = nowMs - config::kLgStatusPeriodMs;
  snapshot_.lastTypeBRequestMs = nowMs;
  queueStatus(true);
}

void LgControllerService::setDesired(const DesiredClimate& desired) {
  desired_ = desired;
  desired_.targetTemperatureC = roundToLgStep(desired_.targetTemperatureC, state_.capabilities);
  snapshot_.desired = desired_;
  queueStatus(true);
}

void LgControllerService::setLocalRoomTemperature(float temperatureC, bool valid) {
  state_.currentTemperatureC = temperatureC;
  state_.currentTemperatureValid = valid;
}

void LgControllerService::tick(uint32_t nowMs) {
  LgFrame frame;
  while (bus_.poll(nowMs, frame)) {
    handleFrame(frame, nowMs);
  }

  if (pendingKind_ != PendingKind::None) {
    if (sendPending(nowMs)) {
      return;
    }
    if (pendingSinceMs_ != 0 && (nowMs - pendingSinceMs_) > 8000) {
      snapshot_.missedEchoes++;
      pendingKind_ = PendingKind::None;
      pendingSinceMs_ = 0;
      if (pendingChanged_) {
        queueStatus(true);
      }
    }
    return;
  }

  if (!slaveController_ &&
      (nowMs - snapshot_.lastTypeBRequestMs) > config::kLgTypeBRequestPeriodMs) {
    pendingFrame_ = buildTypeBSettingsFrame(state_, slaveController_, true);
    pendingKind_ = PendingKind::TypeB;
    pendingChanged_ = false;
  } else if (!slaveController_ &&
             (nowMs - snapshot_.lastStatusSendMs) > config::kLgStatusPeriodMs) {
    queueStatus(false);
  }

  (void)sendPending(nowMs);
  snapshot_.state = state_;
  snapshot_.desired = desired_;
  snapshot_.pendingEcho = pendingKind_ != PendingKind::None && pendingSinceMs_ != 0;
}

bool LgControllerService::sendRaw(const FrameBytes& frame, uint32_t nowMs) {
  if (!hasValidChecksum(frame)) {
    return false;
  }
  pendingFrame_ = frame;
  pendingKind_ = PendingKind::Raw;
  pendingChanged_ = false;
  pendingSinceMs_ = 0;
  return sendPending(nowMs);
}

void LgControllerService::queueStatus(bool changed) {
  pendingFrame_ = buildStatusFrame(desired_, state_, slaveController_, changed);
  pendingKind_ = PendingKind::Status;
  pendingChanged_ = changed;
  pendingSinceMs_ = 0;
}

bool LgControllerService::sendPending(uint32_t nowMs) {
  if (pendingKind_ == PendingKind::None) {
    return false;
  }
  if (pendingSinceMs_ != 0) {
    return false;
  }
  if (!bus_.canSend(nowMs, config::kLgIdleBeforeTxMs)) {
    return false;
  }
  if (!bus_.send(pendingFrame_, nowMs)) {
    return false;
  }
  pendingSinceMs_ = nowMs;
  if (pendingKind_ == PendingKind::Status) {
    snapshot_.lastStatusSendMs = nowMs;
  } else if (pendingKind_ == PendingKind::TypeB) {
    snapshot_.lastTypeBRequestMs = nowMs;
  }
  return true;
}

void LgControllerService::handleFrame(const LgFrame& frame, uint32_t nowMs) {
  if (pendingKind_ != PendingKind::None && pendingSinceMs_ != 0 &&
      frame.bytes == pendingFrame_) {
    pendingKind_ = PendingKind::None;
    pendingSinceMs_ = 0;
    pendingChanged_ = false;
    return;
  }

  const ApplyResult result = applyFrameToState(frame, nowMs, state_);
  if (result.accepted) {
    snapshot_.acceptedFrames++;
  } else {
    snapshot_.rejectedFrames++;
  }

  if (result.accepted && frame.sender == Sender::Unit) {
    if (frame.type == FrameType::Status) {
      desired_.mode = state_.mode;
      desired_.fan = state_.fan;
      desired_.swing = state_.swing;
      desired_.targetTemperatureC = state_.targetTemperatureC;
      desired_.thermistor = state_.thermistor;
      desired_.purifier = state_.purifier;
      desired_.autoDry = state_.autoDry;
      desired_.sleepTimerMinutes = state_.sleepTimerMinutes;
    } else if (frame.type == FrameType::TypeASettings) {
      pendingFrame_ = buildTypeASettingsFrame(state_, slaveController_);
      pendingKind_ = PendingKind::TypeA;
      pendingChanged_ = false;
      pendingSinceMs_ = 0;
    }
  }
}

}  // namespace lgcl::lg

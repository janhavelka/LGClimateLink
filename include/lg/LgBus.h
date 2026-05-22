#pragma once

#include "lg/LgProtocol.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

namespace lgcl::lg {

struct LgBusSnapshot {
  bool initialized = false;
  bool enabled = false;
  uint32_t rxFrames = 0;
  uint32_t txFrames = 0;
  uint32_t checksumErrors = 0;
  uint32_t formatErrors = 0;
  uint32_t lastRxActivityMs = 0;
  uint32_t lastFrameMs = 0;
  const char* lastError = "not initialized";
};

class LgBus {
 public:
  bool begin(int enPin, int txPin, int rxPin, uint32_t baud);
  void setEnabled(bool enabled);
  bool canSend(uint32_t nowMs, uint32_t idleMs) const;
  bool send(const FrameBytes& frame, uint32_t nowMs);
  bool poll(uint32_t nowMs, LgFrame& out);
  const LgBusSnapshot& snapshot() const { return snapshot_; }
  bool rxLineIdle() const;

 private:
  int enPin_ = -1;
  int txPin_ = -1;
  int rxPin_ = -1;
  uint32_t baud_ = 104;
  FrameParser parser_;
  LgBusSnapshot snapshot_;
};

}  // namespace lgcl::lg

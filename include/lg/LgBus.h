#pragma once

/**
 * @file LgBus.h
 * @brief Arduino UART/LIN transport wrapper for the LG wired-controller bus.
 */

#include "lg/LgProtocol.h"

#ifdef ARDUINO
#include <Arduino.h>
#endif

namespace lgcl::lg {

/// Runtime counters and last-error state for the LG bus adapter.
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

/**
 * @brief Owns the LIN transceiver pins and byte-level LG bus I/O.
 *
 * The class keeps transport concerns separate from protocol state. It polls
 * UART bytes, feeds FrameParser, tracks errors, and sends complete frames only
 * when the caller has confirmed the bus is idle.
 */
class LgBus {
 public:
  /// Initialize GPIO, UART, parser, and snapshot state.
  bool begin(int enPin, int txPin, int rxPin, uint32_t baud);
  /// Enable or disable the TLIN1027 transceiver output path.
  void setEnabled(bool enabled);
  /// Return true when RX has been idle long enough for a safe transmit attempt.
  bool canSend(uint32_t nowMs, uint32_t idleMs) const;
  /// Send one complete 13-byte LG frame.
  bool send(const FrameBytes& frame, uint32_t nowMs);
  /// Poll received bytes and return one parsed frame when available.
  bool poll(uint32_t nowMs, LgFrame& out);
  /// Return the latest bus counters.
  const LgBusSnapshot& snapshot() const { return snapshot_; }
  /// Sample the RX line and return true when it is recessive/high.
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

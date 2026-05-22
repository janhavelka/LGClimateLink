#include "lg/LgBus.h"

#ifdef ARDUINO

namespace lgcl::lg {

bool LgBus::begin(int enPin, int txPin, int rxPin, uint32_t baud) {
  enPin_ = enPin;
  txPin_ = txPin;
  rxPin_ = rxPin;
  baud_ = baud;
  snapshot_ = LgBusSnapshot{};

  pinMode(enPin_, OUTPUT);
  digitalWrite(enPin_, LOW);
  pinMode(rxPin_, INPUT_PULLUP);
  pinMode(txPin_, OUTPUT);
  digitalWrite(txPin_, HIGH);
  delay(5);

  Serial1.begin(static_cast<unsigned long>(baud_), SERIAL_8N1, rxPin_, txPin_);
  setEnabled(true);
  parser_.reset();
  snapshot_.initialized = true;
  snapshot_.lastError = "OK";
  return true;
}

void LgBus::setEnabled(bool enabled) {
  if (enPin_ >= 0) {
    digitalWrite(enPin_, enabled ? HIGH : LOW);
  }
  snapshot_.enabled = enabled;
}

bool LgBus::rxLineIdle() const {
  if (rxPin_ < 0) {
    return false;
  }
  return digitalRead(rxPin_) == HIGH;
}

bool LgBus::canSend(uint32_t nowMs, uint32_t idleMs) const {
  if (!snapshot_.initialized || !snapshot_.enabled) {
    return false;
  }
  if (!rxLineIdle()) {
    return false;
  }
  if (Serial1.available() > 0) {
    return false;
  }
  return (nowMs - snapshot_.lastRxActivityMs) >= idleMs;
}

bool LgBus::send(const FrameBytes& frame, uint32_t nowMs) {
  if (!snapshot_.initialized || !snapshot_.enabled) {
    snapshot_.lastError = "LIN bus not initialized/enabled";
    return false;
  }
  if (!hasValidChecksum(frame)) {
    snapshot_.lastError = "refusing to send bad checksum";
    return false;
  }
  const size_t written = Serial1.write(frame.data(), frame.size());
  if (written != frame.size()) {
    snapshot_.lastError = "UART write incomplete";
    return false;
  }
  snapshot_.txFrames++;
  snapshot_.lastRxActivityMs = nowMs;
  snapshot_.lastError = "OK";
  return true;
}

bool LgBus::poll(uint32_t nowMs, LgFrame& out) {
  while (Serial1.available() > 0) {
    const int value = Serial1.read();
    if (value < 0) {
      break;
    }
    snapshot_.lastRxActivityMs = nowMs;
    const ParseResult result = parser_.feed(static_cast<uint8_t>(value), nowMs);
    if (result.checksumError) {
      snapshot_.checksumErrors++;
      snapshot_.lastError = "checksum error";
    }
    if (result.formatError) {
      snapshot_.formatErrors++;
      snapshot_.lastError = "format error";
    }
    if (result.hasFrame) {
      out = result.frame;
      snapshot_.rxFrames++;
      snapshot_.lastFrameMs = nowMs;
      snapshot_.lastError = "OK";
      return true;
    }
  }
  return false;
}

}  // namespace lgcl::lg

#endif

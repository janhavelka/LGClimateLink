#include "digipot/DigipotService.h"

namespace lgcl::digipot {

bool DigipotService::begin(uint8_t address,
                           const NtcCalibration& ntc,
                           const DigipotCalibration& digipot,
                           uint32_t nowMs) {
  address_ = address;
  ntc_ = ntc;
  digipot_ = digipot;
  snapshot_ = DigipotSnapshot{};
  snapshot_.code = digipot_.safeWiperCode;
  snapshot_.effectiveOhms = effectiveResistanceForCode(snapshot_.code, digipot_);
  snapshot_.requestedOhms = snapshot_.effectiveOhms;
  snapshot_.lastWriteMs = nowMs;

  if (!validate(ntc_).ok || !validate(digipot_).ok) {
    snapshot_.mode = DigipotMode::Fault;
    snapshot_.lastError = "invalid calibration";
    return false;
  }
  if (driver_ == nullptr) {
    snapshot_.mode = DigipotMode::Fault;
    snapshot_.lastError = "digipot driver missing";
    return false;
  }
  if (!driver_->begin(address_, digipot_)) {
    markError(driver_->lastError());
    return false;
  }
  snapshot_.initialized = true;
  if (!driver_->setTopology(digipot_.topology)) {
    markError(driver_->lastError());
    return false;
  }
  return writeCode(digipot_.safeWiperCode,
                   effectiveResistanceForCode(digipot_.safeWiperCode, digipot_),
                   DigipotMode::BootSafe,
                   nowMs);
}

void DigipotService::tick(uint32_t nowMs, bool temperatureFresh, float temperatureC) {
  if (!snapshot_.initialized || driver_ == nullptr) {
    return;
  }

  if (snapshot_.mode == DigipotMode::Manual || snapshot_.mode == DigipotMode::SafeFixed) {
    return;
  }

  if (temperatureFresh) {
    const WiperResult result = wiperForTemperature(temperatureC, ntc_, digipot_);
    snapshot_.lastGoodInputMs = nowMs;
    if (!result.ok) {
      (void)setSafeFixed(nowMs);
      snapshot_.lastError = result.message;
      return;
    }
    (void)writeCode(result.code, result.requestedResistanceOhms, DigipotMode::Normal, nowMs);
    return;
  }

  if (snapshot_.lastGoodInputMs != 0 &&
      (nowMs - snapshot_.lastGoodInputMs) <= ntc_.holdLastGoodMs) {
    snapshot_.mode = DigipotMode::HoldLastGood;
    snapshot_.degraded = true;
    return;
  }

  (void)setSafeFixed(nowMs);
}

bool DigipotService::setManualCode(uint8_t code, uint32_t nowMs) {
  if (code < digipot_.minWiperCode || code > digipot_.maxAllowedWiperCode) {
    snapshot_.lastError = "manual wiper code out of range";
    return false;
  }
  return writeCode(code, effectiveResistanceForCode(code, digipot_), DigipotMode::Manual, nowMs);
}

bool DigipotService::setSafeFixed(uint32_t nowMs) {
  return writeCode(digipot_.safeWiperCode,
                   effectiveResistanceForCode(digipot_.safeWiperCode, digipot_),
                   DigipotMode::SafeFixed,
                   nowMs);
}

bool DigipotService::writeCode(uint8_t code,
                               float requestedOhms,
                               DigipotMode mode,
                               uint32_t nowMs) {
  if (driver_ == nullptr || !snapshot_.initialized) {
    snapshot_.lastError = "digipot not initialized";
    return false;
  }
  if (!driver_->writeWiper(code)) {
    markError(driver_->lastError());
    return false;
  }
  uint8_t readback = code;
  if (driver_->readWiper(readback) && readback != code) {
    markError("digipot readback mismatch");
    return false;
  }
  snapshot_.mode = mode;
  snapshot_.degraded = mode != DigipotMode::Normal && mode != DigipotMode::Manual;
  snapshot_.code = code;
  snapshot_.requestedOhms = requestedOhms;
  snapshot_.effectiveOhms = effectiveResistanceForCode(code, digipot_);
  snapshot_.lastWriteMs = nowMs;
  snapshot_.consecutiveErrors = 0;
  snapshot_.lastError = "OK";
  return true;
}

void DigipotService::markError(const char* msg) {
  snapshot_.mode = DigipotMode::Fault;
  snapshot_.degraded = true;
  snapshot_.consecutiveErrors++;
  snapshot_.totalErrors++;
  snapshot_.lastError = msg == nullptr ? "digipot error" : msg;
}

const char* digipotModeName(DigipotMode mode) {
  switch (mode) {
    case DigipotMode::BootSafe:
      return "boot_safe";
    case DigipotMode::Normal:
      return "normal";
    case DigipotMode::HoldLastGood:
      return "hold_last_good";
    case DigipotMode::SafeFixed:
      return "safe_fixed";
    case DigipotMode::Fault:
      return "fault";
    case DigipotMode::Manual:
      return "manual";
    default:
      return "unknown";
  }
}

#ifdef ARDUINO
MCP45HVX1::Status Mcp45hvx1ArduinoDriver::mapWireResult(uint8_t result,
                                                        const char* context) {
  switch (result) {
    case 0:
      return MCP45HVX1::Status::Ok();
    case 1:
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::INVALID_PARAM, context, result);
    case 2:
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_NACK_ADDR, context, result);
    case 3:
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_NACK_DATA, context, result);
    case 5:
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_TIMEOUT, context, result);
    case 4:
    default:
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_BUS, context, result);
  }
}

MCP45HVX1::Status Mcp45hvx1ArduinoDriver::wireWrite(uint8_t addr,
                                                    const uint8_t* data,
                                                    size_t len,
                                                    uint32_t timeoutMs,
                                                    void* user) {
  (void)timeoutMs;
  TwoWire* wire = static_cast<TwoWire*>(user);
  if (wire == nullptr || data == nullptr || len == 0) {
    return MCP45HVX1::Status::Error(MCP45HVX1::Err::INVALID_PARAM, "invalid I2C write");
  }
  wire->beginTransmission(addr);
  if (wire->write(data, len) != len) {
    return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_ERROR, "I2C write incomplete");
  }
  return mapWireResult(wire->endTransmission(true), "I2C write failed");
}

MCP45HVX1::Status Mcp45hvx1ArduinoDriver::wireWriteRead(uint8_t addr,
                                                        const uint8_t* tx,
                                                        size_t txLen,
                                                        uint8_t* rx,
                                                        size_t rxLen,
                                                        uint32_t timeoutMs,
                                                        void* user) {
  (void)timeoutMs;
  TwoWire* wire = static_cast<TwoWire*>(user);
  if (wire == nullptr || (txLen > 0 && tx == nullptr) || rx == nullptr || rxLen == 0) {
    return MCP45HVX1::Status::Error(MCP45HVX1::Err::INVALID_PARAM, "invalid I2C read");
  }
  if (txLen > 0) {
    wire->beginTransmission(addr);
    if (wire->write(tx, txLen) != txLen) {
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_ERROR, "I2C write phase incomplete");
    }
    const uint8_t result = wire->endTransmission(false);
    if (result != 0) {
      return mapWireResult(result, "I2C write phase failed");
    }
  }
  const size_t got = wire->requestFrom(addr, static_cast<uint8_t>(rxLen));
  if (got != rxLen) {
    return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_ERROR, "I2C read length mismatch",
                                    static_cast<int32_t>(got));
  }
  for (size_t i = 0; i < rxLen; ++i) {
    if (!wire->available()) {
      return MCP45HVX1::Status::Error(MCP45HVX1::Err::I2C_ERROR, "I2C data unavailable");
    }
    rx[i] = static_cast<uint8_t>(wire->read());
  }
  return MCP45HVX1::Status::Ok();
}

MCP45HVX1::Status Mcp45hvx1ArduinoDriver::wireBusReset(void* user) {
  TwoWire* wire = static_cast<TwoWire*>(user);
  if (wire == nullptr) {
    return MCP45HVX1::Status::Error(MCP45HVX1::Err::INVALID_CONFIG, "Wire instance missing");
  }
  wire->end();
  delay(2);
  wire->begin();
  return MCP45HVX1::Status::Ok();
}

uint32_t Mcp45hvx1ArduinoDriver::nowMs(void*) {
  return millis();
}

void Mcp45hvx1ArduinoDriver::remember(const MCP45HVX1::Status& st) {
  lastError_ = st.ok() ? "OK" : st.msg;
}

bool Mcp45hvx1ArduinoDriver::begin(uint8_t address, const DigipotCalibration& cal) {
  cfg_ = MCP45HVX1::Config{};
  cfg_.i2cWrite = wireWrite;
  cfg_.i2cWriteRead = wireWriteRead;
  cfg_.i2cUser = &wire_;
  cfg_.busReset = wireBusReset;
  cfg_.controlUser = &wire_;
  cfg_.nowMs = nowMs;
  cfg_.i2cAddress = address;
  cfg_.i2cTimeoutMs = timeoutMs_;
  cfg_.resolution = MCP45HVX1::Resolution::Bits8;
  cfg_.resistance = cal.nominalRabOhms <= 6000.0f
                        ? MCP45HVX1::ResistanceOption::R5K
                        : (cal.nominalRabOhms <= 15000.0f
                               ? MCP45HVX1::ResistanceOption::R10K
                               : (cal.nominalRabOhms <= 70000.0f
                                      ? MCP45HVX1::ResistanceOption::R50K
                                      : MCP45HVX1::ResistanceOption::R100K));
  const MCP45HVX1::Status st = pot_.begin(cfg_);
  remember(st);
  return st.ok();
}

bool Mcp45hvx1ArduinoDriver::writeWiper(uint8_t code) {
  const MCP45HVX1::Status st = pot_.writeWiper(code);
  remember(st);
  return st.ok();
}

bool Mcp45hvx1ArduinoDriver::readWiper(uint8_t& code) {
  const MCP45HVX1::Status st = pot_.readWiper(code);
  remember(st);
  return st.ok();
}

bool Mcp45hvx1ArduinoDriver::setTopology(TerminalTopology topology) {
  const MCP45HVX1::TerminalMode mode =
      topology == TerminalTopology::RheostatBToW ? MCP45HVX1::TerminalMode::RheostatBToW
                                                 : MCP45HVX1::TerminalMode::RheostatAToW;
  const MCP45HVX1::Status st = pot_.setTerminalMode(mode);
  remember(st);
  return st.ok();
}

bool Mcp45hvx1ArduinoDriver::recover() {
  const MCP45HVX1::Status st = pot_.recover();
  remember(st);
  return st.ok();
}
#endif

}  // namespace lgcl::digipot

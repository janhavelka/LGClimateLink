#include "sensors/Bme280Service.h"

#include <math.h>

namespace lgcl::sensors {

bool Bme280Service::begin(uint8_t address, uint32_t pollMs, uint32_t staleMs, uint32_t nowMs) {
  address_ = address;
  pollMs_ = pollMs;
  staleMs_ = staleMs;
  nextPollMs_ = nowMs;
  measurementPending_ = false;
  snapshot_ = Bme280Snapshot{};
  if (driver_ == nullptr) {
    markError("BME280 driver missing", nowMs);
    return false;
  }
  snapshot_.initialized = driver_->begin(address_);
  if (!snapshot_.initialized) {
    markError(driver_->lastError(), nowMs);
    return false;
  }
  snapshot_.lastError = "OK";
  return true;
}

void Bme280Service::tick(uint32_t nowMs) {
  if (driver_ == nullptr || !snapshot_.initialized) {
    return;
  }
  driver_->tick(nowMs);

  if (measurementPending_ && driver_->measurementReady()) {
    float t = 0.0f;
    float h = 0.0f;
    float p = 0.0f;
    if (driver_->readMeasurement(t, h, p) && plausible(t, h, p)) {
      acceptSample(t, h, p, nowMs);
    } else {
      markError(driver_->lastError(), nowMs);
    }
    measurementPending_ = false;
  }

  if ((int32_t)(nowMs - nextPollMs_) >= 0 && !measurementPending_) {
    forceRead(nowMs);
  }
  snapshot_.stale = !snapshot_.sample.valid || (nowMs - snapshot_.lastSuccessMs) > staleMs_;
}

const Bme280Snapshot& Bme280Service::snapshot(uint32_t nowMs) {
  snapshot_.stale = !snapshot_.sample.valid || (nowMs - snapshot_.lastSuccessMs) > staleMs_;
  return snapshot_;
}

bool Bme280Service::freshTemperature(float& outC, uint32_t nowMs) {
  const Bme280Snapshot& s = snapshot(nowMs);
  if (!s.sample.valid || s.stale) {
    return false;
  }
  outC = s.sample.temperatureC;
  return true;
}

void Bme280Service::forceRead(uint32_t nowMs) {
  snapshot_.lastAttemptMs = nowMs;
  nextPollMs_ = nowMs + pollMs_;
  if (driver_ == nullptr || !snapshot_.initialized) {
    markError("BME280 not initialized", nowMs);
    return;
  }
  if (driver_->requestMeasurement()) {
    measurementPending_ = true;
  } else {
    markError(driver_->lastError(), nowMs);
  }
}

bool Bme280Service::plausible(float temperatureC, float humidityPct, float pressurePa) const {
  return isfinite(temperatureC) && temperatureC >= -40.0f && temperatureC <= 85.0f &&
         isfinite(humidityPct) && humidityPct >= 0.0f && humidityPct <= 100.0f &&
         isfinite(pressurePa) && pressurePa >= 30000.0f && pressurePa <= 110000.0f;
}

void Bme280Service::markError(const char* msg, uint32_t nowMs) {
  snapshot_.lastAttemptMs = nowMs;
  snapshot_.consecutiveErrors++;
  snapshot_.totalErrors++;
  snapshot_.lastError = msg == nullptr ? "BME280 error" : msg;
  snapshot_.stale = !snapshot_.sample.valid || (nowMs - snapshot_.lastSuccessMs) > staleMs_;
}

void Bme280Service::acceptSample(float temperatureC,
                                 float humidityPct,
                                 float pressurePa,
                                 uint32_t nowMs) {
  snapshot_.sample.temperatureC = temperatureC;
  snapshot_.sample.humidityPct = humidityPct;
  snapshot_.sample.pressurePa = pressurePa;
  snapshot_.sample.timestampMs = nowMs;
  snapshot_.sample.valid = true;
  snapshot_.lastSuccessMs = nowMs;
  snapshot_.consecutiveErrors = 0;
  snapshot_.totalSuccess++;
  snapshot_.lastError = "OK";
  snapshot_.stale = false;
}

#ifdef ARDUINO
BME280::Status Bme280ArduinoDriver::mapWireResult(uint8_t result, const char* context) {
  switch (result) {
    case 0:
      return BME280::Status::Ok();
    case 1:
      return BME280::Status::Error(BME280::Err::INVALID_PARAM, context, result);
    case 2:
      return BME280::Status::Error(BME280::Err::I2C_NACK_ADDR, context, result);
    case 3:
      return BME280::Status::Error(BME280::Err::I2C_NACK_DATA, context, result);
    case 5:
      return BME280::Status::Error(BME280::Err::I2C_TIMEOUT, context, result);
    case 4:
    default:
      return BME280::Status::Error(BME280::Err::I2C_BUS, context, result);
  }
}

BME280::Status Bme280ArduinoDriver::wireWrite(uint8_t addr,
                                              const uint8_t* data,
                                              size_t len,
                                              uint32_t timeoutMs,
                                              void* user) {
  (void)timeoutMs;
  TwoWire* wire = static_cast<TwoWire*>(user);
  if (wire == nullptr || data == nullptr || len == 0) {
    return BME280::Status::Error(BME280::Err::INVALID_PARAM, "invalid I2C write");
  }
  wire->beginTransmission(addr);
  if (wire->write(data, len) != len) {
    return BME280::Status::Error(BME280::Err::I2C_ERROR, "I2C write incomplete");
  }
  return mapWireResult(wire->endTransmission(true), "I2C write failed");
}

BME280::Status Bme280ArduinoDriver::wireWriteRead(uint8_t addr,
                                                  const uint8_t* tx,
                                                  size_t txLen,
                                                  uint8_t* rx,
                                                  size_t rxLen,
                                                  uint32_t timeoutMs,
                                                  void* user) {
  (void)timeoutMs;
  TwoWire* wire = static_cast<TwoWire*>(user);
  if (wire == nullptr || (txLen > 0 && tx == nullptr) || rx == nullptr || rxLen == 0) {
    return BME280::Status::Error(BME280::Err::INVALID_PARAM, "invalid I2C read");
  }
  wire->beginTransmission(addr);
  if (wire->write(tx, txLen) != txLen) {
    return BME280::Status::Error(BME280::Err::I2C_ERROR, "I2C write phase incomplete");
  }
  const uint8_t result = wire->endTransmission(false);
  if (result != 0) {
    return mapWireResult(result, "I2C write phase failed");
  }
  const size_t got = wire->requestFrom(addr, static_cast<uint8_t>(rxLen));
  if (got != rxLen) {
    return BME280::Status::Error(BME280::Err::I2C_ERROR, "I2C read length mismatch",
                                 static_cast<int32_t>(got));
  }
  for (size_t i = 0; i < rxLen; ++i) {
    if (!wire->available()) {
      return BME280::Status::Error(BME280::Err::I2C_ERROR, "I2C data unavailable");
    }
    rx[i] = static_cast<uint8_t>(wire->read());
  }
  return BME280::Status::Ok();
}

uint32_t Bme280ArduinoDriver::nowMs(void*) {
  return millis();
}

void Bme280ArduinoDriver::remember(const BME280::Status& st) {
  lastError_ = st.ok() ? "OK" : st.msg;
}

bool Bme280ArduinoDriver::begin(uint8_t address) {
  cfg_ = BME280::Config{};
  cfg_.i2cWrite = wireWrite;
  cfg_.i2cWriteRead = wireWriteRead;
  cfg_.i2cUser = &wire_;
  cfg_.i2cAddress = address;
  cfg_.i2cTimeoutMs = timeoutMs_;
  cfg_.nowMs = nowMs;
  cfg_.mode = BME280::Mode::FORCED;
  cfg_.osrsT = BME280::Oversampling::X1;
  cfg_.osrsP = BME280::Oversampling::X1;
  cfg_.osrsH = BME280::Oversampling::X1;
  const BME280::Status st = bme_.begin(cfg_);
  remember(st);
  return st.ok();
}

void Bme280ArduinoDriver::tick(uint32_t nowMs) {
  bme_.tick(nowMs);
}

bool Bme280ArduinoDriver::requestMeasurement() {
  BME280::Status st = bme_.requestMeasurement();
  if (st.code == BME280::Err::IN_PROGRESS) {
    lastError_ = "OK";
    return true;
  }
  remember(st);
  return false;
}

bool Bme280ArduinoDriver::measurementReady() const {
  return bme_.measurementReady();
}

bool Bme280ArduinoDriver::readMeasurement(float& temperatureC,
                                          float& humidityPct,
                                          float& pressurePa) {
  BME280::Measurement m;
  const BME280::Status st = bme_.getMeasurement(m);
  remember(st);
  if (!st.ok()) {
    return false;
  }
  temperatureC = m.temperatureC;
  humidityPct = m.humidityPct;
  pressurePa = m.pressurePa;
  return true;
}

bool Bme280ArduinoDriver::recover() {
  const BME280::Status st = bme_.recover();
  remember(st);
  return st.ok();
}
#endif

}  // namespace lgcl::sensors

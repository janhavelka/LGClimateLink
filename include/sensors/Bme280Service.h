#pragma once

#include <stdint.h>

#ifdef ARDUINO
#include <BME280/BME280.h>
#include <Wire.h>
#endif

namespace lgcl::sensors {

struct EnvSample {
  float temperatureC = 0.0f;
  float humidityPct = 0.0f;
  float pressurePa = 0.0f;
  uint32_t timestampMs = 0;
  bool valid = false;
};

struct Bme280Snapshot {
  EnvSample sample;
  uint32_t lastAttemptMs = 0;
  uint32_t lastSuccessMs = 0;
  uint32_t consecutiveErrors = 0;
  uint32_t totalErrors = 0;
  uint32_t totalSuccess = 0;
  bool initialized = false;
  bool stale = true;
  const char* lastError = "not initialized";
};

class IBme280Driver {
 public:
  virtual ~IBme280Driver() = default;
  virtual bool begin(uint8_t address) = 0;
  virtual void tick(uint32_t nowMs) = 0;
  virtual bool requestMeasurement() = 0;
  virtual bool measurementReady() const = 0;
  virtual bool readMeasurement(float& temperatureC, float& humidityPct, float& pressurePa) = 0;
  virtual const char* lastError() const = 0;
  virtual bool recover() = 0;
};

class Bme280Service {
 public:
  Bme280Service() = default;

  void setDriver(IBme280Driver* driver) { driver_ = driver; }
  bool begin(uint8_t address, uint32_t pollMs, uint32_t staleMs, uint32_t nowMs);
  void tick(uint32_t nowMs);
  const Bme280Snapshot& snapshot(uint32_t nowMs);
  bool freshTemperature(float& outC, uint32_t nowMs);
  void forceRead(uint32_t nowMs);

 private:
  bool plausible(float temperatureC, float humidityPct, float pressurePa) const;
  void markError(const char* msg, uint32_t nowMs);
  void acceptSample(float temperatureC, float humidityPct, float pressurePa, uint32_t nowMs);

  IBme280Driver* driver_ = nullptr;
  Bme280Snapshot snapshot_;
  uint8_t address_ = 0x76;
  uint32_t pollMs_ = 5000;
  uint32_t staleMs_ = 30000;
  uint32_t nextPollMs_ = 0;
  bool measurementPending_ = false;
};

#ifdef ARDUINO
class Bme280ArduinoDriver final : public IBme280Driver {
 public:
  Bme280ArduinoDriver(TwoWire& wire, uint32_t timeoutMs) : wire_(wire), timeoutMs_(timeoutMs) {}
  bool begin(uint8_t address) override;
  void tick(uint32_t nowMs) override;
  bool requestMeasurement() override;
  bool measurementReady() const override;
  bool readMeasurement(float& temperatureC, float& humidityPct, float& pressurePa) override;
  const char* lastError() const override { return lastError_; }
  bool recover() override;

 private:
  static BME280::Status wireWrite(uint8_t addr,
                                  const uint8_t* data,
                                  size_t len,
                                  uint32_t timeoutMs,
                                  void* user);
  static BME280::Status wireWriteRead(uint8_t addr,
                                      const uint8_t* tx,
                                      size_t txLen,
                                      uint8_t* rx,
                                      size_t rxLen,
                                      uint32_t timeoutMs,
                                      void* user);
  static uint32_t nowMs(void*);
  static BME280::Status mapWireResult(uint8_t result, const char* context);
  void remember(const BME280::Status& st);

  TwoWire& wire_;
  uint32_t timeoutMs_;
  BME280::BME280 bme_;
  BME280::Config cfg_;
  const char* lastError_ = "OK";
};
#endif

}  // namespace lgcl::sensors

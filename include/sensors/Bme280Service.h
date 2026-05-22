#pragma once

/**
 * @file Bme280Service.h
 * @brief BME280 polling service and Arduino driver adapter.
 */

#include <stdint.h>

#ifdef ARDUINO
#include <BME280/BME280.h>
#include <Wire.h>
#endif

namespace lgcl::sensors {

/// One environmental sample with acquisition timestamp and validity flag.
struct EnvSample {
  float temperatureC = 0.0f;
  float humidityPct = 0.0f;
  float pressurePa = 0.0f;
  uint32_t timestampMs = 0;
  bool valid = false;
};

/// Runtime health and measurement state for the BME280 service.
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

/**
 * @brief Minimal driver contract used by Bme280Service.
 *
 * Tests can provide fakes through this interface. The Arduino implementation
 * adapts the required `janhavelka/BME280` library.
 */
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

/**
 * @brief Nonblocking BME280 measurement scheduler.
 *
 * The service requests measurements periodically, validates plausibility, tracks
 * freshness, and exposes a fresh-temperature helper for the virtual thermistor
 * path.
 */
class Bme280Service {
 public:
  Bme280Service() = default;

  /// Install the hardware driver. Must be called before begin().
  void setDriver(IBme280Driver* driver) { driver_ = driver; }
  /// Start the service with address, poll interval, and stale deadline.
  bool begin(uint8_t address, uint32_t pollMs, uint32_t staleMs, uint32_t nowMs);
  /// Run bounded polling work.
  void tick(uint32_t nowMs);
  /// Return the latest snapshot after refreshing the stale flag.
  const Bme280Snapshot& snapshot(uint32_t nowMs);
  /// Return true and fill outC only when the latest temperature is fresh.
  bool freshTemperature(float& outC, uint32_t nowMs);
  /// Request an immediate measurement on the next tick.
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
/// Arduino adapter for `janhavelka/BME280` using an injected TwoWire bus.
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

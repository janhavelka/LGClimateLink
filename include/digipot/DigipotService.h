#pragma once

/**
 * @file DigipotService.h
 * @brief MCP45HVX1 service and safety state machine for virtual thermistor output.
 */

#include <stdint.h>

#include "digipot/NtcEmulator.h"

#ifdef ARDUINO
#include <Arduino.h>
#include <MCP45HVX1/MCP45HVX1.h>
#include <Wire.h>
#endif

namespace lgcl::digipot {

/// Digipot service operating mode.
enum class DigipotMode : uint8_t {
  /// Startup mode before normal control is allowed.
  BootSafe = 0,
  /// Fresh BME280 temperature is driving the virtual thermistor.
  Normal,
  /// Last known safe output is held while input freshness recovers.
  HoldLastGood,
  /// Configured safe fixed output is active.
  SafeFixed,
  /// Hardware or validation fault prevents normal operation.
  Fault,
  /// One-shot manual output has been requested through guarded control.
  Manual,
};

/// Runtime digipot state exposed to CLI, MQTT, and health monitoring.
struct DigipotSnapshot {
  DigipotMode mode = DigipotMode::BootSafe;
  bool initialized = false;
  bool degraded = true;
  uint8_t code = 0;
  float effectiveOhms = 0.0f;
  float requestedOhms = 0.0f;
  uint32_t lastWriteMs = 0;
  uint32_t lastGoodInputMs = 0;
  uint32_t consecutiveErrors = 0;
  uint32_t totalErrors = 0;
  const char* lastError = "not initialized";
};

/**
 * @brief Minimal MCP45HVX1 driver contract.
 *
 * The service depends only on this interface. The Arduino adapter uses the
 * required `janhavelka/MCP45HVX1` library.
 */
class IDigipotDriver {
 public:
  virtual ~IDigipotDriver() = default;
  virtual bool begin(uint8_t address, const DigipotCalibration& cal) = 0;
  virtual bool writeWiper(uint8_t code) = 0;
  virtual bool readWiper(uint8_t& code) = 0;
  virtual bool setTopology(TerminalTopology topology) = 0;
  virtual const char* lastError() const = 0;
  virtual bool recover() = 0;
};

/**
 * @brief Owns safe MCP45HVX1 output behavior.
 *
 * The service validates calibration on begin(), writes the safe boot code, and
 * then moves between normal, hold-last-good, safe-fixed, manual, and fault
 * modes based on sensor freshness and I2C/writeback health.
 */
class DigipotService {
 public:
  /// Install the hardware driver. Must be called before begin().
  void setDriver(IDigipotDriver* driver) { driver_ = driver; }
  /// Validate calibration, initialize hardware, set topology, and write safe code.
  bool begin(uint8_t address,
             const NtcCalibration& ntc,
             const DigipotCalibration& digipot,
             uint32_t nowMs);
  /// Update output from the latest temperature freshness state.
  void tick(uint32_t nowMs, bool temperatureFresh, float temperatureC);
  /// Write a guarded manual wiper code.
  bool setManualCode(uint8_t code, uint32_t nowMs);
  /// Move immediately to the configured safe fixed output.
  bool setSafeFixed(uint32_t nowMs);
  /// Return the latest runtime snapshot.
  const DigipotSnapshot& snapshot() const { return snapshot_; }
  /// Return active thermistor calibration.
  const NtcCalibration& ntcCalibration() const { return ntc_; }
  /// Return active digipot electrical calibration.
  const DigipotCalibration& digipotCalibration() const { return digipot_; }

 private:
  bool writeCode(uint8_t code, float requestedOhms, DigipotMode mode, uint32_t nowMs);
  void markError(const char* msg);

  IDigipotDriver* driver_ = nullptr;
  NtcCalibration ntc_;
  DigipotCalibration digipot_;
  DigipotSnapshot snapshot_;
  uint8_t address_ = 0x3C;
};

#ifdef ARDUINO
/// Arduino adapter for `janhavelka/MCP45HVX1` using an injected TwoWire bus.
class Mcp45hvx1ArduinoDriver final : public IDigipotDriver {
 public:
  Mcp45hvx1ArduinoDriver(TwoWire& wire, uint32_t timeoutMs) : wire_(wire), timeoutMs_(timeoutMs) {}
  bool begin(uint8_t address, const DigipotCalibration& cal) override;
  bool writeWiper(uint8_t code) override;
  bool readWiper(uint8_t& code) override;
  bool setTopology(TerminalTopology topology) override;
  const char* lastError() const override { return lastError_; }
  bool recover() override;

 private:
  static MCP45HVX1::Status wireWrite(uint8_t addr,
                                     const uint8_t* data,
                                     size_t len,
                                     uint32_t timeoutMs,
                                     void* user);
  static MCP45HVX1::Status wireWriteRead(uint8_t addr,
                                         const uint8_t* tx,
                                         size_t txLen,
                                         uint8_t* rx,
                                         size_t rxLen,
                                         uint32_t timeoutMs,
                                         void* user);
  static MCP45HVX1::Status wireBusReset(void* user);
  static MCP45HVX1::Status mapWireResult(uint8_t result, const char* context);
  static uint32_t nowMs(void*);
  void remember(const MCP45HVX1::Status& st);

  TwoWire& wire_;
  uint32_t timeoutMs_;
  MCP45HVX1::MCP45HVX1 pot_;
  MCP45HVX1::Config cfg_;
  const char* lastError_ = "OK";
};
#endif

/// Human-readable digipot mode name for CLI and diagnostics.
const char* digipotModeName(DigipotMode mode);

}  // namespace lgcl::digipot

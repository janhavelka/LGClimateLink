#pragma once

/**
 * @file NtcEmulator.h
 * @brief Pure conversion logic for LG room-sensor emulation.
 *
 * This header contains no Arduino dependencies. It is used by native tests and
 * by DigipotService to convert a validated room temperature into a clamped
 * MCP45HVX1 wiper code.
 */

#include <stddef.h>
#include <stdint.h>

namespace lgcl::digipot {

/// Available temperature-to-resistance models.
enum class ThermistorModel : uint8_t {
  Beta = 0,
  SteinhartHart = 1,
  Table = 2,
};

/// Sensor polarity. NTC resistance falls with temperature; PTC rises.
enum class ThermistorPolarity : uint8_t {
  Ntc = 0,
  Ptc = 1,
};

/// Generic validation result for calibration data.
struct ValidationResult {
  bool ok = true;
  const char* message = "OK";
};

/// One measured calibration point for table-based conversion.
struct CalibrationPoint {
  float temperatureC = 0.0f;
  float resistanceOhms = 0.0f;
};

/**
 * @brief Thermistor model and safety clamps for the virtual LG room sensor.
 *
 * Defaults are safe software placeholders for bench bring-up. They are not
 * verified LG sensor constants.
 */
struct NtcCalibration {
  ThermistorModel model = ThermistorModel::Beta;
  ThermistorPolarity polarity = ThermistorPolarity::Ntc;

  // Safe defaults are placeholders for LG sensor bring-up. They must be
  // verified against the original LG thermistor before production use.
  float rRefOhms = 5000.0f;
  float tRefC = 25.0f;
  float betaK = 3950.0f;

  // Steinhart-Hart: 1/T = A + B*ln(R) + C*ln(R)^3.
  float shA = 0.001129148f;
  float shB = 0.000234125f;
  float shC = 0.0000000876741f;

  float minTemperatureC = 5.0f;
  float maxTemperatureC = 35.0f;
  float minResistanceOhms = 1000.0f;
  float maxResistanceOhms = 5075.0f;
  float safeResistanceOhms = 2565.0f;
  uint32_t holdLastGoodMs = 300000;

  CalibrationPoint table[8] = {};
  uint8_t tableCount = 0;
};

/// Supported MCP45HVX1 terminal use in rheostat mode.
enum class TerminalTopology : uint8_t {
  /// Effective path is terminal B to wiper.
  RheostatBToW = 0,
  /// Effective path is terminal A to wiper.
  RheostatAToW = 1,
};

/**
 * @brief Digital potentiometer electrical model and output clamps.
 *
 * The model estimates the resistance seen by the LG unit from nominal RAB,
 * wiper code, wiper resistance, optional series resistance, and terminal
 * topology. Production values must be measured on the real board.
 */
struct DigipotCalibration {
  float nominalRabOhms = 5000.0f;  // MCP45HV51-502E/ST nominal end-to-end resistance.
  uint8_t maxWiperCode = 255;
  uint8_t minWiperCode = 1;
  uint8_t maxAllowedWiperCode = 254;
  uint8_t safeWiperCode = 127;
  float seriesOhms = 0.0f;
  float wiperOhms = 75.0f;
  bool invertCode = false;
  TerminalTopology topology = TerminalTopology::RheostatBToW;
  float minEffectiveOhms = 1000.0f;
  float maxEffectiveOhms = 5075.0f;
};

/// Result of converting temperature to target thermistor resistance.
struct NtcResult {
  bool ok = false;
  bool clamped = false;
  float requestedTemperatureC = 0.0f;
  float usedTemperatureC = 0.0f;
  float targetResistanceOhms = 0.0f;
  const char* message = "not calculated";
};

/// Result of converting target resistance to a digipot wiper code.
struct WiperResult {
  bool ok = false;
  bool clamped = false;
  float requestedResistanceOhms = 0.0f;
  float effectiveResistanceOhms = 0.0f;
  uint8_t code = 0;
  const char* message = "not calculated";
};

/// Validate thermistor calibration limits and model parameters.
ValidationResult validate(const NtcCalibration& cal);

/// Validate digipot electrical model and clamp ranges.
ValidationResult validate(const DigipotCalibration& cal);

/// Clamp a floating-point value to an inclusive range.
float clampFloat(float value, float minValue, float maxValue);

/// Convert temperature to target resistance using the selected thermistor model.
NtcResult resistanceForTemperature(float temperatureC, const NtcCalibration& cal);

/// Convert target resistance to the nearest safe digipot wiper code.
WiperResult wiperForResistance(float resistanceOhms, const DigipotCalibration& cal);

/// Estimate effective resistance for one wiper code.
float effectiveResistanceForCode(uint8_t code, const DigipotCalibration& cal);

/// Convert temperature directly to a safe digipot wiper result.
WiperResult wiperForTemperature(float temperatureC,
                                const NtcCalibration& ntc,
                                const DigipotCalibration& digipot);

}  // namespace lgcl::digipot

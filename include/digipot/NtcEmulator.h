#pragma once

#include <stddef.h>
#include <stdint.h>

namespace lgcl::digipot {

enum class ThermistorModel : uint8_t {
  Beta = 0,
  SteinhartHart = 1,
  Table = 2,
};

enum class ThermistorPolarity : uint8_t {
  Ntc = 0,
  Ptc = 1,
};

struct ValidationResult {
  bool ok = true;
  const char* message = "OK";
};

struct CalibrationPoint {
  float temperatureC = 0.0f;
  float resistanceOhms = 0.0f;
};

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

enum class TerminalTopology : uint8_t {
  RheostatBToW = 0,
  RheostatAToW = 1,
};

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

struct NtcResult {
  bool ok = false;
  bool clamped = false;
  float requestedTemperatureC = 0.0f;
  float usedTemperatureC = 0.0f;
  float targetResistanceOhms = 0.0f;
  const char* message = "not calculated";
};

struct WiperResult {
  bool ok = false;
  bool clamped = false;
  float requestedResistanceOhms = 0.0f;
  float effectiveResistanceOhms = 0.0f;
  uint8_t code = 0;
  const char* message = "not calculated";
};

ValidationResult validate(const NtcCalibration& cal);
ValidationResult validate(const DigipotCalibration& cal);

float clampFloat(float value, float minValue, float maxValue);
NtcResult resistanceForTemperature(float temperatureC, const NtcCalibration& cal);
WiperResult wiperForResistance(float resistanceOhms, const DigipotCalibration& cal);
float effectiveResistanceForCode(uint8_t code, const DigipotCalibration& cal);
WiperResult wiperForTemperature(float temperatureC,
                                const NtcCalibration& ntc,
                                const DigipotCalibration& digipot);

}  // namespace lgcl::digipot

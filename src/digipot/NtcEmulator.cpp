#include "digipot/NtcEmulator.h"

#include <math.h>

namespace lgcl::digipot {

namespace {

static constexpr float kKelvinOffset = 273.15f;

bool finitePositive(float v) {
  return isfinite(v) && v > 0.0f;
}

float betaResistance(float temperatureC, const NtcCalibration& cal) {
  const float tK = temperatureC + kKelvinOffset;
  const float t0K = cal.tRefC + kKelvinOffset;
  const float sign = cal.polarity == ThermistorPolarity::Ntc ? 1.0f : -1.0f;
  return cal.rRefOhms * expf(sign * cal.betaK * ((1.0f / tK) - (1.0f / t0K)));
}

float steinhartTempForResistance(float resistanceOhms, const NtcCalibration& cal) {
  const float lnR = logf(resistanceOhms);
  const float invT = cal.shA + cal.shB * lnR + cal.shC * lnR * lnR * lnR;
  if (!finitePositive(invT)) {
    return NAN;
  }
  return (1.0f / invT) - kKelvinOffset;
}

float steinhartResistanceForTemperature(float temperatureC, const NtcCalibration& cal) {
  float lo = cal.minResistanceOhms;
  float hi = cal.maxResistanceOhms;
  if (lo > hi) {
    const float tmp = lo;
    lo = hi;
    hi = tmp;
  }

  const float target = clampFloat(temperatureC, cal.minTemperatureC, cal.maxTemperatureC);
  const bool tempRisesWithResistance =
      steinhartTempForResistance(hi, cal) > steinhartTempForResistance(lo, cal);

  for (uint8_t i = 0; i < 32; ++i) {
    const float mid = (lo + hi) * 0.5f;
    const float tMid = steinhartTempForResistance(mid, cal);
    if (!isfinite(tMid)) {
      return cal.safeResistanceOhms;
    }
    if (tempRisesWithResistance) {
      if (tMid < target) {
        lo = mid;
      } else {
        hi = mid;
      }
    } else {
      if (tMid > target) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
  }
  return (lo + hi) * 0.5f;
}

float tableResistanceForTemperature(float temperatureC, const NtcCalibration& cal) {
  if (cal.tableCount < 2) {
    return cal.safeResistanceOhms;
  }

  const CalibrationPoint* first = &cal.table[0];
  const CalibrationPoint* last = &cal.table[cal.tableCount - 1];
  if (temperatureC <= first->temperatureC) {
    return first->resistanceOhms;
  }
  if (temperatureC >= last->temperatureC) {
    return last->resistanceOhms;
  }

  for (uint8_t i = 1; i < cal.tableCount; ++i) {
    const CalibrationPoint& a = cal.table[i - 1];
    const CalibrationPoint& b = cal.table[i];
    if (temperatureC >= a.temperatureC && temperatureC <= b.temperatureC) {
      const float span = b.temperatureC - a.temperatureC;
      if (span <= 0.0f) {
        return cal.safeResistanceOhms;
      }
      const float f = (temperatureC - a.temperatureC) / span;
      return a.resistanceOhms + f * (b.resistanceOhms - a.resistanceOhms);
    }
  }
  return cal.safeResistanceOhms;
}

uint8_t clampCode(uint8_t code, const DigipotCalibration& cal, bool* clamped) {
  uint8_t out = code;
  if (out < cal.minWiperCode) {
    out = cal.minWiperCode;
  }
  if (out > cal.maxAllowedWiperCode) {
    out = cal.maxAllowedWiperCode;
  }
  if (clamped != nullptr && out != code) {
    *clamped = true;
  }
  return out;
}

}  // namespace

float clampFloat(float value, float minValue, float maxValue) {
  if (!isfinite(value)) {
    return minValue;
  }
  if (value < minValue) {
    return minValue;
  }
  if (value > maxValue) {
    return maxValue;
  }
  return value;
}

ValidationResult validate(const NtcCalibration& cal) {
  if (!finitePositive(cal.rRefOhms) || !finitePositive(cal.betaK)) {
    return {false, "invalid beta reference"};
  }
  if (!isfinite(cal.tRefC) || cal.tRefC <= -273.0f) {
    return {false, "invalid reference temperature"};
  }
  if (cal.minTemperatureC >= cal.maxTemperatureC) {
    return {false, "temperature limits inverted"};
  }
  if (!finitePositive(cal.minResistanceOhms) || !finitePositive(cal.maxResistanceOhms) ||
      cal.minResistanceOhms >= cal.maxResistanceOhms) {
    return {false, "resistance limits invalid"};
  }
  if (cal.safeResistanceOhms < cal.minResistanceOhms ||
      cal.safeResistanceOhms > cal.maxResistanceOhms) {
    return {false, "safe resistance outside limits"};
  }
  if (cal.model == ThermistorModel::Table) {
    if (cal.tableCount < 2 || cal.tableCount > 8) {
      return {false, "calibration table size invalid"};
    }
    for (uint8_t i = 0; i < cal.tableCount; ++i) {
      if (!isfinite(cal.table[i].temperatureC) || !finitePositive(cal.table[i].resistanceOhms)) {
        return {false, "calibration table point invalid"};
      }
      if (i > 0 && cal.table[i].temperatureC <= cal.table[i - 1].temperatureC) {
        return {false, "calibration table must be sorted by temperature"};
      }
    }
  }
  return {};
}

ValidationResult validate(const DigipotCalibration& cal) {
  if (!finitePositive(cal.nominalRabOhms) || cal.maxWiperCode == 0) {
    return {false, "invalid nominal digipot resistance"};
  }
  if (cal.minWiperCode > cal.maxAllowedWiperCode ||
      cal.maxAllowedWiperCode > cal.maxWiperCode) {
    return {false, "wiper code limits invalid"};
  }
  if (cal.safeWiperCode < cal.minWiperCode || cal.safeWiperCode > cal.maxAllowedWiperCode) {
    return {false, "safe wiper code outside limits"};
  }
  if (!isfinite(cal.seriesOhms) || cal.seriesOhms < 0.0f ||
      !isfinite(cal.wiperOhms) || cal.wiperOhms < 0.0f) {
    return {false, "series/wiper resistance invalid"};
  }
  if (!finitePositive(cal.minEffectiveOhms) || !finitePositive(cal.maxEffectiveOhms) ||
      cal.minEffectiveOhms >= cal.maxEffectiveOhms) {
    return {false, "effective resistance limits invalid"};
  }
  return {};
}

NtcResult resistanceForTemperature(float temperatureC, const NtcCalibration& cal) {
  NtcResult result;
  result.requestedTemperatureC = temperatureC;
  const ValidationResult valid = validate(cal);
  if (!valid.ok) {
    result.message = valid.message;
    result.targetResistanceOhms = cal.safeResistanceOhms;
    return result;
  }
  if (!isfinite(temperatureC)) {
    result.message = "temperature is not finite";
    result.targetResistanceOhms = cal.safeResistanceOhms;
    return result;
  }

  result.usedTemperatureC = clampFloat(temperatureC, cal.minTemperatureC, cal.maxTemperatureC);
  result.clamped = result.usedTemperatureC != temperatureC;

  float r = cal.safeResistanceOhms;
  if (cal.model == ThermistorModel::Beta) {
    r = betaResistance(result.usedTemperatureC, cal);
  } else if (cal.model == ThermistorModel::SteinhartHart) {
    r = steinhartResistanceForTemperature(result.usedTemperatureC, cal);
  } else {
    r = tableResistanceForTemperature(result.usedTemperatureC, cal);
  }

  if (!finitePositive(r)) {
    result.message = "computed resistance invalid";
    result.targetResistanceOhms = cal.safeResistanceOhms;
    return result;
  }

  const float clampedR = clampFloat(r, cal.minResistanceOhms, cal.maxResistanceOhms);
  result.clamped = result.clamped || clampedR != r;
  result.targetResistanceOhms = clampedR;
  result.ok = true;
  result.message = result.clamped ? "clamped" : "OK";
  return result;
}

float effectiveResistanceForCode(uint8_t code, const DigipotCalibration& cal) {
  uint8_t physicalCode = code;
  if (cal.invertCode) {
    physicalCode = static_cast<uint8_t>(cal.maxWiperCode - physicalCode);
  }

  const float fraction =
      static_cast<float>(physicalCode) / static_cast<float>(cal.maxWiperCode);
  const float terminal =
      cal.topology == TerminalTopology::RheostatBToW
          ? fraction * cal.nominalRabOhms
          : (1.0f - fraction) * cal.nominalRabOhms;
  return cal.seriesOhms + cal.wiperOhms + terminal;
}

WiperResult wiperForResistance(float resistanceOhms, const DigipotCalibration& cal) {
  WiperResult result;
  result.requestedResistanceOhms = resistanceOhms;

  const ValidationResult valid = validate(cal);
  if (!valid.ok) {
    result.message = valid.message;
    result.code = cal.safeWiperCode;
    result.effectiveResistanceOhms = effectiveResistanceForCode(result.code, cal);
    return result;
  }
  if (!finitePositive(resistanceOhms)) {
    result.message = "target resistance is not finite/positive";
    result.code = cal.safeWiperCode;
    result.effectiveResistanceOhms = effectiveResistanceForCode(result.code, cal);
    return result;
  }

  float target = clampFloat(resistanceOhms, cal.minEffectiveOhms, cal.maxEffectiveOhms);
  result.clamped = target != resistanceOhms;
  target -= cal.seriesOhms + cal.wiperOhms;

  float fraction = 0.0f;
  if (cal.topology == TerminalTopology::RheostatBToW) {
    fraction = target / cal.nominalRabOhms;
  } else {
    fraction = 1.0f - (target / cal.nominalRabOhms);
  }
  fraction = clampFloat(fraction, 0.0f, 1.0f);

  uint8_t physicalCode =
      static_cast<uint8_t>(floorf(fraction * static_cast<float>(cal.maxWiperCode) + 0.5f));
  if (cal.invertCode) {
    physicalCode = static_cast<uint8_t>(cal.maxWiperCode - physicalCode);
  }

  bool codeClamped = false;
  result.code = clampCode(physicalCode, cal, &codeClamped);
  result.clamped = result.clamped || codeClamped;
  result.effectiveResistanceOhms = effectiveResistanceForCode(result.code, cal);
  result.ok = true;
  result.message = result.clamped ? "clamped" : "OK";
  return result;
}

WiperResult wiperForTemperature(float temperatureC,
                                const NtcCalibration& ntc,
                                const DigipotCalibration& digipot) {
  const NtcResult ntcResult = resistanceForTemperature(temperatureC, ntc);
  WiperResult wiper = wiperForResistance(ntcResult.targetResistanceOhms, digipot);
  wiper.clamped = wiper.clamped || ntcResult.clamped;
  if (!ntcResult.ok) {
    wiper.ok = false;
    wiper.message = ntcResult.message;
  }
  return wiper;
}

}  // namespace lgcl::digipot

# Changelog

## Unreleased

- Latched `OFFLINE` behavior for normal public I2C operations. Once the health
  threshold is reached, normal operations return `BUSY` with
  `Driver is offline; call recover()` and do not touch the bus until
  `recover()` succeeds.
- Native coverage for the latched `OFFLINE` guard, explicit recovery path, and
  static helper API usage.
- Added GitHub Actions CI for ESP32-S3/ESP32-S2 builds, native tests, contract
  checks, package validation, and version checks.
- ESP32 example builds now pin pioarduino `platform-espressif32` 54.03.20 and
  rely on the Arduino framework-provided `Wire` library instead of an explicit
  `lib_deps = Wire` entry.
- README documentation now covers thread/ISR expectations, the latched recovery
  model, and the remaining hardware-validation caveats.
- Failed explicit recovery attempts that begin from `OFFLINE` now reassert the
  latch after any later recovery-step failure, using `_reassertOfflineLatch()`.

## 1.0.0

- Initial production-style MCP45HVX1 driver.
- Added injected I2C transport, status/error model, health tracking, register
  helpers, wiper and TCON APIs, General Call helpers, examples, tests, and docs.

# Changelog

All notable project changes are recorded here.

This project uses plain engineering categories instead of marketing release notes:

- `Added` for new firmware, documentation, or test coverage.
- `Changed` for behavior changes.
- `Fixed` for defects.
- `Safety` for reliability or fail-safe changes.
- `Verification` for build, test, and audit evidence.
- `Known Limits` for unresolved work that affects hardware release confidence.

## [0.1.0] - 2026-05-22

Initial bench-bring-up release.

### Added

- Added Arduino + PlatformIO firmware for the ESP32-S2-MINI-2-N4 target.
- Added USB CDC serial CLI with colored output and guarded dangerous commands.
- Added LG wired-controller bus service for the TLIN1027-Q1 transceiver pins:
  - `LIN_EN` on GPIO16
  - `LIN_TX` on GPIO17
  - `LIN_RX` on GPIO18
- Added modern LG 13-byte frame parser, serializer, checksum handling, frame classification, and climate-state mapping.
- Added LG controller service with desired-state handling, periodic status sends, type-B request scheduling, echo tracking, and stale-bus detection.
- Added BME280 service using `janhavelka/BME280` with injected I2C transport, freshness tracking, plausibility checks, and error counters.
- Added MCP45HVX1 digipot service using `janhavelka/MCP45HVX1` with safe boot write, readback, recovery hook, and fault tracking.
- Added virtual thermistor conversion logic:
  - beta model
  - Steinhart-Hart model
  - monotonic calibration table support
  - resistance clamps
  - wiper-code clamps
  - effective-resistance estimate
- Added StatusLED service using `janhavelka/StatusLED`.
- Added Wi-Fi and MQTT service with reconnect backoff.
- Added Home Assistant MQTT Discovery payload and runtime topics for climate, BME280, health, LG diagnostics, and digipot diagnostics.
- Added NVS-backed settings store with delayed/coalesced writes.
- Added health monitor and watchdog feed quorum.
- Added native PlatformIO tests for protocol, state mapping, MQTT command validation, thermistor/digipot math, BME280 stale-data logic, settings validation, and watchdog quorum.
- Added Doxygen configuration for API documentation.

### Safety

- Digipot output is initialized to a safe configured code during boot.
- BME280 temperature must be fresh and plausible before it drives the virtual thermistor.
- Stale BME280 data holds the last known safe resistance for a bounded interval, then falls back to safe fixed output.
- Raw LG-frame transmit and raw digipot wiper commands require one-shot arming.
- MQTT retained command payloads are ignored.
- Retained MQTT command topics are cleared after reconnect before subscribing.
- The watchdog is fed only when required services satisfy the health quorum.
- Settings writes are delayed to reduce flash wear.

### Fixed

- Fixed Home Assistant component availability publishing so documented `availability/lg_bus` and `availability/bme280` topics are retained and updated.
- Fixed Home Assistant MQTT Discovery unit strings to emit explicit JSON Unicode escapes for degrees Celsius and ohms.
- Corrected CLI help text for BME280 commands.

### Documentation

- Added project README with hardware assumptions, build/upload/monitor commands, Home Assistant setup, CLI reference, safety behavior, and calibration workflow.
- Added `docs/PROTOCOL.md` summarizing the implemented LG protocol behavior and JanM321 reference points.
- Added `docs/HARDWARE.md` with pin map, I2C devices, LED assumptions, TLIN1027 assumptions, and open hardware checks.
- Added `docs/DIGIPOT_NTC_EMULATION.md` with conversion math, calibration constants, clamps, and failure behavior.
- Added `HARDENING_REPORT.md` with audit passes, fixes, verification results, and remaining hardware risks.
- Added `docs/reference/` with upstream protocol/library docs, source licenses, hardware datasheets, Home Assistant MQTT references, and platform API references.
- Expanded Doxygen configuration with a maintainer main page and public-header API comments.
- Added a filled pre-audit evidence questionnaire under `docs/audit/`.

### Verification

- `pio test -e native` passed with 8 of 8 test cases.
- `pio run -e esp32-s2-mini-2-n4` passed.
- `pio run` passed.
- ESP32-S2 target size at this release:
  - RAM: 20.4 percent
  - Flash: 77.8 percent

### Known Limits

- Final I2C SDA/SCL pins still require schematic or continuity verification.
- LED topology on GPIO36/GPIO37 still requires board verification.
- MCP45HVX1 terminal wiring and series resistors still require measurement.
- Original LG thermistor curve is not known.
- Resistance seen by the LG unit during reset, brownout, and MCU failure is not yet proven.
- TLIN1027 enable polarity is assumed active high and must be verified.
- ESP32-S2 low-baud UART timing at 104 baud must be scoped on hardware.

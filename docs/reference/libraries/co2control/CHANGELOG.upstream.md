# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Runtime ENV auto-detection and auto-selection between SHT3x and BME280; the Devices tab now reports the detected model/address and shows the active model-specific settings instead of a manual selector
- EE871 CO2 diagnostics surfaced in `co2 status` and `/api/status`, including measurement-pending state, raw status byte, and raw error code
- Build-generated gzip web assets and memory-aware web runtime tuning; S2 keeps the lite UI and reduced async/WiFi buffers while S3 can keep the full UI with PSRAM-backed scratch when available
- The web device-actions API now documents and exposes the ENV/RTC/CO2 probe and recover flows used by the UI

### Changed
- EE871 hardware pin naming is now consistently documented as E2 SDA/SCL (`IO6`/`IO7` on the current board mapping)
- Confirmation flashes from web/CLI actions now use the WiFi/Web LED only and leave the health LED dedicated to health state presentation
- README now reflects the actual board-config source files, current pinned dependency versions, optional memory diagnostics, and S2-vs-S3 web/mDNS behavior

### Fixed
- EE871 zero readings are no longer accepted as healthy data when the sensor reports a measurement fault or a suspended measurement state
- Web UI devices/status rendering now follows the live ENV detection state, so swapping the physical SHT3x/BME280 sensor updates the UI automatically
- Restored the linked RTC backup-persistence implementation note under `docs/`

## [1.4.1] - 2026-03-07

### Fixed
- Hardened WebServer OOM handling on constrained boards:
  - concurrent root-page copies are serialized
  - null `beginResponse*()` allocations return `503` instead of crashing
  - shared WebSocket payload creation uses `new (std::nothrow)` / guarded paths
- Completed a broad stress audit of I2C, SD logger, timing, memory, and control paths before tagging `v1.4.1`

## [1.4.0] - 2026-03-07

### Added
- PSRAM-aware runtime allocation tiers for sample history, event history, SD log queues, and web scratch buffers
- SD logging session markers for clearer run boundaries in persisted logs
- Tracked WebSocket client state with stalled-client management

### Changed
- Web graph/event scratch allocation now scales dynamically by available memory tier instead of assuming a single fixed-capacity profile
- Session-aware SD logging and live-web buffering were integrated as part of the PSRAM/runtime memory rollout
- Runtime validation added upper-bound checks for settings such as sample interval

## [1.3.0] - 2026-03-03

### Added
- Output controller: fan PWM percent-to-effective mapping with configurable minimum, fan interval gating, temperature-based output source
- `POST /api/settings/reset` endpoint for restoring runtime settings to defaults
- PSRAM telemetry in `/api/status` and serial CLI (`psram_total`, `psram_free`, `psram_min_free`)
- Web scratch buffers use PSRAM when available, with hard fallback to internal heap
- RS485 device status is config-driven: reports "disabled (no pins)" when `rs485Rx`/`rs485Tx` are -1
- SD logger session-based logging under `/logs/runs/<session>_NNNNN/` with automatic resume and file rotation
- Settings validation: `logSessionName` pattern, output channel conflict detection, AP password update mode
- 6 new native tests (44 total): output controller, settings validation extremes, PSRAM guardrails

### Changed
- Updated external library pins in `platformio.ini`:
  - `BME280` `v1.1.1 → v1.2.1`
  - `SHT3x-main` `v1.3.2 → v1.4.0`
  - `RV3032-C7` `v1.2.2 → v1.3.0`
  - `SSD1315` `v1.0.2 → v1.1.0`
  - `EE871-E2` `v0.2.1 → v0.3.0`
  - `AsyncSD` `v1.2.1 → v1.3.0`
  - `SystemChrono` `v1.1.0 → v1.2.0`
  - `StatusLED` `v1.2.0 → v1.3.0`
- Tightened compile-time dependency guards to enforce the updated minimum library versions
- Updated serial CLI help/output to the new grouped standard:
  - `help` default view reorganized into `Common`, `Domains`, and `Aliases`
  - added `?` alias for `help`
  - meaningful color emphasis for help, usage hints, health, and error tokens
  - `version` now reports `AsyncSD`, `SystemChrono`, and `StatusLED` versions in addition to sensor/display libs
- Updated README configuration and dependency documentation to reflect current project structure and pinned versions
- RS485 device handling refactored: skip logic in global health and `/api/devices` is now config-driven instead of hardcoded
- Legacy output channel conflict auto-heals silently and records the change in event log
- PSRAM rollout document rewritten for phased approach (web scratch first, rings later)
- Web UI: updated Outputs tab with fan PWM control, interval settings, temperature source toggle

### Fixed
- SdLogger: fixed double-encoded UTF-8 em dashes in comments
- SdLogger: IoError for mkdir now treated as "may exist" with documenting comment for hot-remove/reinsert FAT32 behavior
- RuntimeSettings: validation error message for `logSessionName` now accurately reflects the pattern including trailing alphanumeric requirement
- Test: renamed misleading `good_` test case to `bad_trailing_` to correctly describe what is being validated

## [1.2.0] - 2026-02-23

### Fixed
- SD card removal takes up to 60 s to detect without a CD pin — reduced `SD_INFO_REFRESH_MS` from 60 s to 15 s for faster idle-period card-removal detection
- SD card reinsertion fails to mount ("AsyncSD begin failed") — `markUnmounted()` orphaned the AsyncSD worker task by skipping `_sd.end()`; added two-phase teardown via `_deferredTeardown` flag so `_sd.end()` runs in a separate `processDeferred()` cycle from `_sd.begin()`, giving FreeRTOS time to release SPI/worker resources
- All `handleMountResult` media-fault paths and tick fault checks now properly trigger deferred teardown instead of silently clearing `_sdStarted`
- Remount command falsely reported "sd remount ok" in events — changed to "sd remount queued" to accurately reflect the deferred nature
- WiFi status LED stuck solid blue after phone disconnect — set `esp_wifi_set_inactive_time(WIFI_IF_AP, 15)` to cut stale station detection from 300 s to 15 s; reduced hysteresis from 10 s to 3 s

### Changed
- SD mount, remount, and teardown operations are fully deferred out of the cooperative tick via `processDeferred()` flags (`_deferredMount`, `_deferredRemount`, `_deferredTeardown`)
- NVS save, WiFi start/stop, and SD mount/remount all use the same deferred processing pattern — tick stays under 100 ms
- Logging UX: "Stop Logging" button stays enabled when card is missing; "Start Logging" disabled with 409 rejection on no-card/FAT32

## [1.1.0] - 2026-02-22

### Added
- FAT32 logging prohibition: SD logging is disabled on FAT12/16/32 filesystems with a clear warning to format exFAT
- Web UI shows red warning banner on Logging and SD Capacity tabs when FAT32 is detected
- Logging toggle button is disabled and greyed out when no SD card is mounted or FAT filesystem is detected
- `SdLogger::isFatFs()` public API for querying filesystem compatibility

### Changed
- E2 bus managed-settings EEPROM writes are now applied one parameter per tick instead of all at once
  - Converts `Co2Adapter::applyManagedDeviceSettings()` to a staged state machine (6 stages)
  - Caps worst-case per-tick E2 contribution to ~150-300 ms (was ~1000 ms when all 6 params needed writes)
  - CO2 readings continue concurrently during multi-tick settings application
- `attemptBeginOrRecover()` defers managed-settings application to the `readOnce()` tick loop instead of applying all settings in a single blocking call after driver init
- Events timeline and CSV export (from v1.0.0 web UI fixes) now ship in this release

### Fixed
- Events tab timeline showed infinite "Loading..." — now renders color-coded event dots
- CSV Download button did nothing (missing `exportCsv()` function) — now generates and downloads a Blob CSV
- SHT3x button crash (Guru Meditation Error) from `.end()` on null I2C handle in main task context — removed unsafe teardown from `I2cTask::applySettings()`

## [1.0.0] - 2026-02-22

### Added
- CO2Control firmware architecture with deterministic begin/tick/end lifecycle
- Unified Status/Health model and device status reporting
- SD logging with daily files plus single all-time CSV (AsyncSD 1.2.0)
- SoftAP web UI with REST endpoints and WebSocket updates
- CO2 threshold control with hysteresis and min on/off times
- I2C task-owned bus architecture with staged recovery and exponential backoff
- System resource monitor (heap, stack, tick latency) in web UI
- Native unit test environment (38 tests)
- Conformance gates (I2C ownership, ap_pass exposure, web async mutator, text integrity)
- Serial CLI for device access and diagnostics
- Event logging with bounded rollover
- Real-time graph data API with preallocated scratch buffers

### Changed
- Rebranded template to CO2Control and updated documentation

### Fixed
- CRITICAL: Tick/I2C metric counter overflows (C1–C4) — widened to uint64_t
- HIGH: I2C backend race on settings change (H1) — enqueue-based reconfiguration
- HIGH: Settings struct torn-read between tasks (H2) — mutex-protected
- MEDIUM: I2C task lifecycle race (M3) — semaphore-based shutdown
- MEDIUM: SdLogger FileJob no per-job timeout (M1) — 10s deadline with abort
- MEDIUM: RtcAdapter 49-day software fallback drift (M4) — uint64_t millis
- MEDIUM: I2cGpioProbe spin-wait blocking (M2) — vTaskDelay yielding
- LOW: fromUnixSeconds valid beyond 2099 (L2) — year range check
- LOW: const_cast in RtcAdapter (L3) — mutable field
- LOW: Session sequence exhaustion after 9999 (L4) — 5-digit / 65535 cap
- LOW: Per-transfer heap allocation in IDF I2C backend (L5) — static cmd buffer
- LOW: int32_t debounce 24.8-day stale edge (L6) — unsigned arithmetic
- FAT32 SD card info request perpetual timeout cycle — exponential backoff, SPI frequency reduction

### Security
- ap_pass is write-only in all GET endpoints (plaintext never returned)
- Web JSON uses ArduinoJson serialization (no hand-formatted printf for strings/floats)
- Non-finite floats (NaN, Inf) emitted as JSON null

## [0.1.0] - 2026-01-10

### Added
- Initial release with template structure
- ESP32-S2 and ESP32-S3 support

[Unreleased]: https://github.com/janhavelka/CO2Control/compare/v1.4.1...HEAD
[1.4.1]: https://github.com/janhavelka/CO2Control/compare/v1.4.0...v1.4.1
[1.4.0]: https://github.com/janhavelka/CO2Control/compare/v1.3.0...v1.4.0
[1.3.0]: https://github.com/janhavelka/CO2Control/compare/v1.2.0...v1.3.0
[1.2.0]: https://github.com/janhavelka/CO2Control/compare/v1.1.0...v1.2.0
[1.1.0]: https://github.com/janhavelka/CO2Control/compare/v1.0.0...v1.1.0
[1.0.0]: https://github.com/janhavelka/CO2Control/compare/v0.1.0...v1.0.0
[0.1.0]: https://github.com/janhavelka/CO2Control/releases/tag/v0.1.0

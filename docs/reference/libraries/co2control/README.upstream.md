# CO2Control Firmware (ESP32-S2 / ESP32-S3)

Production-grade firmware for **CO2Control / Pavel Reiterman Ustredna**. The project follows a deterministic **begin/tick/end** lifecycle with a unified **Status/Health** model, robust SD logging, and a local SoftAP web UI.

## Quickstart

```bash
# Build for ESP32-S2
pio run -e firmware_esp32s2

# Upload + monitor
pio run -e firmware_esp32s2 -t upload
pio device monitor -e firmware_esp32s2
```

## Supported Targets

| Board                 | Environment         | Notes           |
| --------------------- | ------------------- | --------------- |
| ESP32-S2 (Saola-1)    | `firmware_esp32s2`   | Primary target  |
| ESP32-S3 (DevKitC-1)  | `firmware_esp32s3`   | Secondary check |

## Dependency Versions

External runtime libraries are pinned in [`platformio.ini`](./platformio.ini):

- `BME280` `v1.4.0`
- `SHT3x-main` `v1.4.2`
- `RV3032-C7` `v1.4.1`
- `SSD1315` `v1.1.3`
- `EE871-E2` `v0.3.0`
- `AsyncSD` `v1.3.0`
- `SystemChrono` `v1.2.0`
- `StatusLED` `v1.3.0`

## Architecture

### Lifecycle

```cpp
#include "CO2Control/CO2Control.h"

CO2Control::CO2Control app;

void setup() {
  CO2Control::Config cfg;
  CO2Control::Status st = app.begin(cfg);
  if (!st.ok()) {
    // handle error
  }
}

void loop() {
  app.tick(millis());
}
```

### Threading Model
- Main orchestration runs in cooperative `loop()` via `tick()`.
- Async web handlers never mutate app state directly; they enqueue commands.
- Web reads use non-blocking snapshots and return `503` when state is busy.
- I2C runs in a dedicated FreeRTOS task; only that task touches the bus driver.
- RV3032 RTC and SHT3x/BME280 sensor libraries are integrated through task-owned I2C callbacks.
- ENV model/address selection is orchestrator-owned: the firmware probes supported SHT3x/BME280 addresses, caches the detected sensor, and switches automatically when hardware changes.
- Default I2C backend on ESP32-S2/S3 is ESP-IDF 5.x I2C master driver (deterministic timeout).

### Timing
- `tick()` is cooperative and bounded by per-component work limits.
- SD logger processes at most one stream operation per tick and tracks per-tick I/O budget via `Settings.logIoBudgetMs`.
- I2C request generation is budgeted per tick (`Settings.i2cRequestsPerTick`), and stale results are ignored safely by token/deadline matching.
- I2C task performs GPIO preflight stuck-bus checks before every transaction. If SDA/SCL is held low, request fails fast with `BUS_STUCK` and recovery backoff is scheduled without entering the backend call.
- I2C op timeout target is controlled by `Settings.i2cOpTimeoutMs`; IDF backend enforces this through driver timeout ticks, and RTC read/set requests use an effective `50 ms` floor when RV3032 backup persistence is active.

### Resource Ownership
- UART/I2C/SPI pins are provided via `Config`. No hardcoded pins in library code.
- `src/main.cpp` is the firmware entrypoint.
- Board defaults and pin mapping live in `src/config/AppConfig.cpp`, with startup-profile overrides in `src/config/AppConfig.h`.
- The current board mapping names the EE871 bus as E2 SDA/SCL on `IO6`/`IO7`, with no dedicated enable pin.

### Memory
- All allocation occurs in `begin()`. Zero allocations in `tick()`.
- Startup now enables `heap_caps_malloc_extmem_enable(64)` so eligible large allocations prefer PSRAM when it is available, reducing pressure on internal SRAM.
- Optional serial `[mem ...]` and `[web ...]` snapshots are available behind `CO2CONTROL_TEMP_MEM_DIAG=1` in `src/main.cpp`; they are disabled by default and intended for on-target memory diagnostics.

### Error Handling
- All fallible APIs return `Status`. No silent failures.

### ENV / CO2 Behavior
- The ENV sensor is auto-detected at runtime between SHT3x and BME280. The Devices tab is read-only for sensor selection, shows the detected model/address, and exposes only the settings that match the active sensor, so swapping the physical sensor updates the UI automatically.
- `co2 status` and `/api/status` expose EE871 diagnostics, including measurement-pending state, raw status byte, and raw error code. A raw error code of `0x00` is treated as "detail unavailable", not as a valid decoded fault.
- Vendor EE871 documentation describes both a measurement current peak and a warm-up inrush. The published figures are up to `350 mA` for `0.05 s` peak current, about `120 mA` average during the measuring pulse, and an internal-capacitor warm-up inrush up to about `1.2 A` for about `200 us`. If the probe fails under load but works when a large capacitor is added on `VIN-GND`, treat that as a power-integrity issue and place local bulk capacitance close to the probe.

## Configuration

### Hardware Config
Hardware settings live in `include/CO2Control/HardwareSettings.h`. Board-specific defaults are loaded by `loadHardwareSettings()` in `src/config/AppConfig.cpp`.

### Settings
Runtime settings live in `include/CO2Control/RuntimeSettings.h` and can be loaded/saved via NVS when enabled. Defaults:
- `sampleIntervalSec = 600`
- `logDailyEnabled = true`
- `logAllEnabled = true`
- `wifiEnabled = false`
- `apSsid = "CO2Control-XXXX"`
- `apPass = "co2control"`
- `logIoBudgetMs = 10`
- `logSessionName = "run"` (session directories under `/logs/runs`, e.g. `run_00001`)
- `i2cFreqHz = 400000`
- `i2cOpTimeoutMs = 20`
- `i2cSlowOpThresholdUs = 50000`
- `i2cRtcAddress = 0x51` (RV3032-C7 default)
- `i2cRtcBackupMode = 1`
- `i2cRtcEnableEepromWrites = true`
- RV3032 backup configuration persistence is enabled by default on fresh settings; see [`docs/RTC_DEFAULT_BACKUP_PERSISTENCE_2026-03-18.md`](./docs/RTC_DEFAULT_BACKUP_PERSISTENCE_2026-03-18.md) for the implementation note

Build-time feature flags (in `platformio.ini`):
- `CO2CONTROL_ENABLE_WEB` (`1` by default)
- `CO2CONTROL_ENABLE_DISPLAY` (`0` by default, disables all OLED refresh scheduling)
- `CO2CONTROL_LITE_WEB` is enabled on the SRAM-constrained S2 firmware build and disabled on S3
- `CO2CONTROL_DISABLE_MDNS=1` is used on S2 to save heap; S3 keeps mDNS enabled

## Serial CLI

The CLI follows grouped help/output conventions:

- `help` or `?` prints grouped command overview.
- `help <topic>` prints detailed contract for a single domain.
- Key health/error tokens are color-emphasized for faster diagnostics (`OK`, `DEGRADED`, `FAULT`, errors).
- `version` prints firmware version and linked library versions.
- `co2 status` prints EE871 hardware pins, managed config, measurement-pending state, raw status/error diagnostics, and likely-cause hints for power-integrity faults.
- `preset env bme280` / `preset env sht3x` tune model-specific ENV settings only; they do not manually force sensor selection, which remains automatic.

## Logging (SD)

Two outputs are written in parallel:
- `logs/daily/YYYY-MM-DD.csv`
- `logs/all.csv`

CSV format:
```
ts_unix,ts_local,co2_ppm,temp_c,rh_pct,pressure_hpa,valid_mask
```

If `logs/all.csv` exceeds the size limit (default 3.5 GB), it stops growing and is marked degraded while daily logs continue.
Firmware uses `AsyncSD` (pinned in `platformio.ini`) for bounded, nonblocking SD I/O.
Mount flow creates `/logs` + `/logs/daily` and verifies `/logs` via `requestListDir()` before marking SD ready.
Manual `POST /api/sd/remount` queues a deferred teardown + restart cycle so remount does not reinitialize AsyncSD in the same cooperative tick.
`logFlushMs` controls the minimum spacing between queued SD flush attempts.
Events are persisted to `logs/events.csv` with rollover to `logs/events.prev.csv` when the file reaches the bounded size limit.
Logger status in `/api/status` includes:
- `log_io_budget_ms`
- `log_last_tick_elapsed_ms`
- `log_budget_exceeded_count`
- `log_last_error_age_ms`
- `log_event_queue_depth`
- `log_event_dropped_count`

FAT32 / media notes:
- FAT12/16/32 filesystems are detected and reported, but logging remains disabled until the card is reformatted as exFAT.
- Large FAT32 cards (16-32 GB) can still take 10-30 seconds to report free space during info refresh; those scans are isolated from the steady-state logging path and rate-limited with backoff.
- Default SD SPI frequency is `10 MHz`. Lower it toward `4 MHz` for marginal cards/adapters, or raise it only after validating the card model and wiring.

## I2C Recovery and Metrics

I2C recovery uses staged escalation with backoff:
1. backend reset (`end/begin`)
2. optional SCL pulse sequence (`Config.i2cRecoveryPulses`)
3. optional board-specific power-cycle hook

`/api/status` exports production diagnostics:
- bus errors, recoveries, last recovery stage
- stuck-bus fast-fail counter
- request/result queue depth and overflow/drop counters
- stale result counter
- op duration stats (max, rolling max, mean, slow-op counters)
- task heartbeat and backend type (`idf`)

## Outputs (Valve + Fan)

Outputs are role-based:
- Valve channel (`output_valve_channel`) is controlled by hysteresis source (`output_source`: CO2 or temperature)
- Fan channel (`output_fan_channel`) uses configured power (`output_fan_pwm_percent`)

Valve control:
- ON at `co2_on_ppm` / `temp_on_c` (based on source)
- OFF at `co2_off_ppm` / `temp_off_c`
- `min_on_ms` / `min_off_ms` enforce minimum dwell time

Fan control:
- `0%` = off
- `1..100%` maps to effective `30..100%` on MOSFET channels
- Relay channels are on/off only (any value `>0` means ON)

## Web API (SoftAP)

Endpoints:
- `GET /api/status`
- `GET /api/devices`
- `GET /api/i2c/raw`
- `GET /api/i2c/scan`
- `GET /api/settings`
- `GET /api/settings/defaults`
- `POST /api/device/recover`
- `POST /api/device/probe`
- `POST /api/output/test`
- `POST /api/settings`
- `POST /api/settings/reset`
- `GET /api/graph?count=150`
- `GET /api/events?count=64`
- `POST /api/sd/remount`
- `POST /api/rtc/set`

WebSocket:
- `/ws` for live status updates

Web UI note:
- The System view now collapses firmware/library key-value cards to a single column on narrow/mobile screens so long version strings stay readable.
- The Devices tab now mirrors live ENV auto-detection instead of exposing a manual BME280/SHT3x selector.
- The main UI is generated into a gzip bundle at build time and served with `Content-Encoding: gzip`. S2 builds use the lite web page and tighter async/WiFi buffers to stay within SRAM; S3 builds keep the full page and can use PSRAM-backed web scratch when available.

`GET /api/settings` never returns plaintext `ap_pass`. Password updates are write-only via `POST /api/settings` with:
- `ap_pass_update: true`
- `ap_pass: "<new password>"`

## Status LEDs

Two WS2812 LEDs on a shared strip:
- WiFi/Web LED
  - Red solid: AP off
  - Blue blink: AP on, no stations
  - Blue solid: station connected
  - Green solid: web client active
- Health LED
  - Green blink: init
  - Amber solid: DEGRADED
  - Red/blue police blink: any FAULT
  - Green solid: OK
- Confirmation flashes from web and CLI actions use the WiFi/Web LED only as a short green acknowledgement, so the health LED stays dedicated to health presentation.

## Tests

Native logic tests:
```bash
pio test -e native
```

## Versioning

`include/CO2Control/Version.h` is auto-generated from `library.json` before each build by `scripts/generate_version.py`. Do not edit it manually.

## Copyright

Copyright (c) 2026 Jan Havelka, Thymos Solution s.r.o (www.thymos.cz, info@thymos.cz)

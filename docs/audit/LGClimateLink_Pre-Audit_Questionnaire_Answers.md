# LGClimateLink Pre-Audit Questionnaire Answers

Date: 2026-05-22  
Repository: `https://github.com/janhavelka/LGClimateLink.git`  
Branch: `main`  
Baseline commit reviewed: `78fa7a8 Improve documentation and Doxygen reference`

The command outputs in this document were captured at the clean baseline commit above, before this questionnaire answer file was added. The evidence file is itself a follow-up documentation artifact.

The questionnaire title says `LGClimateBridge`; the repository and firmware are currently named `LGClimateLink`.

---

## 0. Repository Access / Evidence Package

Repository link:

```text
https://github.com/janhavelka/LGClimateLink.git
branch: main
baseline commit: 78fa7a8
```

### Command Output

`git status`

```text
## main...origin/main
```

`git log --oneline -20`

```text
78fa7a8 Improve documentation and Doxygen reference
743a8ed Initial LGClimateLink firmware
```

`git diff --stat HEAD~1..HEAD`

```text
.gitignore                        |   1 +
CHANGELOG.md                      |  98 ++++++++++--
Doxyfile                          |  61 +++++++-
HARDENING_REPORT.md               |   9 +-
README.md                         | 318 +++++++++++++++++++++++++++++++-------
docs/DIGIPOT_NTC_EMULATION.md     |  32 +++-
docs/DOXYGEN_MAIN.md              |  77 +++++++++
docs/HARDWARE.md                  |  25 +++
include/App.h                     |  14 ++
include/cli/SerialCli.h           |  24 +++
include/config/BuildConfig.h      |  31 ++++
include/config/RuntimeSettings.h  |  21 +++
include/digipot/DigipotService.h  |  36 +++++
include/digipot/NtcEmulator.h     |  43 ++++++
include/ha/HaDiscovery.h          |  23 +++
include/ha/MqttService.h          |  18 +++
include/health/HealthMonitor.h    |  22 +++
include/health/WatchdogService.h  |  16 ++
include/lg/LgBus.h                |  20 +++
include/lg/LgClimateModel.h       |  20 +++
include/lg/LgControllerService.h  |  23 +++
include/lg/LgProtocol.h           |  28 ++++
include/lg/LgTypes.h              |  25 +++
include/sensors/Bme280Service.h   |  27 ++++
include/status/StatusLedService.h |  13 ++
include/storage/SettingsStore.h   |  19 +++
src/App.cpp                       |   2 +-
src/ha/HaDiscovery.cpp            |   4 +-
src/ha/MqttService.cpp            |  12 +-
29 files changed, 983 insertions(+), 79 deletions(-)
```

`pio project config`

```text
platformio
----------
default_envs  =  esp32-s2-mini-2-n4
test_dir      =  C:\Users\Honza\Documents\Projects\LGClimateLink\test\native

common
------
lib_deps  =  https://github.com/janhavelka/MCP45HVX1.git
             https://github.com/janhavelka/StatusLED.git
             https://github.com/janhavelka/BME280.git
             knolleary/PubSubClient@^2.8
             bblanchon/ArduinoJson@^7.0.4

env:esp32-s2-mini-2-n4
----------------------
platform                =  espressif32
board                   =  esp32-s2-saola-1
framework               =  arduino
monitor_speed           =  115200
upload_speed            =  921600
lib_deps                =  https://github.com/janhavelka/MCP45HVX1.git
                           https://github.com/janhavelka/StatusLED.git
                           https://github.com/janhavelka/BME280.git
                           knolleary/PubSubClient@^2.8
                           bblanchon/ArduinoJson@^7.0.4
build_unflags           =  -std=gnu++11
build_flags             =  -std=gnu++17
                           -Wall
                           -Wextra
                           -DARDUINO_USB_MODE=0
                           -DARDUINO_USB_CDC_ON_BOOT=1
                           -DCORE_DEBUG_LEVEL=2
                           -DSTATUSLED_BACKEND_IDF5_WS2812=1
                           -DLGCLIMATELINK_FIRMWARE=1
board_build.flash_size  =  4MB
board_build.partitions  =  default.csv

env:native
----------
platform          =  native
test_framework    =  unity
test_build_src    =  True
build_flags       =  -std=gnu++17
                     -Wall
                     -Wextra
                     -Werror=return-type
                     -DUNIT_TEST
                     -DLGCLIMATELINK_NATIVE_TEST
                     -DSTATUSLED_BACKEND_NULL=1
                     -Iinclude
build_src_filter  =  -<*>
                     +<config/RuntimeSettings.cpp>
                     +<lg/LgProtocol.cpp>
                     +<lg/LgClimateModel.cpp>
                     +<digipot/NtcEmulator.cpp>
                     +<ha/HaDiscovery.cpp>
                     +<sensors/Bme280Service.cpp>
                     +<health/HealthMonitor.cpp>
                     +<health/WatchdogService.cpp>
```

`pio run`

```text
Environment         Status    Duration
------------------  --------  ------------
esp32-s2-mini-2-n4  SUCCESS   00:00:02.058

RAM:   [==        ]  20.4% (used 66960 bytes from 327680 bytes)
Flash: [========  ]  77.8% (used 1019297 bytes from 1310720 bytes)
```

`pio test -e native`

```text
test\native\test_main.cpp:199: test_lg_checksum_vectors                  [PASSED]
test\native\test_main.cpp:200: test_lg_parser_resyncs_after_garbage     [PASSED]
test\native\test_main.cpp:201: test_lg_status_mapping_and_build         [PASSED]
test\native\test_main.cpp:202: test_ntc_and_digipot_conversion_clamping [PASSED]
test\native\test_main.cpp:203: test_bme_stale_logic                     [PASSED]
test\native\test_main.cpp:204: test_settings_validation                 [PASSED]
test\native\test_main.cpp:205: test_mqtt_topic_payload_decode           [PASSED]
test\native\test_main.cpp:206: test_watchdog_quorum                     [PASSED]

8 test cases: 8 succeeded
```

`pio check`

```text
Checking esp32-s2-mini-2-n4 > cppcheck (platform: espressif32; board: esp32-s2-saola-1; framework: arduino)
--------------------------------------------------------------------------------
src\config\RuntimeSettings.cpp:21: [low:style] The function 'defaults' is never used. [unusedFunction]
src\health\HealthMonitor.cpp:26: [low:style] The function 'markOk' is never used. [unusedFunction]
src\health\HealthMonitor.cpp:34: [low:style] The function 'markDegraded' is never used. [unusedFunction]
src\health\HealthMonitor.cpp:42: [low:style] The function 'markFault' is never used. [unusedFunction]
src\health\HealthMonitor.cpp:50: [low:style] The function 'evaluate' is never used. [unusedFunction]
src\health\HealthMonitor.cpp:77: [low:style] The function 'healthLevelName' is never used. [unusedFunction]
src\status\StatusLedService.cpp:7: [low:style] The function 'ledStateName' is never used. [unusedFunction]
src\status\StatusLedService.cpp:80: [low:style] The function 'setTestColor' is never used. [unusedFunction]
Error: cppcheck failed to perform check! Please examine tool output in verbose mode.
========================= [FAILED] Took 75.81 seconds =========================

Component     HIGH    MEDIUM    LOW
-----------  ------  --------  -----
src\config     0        0        1
src\health     0        0        5
src\status     0        0        2

Total          0        0        8
```

Assessment of `pio check`: it currently fails only on low-severity `unusedFunction` findings. Several of the reported functions are used from Arduino-gated code paths, so this needs either analyzer configuration or code-visibility cleanup. It is still a real audit item because the exact command fails.

---

## 1. Project Identity

1. Final project/repository name: `LGClimateLink`.
2. Intended form: firmware application. It contains reusable logic modules, but it is not packaged as an Arduino or PlatformIO library.
3. Exact target:
   - MCU: ESP32-S2-MINI-2-N4.
   - PlatformIO board: `esp32-s2-saola-1`, used as the closest 4 MB ESP32-S2 board profile.
   - Platform: `espressif32` 54.3.20 from the current build.
   - Arduino-ESP32: `framework-arduinoespressif32 @ 3.2.0`, Arduino-ESP32 libs `5.4.0+sha.2f7dcd862a`.
   - USB CDC settings: `ARDUINO_USB_MODE=0`, `ARDUINO_USB_CDC_ON_BOOT=1`.
   - Flash / partition: `4MB`, `default.csv`.
4. Main user-facing features:
   - LG wired-controller bus communication.
   - HVAC mode, target temperature, fan, swing, thermistor mode, status/error mapping.
   - BME280 room temperature/humidity/pressure.
   - MCP45HVX1 virtual thermistor output with clamps and safe fallback.
   - USB CDC colored CLI.
   - MQTT/Home Assistant Discovery.
   - Status LEDs.
   - NVS settings.
   - Health monitor and watchdog feed quorum.

---

## 2. High-Level Architecture

### Important Directory Tree

```text
.
|-- platformio.ini
|-- README.md
|-- CHANGELOG.md
|-- HARDENING_REPORT.md
|-- Doxyfile
|-- AGENTS.md
|-- docs/
|   |-- PROTOCOL.md
|   |-- HARDWARE.md
|   |-- DIGIPOT_NTC_EMULATION.md
|   |-- DOXYGEN_MAIN.md
|   |-- audit/
|   |   `-- LGClimateLink_Pre-Audit_Questionnaire_Answers.md
|   `-- reference/
|       |-- README.md
|       |-- hardware/
|       |-- home-assistant/
|       |-- lg-esphome-controller/
|       |-- libraries/
|       `-- platform-libraries/
|-- include/
|   |-- App.h
|   |-- cli/SerialCli.h
|   |-- config/BuildConfig.h
|   |-- config/RuntimeSettings.h
|   |-- digipot/DigipotService.h
|   |-- digipot/NtcEmulator.h
|   |-- ha/HaDiscovery.h
|   |-- ha/MqttService.h
|   |-- health/HealthMonitor.h
|   |-- health/WatchdogService.h
|   |-- lg/LgBus.h
|   |-- lg/LgClimateModel.h
|   |-- lg/LgControllerService.h
|   |-- lg/LgProtocol.h
|   |-- lg/LgTypes.h
|   |-- sensors/Bme280Service.h
|   |-- status/StatusLedService.h
|   `-- storage/SettingsStore.h
|-- src/
|   |-- main.cpp
|   |-- App.cpp
|   |-- cli/SerialCli.cpp
|   |-- config/RuntimeSettings.cpp
|   |-- digipot/DigipotService.cpp
|   |-- digipot/NtcEmulator.cpp
|   |-- ha/HaDiscovery.cpp
|   |-- ha/MqttService.cpp
|   |-- health/HealthMonitor.cpp
|   |-- health/WatchdogService.cpp
|   |-- lg/LgBus.cpp
|   |-- lg/LgClimateModel.cpp
|   |-- lg/LgControllerService.cpp
|   |-- lg/LgProtocol.cpp
|   |-- sensors/Bme280Service.cpp
|   |-- status/StatusLedService.cpp
|   `-- storage/SettingsStore.cpp
`-- test/native/test_main.cpp
```

The complete file tree is available from `rg --files`; `docs/reference/` contains vendored datasheets and upstream reference documents.

### Services

| Module/service | Files | Responsibility | Owns hardware? | Has tests? |
|---|---|---|---|---|
| App | `src/App.cpp`, `include/App.h`, `src/main.cpp` | Top-level Arduino composition, setup, loop, CLI command dispatch | Owns service instances | Indirect through native service tests |
| CLI | `src/cli/SerialCli.cpp`, `include/cli/SerialCli.h` | Nonblocking serial line parser and ANSI helpers | Uses `Stream` | Not directly |
| LG protocol | `src/lg/LgProtocol.cpp`, `src/lg/LgClimateModel.cpp` | Frame parser/checksum/classification and climate mapping | No | Yes |
| LG bus | `src/lg/LgBus.cpp` | UART/LIN GPIO transport | Yes | Not hardware-tested |
| MQTT/Home Assistant | `src/ha/MqttService.cpp`, `src/ha/HaDiscovery.cpp` | Wi-Fi/MQTT reconnect, Discovery, payloads, command decode | Wi-Fi/MQTT client | Payload/command tests |
| BME280 | `src/sensors/Bme280Service.cpp` | Polling, freshness, plausibility, Arduino adapter | Adapter owns I2C driver | Freshness logic tested |
| MCP45HVX1/digipot | `src/digipot/DigipotService.cpp` | Safe write/readback, modes, Arduino adapter | Adapter owns I2C driver | Conversion tested, service not fully faked |
| Virtual NTC | `src/digipot/NtcEmulator.cpp` | Temperature/resistance/wiper math | No | Yes |
| Status LEDs | `src/status/StatusLedService.cpp` | StatusLED presets and test color | Yes | Not directly |
| Settings/storage | `src/storage/SettingsStore.cpp`, `src/config/RuntimeSettings.cpp` | NVS persistence and validation | Preferences/NVS | Validation tested |
| Watchdog/health | `src/health/*` | Health levels and watchdog feed quorum | Watchdog adapter owns ESP WDT | Yes |

### Runtime Model

Single Arduino `loop()` cooperative scheduler. No custom FreeRTOS tasks are created by this firmware. MQTT uses PubSubClient callbacks inside `mqtt_.loop()`. UART RX is polled from the Arduino UART buffer. There are no intentional unbounded busy loops. Known bounded/blocking calls include I2C transactions, PubSubClient connect/publish behavior, and `delay(50)` before confirmed reboot.

### Pure vs Arduino-Dependent

Pure/testable:

- `lg::LgProtocol`
- `lg::LgClimateModel`
- `digipot::NtcEmulator`
- `ha::HaDiscovery`
- `config::RuntimeSettings`
- `health::HealthMonitor`
- `health::WatchdogService` with fake port
- Parts of `sensors::Bme280Service`

Arduino-dependent:

- `App`
- `SerialCli`
- `LgBus`
- Arduino adapters for BME280 and MCP45HVX1
- `MqttService`
- `StatusLedService`
- `SettingsStore`
- ESP task watchdog adapter

---

## 3. Dependencies

| Dependency | Version/source | Used for | Why needed | License concern |
|---|---|---|---|---|
| ESP32 Arduino framework | PlatformIO `espressif32`, Arduino 3.2.0 | MCU, Wi-Fi, USB CDC, Wire, Preferences | Target runtime | Standard framework dependency |
| `janhavelka/MCP45HVX1` | Git dependency, resolved as `1.0.0+sha.88f27da` | MCP45HVX1 control | Required library | Upstream license vendored in references |
| `janhavelka/StatusLED` | Git dependency, resolved as `1.3.0+sha.194c00a` | WS2812/SK6805 status LED control | Required library | Upstream license vendored in references |
| `janhavelka/BME280` | Git dependency, resolved as `1.5.0+sha.ab16222` | BME280 sensor driver | Required library | Upstream license vendored in references |
| `knolleary/PubSubClient@^2.8` | PlatformIO library | MQTT client | HA integration | MIT, upstream reference copied |
| `bblanchon/ArduinoJson@^7.0.4` | PlatformIO library | JSON support dependency | MQTT/HA payload support | MIT |
| `JanM321/esphome-lg-controller` | Reference only in `docs/reference` | Protocol and HA behavior reference | Reverse-engineering baseline | License vendored; no code intentionally copied |
| `janhavelka/CO2Control` | Reference only in `docs/reference` | CLI/style inspiration | Design reference | License vendored; no source copied into firmware |

Library integration:

- MCP45HVX1 and BME280 use injected I2C callback adapters around `TwoWire`.
- StatusLED is used through `StatusLed::StatusLed`, presets, tick, and test-color APIs.
- CO2Control is an ergonomics/style reference only.
- JanM321 is a behavior/protocol reference; firmware code is reimplemented.

Project license status: no root `LICENSE` file currently exists. This must be resolved before release.

---

## 4. Hardware Mapping

| Signal | GPIO | Direction | Peripheral | Notes |
|---|---:|---|---|---|
| LIN_EN | 16 | output | GPIO | Assumed active-high TLIN1027 normal mode |
| LIN_TX | 17 | output | UART1 TX | 104 baud, 8N1 |
| LIN_RX | 18 | input | UART1 RX/GPIO sample | Used for RX and idle-before-send guard |
| STAT_LED | 36 | output | RMT/StatusLED | Default one chain, two pixels |
| PAIR | 37 | output | RMT/StatusLED | Optional second output |
| I2C SDA | 8 | bidirectional | I2C | Placeholder until schematic is verified |
| I2C SCL | 9 | output | I2C | Placeholder until schematic is verified |
| MCP45HVX1 address pins | unknown | hardware strap | I2C address | Firmware default `0x3C` |
| BME280 address | n/a | hardware strap | I2C address | Firmware default `0x76`, alternate `0x77` |

Answers:

1. GPIO36/GPIO37 are output-capable ESP32-S2 module pins per the ESP32-S2-MINI-2 datasheet. Board-level routing still needs verification.
2. SK6805D logic level is assumed direct 3.3 V drive. This has not been bench-verified.
3. Firmware defaults to one chain on `STAT_LED` with two pixels. It supports two independent outputs if configured. Actual topology is unverified.
4. I2C clock: 100 kHz.
5. I2C pullups: unknown from current workspace. Must be checked on schematic/PCB.
6. MCP45HVX1 supply/terminal suitability for LG sensor voltage range is not verified.
7. Exact resistor values around the digipot path are unknown.
8. Firmware still uses documented assumptions for topology and resistor network.

---

## 5. LG Wired-Controller Protocol

| Feature | Implemented? | File(s) | Tested? | Notes |
|---|---|---|---|---|
| frame RX | Yes | `LgBus`, `LgProtocol` | Parser tests | UART polling, sliding parser |
| frame TX | Yes | `LgBus`, `LgControllerService` | Build only | 13-byte writes through UART |
| checksum/parity | Checksum yes, parity no separate layer | `LgProtocol` | Yes | `(sum[0..11] & 0xff) ^ 0x55` |
| climate mode | Yes | `LgClimateModel` | Yes | Mapped to HA names |
| target temperature | Yes | `LgClimateModel` | Yes | Clamped/rounded to capabilities |
| fan speed | Yes | `LgClimateModel` | Yes partial | Supported modes mapped |
| swing/vane | Yes partial | `LgClimateModel` | Partial | Simple swing plus vane fields |
| current temperature | Yes | `LgClimateModel`, `LgControllerService` | Partial | BME local temp can update state |
| error/status | Yes | `LgClimateModel` | Partial | Error code, defrost, preheat, outdoor active |
| installer settings | Yes partial | `LgClimateModel` | Partial | Type-A/B fields mapped |
| thermistor override | Yes | `LgTypes`, `LgClimateModel` | Command parsing tested indirectly | Desired state supports thermistor mode |
| capability detection | Yes partial | `LgClimateModel` | Partial | Reverse-engineered capability bits |

Physical layer:

- ESP32 Arduino UART1 through TLIN1027.
- No bit-banged or RMT implementation.
- UART RX is polled in `LgBus::poll()`.
- TX waits until RX line is high/idle and no UART bytes are pending.

Timing:

- Baud: 104.
- Frame: 13 bytes, 8N1.
- Inter-byte parser timeout: 15000 ms.
- Idle-before-TX: 500 ms.
- Status send period: 20 s.
- Type-B request period: 10 min.
- Echo wait timeout: 8 s.
- LG stale health threshold: 180 s.

Verification:

- Protocol parser/checksum and status mapping have native tests.
- 104 baud ESP32-S2 UART timing has not been scoped on hardware.
- No real LG bus captures are currently included.

Corruption/disconnect/reset behavior:

- Corrupted frames increment checksum/format counters and parser resynchronizes by sliding window.
- LG disconnect becomes stale/offline health and LED/MQTT degraded state.
- LG reset/power cycle should recover when valid frames resume; no dedicated reset handshake is implemented.

Trace:

- CLI command `lg trace <on|off>` toggles a trace flag.
- There is currently no implemented frame dump/rate-limited trace output. This is a documentation/audit finding.

Golden test vectors:

```text
00 00 00 00 00 00 00 00 00 00 00 00 => checksum 55
C9 C4 EA 1F 81 71 00 80 02 40 04 81 9A
A8 22 00 00 00 00 16 20 40 00 80 00 95
A8 10 00 00 00 00 08 14 00 00 00 00 81
```

---

## 6. Home Assistant / MQTT

1. Integration is through MQTT Discovery.

Topic tree:

```text
homeassistant/device/<device_id>/config
<mqtt_base>/<device_id>/availability
<mqtt_base>/<device_id>/availability/lg_bus
<mqtt_base>/<device_id>/availability/bme280
<mqtt_base>/<device_id>/state/climate
<mqtt_base>/<device_id>/state/bme280
<mqtt_base>/<device_id>/state/health
<mqtt_base>/<device_id>/event/error
<mqtt_base>/<device_id>/cmd/mode
<mqtt_base>/<device_id>/cmd/target_temp
<mqtt_base>/<device_id>/cmd/fan_mode
<mqtt_base>/<device_id>/cmd/swing_mode
<mqtt_base>/<device_id>/cmd/thermistor_mode
<mqtt_base>/<device_id>/cmd/digipot_wiper
```

Entities:

| Entity | Type | Topic(s) | Retained? | Availability? | Command validation? |
|---|---|---|---|---|
| LG climate | climate | state/climate, cmd/mode, cmd/target_temp, cmd/fan_mode, cmd/swing_mode | State no, discovery yes | global + lg_bus | Yes |
| BME280 temperature | sensor | state/bme280 | State no | global | n/a |
| BME280 humidity | sensor | state/bme280 | State no | global | n/a |
| BME280 pressure | sensor | state/bme280 | State no | global | n/a |
| Thermistor mode | select | state/climate, cmd/thermistor_mode | State no | global | Yes |
| Digipot resistance | sensor | state/climate | State no | global | n/a |
| Fault | binary_sensor | state/health | State no | global | n/a |
| LG bus online | binary_sensor | state/health | State no | global | n/a |
| LG error code | sensor | state/climate | State no | global | n/a |
| Defrost | binary_sensor | state/climate | State no | global | n/a |
| Preheat | binary_sensor | state/climate | State no | global | n/a |
| Outdoor active | binary_sensor | state/climate | State no | global | n/a |

Behavior:

- MQTT offline: local LG/digipot operation continues.
- Wi-Fi offline: local LG/digipot operation continues.
- Inbound commands are validated and clamped where applicable.
- Retained inbound command payloads are ignored.
- Discovery is retained.
- State publishing is heartbeat-limited to 60 s in `App`; `MqttService` also has a 1 s minimum state publish interval.
- Wi-Fi and MQTT reconnect attempts use exponential backoff up to 60 s.

Files:

- `src/ha/MqttService.cpp`
- `src/ha/HaDiscovery.cpp`
- `include/ha/MqttService.h`
- `include/ha/HaDiscovery.h`

---

## 7. BME280 Integration

1. Library: `janhavelka/BME280`, class `BME280::BME280` with `BME280::Config`.
2. Uses injected I2C callbacks over `TwoWire`, not direct library-owned `Wire`.
3. Measurement interval: default 5000 ms.
4. Oversampling/filter:
   - mode: forced
   - temperature oversampling: x1
   - humidity oversampling: x1
   - pressure oversampling: x1
   - no separate filter configuration seen
5. Tracked:
   - temperature C
   - humidity %
   - pressure Pa
   - sample timestamp
   - last attempt/success timestamps
   - last error
   - consecutive and total errors
   - success count
6. Invalid reading:
   - non-finite temperature/humidity/pressure
   - temperature outside `-40..85 C`
   - humidity outside `0..100 %`
   - pressure outside `30000..110000 Pa`
7. Stale reading:
   - no valid sample or `nowMs - lastSuccessMs > staleMs`
   - default stale timeout 30000 ms
8. On failure:
   - marks error
   - increments counters
   - stale state eventually drives digipot hold/safe fallback
9. Sensor failure does not intentionally block the main loop.
10. Values are exposed through CLI `bme status`, `bme read`, and MQTT/Home Assistant sensors.

Files:

- `src/sensors/Bme280Service.cpp`
- `include/sensors/Bme280Service.h`
- `test/native/test_main.cpp`

---

## 8. MCP45HVX1 / Virtual NTC Emulation

1. Assumed part: MCP45HV51-502E/ST.
2. Assumed resistance range:
   - nominal RAB: 5000 ohm
   - effective clamp: 1000..5075 ohm
3. Terminal topology:
   - default rheostat B-to-W
   - supports A-to-W and code inversion in firmware model
   - actual PA/PB/PW wiring unverified
4. External resistors:
   - model includes `seriesOhms`, default 0
   - no known parallel resistor model
   - exact board resistor values unknown
5. Temperature formula:
   - beta model: `R = Rref * exp(beta * (1/T - 1/Tref))`
   - Kelvin temperatures
   - PTC polarity supported by sign inversion
6. Supported models:
   - beta
   - Steinhart-Hart
   - lookup table
7. Defaults:
   - `Rref = 5000 ohm`
   - `Tref = 25 C`
   - `beta = 3950 K`
   - min/max temperature: `5..35 C`
   - min/max resistance: `1000..5075 ohm`
   - safe resistance: `2565 ohm`
   - safe wiper: `127`
   - min/max allowed wiper: `1..254`
   - estimated wiper resistance: `75 ohm`
8. Calibration storage:
   - Struct supports calibration in `RuntimeSettings`.
   - NVS persistence stores `RuntimeSettings`.
   - CLI currently exposes only `safe_ohms` and `bme_addr`; most calibration fields are firmware constants until more CLI/NVS schema is added.
9. Invalid calibration:
   - rejected by `digipot::validate()` and `config::validate()`.
   - digipot enters fault if invalid at begin.
10. Min/max temperatures: default `5..35 C`.
11. Min/max resistances: default `1000..5075 ohm`.
12. Min/max wiper codes: default `1..254`, max physical code `255`.
13. Output is clamped at temperature, resistance, and code stages.
14. Boot-time safe state:
   - safe wiper code is written during digipot begin.
   - mode becomes `BootSafe`.
15. Fault behavior:
   - BME stale: hold last good until `holdLastGoodMs`, then safe fixed.
   - BME failed: same stale path after no fresh valid sample.
   - I2C bus failure: BME/digipot errors, health degraded/fault.
   - MCP write failure: digipot fault.
   - MCP readback mismatch: digipot fault.
   - Invalid calibration: begin fails and digipot fault.
   - LG bus offline: health degraded; digipot local thermistor path continues.
   - Repeated reboot loop: boot count persisted, but no full repeated-crash safe-mode policy yet.
16. Digipot write readback:
   - after write, readback is attempted.
   - mismatch faults the digipot.
   - if readback call fails, current code does not fault solely on read failure because it checks `if (driver_->readWiper(readback) && readback != code)`. This should be audited.
17. Write retries:
   - bounded: no unbounded retry loop in service.
   - lower library may recover; service makes one write attempt per call.
18. Safe fallback resistance exists through safe wiper/safe fixed output.
19. Last-known-good:
   - held for `holdLastGoodMs`, default 300000 ms.
20. Unsafe CLI/MQTT:
   - manual wiper code is clamped to allowed code range.
   - CLI requires `digipot set arm`.
   - MQTT `cmd/digipot_wiper` is ignored unless the local CLI arm flag is active.

Files:

- `src/digipot/NtcEmulator.cpp`
- `src/digipot/DigipotService.cpp`
- `docs/DIGIPOT_NTC_EMULATION.md`
- `test/native/test_main.cpp`

---

## 9. CLI

1. USB CDC is enabled by build flags. Hardware operation is not bench-confirmed in this evidence package.
2. CLI starts in `App::begin()` after settings, I2C, services, watchdog, and MQTT begin. It is early enough for normal bring-up, not earliest possible boot diagnostics.
3. Parser is nonblocking and drains a bounded amount of input per tick.
4. ANSI color can be disabled through `SerialCli::setColorEnabled()`, but no CLI command currently toggles it.

Commands:

| Command | Description | Dangerous? | Guarded? |
|---|---|---:|---:|
| `help` | Print command list | No | n/a |
| `status` | System summary | No | n/a |
| `health` | Health details | No | n/a |
| `uptime` | Uptime seconds | No | n/a |
| `reboot confirm` | Reboot | Yes | Yes |
| `wifi status` | Wi-Fi state | No | n/a |
| `wifi config <ssid> <password>` | Set Wi-Fi in RAM | Sensitive | Save required |
| `wifi clear` | Clear Wi-Fi in RAM | Yes | Save required |
| `mqtt status` | MQTT state | No | n/a |
| `mqtt config <host> <port> [user] [password]` | Set MQTT in RAM | Sensitive | Save required |
| `mqtt clear` | Disable MQTT in RAM | Yes | Save required |
| `lg status` | LG state | No | n/a |
| `lg trace <on|off>` | Toggle trace flag | No | No actual dump currently |
| `lg send arm` | Arm raw frame send | Yes | Arm step |
| `lg send <13 hex bytes>` | Queue raw LG frame | Yes | Requires arm |
| `lg test` | Toggle desired mode | Yes | Not confirmed |
| `bme status` | Show sensor state | No | n/a |
| `bme read` | Request measurement | No | n/a |
| `digipot status` | Show digipot state | No | n/a |
| `digipot set arm` | Arm manual wiper write | Yes | Arm step |
| `digipot set code <0..255>` | Write manual wiper | Yes | Requires arm and clamp |
| `digipot test` | Move to safe fixed | Yes | No separate confirm |
| `digipot calibrate` | Print guidance only | No | n/a |
| `ntc calc <temp_c>` | Calculate resistance/code | No | Input parsed |
| `led status` | LED state | No | n/a |
| `led test <r> <g> <b>` | Set test color | No | RGB parsed, not range-rejected before cast |
| `i2c scan` | Scan bus | No | n/a |
| `config show` | Print config | Sensitive | Prints SSID, not password |
| `config set <key> <value>` | Set limited keys | Yes | Validation |
| `config save` | Persist settings | Yes | Validation/delayed save |
| `config reset` | Load defaults in RAM | Yes | Save required |
| `logs level` | Print compile-time log note | No | n/a |
| `watchdog status` | Print watchdog state | No | n/a |

Required checklist:

- Present: `help`, `status`, `health`, `uptime`, `reboot`, Wi-Fi status/config/clear, MQTT status/config/clear, LG status/trace/send/test, BME status/read, digipot status/set/test/calibrate, `ntc calc`, LED status/test, `i2c scan`, config show/set/save/reset, logs level, watchdog status.
- Missing from original requested checklist: `bme config`.

CLI timing:

- CLI output can block at the serial driver level, but input parsing is bounded.
- LG bus timing does not depend on CLI output.
- No dynamic allocation is used in the parser hot path.

Files:

- `src/cli/SerialCli.cpp`
- `include/cli/SerialCli.h`
- `src/App.cpp`

---

## 10. Status LEDs

1. Library: `janhavelka/StatusLED`.
2. Default one channel with two pixels; firmware supports two independent outputs.
3. LED update calls `tick(nowMs)` and is intended nonblocking.

| State | Pattern/color | Priority |
|---|---|---|
| booting | `StatusPreset::Updating` | Startup |
| Wi-Fi connecting | `StatusPreset::Connecting` | Connectivity |
| MQTT disconnected | `StatusPreset::Warning` | Connectivity |
| LG offline | `StatusPreset::HazardAmber` | Bus health |
| normal operation | `StatusPreset::Ready` | Healthy |
| degraded sensor/digipot | `StatusPreset::Warning` | Degraded |
| configuration mode | `StatusPreset::Maintenance` | Reserved/config |
| fatal fault | `StatusPreset::Critical` | Highest |

5. If LED update fails, `lastError_` is updated; service does not fault the system.
6. LEDs cannot currently be disabled by settings, only brightness/topology can be configured in defaults/struct.

File: `src/status/StatusLedService.cpp`.

---

## 11. Settings / Persistence

1. Storage: ESP `Preferences` / NVS.
2. Persisted settings:

| Setting | Type | Default | Validation | Flash write frequency |
|---|---|---|---|---|
| `deviceId` | char[32] | `lgclimatelink` | nonempty MQTT-safe token | delayed save |
| `deviceName` | char[48] | `LG Climate Link` | minimal | delayed save |
| Wi-Fi SSID/password | char arrays | empty | not deeply validated | delayed save |
| MQTT host/user/password/base/port | char arrays/u16 | base `lgclimatelink`, port 1883 | topic token and nonzero port | delayed save |
| MQTT enable | bool | false | n/a | delayed save |
| LG role and thermistor control flags | bool | defaults | n/a | delayed save |
| BME address/poll/stale | u8/u32 | 0x76, 5000, 30000 | address/range relationship | delayed save |
| MCP address | u8 | 0x3C | only generic settings validation currently | delayed save |
| NTC calibration | struct | placeholder | `digipot::validate()` | delayed save |
| Digipot calibration | struct | placeholder | `digipot::validate()` | delayed save |
| LED topology/brightness | enum/u8 | one chain, 32 | minimal | delayed save |
| Watchdog timeout | u32 | 15 | 5..120 s | delayed save |
| Settings commit delay | u32 | 5000 | >=1000 ms | delayed save |

3. Settings versioned: yes, persisted wrapper has magic and schema version.
4. Schema migration: no migration beyond reject/fallback.
5. CRC/checksum: no CRC; magic/version and validation only.
6. Writes are delayed/coalesced by `scheduleSave()`.
7. Factory reset: `config reset` loads defaults in RAM; `SettingsStore::clear()` exists but no direct CLI command currently calls it.
8. Corrupted/invalid settings: defaults are used.
9. Credentials are stored in NVS without encryption. Suitable only for trusted-device assumptions.
10. Calibration values are validated by settings and digipot validators.

Files:

- `src/storage/SettingsStore.cpp`
- `src/config/RuntimeSettings.cpp`
- `include/config/RuntimeSettings.h`

---

## 12. Watchdog / Health / Unattended Operation

1. Watchdog enabled in Arduino build through ESP task watchdog adapter.
2. Watchdog: ESP task watchdog (`esp_task_wdt`).
3. Fed by `WatchdogService::tick()`.
4. Feed quorum exists; not fed blindly.
5. Services reporting progress:

| Service | Progress metric | Failure threshold | Recovery action |
|---|---|---|---|
| LG bus | last valid frame / degraded mark | 180 s | degraded/offline, watchdog quorum false if stale |
| BME280 | fresh sample / degraded mark | 30 s | stale drives digipot hold/safe |
| digipot | initialized and not fault | 30 s configured health | fault stops watchdog feed |
| I2C | BME/digipot error counters | 30 s health item | degraded/fault via services |
| Wi-Fi | MQTT snapshot connected | 120 s, not watchdog-required | reconnect backoff |
| MQTT | MQTT connected | 120 s, not watchdog-required | reconnect backoff |
| CLI | no health item | n/a | n/a |
| main loop | mark every loop | 2 s | watchdog reset if loop stalls |

7. Reset reasons: printed by CLI/status through ESP reset reason mapping.
8. Boot count: persisted in NVS.
9. Repeated crash/fault detection: boot count exists, but repeated fault counter/safe mode is not fully implemented.
10. Safe mode: digipot safe fixed/fault modes exist; full system safe mode for repeated reboots does not.
11. Heap monitored: free heap printed in status; no threshold health item.
12. Loop latency monitored: max loop latency is tracked and printed.
13. Logs rate-limited: no general logging system; CLI output is command-driven.
14. Blocking calls: I2C has intended timeouts, MQTT/PubSubClient may block during network operations, `delay(50)` before reboot, `delay(2)` in I2C bus reset.

Files:

- `src/health/HealthMonitor.cpp`
- `src/health/WatchdogService.cpp`
- `src/App.cpp`

---

## 13. Error Handling And Degraded Modes

| Fault | Detection | Recovery | User-visible state | Safe output |
|---|---|---|---|---|
| Wi-Fi unavailable | `WiFi.status()` false | Backoff reconnect | health degraded, LED Wi-Fi connecting | Local LG/digipot continues |
| MQTT unavailable | `mqtt_.connected()` false | Backoff reconnect | health degraded, LED MQTT disconnected | Local LG/digipot continues |
| LG bus offline | no fresh frame for 180 s | wait for valid frames | degraded/offline | Digipot continues local BME path |
| corrupted LG frame storm | checksum/format errors | parser sliding resync | counters only | no state update from bad frames |
| BME280 missing | begin/read failure | error tracking, optional driver recover hook unused by service | degraded/stale | hold then safe fixed |
| BME280 stale | stale timeout | hold then safe fixed | degraded | hold/safe |
| MCP45HVX1 missing | begin/write failure | fault | fault/fatal LED | no reliable software output |
| MCP write/readback fail | write failure or mismatch | fault | fault | last hardware state unknown |
| I2C bus stuck | Wire errors/timeouts | driver recover exists, not globally orchestrated | degraded/fault | digipot fault or BME stale path |
| settings corrupt | magic/version/validation fail | defaults | CLI config shows defaults | safe defaults |
| low heap | only status print | none | status only | no automatic action |
| repeated reboot | boot count increments | no full policy | status only | boot safe digipot write |
| CLI malformed command | parser/usage rejection | print error | CLI error | no state change |
| MQTT malformed command | decode rejection | publish error event | MQTT error event/counters | no state change |

---

## 14. Tests And Validation

| Test file | What it tests | Native? | Hardware required? |
|---|---|---|---|
| `test/native/test_main.cpp` | LG checksum/parser/state mapping, NTC/digipot conversion, BME stale logic, settings validation, MQTT decode, watchdog quorum | Yes | No |

Current outputs:

- `pio test -e native`: passed, 8/8.
- `pio run`: passed for `esp32-s2-mini-2-n4`.

Coverage checklist:

| Area | Covered? | Notes |
|---|---|---|
| LG frame parser | Yes | Sliding resync test |
| LG frame serializer | Partial | buildStatusFrame tested |
| checksum/parity | Checksum yes | no parity layer |
| corrupted frames | Partial | garbage/resync |
| partial frames | Partial | parser logic |
| climate state mapping | Partial | status mapping |
| MQTT command validation | Yes | decode tests |
| MQTT discovery payload generation | Partial | not deeply asserted |
| virtual NTC temp-to-resistance | Yes | conversion/clamp test |
| resistance-to-wiper | Yes | conversion/clamp test |
| clamp behavior | Yes | conversion test |
| stale BME280 fallback | Partial | BME stale logic tested; full DigipotService fake not tested |
| MCP write failure fallback | No | no fake MCP integration test |
| settings validation | Yes | validation test |
| watchdog feed quorum | Yes | quorum test |
| ring buffers/log rate limits | No | CLI bounded parser not directly tested |

Tests are deterministic and hardware-independent. Hardware tests are not configured. CI is not configured.

---

## 15. Static Analysis / Code Quality

1. `pio check` runs cppcheck by default but currently fails on low-severity findings.
2. Compiler warnings enabled: `-Wall`, `-Wextra`; native adds `-Werror=return-type`.
3. Warning level: compiler warnings as above; static analyzer defaults.
4. Ignored warnings: none configured.
5. TODO/FIXME scan over authored files, excluding `docs/reference`:

```text
docs\HARDWARE.md:37:Configured placeholders:
docs\DIGIPOT_NTC_EMULATION.md:63:These constants are not claimed to be the original LG sensor. They are safe software placeholders until the real thermistor and board topology are verified.
docs\DIGIPOT_NTC_EMULATION.md:75:| Reference resistance | `NtcCalibration::rRefOhms` | Firmware constant | Default is 5000 ohm placeholder. |
docs\DIGIPOT_NTC_EMULATION.md:77:| Beta coefficient | `NtcCalibration::betaK` | Firmware constant | Default is 3950 K placeholder. |
docs\DIGIPOT_NTC_EMULATION.md:110:## Hardware Verification TODOs
include\digipot\NtcEmulator.h:45: * Defaults are safe software placeholders for bench bring-up. They are not
include\digipot\NtcEmulator.h:52:  // Safe defaults are placeholders for LG sensor bring-up. They must be
include\config\BuildConfig.h:7: * Values in this file are hardware assumptions. Items marked as TODO must be
include\config\BuildConfig.h:31:// Hardware TODO: verify the final board's I2C pins. GPIO8/GPIO9 are safe
```

Code quality observations:

- Global mutable state: Arduino global `App app`; static `MqttService::instance_` for PubSubClient callback; static `Preferences prefs` in storage.
- Hidden singletons: MQTT callback instance and Preferences object.
- Raw pointers: service driver injection pointers; checked before use.
- Heap allocation in periodic paths: no obvious explicit allocation; PubSubClient/Wi-Fi internals may allocate.
- Unbounded `String`: no project `String` hot path use found.
- Blocking delays: `delay(50)` before reboot, `delay(2)` in I2C bus reset.
- Blocking network calls: PubSubClient connect/publish can block.
- Busy waits/recursion: none obvious.
- Unsafe casts: `static_cast<uint8_t>` on CLI RGB values can wrap if >255; digipot code cast is guarded by service range.
- Magic constants: present but most are centralized in `BuildConfig.h`.

---

## 16. Timing / Real-Time Behavior

1. Expected loop frequency: not specified; cooperative loop should run frequently enough for UART polling and service ticks.
2. Worst-case loop time: not bounded by formal analysis; max loop latency is measured.
3. Loop timings measured: `maxLoopLatencyUs_` tracked and printed.
4. Blocking operations:
   - I2C transactions
   - Wi-Fi/MQTT connect/publish
   - Serial output
   - LED update library calls
   - short explicit delays in reboot/bus reset
5. I2C timeout: configured 50 ms in driver configs, but callbacks ignore `timeoutMs` directly and rely on Wire behavior.
6. Wi-Fi/MQTT timeout: reconnect attempts are backoff-limited; per-call blocking time is not explicitly bounded.
7. CLI output can block at stream level.
8. MQTT publish can block in PubSubClient.
9. LED updates are intended nonblocking through StatusLED tick.
10. Logging should not disturb LG timing because LG bus send checks happen independently, but heavy serial output can still consume loop time.
11. LG RX is UART buffered by Arduino and polled.
12. High log volume: no general log stream exists; CLI command output can delay loop while printing.

---

## 17. Security / Robustness

1. No web server.
2. OTA is not enabled.
3. MQTT password is not printed by `config show`; Wi-Fi SSID is printed. Credentials are stored in NVS without encryption.
4. MQTT commands cannot reboot or reconfigure device. They can change climate desired state and guarded digipot wiper.
5. Destructive CLI commands:
   - reboot requires confirm
   - raw LG send requires arm
   - raw digipot write requires arm
   - config reset requires save to persist
6. Pairing/config mode is not implemented.
7. Logs are minimal; sanitization not systematically implemented.
8. Malformed MQTT payloads are length-capped and decoded defensively.
9. Malformed CLI input is bounded by fixed buffers and usage checks.
10. Buffers are fixed-size in CLI, MQTT topics, and payload builders.

---

## 18. Documentation

| Document | Exists? | Complete? | Notes |
|---|---:|---:|---|
| `README.md` | Yes | Good for bench bring-up | Includes build, pin map, CLI, MQTT, risks |
| `docs/HARDWARE.md` | Yes | Good with open items | Includes electrical checklist |
| `docs/PROTOCOL.md` | Yes | Good summary | No real capture logs |
| `docs/DIGIPOT_NTC_EMULATION.md` | Yes | Good for current state | Marks many fields firmware constants |
| `docs/CLI.md` | No | n/a | CLI docs are in README |
| `docs/HOME_ASSISTANT.md` | No | n/a | MQTT docs are in README |
| `docs/CALIBRATION.md` | No | n/a | Calibration docs are in digipot doc |
| `CHANGELOG.md` | Yes | Good | Engineering categories |
| `HARDENING_REPORT.md` | Yes | Good | Lists risks and verification |
| Doxygen | Yes | Good starting point | `Doxyfile`, `docs/DOXYGEN_MAIN.md` |

Answers:

1. README includes build/upload/monitor commands.
2. README includes pin mapping.
3. README explains safe/fallback behavior.
4. Docs clearly mark unverified LG/digipot assumptions.
5. Docs explain how to calibrate conceptually, but CLI support for full calibration is not implemented.
6. Docs include MQTT topics/entities.
7. Docs include known limitations.

---

## 19. Licensing And Attribution

1. Repository license: currently unspecified. There is no root `LICENSE` file.
2. Third-party upstream licenses are included in `docs/reference` where available.
3. JanM321 is credited in README and protocol docs.
4. Required libraries are credited/linked.
5. No GPL code is intentionally copied into firmware. JanM321 reference material is vendored under `docs/reference`, and implementation was re-created.
6. AI-generated project code has no external source attribution requirements, but project license still needs to be declared.

---

## 20. Known Problems / Remaining Risks

| Item | Severity | Why unresolved | Safe current behavior | How to verify/fix |
|---|---|---|---|---|
| Original LG thermistor curve unknown | High | No real sensor measurements/service data | Placeholder 5 kOhm curve, clamps | Measure sensor or obtain service manual |
| MCP45HVX1 terminal topology unknown | High | Schematic/measurements absent | B-W rheostat model, safe code | Measure sensor-pin resistance over wiper codes |
| Series resistors unknown | High | Schematic/BOM not confirmed | seriesOhms default 0 | Inspect schematic/BOM and measure |
| Reset/brownout analog failsafe unknown | High | Requires bench measurement | Boot writes safe code | Measure during reset, brownout, watchdog |
| 104 baud UART timing unverified | High | Requires scope/real bus | UART configured and tested only by build | Scope TX/RX and real LG traffic |
| TLIN1027 enable polarity assumed | Medium | Schematic not confirmed | active-high assumption | Check schematic/scope bus |
| I2C pins assumed | Medium | final PCB netlist absent | GPIO8/GPIO9 placeholders | Schematic/continuity, `i2c scan` |
| LED topology unknown | Low | board routing not confirmed | default one chain, supports two | Inspect board or `led test` |
| `pio check` exact command fails | Medium | cppcheck low findings treated as failure | build/test pass | Configure analyzer or resolve unusedFunction findings |
| Root license missing | Medium | not created yet | upstream licenses vendored | add root `LICENSE` and SPDX policy |
| Full repeated-crash safe mode missing | Medium | boot count exists only | watchdog reset and boot safe digipot write | add repeated fault counter/safe mode |
| LG trace command incomplete | Low/Medium | flag exists, no frame dump | no logging timing risk | implement bounded/rate-limited trace buffer |
| Full calibration CLI missing | Medium | fields exist in structs only | safe defaults and docs | add validated calibration schema/commands |
| `bme config` missing | Low | not implemented | BME can be configured via limited config keys | add command or remove from external checklist |

---

## 21. Final Self-Assessment

1. Three riskiest parts:
   - Virtual thermistor analog correctness.
   - Hardware failsafe state during reset/brownout.
   - LG 104 baud physical-layer behavior on real bus.
2. Most likely to fail after months:
   - Wi-Fi/MQTT reconnection edge cases or I2C bus recovery under electrical noise.
3. Least tested:
   - Hardware adapters, real LG bus behavior, MCP45HVX1 failure paths, StatusLED behavior.
4. Implemented with assumptions:
   - I2C pins, LED topology, TLIN1027 enable polarity, MCP45HVX1 topology, resistor network, LG thermistor curve.
5. First safety-critical audit target:
   - Digipot/NTC path, including effective resistance, fail-safe state, readback error handling, and calibration validation.
6. Refuse to deploy before bench testing:
   - Anything connected unattended to an HVAC unit before sensor curve, digipot topology, reset resistance, and LIN timing are measured.
7. Bandaids/temporary fixes:
   - Placeholder thermistor constants.
   - GPIO8/GPIO9 I2C assumption.
   - `lg trace` flag without real trace output.
8. Architecturally questionable but functional:
   - Settings persistence stores raw struct without CRC.
   - MQTT callback uses static instance pointer.
   - PubSubClient blocking behavior is accepted inside cooperative loop.
9. Audit stopped because:
   - Software build/test/docs are coherent, but hardware facts remain unavailable. Hardware verification, not time, is the blocker.
10. Commands proving current state:

```powershell
git status --short --branch
git log --oneline -20
pio project config
pio run
pio test -e native
pio check
doxygen Doxyfile
rg -n "TODO|FIXME|HACK|XXX|temporary|workaround|stub|placeholder" src include test docs platformio.ini -g "!docs/reference/**"
```

---

## 22. Files To Paste / Upload For Audit

Minimum files exist in the repository:

```text
platformio.ini
README.md
CHANGELOG.md
HARDENING_REPORT.md
src/main.cpp
src/App.cpp
include/App.h
include/**/*.h
src/lg/*
src/ha/*
src/cli/*
src/sensors/*
src/digipot/*
src/status/*
src/storage/*
src/health/*
test/native/test_main.cpp
docs/*
```

Recommended evidence bundle for the next auditor:

1. GitHub branch `main` at commit `78fa7a8` or newer.
2. `platformio.ini`.
3. This file.
4. `README.md`.
5. `HARDENING_REPORT.md`.
6. `docs/PROTOCOL.md`.
7. `docs/DIGIPOT_NTC_EMULATION.md`.
8. `src/lg/*`.
9. `src/digipot/*`.
10. `src/health/*`.
11. Native test output.
12. Exact `pio check` output, including the current failure.

---

## Most Important Evidence For Next Audit

1. Repository and branch: `https://github.com/janhavelka/LGClimateLink.git`, `main`.
2. Latest reviewed commit: `78fa7a8`.
3. Build/test status: `pio run` passed, `pio test -e native` passed.
4. Static analysis status: exact `pio check` currently fails on 8 low cppcheck style findings.
5. Primary unresolved risks: hardware topology, thermistor calibration, analog failsafe, 104 baud bus validation, root license.

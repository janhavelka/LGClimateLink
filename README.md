# LGClimateLink

LGClimateLink is Arduino + PlatformIO firmware for an ESP32-S2-MINI-2-N4 based LG wired-controller interface.

The firmware is built for a dedicated controller board with:

- TLIN1027-Q1 LIN transceiver for the LG wired-controller bus.
- BME280 room sensor on I2C.
- MCP45HV51 high-voltage digital potentiometer on I2C.
- SK6805D-EC2018 / WS2812-class status LEDs.
- USB CDC serial CLI.
- Home Assistant integration through MQTT Discovery.

This is not an ESPHome YAML project. The LG protocol model is based on JanM321's reverse engineering work:

- `https://github.com/JanM321/esphome-lg-controller`
- `https://github.com/JanM321/esphome-lg-controller/blob/main/protocol.md`

The firmware uses these required libraries directly:

- `janhavelka/MCP45HVX1`
- `janhavelka/StatusLED`
- `janhavelka/BME280`

Supporting upstream protocol notes, component datasheets, library manuals, and Home Assistant MQTT reference pages are vendored under `docs/reference/`.

## Current Status

The repository is ready for bench bring-up.

The safety paths are implemented, and native tests cover protocol parsing, thermistor math, MQTT command validation, BME280 freshness, settings validation, and watchdog quorum. Run `pio test -e native` and `pio run` locally before each release.

The firmware is not yet approved for unattended connection to an HVAC unit until the remaining hardware measurements are complete. The highest-risk open items are the original LG room-sensor curve and the exact MCP45HVX1 analog topology.

See `HARDENING_REPORT.md` for the current audit status.

## System Model

The firmware is organized as small services with explicit ownership:

| Service | Responsibility |
| --- | --- |
| `lg::LgBus` | Low-speed UART/LIN transport and frame parser. |
| `lg::LgControllerService` | LG state machine, desired climate state, frame scheduling, echo tracking. |
| `sensors::Bme280Service` | BME280 polling, freshness, plausibility checks, error accounting. |
| `digipot::DigipotService` | MCP45HVX1 initialization, safe wiper writes, degraded and fault modes. |
| `digipot::NtcEmulator` | Temperature-to-resistance and resistance-to-wiper conversion. |
| `ha::MqttService` | Wi-Fi/MQTT reconnect, Discovery, state publishing, command validation. |
| `status::StatusLedService` | Nonblocking device-state indication. |
| `storage::SettingsStore` | NVS settings with delayed writes. |
| `health::HealthMonitor` | Service freshness and fault aggregation. |
| `health::WatchdogService` | Watchdog feed gate based on health quorum. |
| `cli::SerialCli` | Nonblocking USB CDC command parser. |

Periodic code paths avoid unbounded blocking. Time-critical LG bus work does not depend on MQTT, Wi-Fi, or serial logging.

## Hardware Assumptions

Target MCU:

```text
ESP32-S2-MINI-2-N4
Arduino framework
USB CDC enabled on boot
4 MB flash target profile
```

Implemented pin map:

| Function | GPIO | Notes |
| --- | ---: | --- |
| LIN transceiver enable | 16 | Assumed active-high TLIN1027 normal mode. Verify against schematic. |
| LIN TXD | 17 | UART1 TX at 104 baud, 8N1. |
| LIN RXD | 18 | UART1 RX, also sampled for the idle-before-send guard. |
| Status LED chain | 36 | `STAT_LED`; default topology is one chain with two pixels. |
| Pair LED output | 37 | `PAIR`; supported as a second independent output if the board uses it. |
| I2C SDA | 8 | Placeholder until the final schematic confirms SDA. |
| I2C SCL | 9 | Placeholder until the final schematic confirms SCL. |
| BME280 I2C | 0x76 | Configurable to 0x77. |
| MCP45HVX1 I2C | 0x3C | Configurable in the expected 0x3C..0x3F range. |

Hardware notes are in `docs/HARDWARE.md`.

## Safety Boundary

The MCP45HVX1 output replaces the original room sensor seen by the LG unit. Treat this path as safety-critical.

Software protections:

- The digipot is written to a configured safe code during boot.
- Temperature input must be fresh and plausible before it drives the virtual thermistor.
- Resistance and wiper code are always clamped.
- If BME280 data becomes stale, the firmware holds the last safe value for a limited time.
- If the hold interval expires, the firmware moves to a safe fixed output.
- Raw digipot writes require prior local CLI arming. MQTT `cmd/digipot_wiper` is ignored unless that one-shot local arm is active.
- The watchdog is fed only when the health quorum allows it.

Software cannot prove the analog failsafe state during reset, brownout, or total MCU failure. Measure the resistance at the LG sensor pins during those states before unattended use.

## Build And Test

Install PlatformIO, then run:

```powershell
pio run
pio test -e native
```

Build the explicit target:

```powershell
pio run -e esp32-s2-mini-2-n4
```

Upload and monitor:

```powershell
pio run -e esp32-s2-mini-2-n4 -t upload
pio device monitor -b 115200
```

USB CDC is enabled by these build flags:

```ini
-DARDUINO_USB_MODE=0
-DARDUINO_USB_CDC_ON_BOOT=1
```

## First Bring-Up

Use this order on new hardware:

1. Power the board from a current-limited bench supply.
2. Open the USB CDC monitor at 115200 baud.
3. Run `status` and `health`.
4. Run `i2c scan` and confirm BME280 and MCP45HVX1 addresses.
5. Run `bme read`, then `bme status`.
6. Run `ntc calc 25` and confirm the computed resistance and wiper code are in range.
7. Measure resistance at the LG sensor pins before connecting the HVAC unit.
8. Run `led test <r> <g> <b>` to confirm LED topology.
9. Scope LIN TX/RX at 104 baud before connecting to the LG bus.
10. Connect to the LG bus only after the analog sensor path and LIN idle levels are verified.

## Configuration

Settings are stored in NVS. CLI changes are applied to RAM first. Use `config save` to schedule a persistent save.

Common commands:

```text
wifi config <ssid> <password>
mqtt config <broker-host> 1883 [user] [password]
config set device_id <safe-token>
config set mqtt_base <safe-token>
config set bme_addr <address>
config set safe_ohms <ohms>
config save
reboot confirm
```

Writes are delayed and coalesced to reduce flash wear.

## Home Assistant MQTT

Enable MQTT from the CLI:

```text
mqtt config <broker-host> 1883 [user] [password]
config save
```

Discovery topic:

```text
homeassistant/device/<device_id>/config
```

Base runtime topic:

```text
<mqtt_base>/<device_id>
```

State and availability topics:

```text
<base>/availability
<base>/availability/lg_bus
<base>/availability/bme280
<base>/state/climate
<base>/state/bme280
<base>/state/health
<base>/event/error
```

Command topics:

```text
<base>/cmd/mode
<base>/cmd/target_temp
<base>/cmd/fan_mode
<base>/cmd/swing_mode
<base>/cmd/thermistor_mode
<base>/cmd/digipot_wiper
```

Inbound MQTT commands are validated before they affect LG state or digipot state. Retained command payloads are ignored, and retained command topics are cleared after MQTT reconnect.

Discovery exposes:

- LG climate entity.
- BME280 temperature, humidity, and pressure.
- Thermistor mode select.
- Digipot resistance diagnostic sensor.
- Fault and LG-bus connectivity diagnostics.
- LG error code, defrost, preheat, and outdoor-active diagnostics.

## USB CDC CLI

Open:

```powershell
pio device monitor -b 115200
```

Commands:

```text
help
status
health
uptime
reboot confirm
wifi status
wifi config <ssid> <password>
wifi clear
mqtt status
mqtt config <host> <port> [user] [password]
mqtt clear
lg status
lg trace <on|off>
lg send arm
lg send <13 hex bytes>
lg test
bme status
bme read
digipot status
digipot set arm
digipot set code <0..255>
digipot test
digipot calibrate
ntc calc <temp_c>
led status
led test <r> <g> <b>
i2c scan
config show
config set <key> <value>
config save
config reset
logs level
watchdog status
```

Guarded commands:

- `reboot confirm` requires the `confirm` argument.
- `lg send <13 hex bytes>` requires a prior `lg send arm`.
- `digipot set code <0..255>` requires a prior `digipot set arm`.

The parser is nonblocking and consumes a bounded amount of serial input per loop.

`digipot calibrate` currently prints calibration guidance only. Calibration values are applied through validated configuration fields or firmware constants after hardware verification.

## LG Protocol

The implemented protocol is the modern 13-byte LG wired-controller frame format.

Key behavior:

- 104 baud, 8N1.
- 13-byte fixed frame length.
- Checksum is `(sum(bytes[0..11]) & 0xff) ^ 0x55`.
- No start byte exists, so the parser uses a sliding window.
- TX waits for the bus to be idle/high for at least 500 ms.
- Echo is expected on the single-wire bus and is tracked.
- Unknown or unsupported frame types are parsed but not forced into the climate model.

See `docs/PROTOCOL.md`.

## Virtual Thermistor Calibration

Default thermistor constants are placeholders that are reachable with the MCP45HV51-502E:

```text
Rref: 5000 ohm at 25 C
Beta: 3950 K
Allowed virtual resistance: 1000..5075 ohm
Safe resistance: about 2565 ohm
```

These are not confirmed LG constants.

Before unattended use, verify:

- Original LG sensor type: NTC or PTC.
- Resistance at known temperatures.
- Beta or Steinhart-Hart coefficients.
- MCP45HVX1 A/W/B terminal wiring.
- Series resistance around the digipot.
- Resistance at the LG sensor pins during reset and power loss.

See `docs/DIGIPOT_NTC_EMULATION.md`.

## Status LED States

The status service maps health and connectivity into visible states:

| State | Meaning |
| --- | --- |
| `booting` | Firmware startup. |
| `wifi_connecting` | Wi-Fi not connected. |
| `mqtt_disconnected` | Wi-Fi is up but MQTT is down. |
| `lg_bus_offline` | No fresh LG frames. |
| `normal` | Required services are healthy. |
| `degraded` | A nonfatal sensor or digipot condition exists. |
| `config_mode` | Reserved for local configuration workflow. |
| `fatal` | Fault or safe mode. |

## Documentation Map

| File | Purpose |
| --- | --- |
| `README.md` | Operator and maintainer entry point. |
| `docs/PROTOCOL.md` | LG protocol notes and implemented behavior. |
| `docs/HARDWARE.md` | Pins, devices, topology assumptions, and open hardware checks. |
| `docs/DIGIPOT_NTC_EMULATION.md` | Virtual thermistor math, calibration, and failure behavior. |
| `HARDENING_REPORT.md` | Audit passes, fixes, verification, and remaining risks. |
| `docs/reference/README.md` | Vendored reference documentation inventory and provenance. |
| `docs/audit/LGClimateLink_Pre-Audit_Questionnaire_Answers.md` | Filled pre-audit evidence questionnaire. |
| `Doxyfile` | Doxygen configuration for API documentation. |

Generate API docs with:

```powershell
doxygen Doxyfile
```

Generated HTML is written to `docs/doxygen/html/`.

## Known Hardware Verification Items

These items are intentionally tracked as hardware verification work, not hidden software assumptions:

| Item | Risk | Required check |
| --- | --- | --- |
| I2C SDA/SCL pins | Medium | Confirm schematic or continuity test. |
| LED topology | Low | Confirm one chain or two independent outputs. |
| MCP45HVX1 terminal wiring | High | Measure LG sensor-pin resistance over wiper codes. |
| Series resistors | High | Confirm schematic/BOM and measurement. |
| Original LG sensor curve | High | Measure original sensor or obtain service manual data. |
| TLIN1027 enable polarity | Medium | Confirm schematic and scope bus idle/TX. |
| Reset analog failsafe | High | Measure LG sensor pins during reset, brownout, and watchdog reset. |
| 104 baud UART tolerance | High | Scope real ESP32-S2 TX bit timing and validate with LG traffic. |

## Development Notes

- Keep protocol and conversion logic testable on the native PlatformIO target.
- Keep hardware access in adapter classes.
- Do not add blocking waits to `loop()` services.
- Do not let logging or CLI output participate in LG bus timing.
- Do not update thermistor defaults without recording the measurement source.

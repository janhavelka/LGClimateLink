# LGClimateLink Firmware API

LGClimateLink is organized as a set of small services. Each service owns one part of the device and exposes a narrow API. The main application wires those services together from Arduino `setup()` and `loop()`.

This API documentation is for maintainers. The operator guide is in `README.md`.

## Design Rules

- Keep protocol parsing, climate mapping, settings validation, and digipot math testable on the native PlatformIO target.
- Keep Arduino APIs inside hardware adapters and the top-level application.
- Keep `loop()` responsive. Services should do bounded work and return.
- Treat the virtual thermistor path as safety-critical.
- Validate every external input before it changes LG state, settings, or digipot output.
- Do not let logging, MQTT, Wi-Fi, or CLI output control LG bus timing.

## Service Map

| Namespace | Main types | Role |
| --- | --- | --- |
| `lgcl::lg` | `LgBus`, `FrameParser`, `LgControllerService`, `ClimateState` | LG transport, protocol parsing, and climate state. |
| `lgcl::sensors` | `Bme280Service`, `IBme280Driver` | BME280 polling and freshness management. |
| `lgcl::digipot` | `DigipotService`, `IDigipotDriver`, `NtcCalibration`, `DigipotCalibration` | Virtual thermistor output and MCP45HVX1 control. |
| `lgcl::ha` | `MqttService`, discovery/payload helpers | Home Assistant MQTT Discovery and command validation. |
| `lgcl::status` | `StatusLedService` | Device-state LED indication. |
| `lgcl::health` | `HealthMonitor`, `WatchdogService` | Service health and watchdog feed gating. |
| `lgcl::storage` | `SettingsStore` | Persistent settings with delayed writes. |
| `lgcl::config` | `RuntimeSettings` | Runtime configuration and validation. |
| `lgcl::cli` | `SerialCli`, `ICliHandler` | USB CDC command parsing. |

## Main Data Flow

```text
BME280 sample
  -> Bme280Service freshness and plausibility checks
  -> DigipotService normal/hold/safe/fault state machine
  -> NtcEmulator resistance and wiper conversion
  -> MCP45HVX1 driver write/readback

LG bus bytes
  -> FrameParser
  -> LgClimateModel
  -> LgControllerService
  -> MQTT state and CLI status

MQTT/CLI commands
  -> parser and validation
  -> desired climate state or guarded manual command
  -> LG frame queue or digipot command
```

## Safety Contracts

### LG Bus

`LgBus` validates checksum and frame format before a frame reaches the climate model. `LgControllerService` sends only after the bus has been idle for the configured guard interval. Missing echo is tracked as a health signal.

### Virtual Thermistor

`DigipotService` must never write an unclamped wiper code. On missing or stale BME280 data, it holds the last known safe output only for the configured hold interval, then switches to the configured safe fixed output.

### Watchdog

`WatchdogService` feeds the hardware watchdog only after `HealthMonitor` reports that required services are making progress. A stalled required service should stop watchdog feeding and allow reset.

### Settings

`RuntimeSettings` must validate before use. `SettingsStore` coalesces writes so repeated CLI changes do not wear flash.

## Documentation Inputs

The Doxygen build also includes:

- `docs/PROTOCOL.md`
- `docs/HARDWARE.md`
- `docs/DIGIPOT_NTC_EMULATION.md`

The large vendored reference bundle in `docs/reference/` is intentionally excluded from Doxygen.

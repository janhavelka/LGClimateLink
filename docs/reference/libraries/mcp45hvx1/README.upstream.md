# MCP45HVX1 Driver Library

Production-grade MCP45HVX1 high-voltage I2C digital potentiometer driver for
ESP32 (Arduino/PlatformIO).

## Features

- **Injected I2C transport** - no `Wire` dependency in library code
- **Health monitoring** - READY/DEGRADED/OFFLINE state tracking
- **Volatile register API** - Wiper 0 and TCON0 read/write helpers
- **Wiper commands** - direct write plus documented INC/DEC commands
- **Terminal control** - potentiometer, rheostat, floating wiper, and software shutdown presets
- **General Call helpers** - broadcast wiper/TCON write and wiper INC/DEC frames, with explicit `GCEN` caveats
- **Bus-interface reset hook** - optional board callback for the documented software-reset/bus-release sequence
- **Variant helpers** - 7-bit/8-bit code limits, terminal-current limits, nominal resistance, and position conversion helpers
- **Comprehensive bring-up CLI** - register, terminal, General Call, defaults, and stress commands
- **Deterministic behavior** - no heap allocation in the core driver
- **Settings snapshot** - runtime config, cache, and health counters
- **Native tests** - fake-bus protocol tests for register and command behavior

## Installation

### PlatformIO

```ini
lib_deps =
  https://github.com/janhavelka/MCP45HVX1.git
```

### Manual

Copy `include/MCP45HVX1/` and `src/` to your project. The Quick Start also
uses the optional example Wire adapter from `examples/common/I2cTransport.h`;
copy that file too, or provide equivalent `Config` transport callbacks.

## Quick Start

```cpp
#include <Wire.h>
#include "MCP45HVX1/MCP45HVX1.h"
#include "examples/common/I2cTransport.h"

MCP45HVX1::MCP45HVX1 pot;

void setup() {
  Wire.begin(8, 9);
  Wire.setClock(400000);
  Wire.setTimeOut(50);

  MCP45HVX1::Config cfg;
  cfg.i2cWrite = transport::wireWrite;
  cfg.i2cWriteRead = transport::wireWriteRead;
  cfg.i2cUser = &Wire;
  cfg.i2cAddress = 0x3C;
  cfg.resolution = MCP45HVX1::Resolution::Bits8; // MCP45HV51

  MCP45HVX1::Status st = pot.begin(cfg);
  if (!st.ok()) {
    return;
  }

  pot.writeWiper(0x80);
  pot.setTerminalMode(MCP45HVX1::TerminalMode::Potentiometer);
}

void loop() {
  pot.tick(millis());
}
```

The ready-made Arduino transport adapter used by the example CLI is in
`examples/common/I2cTransport.h`.

## API Reference

### Lifecycle

- `Status begin(const Config& config)` - validate config, read Wiper/TCON, optionally apply configured initial values
- `void tick(uint32_t nowMs)` - no-op reserved hook
- `void end()` - reset driver object state without changing device terminals

### Diagnostics

- `Status probe()` - raw Wiper read without health-counter updates
- `Status recover()` - tracked Wiper/TCON reads to refresh cache and health
- `Status resetI2cState()` - run optional board-provided I2C bus/software-reset callback
- `Status restorePowerOnDefaults()` / `resetToDefaults()` - write documented volatile defaults
- `SettingsSnapshot getSettings()` - config, cache, and health snapshot
- `DeviceInfo getDeviceInfo()` - active address, resolution, nominal RAB, step size, terminal-current limit, defaults

### Wiper

- `Status readWiper(uint8_t& code)`
- `Status writeWiper(uint8_t code)`
- `Status incrementWiper(uint8_t steps = 1)`
- `Status decrementWiper(uint8_t steps = 1)`
- `uint8_t codeFromFraction(float fraction, Resolution resolution)`
- `float fractionFromCode(uint8_t code, Resolution resolution)`
- `Status readWiperFraction(float& fraction)`
- `Status writeWiperFraction(float fraction)`
- `stepResistanceOhms()`, `resistanceBToWOhms()`, `resistanceAToWOhms()` - ideal helper math only
- `maxTerminalCurrentMilliAmps()` - datasheet terminal-current limit by RAB option

### Terminal Control

- `Status readTcon(uint8_t& value)`
- `Status writeTcon(uint8_t value)` - forces reserved bits `[7:4]` high
- `Status setTerminalEnabled(Terminal terminal, bool enabled)`
- `Status getTerminalEnabled(Terminal terminal, bool& enabled)`
- `Status setSoftwareShutdown(bool enabled)`
- `Status getSoftwareShutdown(bool& enabled)`
- `Status setTerminalMode(TerminalMode mode)`
- `Status getTerminalMode(TerminalMode& mode)`
- `Status readTerminalStatus(TerminalStatus& status)`
- `TerminalStatus decodeTcon(uint8_t value)`

`TerminalMode::Custom` is returned for valid TCON bit combinations that do not
match a named preset. It is a decoded state, not a valid argument to
`setTerminalMode()`.

### Direct Register Access

- `Status readRegister(uint8_t reg, uint8_t& value)` - valid registers: `0x00`, `0x04`
- `Status writeRegister(uint8_t reg, uint8_t value)`
- `Status readLastAddress(uint8_t& value)` - uses the documented last-address read

### General Call

- `Status generalCallWriteWiper(uint8_t code)`
- `Status generalCallWriteTcon(uint8_t value)`
- `Status generalCallIncrementWiper()`
- `Status generalCallDecrementWiper()`

The datasheet references a `GCEN` bit but the extracted register location is not
documented. This library sends only the documented General Call frames. Because
General Call ACKs are broadcast and not device-specific, successful General Call
helpers mark the affected local cache entry unknown; call `readSnapshot()` to
verify local state afterward.

## Configuration

| Field | Default | Description |
|---|---:|---|
| `i2cAddress` | `0x3C` | A1=A0=0 address |
| `resolution` | `Bits8` | `Bits8` for MCP45HV51, `Bits7` for MCP45HV31 |
| `resistance` | `R10K` | Nominal RAB option for helper math |
| `allowAlternateAddressRange` | `false` | Opt-in disputed `0x5C-0x5F` address range |
| `i2cTimeoutMs` | `50` | Transport timeout |
| `busReset` | `nullptr` | Optional board callback for I2C bus/software reset |
| `controlUser` | `nullptr` | Context pointer for `busReset` |
| `writeInitialWiper` | `false` | Opt-in Wiper write during `begin()` |
| `initialWiperCode` | `0x7F` | Wiper value used when opt-in write is enabled |
| `writeInitialTcon` | `false` | Opt-in TCON write during `begin()` |
| `initialTcon` | `0xFF` | TCON value used when opt-in write is enabled |
| `requirePowerOnDefaults` | `false` | Require POR/BOR Wiper and TCON defaults during `begin()` |
| `requireReadMsbZero` | `true` | Enforce documented read MSB byte `0x00` |
| `offlineThreshold` | `5` | Consecutive tracked failures before OFFLINE |

## Runtime Model

The core driver is synchronous and transport-agnostic. It does not allocate heap
memory or own an Arduino `Wire` instance; callers inject I2C callbacks through
`Config`. Calls are not internally locked, so share one driver instance from a
single task/thread at a time or serialize access in the application.

The public API is not ISR-oriented. I2C transports, callbacks, and optional bus
reset hooks are expected to run from normal task context where blocking I2C
transactions and timeout handling are acceptable.

Health tracking is latched at `DriverState::OFFLINE`: after the configured
consecutive tracked-failure threshold is reached, normal public I2C operations
return `Err::BUSY` with `Driver is offline; call recover()` and do not call the
I2C transport. `probe()` may still perform a raw presence check without changing
health counters. `resetI2cState()` may run the configured bus-reset callback but
does not by itself mark the device recovered while already OFFLINE. Call
`recover()` to perform tracked Wiper/TCON reads, refresh caches, and return to
READY on success.

## Device Notes

- The implemented registers are `0x00` Wiper 0 and `0x04` TCON0. All other
  addresses are treated as reserved.
- Reads return two bytes on the bus. The driver checks that the first byte is
  `0x00` and returns the second byte as the register value.
- `WLAT` affects the physical wiper update, not I2C command acceptance.
- `SHDN` overrides terminal connectivity but does not corrupt registers.
- `begin()` does not write the analog state by default. Enable the initial-write
  flags only when that startup behavior is intentional.

## Address Note

DS20005304B Rev B Table 6-2 and the official PDF text give fixed address bits
`01111`, so the default address range is `0x3C-0x3F`. The extracted markdown in
`docs/08_variant_differences_and_open_questions.md` records an apparent
`0x5C-0x5F` conflict from command figures. The driver defaults to `0x3C` and
accepts `0x5C-0x5F` only when `Config::allowAlternateAddressRange` is explicitly
enabled for hardware-verification builds. See `ASSUMPTIONS.md`.

Hardware validation should verify the populated A1/A0 address, the WLAT and SHDN
board strap behavior, General Call enablement, and the analog terminal limits for
the selected RAB option. The helper math is idealized and does not include
tolerance, wiper resistance, leakage, INL/DNL, or board-level loading.

## Examples

### 01_basic_bringup_cli

Interactive serial CLI with commands for bus scan, begin/reconfigure,
probe/recover, settings, Wiper/TCON reads and writes, direct register access,
terminal modes, General Call frames, volatile defaults, I2C interface reset, and
stress passes.

Typical commands:

```text
scan
cfg
read
wiper 0x80
frac 0.5
mode bw
term a 0
tcon 0xFF
gc arm
gc inc
dump
drv
```

## Running Tests

The repository `platformio.ini` pins ESP32 example builds to pioarduino
`platform-espressif32` 54.03.20. `Wire` is supplied by the Arduino ESP32
framework; applications that consume this library through `lib_deps` do not need
to add a separate `Wire` dependency.

```bash
python tools/validate.py
pio run -e esp32s3dev
pio run -e esp32s2dev
pio test -e native
python tools/check_cli_contract.py
python tools/check_core_timing_guard.py
python scripts/generate_version.py check
```

## Documentation

- [Assumptions](ASSUMPTIONS.md)
- [Implementation Manual](MCP45HVX1_digital_potentiometer_implementation_manual.md)
- <a href="docs/05_register_map.md">Register Map</a>
- <a href="docs/register_reference.md">Driver Register Reference</a>
- <a href="docs/hardware_validation.md">Hardware Validation Checklist</a>
- <a href="docs/04_protocol_commands_and_transactions.md">Protocol Commands</a>
- <a href="docs/07_initialization_reset_and_operational_notes.md">Initialization Notes</a>
- <a href="docs/releases/v1.0.0.md">Release Notes v1.0.0</a>

## License

MIT License - see [LICENSE](LICENSE) for details.

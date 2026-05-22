# MCP45HVX1 Digital Potentiometer Implementation Manual

This driver follows the workspace-standard I2C library pattern: injected
transport callbacks, explicit `Status` returns, managed lifecycle, health
counters, native fake-bus tests, and example-only Arduino helpers.

## Driver Model

The core library never calls `Wire` directly. Applications provide:

- `Config::i2cWrite`
- `Config::i2cWriteRead`
- `Config::i2cUser`
- `Config::busReset` and `Config::controlUser` for optional board-specific
  I2C interface reset

The example adapter in `examples/common/I2cTransport.h` maps `TwoWire` errors to
the driver `Status` model.

## Initialization

`begin()` validates configuration, reads Wiper 0 and TCON0 using the documented
random-read command format, and caches the values. It does not write the analog
state by default.

Optional startup writes are available:

- `Config::writeInitialWiper`
- `Config::writeInitialTcon`

Use these only when changing the wiper/terminal state during MCU startup is
intentional for the hardware design.

`restorePowerOnDefaults()` explicitly writes the documented volatile defaults:
TCON0 `0xFF` and Wiper 0 `0x7F` for 8-bit parts or `0x3F` for 7-bit parts.
`resetI2cState()` calls the optional board reset callback and does not alter
Wiper/TCON state.

## Register Access

Only two addresses are implemented:

- `0x00`: Volatile Wiper 0, R/W/INC/DEC
- `0x04`: Volatile TCON0, R/W

All other addresses are rejected in software before I2C access. This avoids
intentionally generating the device's documented reserved-address NACK state.

MCP45HVX1 reads return two bytes. The first byte is the compatibility MSB and
should be `0x00`; the second byte is the 8-bit register value.

## Wiper Handling

The configured resolution controls input validation:

- `Resolution::Bits7`: `0x00-0x7F`
- `Resolution::Bits8`: `0x00-0xFF`

`incrementWiper()` and `decrementWiper()` send the documented command-byte-only
INC/DEC frames. The driver cache clamps at full-scale and zero-scale after
successful commands.

`readWiperFraction()` and `writeWiperFraction()` provide normalized `0.0-1.0`
position helpers. `stepResistanceOhms()`, `resistanceBToWOhms()`, and
`resistanceAToWOhms()` are ideal nominal helpers from the configured ordering
option. They do not include analog tolerance terms.

## TCON Handling

TCON reserved bits `[7:4]` are forced high on all driver writes. Public helpers
operate on the documented lower bits:

- `R0HW`: software shutdown when cleared
- `R0A`: P0A terminal connection
- `R0W`: P0W terminal connection
- `R0B`: P0B terminal connection

`decodeTcon()`, `readTerminalStatus()`, and `getTerminalMode()` expose decoded
state for CLI and diagnostics. TCON combinations that are valid but do not match
a named preset decode as `TerminalMode::Custom`; `Custom` is not accepted by
`setTerminalMode()`.

## Health Tracking

Tracked public I2C operations update:

- last success/error timestamp
- last error `Status`
- consecutive failures
- total failures/successes
- READY/DEGRADED/OFFLINE state

`probe()` uses the raw path and does not update health. `recover()` uses tracked
reads so communication failures are visible in health counters.

Semantic readback failures, such as a non-zero read MSB when
`requireReadMsbZero` is enabled, are also recorded as tracked health failures.

## General Call

The driver exposes helpers for the documented General Call frames. It does not
attempt to configure `GCEN` because the register location is not documented in
the available source notes. Successful General Call writes mark the affected
local cache entry unknown because ACKs are broadcast and do not prove the local
configured device executed the command. The CLI requires `gc arm` before each
broadcast command attempt.

## CLI Coverage

The `01_basic_bringup_cli` example exposes practical chip features:

- device setup: `begin`, `addr`, `res`, `rab`, `scan`, `probe`, `recover`
- register operations: `read`, `dump`, `rreg`, `wreg`, `last`
- wiper operations: `wiper`, `frac`, `pos`, `zero`, `mid`, `max`, `inc`, `dec`
- terminal operations: `tcon`, `term`, `shutdown`, `mode`
- diagnostics: `cfg`, `settings`, `drv`, `info`, `selftest`, `stress`,
  `stress_mix`, `iface_reset`
- General Call frames: `gc arm`, `gc disarm`, `gc wiper`, `gc tcon`, `gc inc`,
  `gc dec`

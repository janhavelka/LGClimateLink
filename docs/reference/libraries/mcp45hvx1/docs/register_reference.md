# MCP45HVX1 Register Reference

This is the implementation-facing register summary used by the driver. The
source extraction details remain in `05_register_map.md`.

## Address Summary

Documented 7-bit I2C addresses are `0x3C-0x3F` from A1:A0. The conflicting
`0x5C-0x5F` extraction is accepted only when
`Config::allowAlternateAddressRange` is enabled.

| Address | Name | Access | Reset |
|---:|---|---|---:|
| `0x00` | Volatile Wiper 0 | R/W/INC/DEC | `0x7F` 8-bit, `0x3F` 7-bit |
| `0x04` | Volatile TCON0 | R/W | `0xFF` |

Reserved ranges:

- `0x01-0x03`
- `0x05-0xFF`

The driver rejects reserved addresses before issuing I2C transactions.

## Command Byte

```text
bit 7..4: AD3:AD0 register address
bit 3..2: C1:C0 command
bit 1..0: D9:D8 compatibility bits, written as 0 by this driver
```

Command values:

| C1:C0 | Driver constant | Meaning |
|---:|---|---|
| `00` | `Command::WriteData` | Write register data byte |
| `01` | `Command::Increment` | Increment Wiper 0 |
| `10` | `Command::Decrement` | Decrement Wiper 0 |
| `11` | `Command::ReadData` | Read selected register |

## General Call Commands

The driver sends only the documented General Call command forms and does not
attempt to configure `GCEN`, whose register location is not identified in the
available source notes.

| Command byte | Driver helper | Payload |
|---:|---|---|
| `0x80` | `generalCallWriteWiper()` | One Wiper 0 data byte |
| `0xC0` | `generalCallWriteTcon()` | One TCON0 data byte |
| `0x84` | `generalCallIncrementWiper()` | None |
| `0x88` | `generalCallDecrementWiper()` | None |

Successful General Call helpers mark the affected local cache entry unknown
because an ACK is broadcast and not device-specific.

## TCON0

| Bit | Mask | Name | Meaning when 1 | Meaning when 0 |
|---:|---:|---|---|---|
| `[7:4]` | `0xF0` | Reserved | Read as `1111` | Driver never writes 0 |
| `3` | `0x08` | `R0HW` | Normal operation | Software shutdown |
| `2` | `0x04` | `R0A` | P0A connected | P0A disconnected |
| `1` | `0x02` | `R0W` | P0W connected | P0W disconnected |
| `0` | `0x01` | `R0B` | P0B connected | P0B disconnected |

Implemented lower-bit mask: `0x0F`. Reserved write mask: `0xF0`.

Driver presets:

| Preset | TCON value |
|---|---:|
| Potentiometer | `0xFF` |
| Rheostat B-W | `0xFB` |
| Rheostat A-W | `0xFE` |
| Wiper floating | `0xFD` |
| Software shutdown | `0xF7` |

Valid lower-bit combinations that do not match a named preset decode as
`TerminalMode::Custom`. `Custom` is a read/decode result and is not accepted by
`setTerminalMode()`.

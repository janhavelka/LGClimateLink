# MCP45HVX1 — Register Map

**Source document:** DS20005304B Rev B, June 2023 (Microchip Technology Inc.)
**Read via:** AllDatasheet.com HTML mirror, pages 28–38

---

## Overview

The MCP45HVX1 contains only **volatile** RAM registers. There is **no non-volatile memory (EEPROM or Flash)** accessible via standard commands.

> **Ambiguity:** The datasheet title reads "with Non-Volatile Memory" but the register descriptions and all functional sections describe only volatile RAM. This contradiction is unresolved. See `08_variant_differences_and_open_questions.md`. [Source: DS20005304B, p. 1 (title), p. 35–38 (register descriptions)]

All registers are 8 bits wide. The I²C read protocol returns them as 2 bytes (MSB = 0x00, LSB = actual value) for compatibility with the MCP44XX/MCP45XX/MCP46XX families. [Source: DS20005304B, p. 57]

---

## Memory Map

**TABLE 4-7 / TABLE 7-2** [Source: DS20005304B, p. 35, p. 57]:

| Address | Name | Access | Reset Value | Description |
|---|---|---|---|---|
| 00h | Volatile Wiper 0 | R/W, INC, DEC | 7Fh (8-bit) / 3Fh (7-bit) | Wiper 0 position register |
| 01h–03h | Reserved | — | — | NACK on any command; do not use |
| 04h | Volatile TCON0 | R/W only | FFh | Terminal connection control register |
| 05h–FFh | Reserved | — | — | NACK on any command; do not use |

Notes:
- Increment (INC) and Decrement (DEC) commands are **invalid** on address 04h; they produce a NACK. [Source: DS20005304B, p. 57]
- Reserved addresses at 01h–03h and 05h–FFh generate an error (NACK) on any command. [Source: DS20005304B, p. 57]
- The datasheet shows the address range as 00h–FFh; only 00h and 04h are valid register addresses. [Source: DS20005304B, p. 35, 57]

---

## Register 00h — Volatile Wiper 0

| Field | Register Name | Address | Width | Access | Reset Value |
|---|---|---|---|---|---|
| — | Volatile Wiper 0 | 00h | 8 bits | R/W/INC/DEC | 7Fh (8-bit) or 3Fh (7-bit) |

**Purpose:** Stores the current wiper tap position for Resistor Network 0.

### Bit field description

| Bit(s) | Field | Description |
|---|---|---|
| [7:0] | D[7:0] | Wiper tap code. Valid range: 00h–FFh (8-bit) or 00h–7Fh (7-bit). |

**Note:** The full 8-bit data register width means bits [7:0] are all used for the 8-bit variant (MCP45HV51). For the 7-bit variant (MCP45HV31), only bits [6:0] are significant; bit 7 in the write data is accepted but the effective range is 00h–7Fh. The internal wiper tap clamps at the full-scale value. [Source: DS20005304B, p. 35, 63]

### Reset/default value

| Variant | Resolution | Default (POR/BOR) |
|---|---|---|
| MCP45HV51 | 8-bit (256 taps, 255 resistors) | 7Fh (mid-scale) |
| MCP45HV31 | 7-bit (128 taps, 127 resistors) | 3Fh (mid-scale) |

[Source: DS20005304B, p. 28, p. 76]

### Wiper code to position mapping

| Code | 7-bit Wiper Position | 8-bit Wiper Position |
|---|---|---|
| 7Fh / FFh | Full Scale (W connected to A terminal) | Full Scale (W connected to A terminal) |
| 3Fh / 7Fh | Mid Scale | Mid Scale |
| 00h | Zero Scale (W connected to B terminal) | Zero Scale (W connected to B terminal) |

[Source: DS20005304B, p. 35]

### INC/DEC clamping

- **Increment** at full scale (7Fh for 7-bit; FFh for 8-bit): INC command is ignored; value stays at maximum. [Source: DS20005304B, p. 63]
- **Decrement** at zero scale (00h for both): DEC command is ignored; value stays at 00h. [Source: DS20005304B, p. 64]

### Access notes

- Write: Data written after complete byte transfer and Acknowledge. A mid-transfer Stop/Restart aborts without writing. [Source: DS20005304B, p. 59]
- Read: Returns 2 bytes (0x00, data). Address pointer defaults to 00h after POR/BOR. [Source: DS20005304B, p. 61]
- INC/DEC: Wiper transitions after each command Acknowledge. [Source: DS20005304B, p. 63–64]
- WLAT = High: Wiper position physically held; register write accepted but wiper position update deferred until WLAT goes Low. [Source: DS20005304B, p. 27, 50]

### POR/BOR behavior

TABLE 4-1 through TABLE 4-6 document POR/BOR default wiper values for all 4 RAB variants across both resolutions:

| Device Suffix | RAB (Typical) | Resolution | POR/BOR Wiper Code |
|---|---|---|---|
| -502 | 5 kΩ | 8-bit | 7Fh |
| -502 | 5 kΩ | 7-bit | 3Fh |
| -103 | 10 kΩ | 8-bit | 7Fh |
| -103 | 10 kΩ | 7-bit | 3Fh |
| -503 | 50 kΩ | 8-bit | 7Fh |
| -503 | 50 kΩ | 7-bit | 3Fh |
| -104 | 100 kΩ | 8-bit | 7Fh |
| -104 | 100 kΩ | 7-bit | 3Fh |

All standard variants default to mid-scale (7Fh for 8-bit, 3Fh for 7-bit). [Source: DS20005304B, p. 28–35, p. 76]

Custom POR/BOR wiper values are available via the Non-Standard Customer Authorization Request (NSCAR) process (requires NRE charges and minimum ordering quantities). [Source: DS20005304B, p. 76]

---

## Register 04h — Volatile TCON0 (Terminal Control)

**REGISTER 4-1** [Source: DS20005304B, p. 36]

| Field | Register Name | Address | Width | Access | Reset Value |
|---|---|---|---|---|---|
| — | Volatile TCON0 | 04h | 8 bits | R/W | FFh |

**Purpose:** Controls whether each terminal (P0A, P0W, P0B) is connected to or disconnected from the resistor network. Also controls hardware shutdown mode (R0HW).

### Bit field description

| Bit | Field | Access | Reset | Description |
|---|---|---|---|---|
| [7:4] | Reserved | R | 1111 | Always read as `1111`. Must be written as `1111` (or all 1s) to avoid undefined behavior. The datasheet does not explicitly state "must be written as 1," but the reset is FFh and bits are shown as reserved. |
| 3 | R0HW | R/W | 1 | **Hardware configuration bit.** 1 = Normal operation; 0 = Forces hardware shutdown state (P0A disconnected, P0W shorted to P0B). |
| 2 | R0A | R/W | 1 | **Terminal A connection.** 1 = P0A connected to resistor network; 0 = P0A disconnected. |
| 1 | R0W | R/W | 1 | **Wiper W connection.** 1 = P0W connected to resistor network; 0 = P0W disconnected (open). |
| 0 | R0B | R/W | 1 | **Terminal B connection.** 1 = P0B connected to resistor network; 0 = P0B disconnected. |

[Source: DS20005304B, p. 36]

### TCON bit combinations and resulting states

| R0HW | R0A | R0W | R0B | State Description |
|---|---|---|---|---|
| 1 | 1 | 1 | 1 | Normal operation; all terminals connected |
| 1 | 0 | 1 | 1 | P0A disconnected; W and B connected (rheostat B–W) |
| 1 | 1 | 0 | 1 | P0W disconnected; A and B connected, wiper floating |
| 1 | 1 | 1 | 0 | P0B disconnected; A and W connected (rheostat A–W) |
| 0 | x | x | x | Hardware shutdown: P0A disconnected, P0W shorted to P0B |

[Source: DS20005304B, p. 36]

### TCON vs. SHDN pin interaction

The SHDN hardware pin (active Low) **overrides** the TCON register bits when it is asserted Low:
- SHDN Low: P0A disconnected, P0W shorted to P0B, regardless of TCON settings.
- SHDN High: TCON bits control terminal connectivity.

TCON register values are **not corrupted** when SHDN is asserted; the stored TCON values take effect when SHDN is released (SHDN goes High). [Source: DS20005304B, p. 47]

### INC/DEC inapplicability

INC and DEC commands to address 04h generate a NACK. Only Write and Read are valid for TCON0. [Source: DS20005304B, p. 57]

### Read behavior

Read of TCON0 returns 2 bytes: MSB = 0x00, LSB = current TCON0 value. [Source: DS20005304B, p. 57]

---

## Wiper Register (TABLE 5-2)

The datasheet presents a wiper register description (TABLE 5-2) that maps the wiper code to physical network behavior:

| Code (hex) | Code (decimal) | Wiper (W) Position | RBW (B to W) | RAW (A to W) |
|---|---|---|---|---|
| FFh | 255 | Full Scale (8-bit) | ≈ RAB | ≈ 0 |
| 80h | 128 | 1 step above mid (8-bit) | > ½ RAB | < ½ RAB |
| 7Fh | 127 | Mid Scale (8-bit) / Full Scale (7-bit) | ≈ ½ RAB | ≈ ½ RAB |
| 40h | 64 | 1 step above mid (7-bit) | > ½ RAB | < ½ RAB |
| 3Fh | 63 | Mid Scale (7-bit) | ≈ ½ RAB | ≈ ½ RAB |
| 01h | 1 | 1 above zero | ≈ RS | ≈ RAB − RS |
| 00h | 0 | Zero Scale | ≈ RZS (wiper resistance) | ≈ RAB − RZS |

[Source: DS20005304B, p. 41–42]

Full resistor network formulas are documented in `01_chip_overview.md` and the source datasheet sections 5.1–5.2.

---

## Device Memory Address Pointer

The device maintains an internal "Device Memory Address" pointer that tracks the last valid register address received in a command byte. This pointer is used for Read operations that do not specify an address (last-address reads).

- **Default after POR/BOR:** 00h [Source: DS20005304B, p. 61]
- The pointer is **not corrupted** by Repeated Start or Stop conditions. [Source: DS20005304B, p. 61]
- The pointer is updated only by valid, complete command bytes.

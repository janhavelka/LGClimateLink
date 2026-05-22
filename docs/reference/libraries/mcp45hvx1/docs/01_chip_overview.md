# MCP45HVX1 — Chip Overview

> **Source:** DS20005304B, "MCP45HVX1 Single 7-Bit/8-Bit High-Voltage I2C™ Digital Potentiometer", Rev B, June 2023, Microchip Technology Inc.

---

## 1. Device Identity

**Family name:** MCP45HVX1  
**Manufacturer:** Microchip Technology Inc.  
**Product category:** Single-potentiometer, high-voltage, I2C digital potentiometer with volatile wiper register.

[Source: DS20005304B, p.1]

> **Note on datasheet title:** The title says "with Non-Volatile Memory." However, based on the register map (Section 4.1, p.35), all registers (Wiper and TCON) are implemented in volatile RAM and revert to POR/BOR defaults on power loss. There is no non-volatile (EEPROM) storage documented in DS20005304B. This appears to be a title carry-over; see `08_variant_differences_and_open_questions.md` for this ambiguity.

---

## 2. Family Members

| Part Number | Resolution | Taps | Resistor Steps | Interface | Package Options |
|---|---|---|---|---|---|
| MCP45HV31 | 7-bit | 128 taps | 127 resistors | I2C only | TSSOP-14 (ST), VQFN-20 (MQ) |
| MCP45HV51 | 8-bit | 256 taps | 255 resistors | I2C only | TSSOP-14 (ST), VQFN-20 (MQ) |

[Source: DS20005304B, p.1–2, p.99]

**SPI-interface variants (separate datasheet DS20005207, NOT covered here):**
- MCP41HV31 (7-bit, SPI)
- MCP41HV51 (8-bit, SPI)

[Source: DS20005304B, p.1]

---

## 3. Feature Summary

[Source: DS20005304B, p.1–2]

- Single potentiometer element
- 7-bit (MCP45HV31) or 8-bit (MCP45HV51) resolution
- Resistor options: 5 kΩ, 10 kΩ, 50 kΩ, 100 kΩ (nominal RAB end-to-end resistance)
- High-voltage analog supply: V+ − V- up to 36V (supports single or dual supply)
- Low-voltage digital supply: VL = 1.8V to 5.5V
- I2C interface: Standard mode (100 kHz), Fast mode (400 kHz), High-Speed mode (3.4 MHz)
- I2C address select via A0 and A1 pins; up to 4 devices on one bus
- Hardware Shutdown pin (SHDN, active low): disconnects P0A, connects P0W to P0B
- Wiper Latch (WLAT) pin: synchronizes wiper updates across multiple devices
- Terminal Control Register (TCON): software control of each terminal connection
- Power-on Reset (POR) and Brown-out Reset (BOR): wiper loads to mid-scale, TCON loads to FFh
- General Call support: broadcast write/increment/decrement to all MCP45HVX1 devices on bus
- Operating temperature: −40°C to +125°C (Automotive E-temp grade)
- Packages: TSSOP-14 (14-lead) and VQFN-20 (5 mm × 5 mm, 20-lead with exposed thermal pad)
- ESD protection: HBM ±5 kV, MM ±400 V

---

## 4. Resistor Options and Part Numbers

### 4.1 RAB Resistance Options

| Option Code | Nominal RAB | Max Terminal Current (IT) |
|---|---|---|
| -502 | 5 kΩ | 25 mA |
| -103 | 10 kΩ | 12.5 mA |
| -503 | 50 kΩ | 6.5 mA |
| -104 | 100 kΩ | 6.5 mA |

[Source: DS20005304B, p.1–2, p.42]

### 4.2 Standard Part Number Format

```
MCP4 5 HV X 1 - XXX / ST
 |   | |  | |   |     |
 |   | |  | |   |     Package: ST = TSSOP-14, MQ = VQFN-20
 |   | |  | |   Resistance: 502 = 5kΩ, 103 = 10kΩ, 503 = 50kΩ, 104 = 100kΩ
 |   | |  | Variant: 1 = volatile only
 |   | |  Resolution: 3 = 7-bit, 5 = 8-bit
 |   | High-Voltage
 |   Number of potentiometers: 5 = single, 4 = quad (not this part)
 MCP = Microchip
```

[Source: DS20005304B, p.99]

**Examples:**
- `MCP45HV31-503E/ST` — 7-bit, 50 kΩ, E-temp grade, TSSOP-14
- `MCP45HV51-104E/MQ` — 8-bit, 100 kΩ, E-temp grade, VQFN-20

### 4.3 Automotive Part Number Format

Automotive variants use a different suffix system:

```
MCP4 5 HV X 1 - XXX E / ST  V A O
                              |   |
                              |   Class: O = AEC-Q100 Grade 0 (−40°C to +150°C) 
                                         [Note: operating junction temp still −40°C to +125°C per spec]
                              V = automotive variant designator
```

[Source: DS20005304B, p.100]

> **Note:** The automotive ordering codes add VAO or similar suffixes. The exact automotive ordering table from DS20005304B p.100 should be consulted for the full list of automotive part numbers.

---

## 5. Package Options

| Package Code | Package Type | Lead Count | Die Pad | Thermal Resistance θJA |
|---|---|---|---|---|
| ST | TSSOP-14 | 14 | No exposed pad | 100 °C/W |
| MQ | VQFN-20 | 20 (5 mm × 5 mm) | Exposed pad (EP, pin 21) | 36.1 °C/W |

[Source: DS20005304B, p.3, p.80–95]

**VQFN-20 Exposed Pad (EP):**
- EP is internally connected to V− (analog negative supply).
- Must be connected to V− or left floating. Do NOT connect to DGND.
- The exposed pad significantly improves thermal performance (θJA = 36.1 °C/W vs 100 °C/W for TSSOP-14).

[Source: DS20005304B, p.24, p.80–95]

---

## 6. Supply Architecture

The device uses two separate power supply domains:

| Domain | Pins | Voltage Range | Function |
|---|---|---|---|
| Digital | VL, DGND | VL = 1.8V to 5.5V (relative to DGND) | I2C interface logic, internal digital logic |
| Analog | V+, V− | V+ − V− = 10V to 36V | Resistor network, analog switches |

**Key supply constraints:**
- V+ − V− maximum: 36V (V+ to DGND: −40V to +40V absolute max; V− to DGND: −40V to +40V absolute max)
- VL must be between V− and V+ (digital ground DGND can be anywhere between V− and V+)
- A delta voltage of at least 2.7V between VL and V− is required for serial interface operation at maximum specified frequency
- The resistor network is specified from 20V to 36V (V+ − V−); operation below 20V is outside specified limits
- VL must reach minimum operating voltage before the Wiper register has a valid POR/BOR value

[Source: DS20005304B, p.3–4, p.46]

---

## 7. Key Operating Parameters Summary

| Parameter | Value | Conditions | Source |
|---|---|---|---|
| Digital supply VL | 1.8V to 5.5V | Referenced to DGND | DS20005304B, p.4 |
| Analog supply V+ − V− | 10V to 36V | — | DS20005304B, p.4 |
| Analog supply V+ (absolute max) | 40V | To DGND | DS20005304B, p.3 |
| Analog supply V− (absolute max) | −40V | To DGND | DS20005304B, p.3 |
| I2C frequency | up to 3.4 MHz | HS mode; 100 kHz standard, 400 kHz fast | DS20005304B, p.16 |
| Operating temperature | −40°C to +125°C | Junction temperature | DS20005304B, p.4 |
| ESD (HBM) | ±5 kV | — | DS20005304B, p.3 |
| ESD (MM) | ±400 V | — | DS20005304B, p.3 |
| POR wiper default (8-bit) | 7Fh (mid-scale) | After POR/BOR | DS20005304B, p.29 |
| POR wiper default (7-bit) | 3Fh (mid-scale) | After POR/BOR | DS20005304B, p.29 |
| POR TCON default | FFh | After POR/BOR | DS20005304B, p.30 |

---

## 8. Functional Block Description

The device consists of:
1. **I2C Serial Interface** — receives Write, Read, Increment, Decrement commands
2. **Volatile RAM** — stores wiper position (address 00h) and terminal control (address 04h, TCON)
3. **Resistor Ladder Network** — 127 (7-bit) or 255 (8-bit) equal-value resistor elements connected between Terminal A (P0A) and Terminal B (P0B)
4. **Wiper Switch** — connects Wiper Terminal (P0W) to the appropriate tap point per the wiper register value
5. **Hardware Shutdown Logic** — SHDN pin disconnects P0A and connects P0W to P0B regardless of register state
6. **Wiper Latch (WLAT)** — holds wiper update in shift register; releases to resistor network when WLAT goes low
7. **Level Shifters** — translate digital logic levels to control analog high-voltage switches; require VL − V− ≥ 2.7V for full-speed operation

[Source: DS20005304B, p.31–38, p.41]

---

## 9. Compatibility with Other Microchip Digital Potentiometer Families

- **I2C address:** MCP45HVX1 uses fixed bits `0111 1` (binary). This differs from MCP44XX/MCP45XX/MCP46XX family which uses `0101 1x`. Both families can coexist on the same I2C bus.
- **Command byte format:** Compatible with MCP44XX/MCP45XX/MCP46XX command byte format (bits D9:D8 are present for compatibility but unused by MCP45HVX1).
- **Hardware SHDN pin:** Backwards compatible with MCP42X1 devices.
- **SPI variant:** MCP41HVX1 (SPI interface equivalent, see DS20005207).

[Source: DS20005304B, p.51, p.47, p.1]

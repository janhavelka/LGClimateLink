# MCP45HVX1 — Pinout and Signals

> **Source:** DS20005304B, "MCP45HVX1 Single 7-Bit/8-Bit High-Voltage I2C™ Digital Potentiometer", Rev B, June 2023, Microchip Technology Inc.

---

## 1. Package Overview

Two package options:

| Package Code | Package Type | Lead Count | Exposed Pad |
|---|---|---|---|
| ST | TSSOP-14 | 14 | No |
| MQ | VQFN-20 | 20 + EP (5 mm × 5 mm) | Yes (EP = pin 21, connected to V−) |

[Source: DS20005304B, p.24]

---

## 2. Pin Table

**TABLE 3-1: PINOUT DESCRIPTION FOR THE MCP45HVX1**

[Source: DS20005304B, p.24]

| Pin (TSSOP-14) | Pin (VQFN-20) | Symbol | Type | Buffer Type | Function |
|---|---|---|---|---|---|
| 1 | 1 | VL | P | — | Positive Digital Power Supply Input |
| 2 | 2 | SCL | I | ST | I2C Serial Clock pin |
| 3 | 3 | A1 | I | ST | I2C Address bit 1 |
| 4 | 4 | SDA | I/O | ST | I2C Serial Data pin |
| 5 | 5 | A0 | I | ST | I2C Address bit 0 |
| 6 | 6 | WLAT | I | ST | Wiper Latch Enable (0 = transfer Shift Buffer to Wiper register; 1 = hold in Shift Buffer) |
| 7 | 8, 9, 10, 17, 18, 19, 20 | NC | — | — | Not internally connected |
| 8 | 7 | SHDN | I | ST | Hardware Shutdown (active Low) |
| 9 | 11 | DGND | P | — | Digital Ground |
| 10 | 12 | V− | P | — | Analog Negative Potential Supply |
| 11 | 13 | P0B | I/O | A | Potentiometer 0 Terminal B |
| 12 | 14 | P0W | I/O | A | Potentiometer 0 Wiper Terminal |
| 13 | 15 | P0A | I/O | A | Potentiometer 0 Terminal A |
| 14 | 16 | V+ | P | — | Analog Positive Potential Supply |
| — | 21 | EP | P | — | Exposed Pad (VQFN-20 only); connect to V− or leave floating |

**Legend:** A = Analog; ST = Schmitt Trigger Input; I = Input; O = Output; I/O = Bidirectional; P = Power

**Note (EP):** The VQFN exposed pad is conductively connected to the die substrate. It must be connected to V− or left floating. Do NOT connect to DGND. [Source: DS20005304B, p.24]

---

## 3. Pin Descriptions

### 3.1 VL — Positive Digital Power Supply Input

- Positive supply for the digital logic and I2C interface.
- Range: 1.8V to 5.5V referenced to DGND.
- A decoupling capacitor on VL (to DGND) is recommended.

[Source: DS20005304B, p.25]

### 3.2 DGND — Digital Ground

- Digital ground reference for VL.
- DGND may be at any potential between V− and V+ (inclusive).
- Maximum current out of DGND pin: 100 mA (absolute maximum).

[Source: DS20005304B, p.3, p.25]

### 3.3 V+ — Analog Positive Voltage

- Positive supply for the analog resistor network and high-voltage switches.
- Must be at a higher potential than V−.
- Maximum V+ to DGND: +40V (absolute maximum).
- For fully specified analog performance, V+ must be ≥ 20V relative to V−.

[Source: DS20005304B, p.3, p.25, p.46]

### 3.4 V− — Analog Negative Voltage

- Negative supply for the analog resistor network.
- V− potential must be ≤ DGND potential.
- Maximum V− to DGND: −40V (absolute maximum).
- Maximum current out of V− pin: 100 mA (absolute maximum).

[Source: DS20005304B, p.3, p.25]

### 3.5 SCL — Serial Clock

- I2C serial clock input.
- MCP45HVX1 is an I2C Client (Slave) device; SCL is **input-only**.
- The device does **not** stretch the SCL signal.
- Schmitt Trigger input; active at all VL levels within spec.
- Supports Standard (100 kHz), Fast (400 kHz), and High-Speed (3.4 MHz) modes.

[Source: DS20005304B, p.25, p.51]

### 3.6 SDA — Serial Data

- I2C serial data bidirectional pin.
- Open-drain N-channel driver output (requires external pull-up resistor).
- Input uses Schmitt Trigger.
- Value latched on rising edge of SCL.
- SDA must be stable while SCL is High (except during Start/Stop conditions).
- Implements slope control on output transitions; different for FS vs HS mode.

[Source: DS20005304B, p.25, p.51–52]

### 3.7 A0 — I2C Address Bit 0

- I2C hardware address pin 0.
- Should be tied statically High or Low; not intended to be toggled dynamically.
- Along with A1, allows up to four MCP45HVX1 devices on a single I2C bus.
- Value is sampled/used at POR/BOR.

[Source: DS20005304B, p.25, p.51]

### 3.8 A1 — I2C Address Bit 1

- I2C hardware address pin 1.
- Should be tied statically High or Low.
- Along with A0, allows up to four MCP45HVX1 devices on a single I2C bus.

[Source: DS20005304B, p.25, p.51]

### 3.9 WLAT — Wiper Latch Enable

- Controls when the received wiper value is transferred from the internal Shift Buffer to the Wiper register.
- **WLAT = High:** Transfer from Wiper register to wiper is inhibited. Wiper register can still be updated by I2C commands, but the physical wiper position does not change.
- **WLAT = Low:** Transfer from Wiper register to wiper is permitted.
- Used to synchronize wiper updates to an external event (e.g., zero crossing) or to synchronize multiple potentiometers simultaneously.
- **If WLAT synchronization is not needed, tie WLAT Low.**
- WLAT transition within 10 ns before and 200 ns after the ACK rising edge of SCL is indeterminate (see timing spec 94/95).
- Note: Only inhibits transfer from Wiper register to the wiper; I2C communication continues normally.
- Note: When WLAT goes active, data transferred to wiper will not be corrupted if an active I2C command is loading the Wiper Register Buffer simultaneously.

[Source: DS20005304B, p.25, p.27, p.33–34]

### 3.10 SHDN — Hardware Shutdown (Active Low)

- Forces the resistor network terminals into hardware shutdown state when Low.
- **SHDN = Low (active):**
  - P0A terminal is disconnected (open).
  - P0W terminal is simultaneously connected to P0B terminal.
  - Serial interface is NOT disabled; all I2C commands continue to execute.
  - Volatile Wiper register and TCON register values are NOT corrupted.
  - TCON register bits R0A, R0W, R0B are overridden (ignored) while SHDN is Low.
- **SHDN = High (inactive):**
  - Device returns to wiper setting specified by the volatile wiper value.
  - TCON register bits return to controlling terminal connection state.
- SHDN pin overrides TCON register bits; SHDN does not modify TCON register state.
- Backwards compatible with MCP42X1 devices.

[Source: DS20005304B, p.25, p.27–28, p.32, p.47]

### 3.11 P0B — Potentiometer 0 Terminal B

- Connected to internal potentiometer's Terminal B.
- Wiper at zero-scale (code = 00h for both 7-bit and 8-bit): P0W connects to this terminal.
- No polarity restriction relative to P0W or P0A.
- Voltage must be between V+ and V−.

[Source: DS20005304B, p.25]

### 3.12 P0W — Potentiometer 0 Wiper Terminal

- Connected to the internal potentiometer's adjustable tap (Wiper).
- No polarity restriction relative to P0A or P0B.
- Voltage must be between V+ and V−.
- **Power-up behavior:**
  - If V+ powers up **before** VL: wiper is forced to mid-scale after the analog POR threshold is crossed.
  - If V+ powers up **after** VL has exceeded the digital POR threshold: wiper is set to the value in the Wiper register after the analog POR threshold is crossed.

[Source: DS20005304B, p.25–26]

### 3.13 P0A — Potentiometer 0 Terminal A

- Connected to internal potentiometer's Terminal A.
- Wiper at full-scale (code = FFh for 8-bit, 7Fh for 7-bit): P0W connects to this terminal.
- No polarity restriction relative to P0W or P0B.
- Voltage must be between V+ and V−.

[Source: DS20005304B, p.26]

### 3.14 EP — Exposed Pad (VQFN-20 Only)

- Conductively connected to the die substrate.
- Must be connected to V− or left floating.
- Can optionally be connected to a PCB heatsink area for improved thermal dissipation.
- Do NOT connect to DGND.
- Significantly improves thermal performance: θJA = 36.1 °C/W vs 100 °C/W for TSSOP-14.

[Source: DS20005304B, p.26, p.80–95]

### 3.15 NC — Not Connected

- Not internally connected to the die.
- In TSSOP-14: pin 7 is NC.
- In VQFN-20: pins 8, 9, 10, 17, 18, 19, 20 are NC.
- Recommendation: connect NC pins to VL or DGND to reduce noise coupling.

[Source: DS20005304B, p.26]

---

## 4. Electrical Summary for Digital Pins

| Parameter | Symbol | Min | Max | Units | Conditions |
|---|---|---|---|---|---|
| Schmitt Trigger High-Input Threshold | VIH | 0.7 × VL | VL + 0.3V | V | 1.8V ≤ VL ≤ 5.5V |
| Schmitt Trigger Low-Input Threshold | VIL | DGND − 0.5V | 0.3 × VL | V | — |
| Hysteresis | VHYS | 0.1 × VL | — | V | — |
| Output Low Voltage (SDA only) | VOL | DGND | 0.2 × VL | V | VL = 5.5V, IOL = 5 mA |
| Output Low Voltage (SDA only) | VOL | DGND | 0.2 × VL | V | VL = 1.8V, IOL = 800 µA |
| Input Leakage Current | IIL | −1 | +1 | µA | VIN = VL or VIN = DGND |
| Digital Pin Capacitance | CIN, COUT | — | 10 | pF | fC = 400 kHz |

[Source: DS20005304B, p.13]

---

## 5. Electrical Summary for Analog Pins (P0A, P0W, P0B)

| Parameter | Symbol | Value | Units | Conditions |
|---|---|---|---|---|
| Terminal Voltage Range | VA, VW, VB | V− to V+ | V | No polarity restriction between terminals |
| Max Terminal Current (−502, 5 kΩ) | IT | 25 | mA | IBW (W ≠ ZS) and IAW (W ≠ FS) |
| Max Terminal Current (−103, 10 kΩ) | IT | 12.5 | mA | — |
| Max Terminal Current (−503, 50 kΩ) | IT | 6.5 | mA | — |
| Max Terminal Current (−104, 100 kΩ) | IT | 6.5 | mA | — |
| Max Terminal Current (W = ZS or W = FS) | IT | 36 | mA | IBW (W = ZS) or IAW (W = FS) |
| Leakage Current | ITL | 5 | nA | A = W = B = V− |
| Capacitance PA | CA | 75 | pF | Measured to V−, f = 1 MHz, mid-scale code |
| Capacitance PW | CW | 120 | pF | Measured to V−, f = 1 MHz, mid-scale code |
| Capacitance PB | CB | 75 | pF | Measured to V−, f = 1 MHz, mid-scale code |
| Common-Mode Leakage | ICM | 5 | nA | VA = VB = VW |

[Source: DS20005304B, p.6, p.13]

---

## 6. Package-Specific Notes

### TSSOP-14 (ST)
- 14 leads, 0.65 mm pitch.
- Pin 7 is NC; connect to DGND or VL to reduce noise.
- No exposed pad.
- θJA = 100 °C/W, max power dissipation at TA = +50°C, TJ = +150°C: 1000 mW.

[Source: DS20005304B, p.3, p.80–95]

### VQFN-20 (MQ)
- 20 leads + exposed pad (EP, pin 21), 5 mm × 5 mm body.
- Pins 8, 9, 10, 17, 18, 19, 20 are NC; connect to DGND or VL to reduce noise.
- EP (pin 21) must connect to V− or float; do NOT connect to DGND.
- θJA = 36.1 °C/W, max power dissipation at TA = +50°C, TJ = +150°C: 2800 mW.
- Better thermal performance than TSSOP-14 for high-current applications.

[Source: DS20005304B, p.3, p.24, p.80–95]

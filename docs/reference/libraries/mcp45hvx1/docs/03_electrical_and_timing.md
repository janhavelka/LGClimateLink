# MCP45HVX1 — Electrical and Timing Characteristics

> **Source:** DS20005304B, "MCP45HVX1 Single 7-Bit/8-Bit High-Voltage I2C™ Digital Potentiometer", Rev B, June 2023, Microchip Technology Inc.

---

## 1. Absolute Maximum Ratings

> ⚠ Stresses above those listed may cause permanent damage to the device. Functional operation at these conditions is not implied.

[Source: DS20005304B, p.3]

| Parameter | Min | Max | Units |
|---|---|---|---|
| Voltage on V− w.r.t. DGND | DGND + 0.6V | −40.0 | V |
| Voltage on V+ w.r.t. DGND | DGND − 0.3V | +40.0 | V |
| Voltage on V+ w.r.t. V− | DGND − 0.3V | +40.0 | V |
| Voltage on VL w.r.t. V+ | −0.6 | −40.0 | V |
| Voltage on VL w.r.t. V− | −0.6 | +40.0 | V |
| Voltage on VL w.r.t. DGND | −0.6 | +7.0 | V |
| Voltage on SCL, SDA, A0, A1, WLAT, SHDN w.r.t. DGND | −0.6 | VL + 0.6 | V |
| Voltage on P0A, P0W, P0B w.r.t. V− | −0.3 | V+ + 0.3 | V |
| Input clamp current IIK | — | ±20 | mA |
| Output clamp current IOK | — | ±20 | mA |
| Max current out of DGND pin | — | 100 | mA |
| Max current into VL pin | — | 100 | mA |
| Max current out of V− pin | — | 100 | mA |
| Max current into V+ pin | — | 100 | mA |
| Max continuous current into P0A, P0W, P0B (−502, 5 kΩ) | — | ±25 | mA |
| Max continuous current into P0A, P0W, P0B (−103, 10 kΩ) | — | ±12.5 | mA |
| Max continuous current into P0A, P0W, P0B (−503, 50 kΩ) | — | ±6.5 | mA |
| Max continuous current into P0A, P0W, P0B (−104, 100 kΩ) | — | ±6.5 | mA |
| Max output current sunk by any output pin | — | 25 | mA |
| Max output current sourced by any output pin | — | 25 | mA |
| Package power dissipation (TA = +50°C, TJ = +150°C) — TSSOP-14 | — | 1000 | mW |
| Package power dissipation (TA = +50°C, TJ = +150°C) — VQFN-20 | — | 2800 | mW |
| Soldering temperature of leads (10 s) | — | +300 | °C |
| ESD (HBM) all pins | — | ±5 | kV |
| ESD (MM) all pins | — | ±400 | V |
| Maximum junction temperature TJ | — | 150 | °C |
| Storage temperature | −65 | +150 | °C |

**Note (pulsed current):** For pulsed currents at FPULSE > 10 kHz: Max I(continuous) / Duty Cycle; for FPULSE ≤ 10 kHz: same formula applies. [Source: DS20005304B, p.3]

---

## 2. Recommended DC Operating Conditions

> Standard Operating Conditions: TA = −40°C to +125°C; V+ = 10V to 36V (ref V−) or ±5V to ±18V; VL = +2.7V to 5.5V; Typical values at VL = 5.5V, TA = +25°C.

[Source: DS20005304B, p.4–5]

### 2.1 Supply Voltages

| Parameter | Symbol | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| Digital Positive Supply (ref DGND) | VL | 2.7 | — | 5.5 | V | Note 4 |
| Digital Positive Supply (ref DGND, if VL ≥ V− + 2.7V) | VL | 1.8 | — | 5.5 | V | Note 1, 4 |
| Digital Supply (ref V+) | VL | — | — | 0 | V | — |
| Analog Positive Supply (ref V−) | V+ | VL (Note 16) | — | 36.0 | V | Note 4 |
| Digital Ground Voltage (ref V−) | VDGND | V− | — | V+ − VL | V | Note 4, 5 |
| Analog Negative Supply (ref DGND, VL = 1.8V) | V− | −36.0 + VL | — | 0 | V | — |
| Resistor Network Supply Voltage (V+ − V−) | VRN | — | — | 36.0 | V | Note 4 |

**Notes:**
1. By design.
4. V+ voltage is dependent on V−; max delta is 36V; DGND can be anywhere between V+ and V−; VL must be ≥ DGND and ≤ V+.
5. Minimum value: 36V − 1.8V = 34.2V.
16. For specified analog performance, V+ must be ≥ 20V unless otherwise noted.
18. During power-up, to ensure expected analog POR operation, the two power systems should have a common reference so that the driven DGND voltage is **not at a higher potential** than the driven V+ voltage. [Source: DS20005304B, p. 15]

### 2.2 Power-Up / BOR / POR Voltage Thresholds

| Parameter | Symbol | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| VL Start voltage to ensure Wiper Reset (DPOR) | VDPOR | — | — | 1.8 | V | Re DGND; V+ > 6.0V; VRAM < VDBOR |
| V+ Voltage to ensure Wiper Reset (APOR) | VAPOR | — | — | 6.0 | V | Re V−; VL = 0V; VRAM < VBOR |
| Digital-to-Analog Level Shifter Operational Voltage | VLS | — | — | 2.3 | V | VL to V− voltage; DGND = V− |
| VL during power-up (digital powers up first) | VLPOR | — | — | 5.5 | V | — |
| V+ during power-up (analog powers up first) | V+POR | — | — | 36 | V | — |
| VL Rise Rate to ensure POR | VLRR | — | — | — | V/ms | POR/BOR is NOT rate-dependent (Note 6) |
| Delay after device exits Reset state (VL > VBOR) | TBORD | — | 10 | 20 | µs | — |

**Note 6:** POR/BOR is not rate-dependent.

---

## 3. DC Characteristics — Supply Current

[Source: DS20005304B, p.5]

| Parameter | Symbol | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| Digital supply current (serial interface active) | IDDD | — | 45 | 650 | µA | Serial interface active, write 0s to Wiper 0 (addr 00h), VL = 5.5V, FSCL = 3.4 MHz, V− = DGND |
| Digital supply current (serial interface inactive) | IDDD | — | 4 | 7 | µA | Serial interface inactive, VL = 5.5V, SCL = VIH, Wiper = 0, V− = DGND |
| Analog supply current | IDDA | — | — | 5 | µA | V+ to V−; P0A = P0B = P0W; DGND = V− + (V+/2) |

> **Note 7:** Supply current (IDDD and IDDA) is independent of current through the resistor network. [Source: DS20005304B, p.15]

---

## 4. DC Characteristics — Resistor Network

[Source: DS20005304B, p.5–6]

### 4.1 RAB End-to-End Resistance

| Device Code | Symbol | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| −502 (5 kΩ) | RAB | 4.0 | 5 | 6.0 | kΩ | V+/V− = 10V to 36V (Note 8) |
| −103 (10 kΩ) | RAB | 8.0 | 10 | 12.0 | kΩ | — |
| −503 (50 kΩ) | RAB | 40.0 | 50 | 60.0 | kΩ | — |
| −104 (100 kΩ) | RAB | 80.0 | 100 | 120.0 | kΩ | — |

**Note 8:** RAB = resistance Terminal A to Terminal B. Tolerance is ±20%.

### 4.2 RAB Current (IAB)

| Device Code | IAB (Max) | Units | Conditions |
|---|---|---|---|
| −502 (5 kΩ) | 9.00 | mA | 36V / RAB(MIN); V− = −18V, V+ = +18V |
| −103 (10 kΩ) | 4.50 | mA | — |
| −503 (50 kΩ) | 0.90 | mA | — |
| −104 (100 kΩ) | 0.45 | mA | — |

**Note 9:** Ensured by RAB specification and Ohm's Law.

### 4.3 Resolution

| Parameter | Symbol | Value | Units | Notes |
|---|---|---|---|---|
| Resolution (8-bit) | N | 256 | Taps | No Missing Codes |
| Resolution (7-bit) | N | 128 | Taps | No Missing Codes |
| Step Resistance (8-bit simplified) | RS | RAB / 255 | Ω | By design (Note 1) |
| Step Resistance (7-bit simplified) | RS | RAB / 127 | Ω | By design (Note 1) |

### 4.4 Wiper Resistance

| Conditions | Symbol | Typ | Max | Units |
|---|---|---|---|---|
| IW = 1 mA; V+ = +18V; V− = −18V; code = 00h; P0A floating; P0B = V− | RW | 75 | 170 | Ω |
| IW = 1 mA; V+ = +5.0V; V− = −5.0V; code = 00h; P0A floating; P0B = V− | RW | 145 | 200 | Ω |

**Note (±5V condition):** Not tested; specified by characterization. [Source: DS20005304B, p.6]

**Note on RW variability:** Wiper resistance depends on V+/V− voltage, terminal voltages, wiper code, RAB resistance, and temperature. At higher temperatures (+125°C) and larger RAB (50 kΩ, 100 kΩ), analog switch leakage causes increased RW. [Source: DS20005304B, p.41]

### 4.5 Temperature Coefficients

| Parameter | Symbol | Typ | Units | Conditions |
|---|---|---|---|---|
| Nominal Resistance Tempco (RAB) | RAB/ΔT | 50 | ppm/°C | TA = −40°C to +85°C |
| Nominal Resistance Tempco (RAB) | RAB/ΔT | 100 | ppm/°C | TA = −40°C to +125°C |
| Ratiometric Tempco | VBW/ΔT | 15 | ppm/°C | Code = mid-scale (7Fh or 3Fh) |

[Source: DS20005304B, p.6]

### 4.6 Terminal Voltage and Current Limits

| Parameter | Symbol | Min | Max | Units | Conditions |
|---|---|---|---|---|---|
| Resistor Terminal Input Voltage (A, B, W) | VA, VW, VB | V− | V+ | V | Note 1, Note 11 |
| Max Terminal Current (−502, 5 kΩ) | IT, IW | — | 25 | mA | IBW (W ≠ ZS) and IAW (W ≠ FS) |
| Max Terminal Current (−103, 10 kΩ) | IT, IW | — | 12.5 | mA | — |
| Max Terminal Current (−503, 50 kΩ) | IT, IW | — | 6.5 | mA | — |
| Max Terminal Current (−104, 100 kΩ) | IT, IW | — | 6.5 | mA | — |
| Max Terminal Current (W = ZS or FS) | IT | — | 36 | mA | IBW (W = ZS) or IAW (W = FS) |
| Leakage Current into A, W, or B | ITL | — | 5 | nA | A = W = B = V− |

**Note 11:** Resistor terminal polarity w.r.t. each other is not restricted.

---

## 5. DC Characteristics — Potentiometer Accuracy (Potentiometer Configuration)

> VA = V+, VB = V−. Full-Scale code: 8-bit = FFh, 7-bit = 7Fh. Zero-Scale code: 00h for both.

### 5.1 Full-Scale Error (VWFSE)

[Source: DS20005304B, p.7]

| Device | Resolution | Min | Units | Conditions |
|---|---|---|---|---|
| 5 kΩ | 8-bit | −10.5 | LSb | VAB = 20V to 36V |
| 5 kΩ | 8-bit | −8.5 | LSb | VAB = 20V to 36V; −40°C ≤ TA ≤ +85°C (Note 2) |
| 5 kΩ | 8-bit | −14.0 | LSb | VAB = 10V to 36V |
| 5 kΩ | 7-bit | −5.5 | LSb | VAB = 20V to 36V |
| 5 kΩ | 7-bit | −4.5 | LSb | VAB = 20V to 36V; −40°C ≤ TA ≤ +85°C (Note 2) |
| 5 kΩ | 7-bit | −7.5 | LSb | VAB = 10V to 36V |
| 10 kΩ | 8-bit | −4.5 | LSb | VAB = 20V to 36V |
| 10 kΩ | 8-bit | −6.0 | LSb | VAB = 10V to 36V |
| 10 kΩ | 7-bit | −2.65 | LSb | VAB = 20V to 36V |
| 10 kΩ | 7-bit | −2.25 | LSb | VAB = 20V to 36V; −40°C ≤ TA ≤ +85°C (Note 2) |
| 10 kΩ | 7-bit | −3.5 | LSb | VAB = 10V to 36V |
| 50 kΩ | 8-bit | −1.0 | LSb | VAB = 20V to 36V |
| 50 kΩ | 8-bit | −1.4 | LSb | VAB = 10V to 36V |
| 50 kΩ | 7-bit | −1.0 | LSb | VAB = 20V to 36V |
| 50 kΩ | 7-bit | −1.2 | LSb | VAB = 10V to 36V |
| 100 kΩ | 8-bit | −0.7 | LSb | VAB = 20V to 36V |
| 100 kΩ | 8-bit | −0.95 | LSb | VAB = 10V to 36V |
| 100 kΩ | 7-bit | −0.85 | LSb | VAB = 20V to 36V |
| 100 kΩ | 7-bit | −0.975 | LSb | VAB = 10V to 36V |

**Note 2:** Not tested; specified by characterization. **Note 17:** Analog switch leakage affects this spec.

### 5.2 Zero-Scale Error (VWZSE)

[Source: DS20005304B, p.8]

| Device | Resolution | Max | Units | Conditions |
|---|---|---|---|---|
| 5 kΩ | 8-bit | +9.5 | LSb | VAB = 20V to 36V |
| 5 kΩ | 8-bit | +8.5 | LSb | VAB = 20V to 36V; −40°C ≤ TA ≤ +85°C (Note 2) |
| 5 kΩ | 8-bit | +14.5 | LSb | VAB = 10V to 36V |
| 5 kΩ | 7-bit | +4.5 | LSb | VAB = 20V to 36V |
| 5 kΩ | 7-bit | +7.0 | LSb | VAB = 10V to 36V |
| 10 kΩ | 8-bit | +4.25 | LSb | VAB = 20V to 36V |
| 10 kΩ | 8-bit | +6.5 | LSb | VAB = 10V to 36V |
| 10 kΩ | 7-bit | +2.125 | LSb | VAB = 20V to 36V |
| 10 kΩ | 7-bit | +3.25 | LSb | VAB = 10V to 36V |
| 50 kΩ | 8-bit | +0.9 | LSb | VAB = 20V to 36V |
| 50 kΩ | 8-bit | +1.3 | LSb | VAB = 10V to 36V |
| 50 kΩ | 7-bit | +0.5 | LSb | VAB = 20V to 36V |
| 50 kΩ | 7-bit | +0.7 | LSb | VAB = 10V to 36V |
| 100 kΩ | 8-bit | +0.6 | LSb | VAB = 20V to 36V |
| 100 kΩ | 8-bit | +0.95 | LSb | VAB = 10V to 36V |
| 100 kΩ | 7-bit | +0.3 | LSb | VAB = 20V to 36V |
| 100 kΩ | 7-bit | +0.475 | LSb | VAB = 10V to 36V |

### 5.3 Potentiometer INL (P-INL)

[Source: DS20005304B, p.9]

| Device | Resolution | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| 5 kΩ | 8-bit | −1 | ±0.5 | +1 | LSb | VAB = 10V to 36V |
| 5 kΩ | 7-bit | −0.5 | ±0.25 | +0.5 | LSb | VAB = 10V to 36V |
| 10 kΩ | 8-bit | −1 | ±0.5 | +1 | LSb | VAB = 10V to 36V |
| 10 kΩ | 7-bit | −0.5 | ±0.25 | +0.5 | LSb | VAB = 10V to 36V |
| 50 kΩ | 8-bit | −1.1 | ±0.5 | +1.1 | LSb | VAB = 10V to 36V |
| 50 kΩ | 8-bit | −1 | ±0.5 | +1 | LSb | VAB = 20V to 36V (Note 2) |
| 50 kΩ | 7-bit | −0.6 | ±0.25 | +0.6 | LSb | VAB = 10V to 36V |
| 100 kΩ | 8-bit | −1.85 | ±0.5 | +1.85 | LSb | VAB = 10V to 36V |
| 100 kΩ | 8-bit | −1.2 | ±0.5 | +1.2 | LSb | VAB = 20V to 36V (Note 2) |
| 100 kΩ | 7-bit | −1 | ±0.5 | +1 | LSb | VAB = 10V to 36V |

### 5.4 Potentiometer DNL (P-DNL)

[Source: DS20005304B, p.9]

| Device | Resolution | Min | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| 5 kΩ | 8-bit | −0.7 | ±0.25 | +0.7 | LSb | VAB = 10V to 36V |
| 5 kΩ | 7-bit | −0.25 | ±0.125 | +0.25 | LSb | VAB = 10V to 36V |
| 10 kΩ | 8-bit | −0.375 | ±0.125 | +0.375 | LSb | VAB = 10V to 36V |
| 10 kΩ | 7-bit | −0.25 | ±0.1 | +0.25 | LSb | VAB = 10V to 36V |
| 50 kΩ | 8-bit | −0.25 | ±0.125 | +0.25 | LSb | VAB = 10V to 36V |
| 50 kΩ | 7-bit | −0.125 | ±0.1 | +0.125 | LSb | VAB = 10V to 36V |
| 100 kΩ | 8-bit | −0.25 | ±0.125 | +0.25 | LSb | VAB = 10V to 36V |
| 100 kΩ | 7-bit | −0.125 | ±0.1 | +0.125 | LSb | VAB = 10V to 36V |

---

## 6. DC Characteristics — Rheostat Accuracy (Rheostat Configuration)

> Notes 12, 13, 14, 17 apply: Nonlinearity affected by RW over voltage and temperature; measured in RBW rheostat configuration; IW condition determined by RAB(max) and specified voltage.

### 6.1 Rheostat INL (R-INL)

[Source: DS20005304B, p.11]

| Device | Resolution | Min | Max | Units | Conditions |
|---|---|---|---|---|---|
| 5 kΩ | 8-bit | −2.0 | +2.0 | LSb | IW = 6.0 mA; (V+ − V−) = 36V (Note 2) |
| 5 kΩ | 8-bit | −2.5 | +2.5 | LSb | IW = 3.3 mA; 20V (Note 2) |
| 5 kΩ | 8-bit | −4.5 | +4.5 | LSb | IW = 1.7 mA; 10V |
| 5 kΩ | 7-bit | −1.0 | +1.0 | LSb | IW = 6.0 mA; 36V (Note 2) |
| 5 kΩ | 7-bit | −1.5 | +1.5 | LSb | IW = 3.3 mA; 20V (Note 2) |
| 5 kΩ | 7-bit | −2.0 | +2.0 | LSb | IW = 1.7 mA; 10V |
| 10 kΩ | 8-bit | −1.2 | +1.2 | LSb | IW = 3.0 mA; 36V (Note 2) |
| 10 kΩ | 8-bit | −1.75 | +1.75 | LSb | IW = 1.7 mA; 20V (Note 2) |
| 10 kΩ | 8-bit | −2.0 | +2.0 | LSb | IW = 830 µA; 10V |
| 10 kΩ | 7-bit | −0.6 | +0.6 | LSb | IW = 3.0 mA; 36V (Note 2) |
| 10 kΩ | 7-bit | −0.8 | +0.8 | LSb | IW = 1.7 mA; 20V (Note 2) |
| 10 kΩ | 7-bit | −1.1 | +1.1 | LSb | IW = 830 µA; 10V |
| 50 kΩ | 8-bit | −1.0 | +1.0 | LSb | IW = 600 µA; 36V (Note 2) |
| 50 kΩ | 8-bit | −1.0 | +1.0 | LSb | IW = 330 µA; 20V (Note 2) |
| 50 kΩ | 8-bit | −1.2 | +1.2 | LSb | IW = 170 µA; 10V |
| 50 kΩ | 7-bit | −0.5 | +0.5 | LSb | IW = 600 µA; 36V (Note 2) |
| 50 kΩ | 7-bit | −0.5 | +0.5 | LSb | IW = 330 µA; 20V (Note 2) |
| 50 kΩ | 7-bit | −0.6 | +0.6 | LSb | IW = 170 µA; 10V |
| 100 kΩ | 8-bit | −1.0 | +1.0 | LSb | IW = 300 µA; 36V (Note 2) |
| 100 kΩ | 8-bit | −1.0 | +1.0 | LSb | IW = 170 µA; 20V (Note 2) |
| 100 kΩ | 8-bit | −1.2 | +1.2 | LSb | IW = 83 µA; 10V |
| 100 kΩ | 7-bit | −0.5 | +0.5 | LSb | IW = 300 µA; 36V (Note 2) |
| 100 kΩ | 7-bit | −0.5 | +0.5 | LSb | IW = 170 µA; 20V (Note 2) |
| 100 kΩ | 7-bit | −0.6 | +0.6 | LSb | IW = 83 µA; 10V |

### 6.2 Rheostat DNL (R-DNL)

[Source: DS20005304B, p.12]

| Device | Resolution | Min | Max | Units | Conditions |
|---|---|---|---|---|---|
| 5 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 6.0 mA; 36V (Note 2) |
| 5 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 3.3 mA; 20V (Note 2) |
| 5 kΩ | 8-bit | −0.8 | +0.8 | LSb | IW = 1.7 mA; 10V |
| 5 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 6.0 mA; 36V (Note 2) |
| 5 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 3.3 mA; 20V (Note 2) |
| 5 kΩ | 7-bit | −0.4 | +0.4 | LSb | IW = 1.7 mA; 10V |
| 10 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 3.0 mA; 36V (Note 2) |
| 10 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 1.7 mA; 20V (Note 2) |
| 10 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 830 µA; 10V |
| 10 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 3.0 mA; 36V (Note 2) |
| 10 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 1.7 mA; 20V (Note 2) |
| 10 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 830 µA; 10V |
| 50 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 600 µA; 36V (Note 2) |
| 50 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 330 µA; 20V (Note 2) |
| 50 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 170 µA; 10V |
| 50 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 600 µA; 36V (Note 2) |
| 50 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 330 µA; 20V (Note 2) |
| 50 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 170 µA; 10V |
| 100 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 300 µA; 36V (Note 2) |
| 100 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 170 µA; 20V (Note 2) |
| 100 kΩ | 8-bit | −0.5 | +0.5 | LSb | IW = 83 µA; 10V |
| 100 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 300 µA; 36V (Note 2) |
| 100 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 170 µA; 20V (Note 2) |
| 100 kΩ | 7-bit | −0.25 | +0.25 | LSb | IW = 83 µA; 10V |

---

## 6.3 Terminal Resistance Network Capacitance

[Source: DS20005304B, p. 13]

> Standard Operating Conditions: TA = −40°C to +125°C; VL = 2.7V to 5.5V.

| Parameter | Symbol | Typ | Units | Conditions |
|---|---|---|---|---|
| Capacitance, Terminal A (P0A) | CA | 75 | pF | Measured to V−; f = 1 MHz; Wiper code = mid scale |
| Capacitance, Wiper (P0W) | CW | 120 | pF | Measured to V−; f = 1 MHz; Wiper code = mid scale |
| Capacitance, Terminal B (P0B) | CB | 75 | pF | Measured to V−; f = 1 MHz; Wiper code = mid scale |
| Common-Mode Leakage | ICM | 5 | nA | VA = VB = VW |
| Digital I/O Pin Capacitance (input/output) | CIN, COUT | 10 | pF | fC = 400 kHz |

> No Max values are stated in the source for CA, CW, CB or ICM. CIN/COUT are given as typical only. [Source: DS20005304B, p. 13]

---

## 6.4 Digital I/O Specifications — SDA, SCL, A0, A1, SHDN, WLAT

[Source: DS20005304B, p. 13]

> Applies to all digital input/output pins: SDA, SCL, A0, A1, SHDN, WLAT.

| Parameter | Symbol | Min | Max | Units | Conditions |
|---|---|---|---|---|---|
| Schmitt Trigger High-Input Threshold | VIH | 0.7 × VL | VL + 0.3 | V | 1.8 V ≤ VL ≤ 5.5 V |
| Schmitt Trigger Low-Input Threshold | VIL | DGND − 0.5 | 0.3 × VL | V | — |
| Hysteresis of Schmitt Trigger Inputs | VHYS | 0.1 × VL | — | V | — |
| Output Low Voltage (SDA only) | VOL | DGND | 0.2 × VL | V | VL = 5.5 V; IOL = 5 mA |
| Output Low Voltage (SDA only) | VOL | DGND | 0.2 × VL | V | VL = 1.8 V; IOL = 800 µA |
| Input Leakage Current | IIL | −1 | +1 | µA | VIN = VL and VIN = DGND |

> SDA is the only digital output pin. All other digital signals (SCL, A0, A1, SHDN, WLAT) are input-only. The 0.2 × VL formula means VOL scales with VL; at VL = 5.5 V this gives 1.1 V max VOL (at 5 mA), at VL = 1.8 V this gives 0.36 V max VOL (at 800 µA). [Source: DS20005304B, p. 13]

---

## 7. DC Characteristics — Bandwidth and Settling Time

[Source: DS20005304B, p.10, p.16]

### 7.1 Bandwidth (−3 dB), Load = 30 pF

| Device | Resolution | Typ | Units | Code |
|---|---|---|---|---|
| 5 kΩ | 8-bit | 480 | kHz | 7Fh |
| 5 kΩ | 7-bit | 480 | kHz | 3Fh |
| 10 kΩ | 8-bit | 240 | kHz | 7Fh |
| 10 kΩ | 7-bit | 240 | kHz | 3Fh |
| 50 kΩ | 8-bit | 48 | kHz | 7Fh |
| 50 kΩ | 7-bit | 48 | kHz | 3Fh |
| 100 kΩ | 8-bit | 24 | kHz | 7Fh |
| 100 kΩ | 7-bit | 24 | kHz | 3Fh |

### 7.2 VW Settling Time (TABLE 1-1)

> Conditions: VA = 10V, VB = 0V; ±1 LSb error band; CL = 50 pF; code steps from 00h → FFh (or 7Fh) and back.

[Source: DS20005304B, p.16]

| Device | Symbol | Typ | Units |
|---|---|---|---|
| 5 kΩ | tS | 1 | µs |
| 10 kΩ | tS | 1 | µs |
| 50 kΩ | tS | 2.5 | µs |
| 100 kΩ | tS | 5 | µs |

---

## 8. DC Characteristics — Power Metrics

[Source: DS20005304B, p.14]

### 8.1 Memory Values

| Parameter | Symbol | Min | Typ | Max | Units |
|---|---|---|---|---|---|
| Wiper Value Range (8-bit) | N | 00h | — | FFh | hex |
| Wiper Value Range (7-bit) | N | 00h | — | 7Fh | hex |
| Wiper POR/BOR Value (8-bit) | NPOR/BOR | — | 7Fh | — | hex |
| Wiper POR/BOR Value (7-bit) | NPOR/BOR | — | 3Fh | — | hex |
| TCON Value Range | N | 00h | — | FFh | hex |
| TCON POR/BOR Value | NTCON | — | FFh | — | hex |

### 8.2 Power Supply Sensitivity (PSS)

| Parameter | Symbol | Typ | Max | Units | Conditions |
|---|---|---|---|---|---|
| Power Supply Sensitivity (8-bit) | PSS | 0.0015 | 0.0035 | %/% | VL = 2.7V to 5.5V, V+ = +18V, V− = −18V, Code = 7Fh |
| Power Supply Sensitivity (7-bit) | PSS | 0.0015 | 0.0035 | %/% | Code = 3Fh |

### 8.3 Typical Power Dissipation

> Formula: PDISS = (IDDD × 5.5V) + (IDDA × 36V) + (IAB × 36V) [Note 15]

| Device | Typ PDISS | Units |
|---|---|---|
| 5 kΩ | 260 | mW |
| 10 kΩ | 130 | mW |
| 50 kΩ | 26 | mW |
| 100 kΩ | 13 | mW |

---

## 9. Timing — I2C Bus Start/Stop Bits and WLAT (TABLE 1-2)

> I2C AC Characteristics: TA = −40°C to +125°C; 2.7V ≤ VL ≤ 5.5V; DGND = V− (Note 1)
> Note 1: Serial interface equal performance when DGND ≥ V− + 0.9V.

[Source: DS20005304B, p.17]

### 9.1 SCL Frequency Limits

| Param | Symbol | Mode | Min | Max | Units | Conditions |
|---|---|---|---|---|---|---|
| — | FSCL | Standard mode | 0 | 100 | kHz | Cb = 400 pF; 1.8V ≤ VL ≤ 5.5V |
| — | FSCL | Fast mode | 0 | 400 | kHz | Cb = 400 pF; 2.7V ≤ VL ≤ 5.5V |
| — | FSCL | High-Speed 1.7 | 0 | 1,700 | kHz | Cb = 400 pF; 4.5V ≤ VL ≤ 5.5V |
| — | FSCL | High-Speed 3.4 | 0 | 3,400 | kHz | Cb = 100 pF; 4.5V ≤ VL ≤ 5.5V |

### 9.2 Bus Capacitive Loading

| Param | Symbol | Mode | Max | Units |
|---|---|---|---|---|
| D102 | Cb | 100 kHz | 400 | pF |
| D102 | Cb | 400 kHz | 400 | pF |
| D102 | Cb | 1.7 MHz | 400 | pF |
| D102 | Cb | 3.4 MHz | 100 | pF |

### 9.3 Start / Stop / WLAT Timing

| Param No. | Symbol | Characteristic | Mode | Min | Max | Units |
|---|---|---|---|---|---|---|
| 90 | TSU:STA | Start Setup Time (Repeated Start only) | 100 kHz | 4700 | — | ns |
| 90 | TSU:STA | — | 400 kHz | 600 | — | ns |
| 90 | TSU:STA | — | 1.7 MHz | 160 | — | ns |
| 90 | TSU:STA | — | 3.4 MHz | 160 | — | ns |
| 91 | THD:STA | Start Hold Time (after which first clock pulse generated) | 100 kHz | 4000 | — | ns |
| 91 | THD:STA | — | 400 kHz | 600 | — | ns |
| 91 | THD:STA | — | 1.7 MHz | 160 | — | ns |
| 91 | THD:STA | — | 3.4 MHz | 160 | — | ns |
| 92 | TSU:STO | Stop Setup Time | 100 kHz | 4000 | — | ns |
| 92 | TSU:STO | — | 400 kHz | 600 | — | ns |
| 92 | TSU:STO | — | 1.7 MHz | 160 | — | ns |
| 92 | TSU:STO | — | 3.4 MHz | 160 | — | ns |
| 93 | THD:STO | Stop Hold Time | 100 kHz | 4000 | — | ns |
| 93 | THD:STO | — | 400 kHz | 600 | — | ns |
| 93 | THD:STO | — | 1.7 MHz | 160 | — | ns |
| 93 | THD:STO | — | 3.4 MHz | 160 | — | ns |
| 94 | TWLSU | WLAT↑ to SCL↑ (write ACK bit) Setup Time | — | 10 | — | ns |
| 95 | TWLHD | SCL↑ to WLAT↑ (write ACK bit) Hold Time | — | 250 | — | ns |
| 96 | TWLATL | WLAT High or Low Time | — | 2 | — | µs (min) |

> **Note 9:** WLAT transition within 10 ns before rising edge (Spec 94) and 200 ns after rising edge (Spec 95) of SCL (write data ACK bit) is **indeterminate** (Write Data may or may not be delayed).

---

## 10. Timing — I2C Bus Requirements Client Mode (TABLE 1-3 and 1-4)

> I2C AC Characteristics: TA = −40°C to +125°C; 2.7V ≤ VL ≤ 5.5V; DGND = V−.

[Source: DS20005304B, p.18–19]

| Param No. | Symbol | Characteristic | Mode | Min | Max | Units |
|---|---|---|---|---|---|---|
| 100 | THIGH | Clock High Time | 100 kHz | 4000 | — | ns |
| 100 | THIGH | — | 400 kHz | 600 | — | ns |
| 100 | THIGH | — | 1.7 MHz | 120 | — | ns |
| 100 | THIGH | — | 3.4 MHz | 60 | — | ns |
| 101 | TLOW | Clock Low Time | 100 kHz | 4700 | — | ns |
| 101 | TLOW | — | 400 kHz | 1300 | — | ns |
| 101 | TLOW | — | 1.7 MHz | 320 | — | ns |
| 101 | TLOW | — | 3.4 MHz | 160 | — | ns |
| 102A (Note 6) | TRSCL | SCL Rise Time | 100 kHz | — | 1000 | ns |
| 102A | TRSCL | — | 400 kHz | 20 + 0.1Cb | 300 | ns |
| 102A | TRSCL | — | 1.7 MHz | 20 | 80 | ns |
| 102A | TRSCL | — | 1.7 MHz (after rpt. Start/ACK) | 20 | 160 | ns |
| 102A | TRSCL | — | 3.4 MHz | 10 | 40 | ns |
| 102A | TRSCL | — | 3.4 MHz (after rpt. Start/ACK) | 10 | 80 | ns |
| 102B (Note 6) | TRSDA | SDA Rise Time | 100 kHz | — | 1000 | ns |
| 102B | TRSDA | — | 400 kHz | 20 + 0.1Cb | 300 | ns |
| 102B | TRSDA | — | 1.7 MHz | 20 | 160 | ns |
| 102B | TRSDA | — | 3.4 MHz | 10 | 80 | ns |
| 103A (Note 5) | TFSCL | SCL Fall Time | 100 kHz | — | 300 | ns |
| 103A | TFSCL | — | 400 kHz | 20 + 0.1Cb | 300 | ns |
| 103A | TFSCL | — | 1.7 MHz | 20 | 80 | ns |
| 103A | TFSCL | — | 3.4 MHz | 10 | 40 | ns |
| 103B (Note 5) | TFSDA | SDA Fall Time | 100 kHz | — | 300 | ns |
| 103B | TFSDA | — | 400 kHz | 20 + 0.1Cb | 300 | ns |
| 103B | TFSDA | — | 1.7 MHz | 20 | 160 | ns |
| 103B | TFSDA | — | 3.4 MHz | 10 | 80 | ns |
| 106 | THD:DAT | Data Input Hold Time | 100 kHz | 0 | — | ns |
| 106 | THD:DAT | — | 400 kHz | 0 | — | ns |
| 106 | THD:DAT | — | 1.7 MHz | 0 | — | ns |
| 106 | THD:DAT | — | 3.4 MHz | 0 | — | ns |
| 107 | TSU:DAT | Data Input Setup Time | 100 kHz | 250 | — | ns |
| 107 | TSU:DAT | — | 400 kHz | 100 | — | ns |
| 107 | TSU:DAT | — | 1.7 MHz | 10 | — | ns |
| 107 | TSU:DAT | — | 3.4 MHz | 10 | — | ns |
| 109 | TAA | Output Valid from Clock (SDA output) | 100 kHz | — | 3450 | ns |
| 109 | TAA | — | 400 kHz | — | 900 | ns |
| 109 | TAA | — | 1.7 MHz | — | 150 | ns (Cb = 100 pF, Note 8) |
| 109 | TAA | — | 1.7 MHz | — | 310 | ns (Cb = 400 pF, Note 6) |
| 109 | TAA | — | 3.4 MHz | — | 150 | ns (Cb = 100 pF) |
| 110 | TBUF | Bus Free Time Before New Transmission | 100 kHz | 4700 | — | ns |
| 110 | TBUF | — | 400 kHz | 1300 | — | ns |
| 110 | TBUF | — | 1.7 MHz | N.A. | — | ns |
| 110 | TBUF | — | 3.4 MHz | N.A. | — | ns |
| — | TSP | Input Filter Spike Suppression (SDA, SCL) | 100 kHz | — | 50 | ns |
| — | TSP | — | 400 kHz | — | 50 | ns |
| — | TSP | — | 1.7 MHz | — | 10 | ns |
| — | TSP | — | 3.4 MHz | — | 10 | ns |

**Timing Table Notes (complete):** [Source: DS20005304B, p.20]
1. Serial interface equal performance when DGND ≥ V− + 0.9V.
2. As a transmitter, device must provide internal min delay to bridge undefined region (min 300 ns) of SCL falling edge to avoid unintended Start or Stop conditions.
3. Fast-mode (400 kHz) device in standard (100 kHz) system: TSU:DAT ≥ 250 ns must be met. If device stretches SCL Low period, next data bit must be output before TR(max) + TSU:DAT = 1000 + 250 = 1250 ns.
4. Use Cb in pF for calculations.
5. Not tested.
6. Not tested.
7. Host transmitter must provide delay to ensure SDA and SCL fall time differences do not unintentionally create Start or Stop condition.
8. Ensured by TAA 3.4 MHz specification test.
9. WLAT transition within 10 ns before rising edge (Spec 94) and 200 ns after rising edge (Spec 95) of SCL (write data ACK bit) is indeterminate.

---

## 11. Temperature Characteristics

[Source: DS20005304B, p.21]

| Parameter | Symbol | Min | Max | Units |
|---|---|---|---|---|
| Specified Temperature Range | TA | −40 | +125 | °C |
| Operating Temperature Range | TA | −40 | +125 | °C |
| Storage Temperature Range | TA | −65 | +150 | °C |

### 11.1 Thermal Package Resistances

| Package | θJA | Units |
|---|---|---|
| 14L-TSSOP (ST) | 100 | °C/W |
| 20L-VQFN-5×5 (MQ) | 36.1 | °C/W |

[Source: DS20005304B, p.21]

---

## 12. Typical Performance Curves

The MCP45HVX1 Typical Performance Curves are in a **separate document, DS20005307**, available on the Microchip web site at the MCP45HVX1 Product Page under Documentation and Software, in the Data Sheets category. [Source: DS20005304B, p.22]

Raw text is now available in `extracted-md/MCP45HVX1_Typical_Performance_Curves_DS20005307A.md` from `MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf`. The source is graph-heavy, so numerical curve interpretation still requires direct PDF review rather than relying on the raw text extraction alone.

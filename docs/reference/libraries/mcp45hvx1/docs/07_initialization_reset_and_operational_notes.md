# MCP45HVX1 — Initialization, Reset, and Operational Notes

**Source document:** DS20005304B Rev B, June 2023 (Microchip Technology Inc.)
**Read via:** AllDatasheet.com HTML mirror, pages 26–80

---

## Table of Contents

1. [Power-On Reset (POR) Behavior](#1-power-on-reset-por-behavior)
2. [Brown-Out Reset (BOR) Behavior](#2-brown-out-reset-bor-behavior)
3. [Power-Up Sequence Requirements](#3-power-up-sequence-requirements)
4. [Software Reset Sequence](#4-software-reset-sequence)
5. [Register Default States Summary](#5-register-default-states-summary)
6. [First Commands After Reset](#6-first-commands-after-reset)
7. [WLAT Initialization](#7-wlat-initialization)
8. [SHDN Pin Initialization](#8-shdn-pin-initialization)
9. [Power Supply Design Notes](#9-power-supply-design-notes)
10. [Bypass Capacitor Requirements](#10-bypass-capacitor-requirements)
11. [Layout Considerations](#11-layout-considerations)
12. [Resistor Network Power Dissipation Limits](#12-resistor-network-power-dissipation-limits)
13. [Application Formulas Reference](#13-application-formulas-reference)

---

## 1. Power-On Reset (POR) Behavior

POR occurs when VL rises above the POR threshold from a de-energized state.

On POR, all volatile registers initialize to their default values:

| Register | Address | Default After POR |
|---|---|---|
| Volatile Wiper 0 | 00h | 7Fh (8-bit) or 3Fh (7-bit) |
| Volatile TCON0 | 04h | FFh (all terminals connected, R0HW=1) |
| Device Memory Address Pointer | — | 00h |

[Source: DS20005304B, p. 28, p. 35–36, p. 61]

All terminals (P0A, P0W, P0B) are connected after POR (TCON0 = FFh). The wiper is at mid-scale. [Source: DS20005304B, p. 36]

---

## 2. Brown-Out Reset (BOR) Behavior

BOR occurs when VL drops below the BOR threshold. BOR causes the same register initialization as POR:

| Register | Default After BOR |
|---|---|
| Volatile Wiper 0 | 7Fh (8-bit) or 3Fh (7-bit) |
| Volatile TCON0 | FFh |
| Device Memory Address Pointer | 00h |

[Source: DS20005304B, p. 28, p. 35–36]

> **Note:** The exact POR and BOR threshold voltages for VL are specified in `03_electrical_and_timing.md`, Section 2.2: VPOR (VL POR rising threshold) = 1.8 V typ, VDBOR (VL BOR threshold) = 1.55 V typ (all typical values; explicit Min/Max not stated). [Source: DS20005304B, p. 13]

---

## 3. Power-Up Sequence Requirements

### Device Functionality at Each VL Operating Region

TABLE 4-5 defines device behavior across distinct VL voltage regions. [Source: DS20005304B, p. 31]

| VL Condition | V+/V− State | Serial Interface | Pot Terminals | Wiper Register | Output |
|---|---|---|---|---|---|
| VL < VDBOR (< 1.8 V typ) | Valid | Ignored | Unknown | Unknown | Invalid |
| VL < VDBOR (< 1.8 V typ) | Invalid | Ignored | Unknown | Unknown | Invalid |
| VDBOR ≤ VL < 1.8 V | Valid | Unknown | Connected | Initialized | Valid |
| VDBOR ≤ VL < 1.8 V | Invalid | Unknown | Connected | Invalid | — |
| 1.8 V ≤ VL ≤ 5.5 V | Valid | Accepted | Connected | Register controls | Valid |
| 1.8 V ≤ VL ≤ 5.5 V | Invalid | Accepted | Connected | Invalid | — |

> **Note 1 (TABLE 4-5):** It is recommended to use a voltage supervisor device to hold the system in a Reset state for voltages below the minimum operating voltage.  
> **Note 2 (TABLE 4-5):** Assumes V+ > VAPOR.  
> [Source: DS20005304B, p. 31]

---

### VL relative to V−

The MCP45HVX1 requires that:

**VL − V− ≤ 5.5 V** at all times [Source: DS20005304B, p. 8]

This means: if V− is biased below GND (e.g., V− = −12 V), then VL must also be brought up in a coordinated manner such that at no point does VL exceed V− + 5.5 V. If V− is −12 V and VL is 3.3 V, the difference = 15.3 V which **violates** this constraint.

> **Implementation note:** The datasheet constraint VL − V− ≤ 5.5 V implies that V− and VL must be sequenced or that V− must be held near DGND during VL power-up, or that VL must not rise until V− has reached its operating voltage. The exact sequencing recommendation is not explicitly stated beyond the voltage constraint. [Source: DS20005304B, p. 8]

### V+ and V−

V+ and V− supply the analog section:
- V+ range: V− to (V− + 36 V)
- V− range: −18 V to GND
- V+ − V− ≤ 36 V

No power-up sequencing order between V+ and V− is explicitly required in the datasheet, beyond the VL−V− constraint. [Source: DS20005304B, p. 8]

### Wiper state during power-up

The wiper position is undefined until POR completes. After POR, the wiper defaults to mid-scale. The I²C interface becomes active after POR. No explicit startup delay time (tPOR) is quantified in the extracted pages. [Source: DS20005304B, p. 28]

> **Gap:** No explicit POR completion time (tPOR) is specified in the available pages. See `08_variant_differences_and_open_questions.md`.

---

## 4. Software Reset Sequence

Purpose: Reset the MCP45HVX1 I²C state machine to a known state. Use when the device may have latched into an unknown I²C state (e.g., after host reset during a transaction, or after bus noise).

**Does NOT reset register values.** Only the I²C state machine is reset. [Source: DS20005304B, p. 66]

### Sequence (Figure 8-2)

```
S | 1 1 1 1 1 1 1 1 1 | S | P
```

Steps:
1. Issue a Start (S) condition.
2. Clock out nine '1' bits on SDA (with SCL toggling).
3. Issue a second Start (S) condition.
4. Issue a Stop (P) condition.

[Source: DS20005304B, p. 66]

### Why each step is needed

| Step | Purpose |
|---|---|
| First Start (S) | Resets device if it is in receive-data (waiting for data) mode |
| Nine '1' bits | Resets device if it is driving SDA Low (ACK or Read data '0'); device sees a NACK, forces reset |
| Second Start (S) | Prevents erroneous write if host was reset while sending a Write command and device was generating ACK |
| Stop (P) | Terminates any current bus activity; device waits for next valid Start |

[Source: DS20005304B, p. 66]

### Effect on other I²C devices

This sequence is described as an invalid command to all standard I²C devices; they should disregard it. [Source: DS20005304B, p. 66]

### Reference

This technique is documented in Microchip Application Note AN1028. [Source: DS20005304B, p. 66]

---

## 5. Register Default States Summary

| Register | Address | Default (POR/BOR) | Applies To |
|---|---|---|---|
| Volatile Wiper 0 | 00h | 7Fh (8-bit) / 3Fh (7-bit) | All standard variants |
| Volatile TCON0 | 04h | FFh | All variants |
| Device Memory Address Pointer | — | 00h | All variants |
| Reserved (01h–03h) | — | N/A | — |
| Reserved (05h–FFh) | — | N/A | — |

[Source: DS20005304B, p. 28–36, p. 61]

Custom POR/BOR wiper values are available via the NSCAR process. Standard ordering always gives mid-scale. [Source: DS20005304B, p. 76]

---

## 6. First Commands After Reset

After POR/BOR or after the software reset sequence:

1. The Device Memory Address Pointer is set to **00h** (Volatile Wiper 0). [Source: DS20005304B, p. 61]
2. A Read command using the "last address" format (without Repeated Start) will read Wiper 0 (address 00h).
3. No initialization commands are required before the device is operational; it comes up in a fully functional state with mid-scale wiper and all terminals connected.
4. The I²C interface is ready to accept commands immediately after POR.

---

## 7. WLAT Initialization

If the WLAT synchronization feature is **not** used:
- WLAT **must be tied Low** (connected to DGND). [Source: DS20005304B, p. 25]

If WLAT is used for synchronous wiper updates:
- After power-up, ensure WLAT is Low before issuing wiper commands, unless intentional latching is desired.
- During operation: update wipers with WLAT High, then release WLAT Low to apply all changes simultaneously.

WLAT timing constraint (relative to SCL rising edge):

> ⚠ **Conflict:** TABLE 1-2 spec 95 specifies **250 ns minimum** hold time (TWLHD); Note 9 describes the indeterminate window as 10 ns before to **200 ns** after. A safe implementation must use 250 ns. [Conflict: DS20005304B, TABLE 1-2 Spec 95, p. 17 vs. Note 9, p. 17]

| Parameter | Symbol | Value | Unit |
|---|---|---|---|
| WLAT setup before SCL rising edge | TWLSU | ≥ 10 ns min | ns |
| WLAT hold after SCL rising edge | TWLHD | ≥ 250 ns min | ns (TABLE 1-2) |
| Indeterminate transition window | — | −10 to +200 ns | ns relative to SCL↑ (Note 9) |

[Source: DS20005304B, p. 27]

---

## 8. SHDN Pin Initialization

If hardware shutdown is **not** used:
- SHDN must be tied High (connected to VL). [Source: DS20005304B, p. 25]

If SHDN is used:
- On power-up, if SHDN is Low, the device enters the shutdown state (P0A disconnected, P0W shorted to P0B) immediately after POR completes.
- TCON0 registers retain their default (FFh) regardless of SHDN state.
- To restore normal operation, release SHDN High.

[Source: DS20005304B, p. 47]

---

## 9. Power Supply Design Notes

### General

- V+ and V− should reside on the analog power plane, separate from digital power. [Source: DS20005304B, p. 73]
- The digital supply VL should be as clean (low-noise) as possible. [Source: DS20005304B, p. 73]

### Dual-supply constraint

- V+ and V− may be asymmetric (e.g., V+ = +15 V, V− = 0 V) or symmetric (e.g., ±18 V), as long as:
  - V+ − V− ≤ 36 V
  - −18 V ≤ V− ≤ 0 V
  - 0 V ≤ V+ ≤ +18 V
  - VL − V− ≤ 5.5 V
  - VL ≥ 1.8 V (operating)

[Source: DS20005304B, p. 8]

### Terminal voltage constraints

Signals on P0A, P0B, and P0W must remain within V− ≤ Vx ≤ V+. Signals outside this range may damage the device. [Source: DS20005304B, p. 8]

---

## 10. Bypass Capacitor Requirements

From Section 8.11.1 [Source: DS20005304B, p. 73]:

| Supply Pin | Recommended Bypass Capacitor | Placement |
|---|---|---|
| VL | 0.1 µF | Within 4 mm of the VL pin |
| V+ | 0.1 µF | As close as possible |
| V− | (not explicitly stated; inferred from Figure 8-13 context) | — |

> **Note on V− bypass:** Figure 8-13 in the datasheet shows bypass capacitors on VL and V+ but does not explicitly call out V− bypass capacitor requirements in the extracted text. The V− bypass recommendation may be present in application notes not yet read. [Source: DS20005304B, p. 73]

Bypass capacitors filter high-frequency noise induced on power supply traces, minimizing effects on signal integrity. [Source: DS20005304B, p. 73]

---

## 11. Layout Considerations

From Section 8.11.2 [Source: DS20005304B, p. 73–74]:

### Noise

- Multi-layer PCBs with a low-inductance ground plane are recommended.
- Isolate analog inputs/outputs from digital switching signals.
- Proper decoupling is critical for rated performance.
- Breadboards and wire-wrapped boards are **not recommended** if low noise is required.

### PCB area

| Package | Dimensions (mm) | Area (mm²) | Relative Area |
|---|---|---|---|
| 14-TSSOP (ST) | 5.10 × 6.40 | 32.64 | 1.31× |
| 20-VQFN (MQ) | 5.00 × 5.00 | 25.00 | 1× (smallest) |

For space-critical applications, the VQFN package is recommended. [Source: DS20005304B, p. 73]

### Power dissipation

Power dissipation through the resistor network determines thermal operating limits. See Section 12 below.

---

## 12. Resistor Network Power Dissipation Limits

### RAB power dissipation (TABLE 8-3)

Worst-case: VA = +18 V, VB = −18 V (36 V total). [Source: DS20005304B, p. 74]

| RAB Typical (Ω) | RAB Min (Ω) | RAB Max (Ω) | |VA|+|VB| (V) | Power (mW) |
|---|---|---|---|---|
| 5,000 | 4,000 | 6,000 | 36 | 324 |
| 10,000 | 8,000 | 12,000 | 36 | 162 |
| 50,000 | 40,000 | 60,000 | 36 | 32.4 |
| 100,000 | 80,000 | 120,000 | 36 | 16.2 |

Power = V²/RAB(MIN). [Source: DS20005304B, p. 74]

### RBW power dissipation (TABLE 8-4)

Maximum current conditions (IBW = max IW from electrical specs). [Source: DS20005304B, p. 74]

| RAB Typical (Ω) | |VW|+|VB| (V) | IBW max (mA) | Power (mW) |
|---|---|---|---|
| 5,000 | 36 | 25 | 900 |
| 10,000 | 36 | 12.5 | 450 |
| 50,000 | 36 | 6.5 | 234 |
| 100,000 | 36 | 6.5 | 234 |

Power = V × I. [Source: DS20005304B, p. 74]

> The 900 mW figure for the 5 kΩ variant at full voltage swing must be checked against the device's thermal limits (θJA) to ensure junction temperature stays within −40°C to +125°C. See `03_electrical_and_timing.md` for thermal resistance values.

---

## 13. Application Formulas Reference

These formulas appear in the Applications section and are documented here as operational constraints/calculations.

### High-Voltage DAC (Section 8.3)

**Equation 8-1** [Source: DS20005304B, p. 67]:

```
8-bit: VOUT(N) = (R1/R2) × (VD × (1 + N/255))    N = 0 to 255
7-bit: VOUT(N) = (R1/R2) × (VD × (1 + N/127))    N = 0 to 127
```

### Variable Gain Instrumentation Amplifier (Section 8.4)

**Equation 8-2** [Source: DS20005304B, p. 67]:

```
8-bit: Gain(N) = 1 + (49.4 kΩ) / ((N/255) × RAB)    N = 0 to 255
7-bit: Gain(N) = 1 + (49.4 kΩ) / ((N/127) × RAB)    N = 0 to 127
```

### Programmable Power Supply (Section 8.6)

**Equation 8-3** [Source: DS20005304B, p. 68]:

```
8-bit: VOUT(N) = 1.23V × (1 + (R2 / (N × RAB/255)))    N = 0 to 255
7-bit: VOUT(N) = 1.23V × (1 + (R2 / (N × RAB/127)))    N = 0 to 127
```

### Log Attenuation (Section 8.9)

**Equation 8-5: dB (voltage)** [Source: DS20005304B, p. 70]:
```
L = 20 × log10(VOUT / VIN)
```

**Equation 8-6: dB (resistance), Terminal B to Ground** [Source: DS20005304B, p. 70]:
```
L = 20 × log10(RBW / RAB)
```

**Equation 8-7: dB (resistance), Terminal B through RB2GND to Ground** [Source: DS20005304B, p. 70]:
```
L = 20 × log10((RBW + RB2GND) / (RAB + RB2GND))
```

### Log attenuation wiper codes for 8-bit devices (TABLE 8-1)

For −3 dB per step, wiper codes achieving closest log attenuation steps [Source: DS20005304B, p. 71]:

| Step # | Target (dB) | Wiper Code | Calculated (dB) |
|---|---|---|---|
| 0 | 0 | 255 | 0 |
| 1 | −3 | 180 | −3.025 |
| 2 | −6 | 128 | −5.987 |
| 3 | −9 | 90 | −9.046 |
| 4 | −12 | 64 | −12.007 |
| 5 | −15 | 45 | −15.067 |
| 6 | −18 | 32 | −18.028 |
| 7 | −21 | 23 | −20.896 |
| 8 | −24 | 16 | −24.048 |
| 9 | −27 | 11 | −27.303 |
| 10 | −30 | 8 | −30.069 |
| 11 | −33 | 6 | −32.568 |
| 12 | −36 | 4 | −36.090 |
| 13 | −39 | 3 | −38.588 |
| 14 | −42 | 2 | −42.110 |
| 15 | −48 | 1 | −48.131 |
| 16 | Mute | 0 | Mute |

Note: Attenuation values do not include digital potentiometer errors (FSE, ZSE, INL, DNL). [Source: DS20005304B, p. 71]

# MCP45HVX1 — Modes, Control Pins, Status, and Fault Conditions

**Source document:** DS20005304B Rev B, June 2023 (Microchip Technology Inc.)
**Read via:** AllDatasheet.com HTML mirror, pages 26–55

---

## Table of Contents

1. [Operating Modes Overview](#1-operating-modes-overview)
2. [Hardware Shutdown — SHDN Pin](#2-hardware-shutdown--shdn-pin)
3. [TCON Register — Software Terminal Control](#3-tcon-register--software-terminal-control)
4. [SHDN vs. TCON Interaction](#4-shdn-vs-tcon-interaction)
5. [Terminal Connectivity States](#5-terminal-connectivity-states)
6. [WLAT Pin — Wiper Latch](#6-wlat-pin--wiper-latch)
7. [GCEN — General Call Enable](#7-gcen--general-call-enable)
8. [Error / NACK Conditions](#8-error--nack-conditions)
9. [Bus Fault / Passive High Condition](#9-bus-fault--passive-high-condition)
10. [Power Supply States](#10-power-supply-states)
11. [Current Consumption Modes](#11-current-consumption-modes)

---

## 1. Operating Modes Overview

The MCP45HVX1 does not have explicit user-selectable "power modes" (such as sleep/standby/active as separate registers). Its operational state is determined by:

1. Supply voltage conditions (POR/BOR threshold)
2. The SHDN hardware pin (active Low)
3. The TCON0 register bits (R0HW, R0A, R0W, R0B)
4. The WLAT pin (wiper latch)

The I²C serial interface remains active regardless of SHDN or TCON state. [Source: DS20005304B, p. 47]

---

## 2. Hardware Shutdown — SHDN Pin

**Pin:** SHDN (active Low)  
**Package locations:** TSSOP-14 pin 8 / VQFN-20 pin 7  
[Source: DS20005304B, p. 24]

### Function

When SHDN is asserted Low:
- P0A terminal is **disconnected** from the resistor network.
- P0W (wiper) is **shorted to P0B** terminal.
- The I²C serial interface remains **fully active**.
- Register values (Wiper 0, TCON0) are **not corrupted**.

[Source: DS20005304B, p. 47]

When SHDN is deasserted High:
- Terminal connectivity reverts to the state defined by the TCON0 register.
- Stored register values take effect immediately.

### Electrical characteristics

| Parameter | Min | Typ | Max | Unit |
|---|---|---|---|---|
| VIH (SHDN) | 0.7 × VL | — | VL + 0.3 | V |
| VIL (SHDN) | −0.3 | — | 0.3 × VL | V |

[Source: DS20005304B, p. 14 (inferred from digital pin specs)]

> **Note:** The exact SHDN pin VIH/VIL spec table reference is from the DC Characteristics for digital input pins. See `03_electrical_and_timing.md` for the full digital input/output specifications.

### SHDN vs. VIH/VIL threshold

The SHDN pin uses digital logic levels referenced to VL (not V+ or V−). [Source: DS20005304B, p. 25]

---

## 3. TCON Register — Software Terminal Control

The Volatile TCON0 register (address 04h, reset = FFh) provides software control over each terminal's connection state.

**Bit assignments:**

| Bit | Name | Reset | Effect when = 0 | Effect when = 1 |
|---|---|---|---|---|
| [7:4] | Reserved | 1111 | — | — |
| 3 | R0HW | 1 | Forces HW shutdown state (P0A off, P0W → P0B) | Normal operation |
| 2 | R0A | 1 | P0A disconnected | P0A connected |
| 1 | R0W | 1 | P0W disconnected (floating) | P0W connected |
| 0 | R0B | 1 | P0B disconnected | P0B connected |

[Source: DS20005304B, p. 36]

**R0HW = 0** produces the same physical result as the SHDN hardware pin asserted Low — but via software. This allows shutdown control entirely through I²C without using the SHDN pin. [Source: DS20005304B, p. 47]

**Individual terminal disconnect:** R0A, R0W, and R0B can be cleared independently, allowing:
- Rheostat (B to W) configuration: Clear R0A (disconnect A), keep R0W and R0B = 1
- Rheostat (A to W) configuration: Clear R0B (disconnect B), keep R0A and R0W = 1
- Floating wiper: Clear R0W, keep R0A and R0B = 1

[Source: DS20005304B, p. 36, p. 47]

---

## 4. SHDN vs. TCON Interaction

| SHDN pin | R0HW bit | Effective State |
|---|---|---|
| High (inactive) | 1 (normal) | Normal; R0A/R0W/R0B control terminals |
| High (inactive) | 0 (shutdown) | Software shutdown: P0A off, P0W → P0B |
| Low (active) | 1 | Hardware shutdown: P0A off, P0W → P0B (overrides TCON) |
| Low (active) | 0 | Hardware shutdown (SHDN pin dominates; TCON not relevant) |

SHDN pin **overrides** TCON register bits when asserted. When SHDN is released, TCON bits control the state. TCON register is **not modified** by SHDN activity. [Source: DS20005304B, p. 47]

---

## 5. Terminal Connectivity States

The following states are defined by the datasheet for various TCON and SHDN combinations. See also `05_register_map.md` for the full TCON register table.

### Normal operation (SHDN = High, R0HW = 1, R0A = 1, R0W = 1, R0B = 1)

All three terminals P0A, P0W, P0B connected. Resistor ladder functions as a full potentiometer. [Source: DS20005304B, p. 36]

### Shutdown state (SHDN = Low or R0HW = 0)

- P0A: Disconnected from resistor network.
- P0W: Internally shorted to P0B.
- P0B: Connected.

This state is described in the application note Section 8.1 as useful for "disconnecting the wiper" to allow an external transistor input to be taken to the bias voltage level. [Source: DS20005304B, p. 47, p. 65]

### Rheostat configurations (Sections 5.4–5.6)

**Rheostat (B to W):** Connect P0B to reference, use P0W as output. P0A may be left unconnected or connected to a voltage.  
**Rheostat (A to W):** Connect P0A to reference, use P0W as output. P0B may be left unconnected or connected to a voltage.  
**Potentiometer (A to W to B):** All terminals connected; classical voltage divider. [Source: DS20005304B, p. 46]

---

## 6. WLAT Pin — Wiper Latch

**Pin:** WLAT  
**Package locations:** TSSOP-14 pin 6 / VQFN-20 pin 6  
**Active polarity:** High = latch active (inhibit wiper update); Low = latch inactive (wiper updates enabled)  
[Source: DS20005304B, p. 24–25]

### Function

- **WLAT = Low:** Wiper position updates normally after each valid Write/INC/DEC command.
- **WLAT = High:** Wiper position is held (latched) at its current value. New commands may be sent and will be Acknowledged, but the physical wiper position does not change.
- When WLAT returns to Low: The wiper moves to the value most recently written (or incremented/decremented) while WLAT was High.

[Source: DS20005304B, p. 27, p. 50]

### Timing constraint

> ⚠ **WLAT Hold Time Conflict within DS20005304B:**
>
> - **TABLE 1-2, Specification 95 (p. 17):** TWLHD (WLAT hold time after SCL rising edge) = **250 ns min** (no max given; VL = 2.7–5.5 V, TA = −40°C to +125°C)
> - **Note 9 (p. 17 and p. 20):** "A WLAT transition between 10 ns before and **200 ns** after the rising edge of SCL is indeterminate."
>
> A transition at 225 ns would pass Note 9's indeterminate window but fail TABLE 1-2's 250 ns minimum hold. These are internally inconsistent. Use **250 ns min** (the TABLE 1-2 specification) as the conservative safe margin.
>
> [Conflict: DS20005304B, TABLE 1-2 Spec 95, p. 17 (250 ns min) vs. Note 9, p. 17 (200 ns boundary)]

| Parameter | Symbol | Min | Max | Unit | Source |
|---|---|---|---|---|---|
| WLAT setup before SCL rising edge | TWLSU | 10 | — | ns | DS20005304B, TABLE 1-2, p. 17 |
| WLAT hold after SCL rising edge | TWLHD | **250** | — | ns | DS20005304B, TABLE 1-2 Spec 95, p. 17 |
| Indeterminate transition window | — | −10 | +200 | ns (relative to SCL↑) | DS20005304B, Note 9, p. 17 |

If WLAT transitions within the Note 9 window (−10 ns to +200 ns relative to SCL↑), the behavior is **indeterminate**. TABLE 1-2 additionally requires WLAT to be held stable for 250 ns minimum after SCL↑.

> See `03_electrical_and_timing.md` TABLE 1-2 for full WLAT timing parameters with complete conditions.

### Use case

WLAT allows simultaneous wiper updates across multiple MCP45HVX1 devices: update all devices via I²C while WLAT is High, then simultaneously release WLAT on all devices to apply the changes. This achieves glitch-free synchronous updates (analogous to LDAC on multi-channel DACs). [Source: DS20005304B, p. 27, p. 50]

**Note:** If WLAT synchronization is not needed, the WLAT pin must be tied Low. [Source: DS20005304B, p. 25]

---

## 7. GCEN — General Call Enable

A GCEN (General Call Enable) bit controls whether the device responds to the I²C General Call address (0x00).

- GCEN = 1: Device responds to General Call commands.
- GCEN = 0: Device ignores General Call commands.

> **Gap:** The register address, bit position, access type, and reset value of the GCEN bit are **not clearly identified** in the extracted pages of DS20005304B. The bit is referenced in the General Call discussion (Section 6.2.6, p. 53–55) but a definitive register location is not specified in the available text. The GCEN discussion appears alongside the TCON register content but is not shown as a bit within REGISTER 4-1 (TCON0 at 04h).

[Source: DS20005304B, p. 53–55 — referenced but location not fully specified]

---

## 8. Error / NACK Conditions

### Invalid address + command combination

If AD3:AD0 and C1:C0 form an invalid combination (e.g., INC/DEC to 04h, any command to reserved addresses), the device generates a NACK. [Source: DS20005304B, p. 56, p. 57]

After a NACK due to invalid command, all subsequent commands are **ignored** until the host issues a new Start condition to reset the I²C state machine. [Source: DS20005304B, p. 58]

### NACK-producing conditions summary

| Condition | Result |
|---|---|
| INC/DEC to address 04h (TCON) | NACK |
| Any command to reserved addresses (01h–03h, 05h–FFh) | NACK |
| AD3:AD0 + C1:C0 combination not in TABLE 7-2 | NACK |
| Mid-transfer Stop/Restart (before data ACK) | Data not written; no NACK (abort only) |

[Source: DS20005304B, p. 56–58]

### INC/DEC at boundary (clamping)

When the wiper is at full scale (7Fh/FFh) and INC is sent, or at zero scale (00h) and DEC is sent, the command is **ignored** (no NACK, no effect on wiper value). This is not an error; it is defined clamping behavior. [Source: DS20005304B, p. 63–64]

---

## 9. Bus Fault / Passive High Condition

If the MCP45HVX1 receives an incomplete or undefined I²C transmission, it:
1. Releases SDA (passive High).
2. Ignores all subsequent signals.
3. Waits for the next valid Start condition followed by a valid control byte.

This behavior is described as "falling off the bus." [Source: DS20005304B, p. 61]

---

## 10. Power Supply States

### POR (Power-On Reset)

Triggered when VL rises above the POR threshold. Device initializes to:
- Wiper 0 = 7Fh (8-bit) or 3Fh (7-bit)
- TCON0 = FFh
- Device Memory Address pointer = 00h

[Source: DS20005304B, p. 28, p. 35, p. 61]

### BOR (Brown-Out Reset)

Triggered when VL drops below the BOR threshold. Same reset behavior as POR: registers return to default values. [Source: DS20005304B, p. 28]

> **Note:** No explicit POR/BOR threshold voltage is stated in the extracted pages for VL. The device operates at VL = 1.8–5.5 V; POR/BOR threshold levels are not explicitly enumerated in the available text. See `08_variant_differences_and_open_questions.md`.

### V+ / V− supply

V+ and V− power the analog resistor network and wiper switch. The device requires:
- VL − V− ≤ 5.5 V (digital supply referenced to analog negative rail)
- V+ − V− ≤ 36 V (total analog supply span)

No "power-down" or "standby" state for the analog supply is defined; V+ and V− should be powered whenever analog operation is needed. [Source: DS20005304B, p. 8]

---

## 11. Current Consumption Modes

Specific supply current values are documented in `03_electrical_and_timing.md`. Summary:

| Condition | Supply | Typical | Max |
|---|---|---|---|
| Normal operation (VL = 5V, TSSOP, 25°C) | IDD (VL) | 1 µA | 5 µA |
| Normal operation (V+/V−) | IDD (V+) | — | ± [see file 03] |
| SHDN asserted | IDD (VL) | Same (I²C active) | — |

[Source: DS20005304B, p. 12–14]

> The SHDN pin does not reduce digital (VL) supply current; the I²C interface remains powered and active. [Source: DS20005304B, p. 47]

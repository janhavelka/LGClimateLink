# MCP45HVX1 — Variant Differences and Open Questions / Known Unknowns

**Source document:** DS20005304B Rev B, June 2023 (Microchip Technology Inc.)
**Supplemental documents:** Listed in `00_document_inventory.md`; raw text extractions are available under `docs/pdf-extracted-md/`

---

## Table of Contents

1. [Family Variant Comparison](#1-family-variant-comparison)
2. [Package Differences](#2-package-differences)
3. [Resistance Option Differences](#3-resistance-option-differences)
4. [Ordering Information](#4-ordering-information)
5. [Related Device Families (Not This Device)](#5-related-device-families-not-this-device)
6. [Known Unknowns — Missing Data](#6-known-unknowns--missing-data)
7. [Unresolved Contradictions](#7-unresolved-contradictions)
8. [Ambiguous Wording in Source Documents](#8-ambiguous-wording-in-source-documents)
9. [Supplemental Document Extracts](#9-supplemental-document-extracts)
10. [Items Likely Needed for Implementation But Not Fully Specified](#10-items-likely-needed-for-implementation-but-not-fully-specified)

---

## 1. Family Variant Comparison

The MCP45HVX1 family has two resolution variants:

| Part Number | Resolution | Taps (including wiper) | Resistors | Full-Scale Code | Mid-Scale Code | Zero-Scale Code |
|---|---|---|---|---|---|---|
| MCP45HV31 | 7-bit | 128 | 127 | 7Fh | 3Fh | 00h |
| MCP45HV51 | 8-bit | 256 | 255 | FFh | 7Fh | 00h |

[Source: DS20005304B, p. 1–3]

Both variants share identical:
- Package options (TSSOP-14, VQFN-20)
- I²C interface and address structure
- TCON register map and reset values
- SHDN and WLAT pin behavior
- Supply voltage ranges
- Terminal current limits (same per RAB option)
- Temperature range (−40°C to +125°C)

[Source: DS20005304B, p. 1–8]

### Key behavioral differences

| Parameter | MCP45HV31 (7-bit) | MCP45HV51 (8-bit) |
|---|---|---|
| Maximum wiper code | 7Fh | FFh |
| POR/BOR wiper default | 3Fh | 7Fh |
| RS (single-step resistance) | RAB/127 | RAB/255 |
| Increment clamp | At 7Fh | At FFh |
| Decrement clamp | At 00h | At 00h |

[Source: DS20005304B, p. 35, p. 39, p. 63–64]

---

## 2. Package Differences

| Package | Code | Pins | Dimensions (mm) | Area (mm²) | Exposed Pad |
|---|---|---|---|---|---|
| TSSOP-14 | ST | 14 | 5.10 × 6.40 | 32.64 | None |
| VQFN-20/5×5 | MQ | 20 | 5.00 × 5.00 | 25.00 | EP (pin 21) → connect to V− or float |

[Source: DS20005304B, p. 24, p. 73, p. 85–95 (package drawings)]

### VQFN-20 Exposed Pad (EP)

The VQFN package has an Exposed Pad (EP) on the underside. The datasheet states the EP is pin 21 and should be connected to V− or left floating. It must **not** be connected to any other potential.

[Source: DS20005304B, p. 24]

### NC pins (VQFN-20)

VQFN-20 has pins 8, 9, 10, 17, 18, 19, 20 designated as NC (No Connect). These pins should be left unconnected. [Source: DS20005304B, p. 24]

### Signal-to-pin mapping differences

TSSOP-14 and VQFN-20 have different pin assignments. See `02_pinout_and_signals.md` for the full pin mapping table.

---

## 3. Resistance Option Differences

Four RAB resistance options are available for each resolution variant:

| Suffix | Typical RAB | Min RAB | Max RAB | Unit |
|---|---|---|---|---|
| -502 | 5,000 | 4,000 | 6,000 | Ω |
| -103 | 10,000 | 8,000 | 12,000 | Ω |
| -503 | 50,000 | 40,000 | 60,000 | Ω |
| -104 | 100,000 | 80,000 | 120,000 | Ω |

[Source: DS20005304B, p. 3, p. 39, p. 74]

Tolerance: ±20% for all variants. [Source: DS20005304B, p. 3]

### Terminal current limits vary by RAB option

| RAB (Typical) | Max Terminal Current (IW, IA, IB) |
|---|---|
| 5 kΩ | ±25 mA |
| 10 kΩ | ±12.5 mA |
| 50 kΩ | ±6.5 mA |
| 100 kΩ | ±6.5 mA |

[Source: DS20005304B, p. 19]

### RS (single-step resistance) by RAB option

| RAB Suffix | 7-bit RS (Ω) | 8-bit RS (Ω) |
|---|---|---|
| -502 (5 kΩ) | 39.4 | 19.6 |
| -103 (10 kΩ) | 78.7 | 39.2 |
| -503 (50 kΩ) | 394 | 196 |
| -104 (100 kΩ) | 787 | 392 |

[Source: DS20005304B, p. 39, TABLE 5-1]

---

## 4. Ordering Information

### Standard ordering system (Section 9.1)

Part number format: `MCP45HV[resolution][package]-[resistance]E/[pkg_code]`

- Resolution: 31 (7-bit) or 51 (8-bit)
- Resistance suffix: 502, 103, 503, 104
- Temperature grade: E = −40°C to +125°C (only grade listed)
- Package code: ST (TSSOP-14) or MQ (VQFN-20)

Examples:
- `MCP45HV31-103E/ST` = 7-bit, 10 kΩ, TSSOP-14
- `MCP45HV51-503E/MQ` = 8-bit, 50 kΩ, VQFN-20

[Source: DS20005304B, p. 1–3, product identification section]

### Automotive ordering system

Automotive-grade variants exist. The product identification system in Appendix B of the datasheet describes separate automotive ordering codes. Specific automotive part numbers are not fully extracted here; see the datasheet pages 96–102 for the complete automotive product identification table. [Source: DS20005304B, p. 96–102]

### Custom options (Section 9.2)

Custom POR/BOR wiper values can be specified via the NSCAR (Non-Standard Customer Authorization Request) process. NRE charges and minimum order quantities apply. Custom devices receive custom device markings. [Source: DS20005304B, p. 76]

---

## 5. Related Device Families (Not This Device)

The following device families are referenced in the datasheet as related products. They use different I²C address schemes or interfaces. Do not use their documentation for MCP45HVX1 implementation.

| Family | Interface | Fixed I²C Address Bits | Note |
|---|---|---|---|
| MCP45HVX1 (this device) | I²C | ⚠ CONFLICT: `01111` per TABLE 6-2 (p. 51) OR `10111` per Figures 7-2–7-8 (pp. 59–64) | See Section 7.4 for details |
| MCP41HVX1 | SPI | N/A | SPI variant; separate DS20005207 |
| MCP44XX / MCP45XX / MCP46XX | I²C | `01011` (5 MSbs) | Different address; command format compatible |

[Source: DS20005304B, p. 51, p. 56, p. 58]

The MCP45HVX1 maintains **command byte compatibility** with the MCP44XX/MCP45XX/MCP46XX families (10-bit data format with D9:D8 compatibility bits) but uses a **different I²C device address**. Code written for MCP44XX/45XX/46XX will require address changes to work with MCP45HVX1. [Source: DS20005304B, p. 56, p. 58]

---

## 6. Known Unknowns — Missing Data

The following information was **not found** in the available pages of DS20005304B. Supplemental PDFs are now available as raw text extracts, but these items have not all been resolved into driver requirements.

### 6.1 POR Completion Time (tPOR)

No tPOR (time from VL reaching POR threshold to device ready for I²C) is stated. The raw supplemental extracts should be searched before treating this as a final gap. [Source: Not found in DS20005304B]

### 6.2 GCEN Bit Location

The GCEN (General Call Enable) bit is referenced in the General Call section (p. 53–55) but its register address, bit number, reset value, and access type are not clearly identified in the extracted text. The description implies it exists within the device configuration, but no register definition was found. [Source: DS20005304B, p. 53–55 — referenced but not located]

### 6.3 D8 Bit Definition

The command byte D8 bit is described as "currently only one of the data bits is defined (D8)" [Source: DS20005304B, p. 56] but no further specification of what D8 does (or doesn't do) is provided in the available text.

### 6.4 V− Bypass Capacitor Recommendation

Figure 8-13 shows bypass capacitors on VL and V+ but the V− bypass capacitor recommendation is not explicitly stated in the extracted text. [Source: DS20005304B, p. 73 — implicit from figure]

### 6.5 SCL/SDA Pull-up Resistor Values

Recommended pull-up resistor values for SCL and SDA are not stated in the extracted pages. Standard I²C pull-up sizing depends on bus capacitance and speed, but no specific recommendation appears in the datasheet text. [Source: Not found in DS20005304B]

### 6.6 Wiper Resistance (RW) at Partial Voltages

Wiper resistance specifications (RWB/RWA) are defined for specific bias conditions. Behavior at intermediate V+/V− voltages is not tabulated. [Source: DS20005304B, p. 15–17 — only specific conditions given]

### 6.7 Automotive Variant Specifications

Differences between standard (E-grade) and automotive variants are referenced in the product identification section but not fully detailed in the extracted pages. [Source: DS20005304B, p. 96–102]

### 6.8 Errata

The errata is now available as `MCP45HVX1_Errata_DS80000649B.pdf` with raw text in `extracted-md/MCP45HVX1_Errata_DS80000649B.md`. It documents I2C-interface anomalies that can affect shared-bus behavior and General Call handling. This is no longer an access gap; implementation impact should be reviewed separately against the errata source PDF.

### 6.9 Startup Analog Rail Behavior During POR

What happens to P0W, P0A, P0B terminals during VL power-up before POR completes is not described. Terminal behavior during analog supply ramp is unspecified. [Source: Not found]

---

## 7. Unresolved Contradictions

### 7.1 "Non-Volatile Memory" Title vs. Volatile-Only Registers

The datasheet title on the cover page reads: **"MCP45HVX1 7/8-Bit Single I²C™ High-Voltage Digital POT with Non-Volatile Memory"**

However, all documented registers (Wiper 0 at 00h, TCON0 at 04h) are explicitly described as **volatile RAM**. No EEPROM write command, EEPROM address space, or non-volatile storage is described in any accessible part of the datasheet. The title's claim of "Non-Volatile Memory" is **contradicted by all register descriptions in the body of the document**.

Possible explanations (not verified):
- The title may be a copy/paste error from a related EEPROM-equipped variant.
- The non-volatile memory may be factory-programmed (POR/BOR wiper code) and not user-accessible.
- The title may apply to the physical process of configuring the POR wiper value at factory.

[Conflict: DS20005304B, title page vs. all register description sections, p. 35–38]

### 7.2 Continuous Write Note (Figure 7-3)

Figure 7-3 note states: "Only functions when writing the volatile wiper registers (AD3:AD0 = 00h **and 01h**) or the TCON registers (AD3:AD0 = 04h)."

However, TABLE 7-2 (Memory Map) marks address 01h as **Reserved** and states it generates a NACK on any command.

The reference to address "01h" in the Figure 7-3 note may be a documentation error (likely should say only 00h), or address 01h may have undocumented behavior.

[Conflict: DS20005304B, Figure 7-3 note, p. 60 vs. TABLE 7-2, p. 57]

### 7.3 Wiper Increment Max Value Specification

Section 7.6 states: "The value will increment up to **100h max** on 8-bit devices and **80h** on 7-bit devices."

This appears to be a maximum count value (beyond the last physical tap), but wiper code 100h (256) and 80h (128) exceed the defined register width of 8 bits (max 255/7Fh). The datasheet may mean the wiper counts 256 tap positions (0–255) and 128 tap positions (0–127), and the "100h / 80h" refers to the count of positions, not a register value.

The clamping behavior table (TABLE 7-4) correctly shows the maximum wiper code as FFh (8-bit) and 7Fh (7-bit), with those being the values where INC no longer operates. This is consistent. The "100h / 80h" language in Section 7.6 prose appears to refer to the number of resistors+1, not a writable register value.

[Ambiguity: DS20005304B, Section 7.6, p. 63 — "100h/80h" language not directly contradicted but potentially confusing]

### 7.4 I²C Device Address — Intra-Document Conflict (CRITICAL)

Two contradictory I²C fixed-address specifications appear within the **same revision** of DS20005304B and cannot be reconciled without external verification:

| Source | Fixed Address Bits (A6:A2) | 7-bit Address Range |
|---|---|---|
| TABLE 6-2 and Section 6.2.4 (p. 51) | `01111` | 0x3C–0x3F |
| Figures 7-2 through 7-8 (pp. 59–64) | `10111` | 0x5C–0x5F |

The TABLE 6-2 Note 1 that the address "differs from MCP44XX/MCP45XX/MCP46XX" does not resolve the conflict; both candidates differ from the MCP45XX `0x2E–0x2F` range.

[Conflict: DS20005304B, TABLE 6-2 / Section 6.2.4, p. 51 vs. Figures 7-2–7-8, pp. 59–64]

**This is the highest-priority open question for any implementation. Address must be verified against hardware.**

---

## 8. Ambiguous Wording in Source Documents

### 8.1 GCEN Bit Description

The GCEN bit is described in the General Call section (p. 53) as controlling whether the device responds to GC, but is not assigned a register address or bit number in the available text. The implementation source is ambiguous.

### 8.2 "Volatile" in Context of Factory-Programmed Default

The POR/BOR default wiper code is described as a "default wiper setting" selectable via device ordering (e.g., -502 = mid scale). Section 9.2 mentions the ability to request a "custom wiper setting" via NSCAR. This implies the POR value is stored somewhere non-volatile at the factory. The mechanism (laser fuse, OTP, etc.) is not described.

### 8.3 TCON Reserved Bits [7:4]

The datasheet shows reserved bits [7:4] of TCON0 as always reading `1111` (reset = FFh). The datasheet does not explicitly state whether these bits must be written as `1` or may be written as `0`. The REGISTER 4-1 description marks them as "Reserved" but does not give a "write as X" instruction. Best practice (not stated in the document) is to always write the upper nibble as `0xF` to avoid undefined behavior.

### 8.4 "High-Voltage" Terminal Behavior at V+ = V−

No description is given for device behavior when V+ = V− (single-supply with no analog span). Presumably all potentiometer values would be 0, but this is not stated.

---

## 9. Supplemental Document Extracts

The following supplemental PDFs are present in `docs/` and now have raw text extractions in `docs/pdf-extracted-md/`:

| File | Extract | Content | Potential Impact on Implementation |
|---|---|---|---|
| `MCP45HVX1_Errata_DS80000649B.pdf` | `MCP45HVX1_Errata_DS80000649B.md` | Device errata | **Critical** — I2C-interface anomalies require implementation review |
| `Microchip_AN691_Optimizing_Digital_Potentiometer_Circuits.pdf` | `Microchip_AN691_Optimizing_Digital_Potentiometer_Circuits.md` | Precision optimization AN | May specify resistor compensation techniques |
| `Microchip_AN692_Precision_Single_Supply_Photo_Detection.pdf` | `Microchip_AN692_Precision_Single_Supply_Photo_Detection.md` | Photo-detection precision AN | Application guidance; likely not core-driver normative |
| `Microchip_AN1080_Digital_Potentiometer_Resistor_Variations.pdf` | `Microchip_AN1080_Digital_Potentiometer_Resistor_Variations.md` | Digital pot resistor variations | May detail RZS, RFS, and RS characterization |
| `Microchip_AN737_Low_Pass_Adjustable_Filters.pdf` | `Microchip_AN737_Low_Pass_Adjustable_Filters.md` | Low-pass adjustable filters | Application guidance |
| `Microchip_AN219_Comparing_Digital_Potentiometers_To_Mechanical_Potentiometers.pdf` | `Microchip_AN219_Comparing_Digital_Potentiometers_To_Mechanical_Potentiometers.md` | Digital vs. mechanical potentiometers | Background only |
| `Microchip_Digital_Potentiometers_Design_Guide_DS20002017.pdf` | `Microchip_Digital_Potentiometers_Design_Guide_DS20002017.md` | Design guide | Cross-device guidance |
| `MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf` | `MCP45HVX1_Typical_Performance_Curves_DS20005307A.md` | Typical characteristics curves | Temperature/voltage performance data not in primary datasheet; graph values require PDF review |

> The `MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf` source is particularly relevant because it contains characterization curves for:
> - Resistance vs. temperature
> - Resistance vs. supply voltage  
> - INL/DNL vs. wiper code
> - Bandwidth vs. supply/RAB
> - These curves are referenced in the primary datasheet but not reproduced in text form.

---

## 10. Items Likely Needed for Implementation But Not Fully Specified

The following are items that a driver/library implementation would typically need, and which are either absent or incomplete in the available documentation:

| Item | Status | Notes |
|---|---|---|
| **I²C device address** | **CONFLICT** | TABLE 6-2 says 0x3C–0x3F; Figures 7-2–7-8 say 0x5C–0x5F — must verify on hardware |
| POR/BOR threshold for VL | **Documented (typical only)** | VPOR = 1.8 V typ, VDBOR = 1.55 V typ — in file 03 Section 2.2; no Min/Max given |
| POR completion time (tPOR) | **Missing** | Device ready time after power-up unknown |
| SCL/SDA pull-up recommendations | **Missing** | No specific values given |
| GCEN bit register location | **Unclear** | Referenced but not located in register map |
| Errata content | **Extracted** | Review `MCP45HVX1_Errata_DS80000649B.pdf` before changing I2C/shared-bus behavior |
| Behavior at V+ = V− (single supply, no analog span) | **Unspecified** | Not described |
| Maximum allowed SCL frequency in Standard/Fast mode | **Partial** | Timing tables in file 03 give tHD:STA, tSU:STA, etc. but max SCL implicitly 400 kHz (Fast) and 1.7 MHz (HS) |
| D8 bit function | **Unclear** | Stated as "defined" but not described |
| Reserved bits [7:4] in TCON write requirement | **Ambiguous** | Should write as 1 (implied by reset = FFh) but not explicitly stated |
| Non-volatile memory mechanism | **Unresolved** | Title implies NVM; body describes only volatile registers |
| Typical wiper resistance vs. wiper code curve | **In DS20005307A** | Raw text extracted; use source PDF for graph interpretation |
| Terminal behavior during power-up (before POR) | **Unspecified** | Not found |
| V− bypass capacitor recommendation | **Implicit** | Not explicitly stated (may be in application notes) |

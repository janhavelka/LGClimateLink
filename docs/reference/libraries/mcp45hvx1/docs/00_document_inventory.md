# MCP45HVX1 — Document Inventory and Navigation Index

> **Primary datasheet:** DS20005304B, "MCP45HVX1 Single 7-Bit/8-Bit High-Voltage I2C™ Digital Potentiometer with Non-Volatile Memory", Rev B, June 2023, Microchip Technology Inc., 102 pages.
> All citations in this document set reference **DS20005304B** unless otherwise stated.

---

## 1. Document Inventory

### 1.1 Documents Available in `docs/`

| File | Document Number | Type | Title / Description | Rev / Date | Status |
|---|---|---|---|---|---|
| `MCP45HVX1-Data-Sheet-DS20005304.pdf` | DS20005304B | Primary Datasheet | Single 7-Bit/8-Bit HV I2C Digital Potentiometer | Rev B, June 2023 | **PRIMARY — curated extraction and raw text available** |
| `MCP45HVX1-Data-Sheet-DS20005304-Duplicate.pdf` | DS20005304B | Primary Datasheet | Duplicate copy of the primary datasheet | Rev B, June 2023 | Duplicate SHA256 of primary datasheet; raw extraction skipped |
| `MCP45HVX1_Errata_DS80000649B.pdf` | DS80000649B | Errata | MCP45HVX1 Rev. A1 Silicon/Data Sheet Errata | Rev B, 2015 | Raw text extraction available |
| `MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf` | DS20005307A | Typical Performance Curves | MCP45HVX1 Typical Performance Curves | Rev A, 2014 | Raw text extraction available; graph values require PDF review |
| `Microchip_AN691_Optimizing_Digital_Potentiometer_Circuits.pdf` | DS00691A / AN691 | Application Note | Optimizing Digital Potentiometer Circuits to Reduce Absolute and Temperature Variations | Rev A, 2001 | Raw text extraction available |
| `Microchip_AN692_Precision_Single_Supply_Photo_Detection.pdf` | DS00692B / AN692 | Application Note | Using a Digital Potentiometer to Optimize a Precision Single-Supply Photo Detection Circuit | Rev B, 2004 | Raw text extraction available |
| `Microchip_AN1080_Digital_Potentiometer_Resistor_Variations.pdf` | DS01080A / AN1080 | Application Note | Understanding Digital Potentiometer Resistor Variations | Rev A, 2007 | Raw text extraction available |
| `Microchip_AN737_Low_Pass_Adjustable_Filters.pdf` | DS00737C / AN737 | Application Note | Using Digital Potentiometers to Design Low-Pass Adjustable Filters | Rev C, 2004 | Raw text extraction available |
| `Microchip_AN219_Comparing_Digital_Potentiometers_To_Mechanical_Potentiometers.pdf` | DS00219A / AN219 | Application Note | Comparing Digital Potentiometers to Mechanical Potentiometers | Rev A, 2000 | Raw text extraction available |
| `Microchip_Digital_Potentiometers_Design_Guide_DS20002017.pdf` | DS20002017 | Design Guide / Brochure | Digital Potentiometers Design Guide | Current Microchip download | Raw text extraction available |

### 1.2 Reading Method

The source PDFs in `docs/` were checked against official Microchip download URLs on 2026-05-09. The local SHA256 hashes matched the official downloads for the datasheet, errata, typical curves, application notes, and design guide.

Raw text was extracted locally with `pypdf` into `docs/pdf-extracted-md/`. These raw extracts preserve page boundaries and are useful for search and traceability, but figures, graphs, equations, and dense tables still require checking against the original PDFs.

The curated files `01_*.md` through `08_*.md` remain the driver-oriented extraction from DS20005304B Rev B. Supplemental PDF content is now available as raw text; it has not been fully re-integrated into every curated topic file.

### 1.3 Primary Document Determination

DS20005304B is the sole normative source for all electrical, timing, protocol, register, and functional specifications unless a conflict note states otherwise. Supplemental documents are present for errata, characterization curves, and application guidance; their raw extracts should be reviewed before changing driver behavior.

---

## 2. Coverage Checklist

| Category | Covered | Source / Notes |
|---|---|---|
| Device identity and variants | ✅ | DS20005304B p.1–2, p.99 |
| Feature summary | ✅ | DS20005304B p.1–2 |
| Package / part-number distinctions | ✅ | DS20005304B p.99–100 |
| Pinout | ✅ | DS20005304B p.24 |
| Pin descriptions | ✅ | DS20005304B p.24–26 |
| Supply requirements | ✅ | DS20005304B p.3–4 |
| Absolute maximum ratings | ✅ | DS20005304B p.3 |
| Recommended operating conditions | ✅ | DS20005304B p.4 |
| DC electrical characteristics | ✅ | DS20005304B p.4–16 |
| AC / timing characteristics | ✅ | DS20005304B p.16–20 |
| Temperature characteristics | ✅ | DS20005304B p.21–23 |
| Protocol behavior (I2C) | ✅ | DS20005304B p.48–64 |
| Commands / transactions | ✅ | DS20005304B p.56–64 |
| Addressing scheme | ✅ | DS20005304B p.51 |
| Register map | ✅ | DS20005304B p.35–38 |
| Bit fields and reset values | ✅ | DS20005304B p.36–38 |
| Power-up / POR / BOR behavior | ✅ | DS20005304B p.28–31 |
| Initialization requirements | ✅ | DS20005304B p.28–31, p.65–70 |
| Reset behavior (software reset) | ✅ | DS20005304B p.71 |
| Shutdown / power modes | ✅ | DS20005304B p.47, p.31–34 |
| WLAT pin operation | ✅ | DS20005304B p.27 |
| SHDN pin operation | ✅ | DS20005304B p.27–28, p.47 |
| General Call | ✅ | DS20005304B p.53–55 |
| HS mode | ✅ | DS20005304B p.52–53 |
| Error conditions / NACK behavior | ✅ | DS20005304B p.56–64 |
| Wiper resistance / terminal currents | ✅ | DS20005304B p.41–47 |
| Resistor network equations | ✅ | DS20005304B p.39–47 |
| Operating modes (potentiometer / rheostat) | ✅ | DS20005304B p.46–47 |
| Variant differences (7-bit vs 8-bit) | ✅ | DS20005304B multiple pages |
| Package differences (TSSOP-14 vs VQFN-20) | ✅ | DS20005304B p.24, p.80–95 |
| Packaging dimensions / land patterns | ✅ | DS20005304B p.80–95 |
| Typical performance curves | ⚠️ | Raw text extracted from `MCP45HVX1_Typical_Performance_Curves_DS20005307A.pdf`; graph interpretation still requires PDF review |
| Errata | ✅ | Raw text extracted from `MCP45HVX1_Errata_DS80000649B.pdf` |
| Application note content (AN691, AN692, AN1080, AN737, AN219) | ✅ | Raw text extracted under `docs/pdf-extracted-md/` |
| Design guide content (DS20002017) | ✅ | Raw text extracted from `Microchip_Digital_Potentiometers_Design_Guide_DS20002017.pdf` |
| Formulas / terminology | ✅ | DS20005304B Appendix B, p.96–98 |
| Product identification system | ✅ | DS20005304B p.99–100 |

---

## 3. Output Navigation Index

| File | Contents |
|---|---|
| `00_document_inventory.md` (this file) | Document list, reading method, coverage checklist, navigation index |
| `01_chip_overview.md` | Device identity, family members, features, part-number system, package options, supply overview, key operating parameters |
| `02_pinout_and_signals.md` | Complete pin table (TSSOP-14 and VQFN-20), pin-by-pin descriptions, special pin functions (WLAT, SHDN, A0/A1), NC/EP handling, buffer types |
| `03_electrical_and_timing.md` | Absolute maximum ratings, DC characteristics tables (all variants/supplies), AC/timing tables (I2C standard/fast/HS), thermal resistance, temperature characteristics summary |
| `04_protocol_commands_and_transactions.md` | I2C signal descriptions, bus state definitions, addressing (7-bit, A0/A1, base value), HS mode master code, General Call (addressing + all GC commands), Write/Read/Increment/Decrement transaction formats with exact frame layouts, NACK/error behavior |
| `05_register_map.md` | Memory map (00h–0Fh), Wiper 0 register (00h) full description, TCON0 register (04h) with all bit fields, reset values, access types, reserved address behavior |
| `06_modes_interrupts_status_and_faults.md` | Hardware shutdown (SHDN pin), TCON software shutdown (R0HW/R0A/R0W/R0B), SHDN vs TCON interaction, WLAT latching behavior, terminal connection states, device current consumption modes, error/NACK conditions, GCEN bit |
| `07_initialization_reset_and_operational_notes.md` | POR/BOR events (Tables 4-1 through 4-5), power-up sequencing rules, VL–V- delta requirement, software reset sequence (Section 8.2), WLAT usage, analog power design notes, bypass capacitor recommendations, level shifter requirement |
| `08_variant_differences_and_open_questions.md` | MCP45HV31 vs MCP45HV51 differences, TSSOP-14 vs VQFN-20 differences, resistance-option differences, ordering/part-number system, custom options, known ambiguities, and supplemental-document notes |

---

## 4. Source Document Details

**DS20005304B** — Full bibliographic information as extracted from the document:
- Title: "MCP45HVX1 Single 7-Bit/8-Bit High-Voltage I2C™ Digital Potentiometer with Non-Volatile Memory"  
  *(Note: Title says "Non-Volatile Memory" but all registers are volatile RAM; terminology note: "Non-Volatile" may be a title carry-over from related families or refer to TCON default behavior. See `08_variant_differences_and_open_questions.md` for this ambiguity.)*
- Document Number: DS20005304B
- Revision: B
- Date: June 2023
- © 2014–2023 Microchip Technology Inc. and its subsidiaries
- Total pages: 102

---

*The curated driver extraction files are based on DS20005304B Rev B (June 2023). Raw supplemental extractions are available under `docs/pdf-extracted-md/` for traceability and follow-up review.*

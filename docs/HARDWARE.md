# Hardware Notes

## MCU

Target module:

```text
ESP32-S2-MINI-2-N4
Arduino framework
USB CDC enabled on boot
```

PlatformIO currently uses `esp32-s2-saola-1` as the closest 4 MB ESP32-S2 board definition.

## LIN Interface

Transceiver: TLIN1027DRQ1 or equivalent without TXD dominant timeout.

Configured pins:

```text
LIN_EN GPIO16
LIN_TX GPIO17
LIN_RX GPIO18
```

Firmware assumptions:

- `LIN_EN` active high enables normal mode.
- TX idles high/recessive before enabling the transceiver.
- RX is sampled directly to confirm bus idle before transmit.

Verify EN polarity and any additional TLIN1027 pins against the schematic.

## I2C

Configured placeholders:

```text
SDA GPIO8
SCL GPIO9
100 kHz
50 ms timeout
```

Devices:

| Device | Address | Notes |
| --- | --- | --- |
| BME280 | 0x76 default, 0x77 alternate | Uses `janhavelka/BME280` injected I2C callbacks. |
| MCP45HVX1 | 0x3C default, 0x3C..0x3F expected | Uses `janhavelka/MCP45HVX1` injected I2C callbacks. |

MCP45HVX1 errata warns about affected silicon accepting traffic intended for other clients. Production hardware should either isolate the MCP45HVX1 on its own I2C bus or validate the exact silicon marking and mixed-bus behavior.

## Status LEDs

Devices: SK6805D-EC2018 / WS2812-class.

Configured pins:

```text
STAT_LED GPIO36
PAIR GPIO37
```

Default topology is one data chain on `STAT_LED` with two pixels. The firmware also supports two independent outputs using `STAT_LED` and `PAIR`, but the actual board topology must be verified from the PCB/schematic.

## MCP45HVX1 Analog Path

Assumed initial software model:

```text
MCP45HV51
8-bit wiper
5 kOhm nominal RAB
rheostat B-W topology
75 ohm estimated wiper resistance
```

The firmware supports A-W/B-W topology, code inversion, series resistance, and clamped min/max resistance. Actual production constants require hardware measurements.

## Electrical Bring-Up Checklist

Record these measurements before connecting the controller to an HVAC unit.

| Check | Expected result | Measured result | Pass |
| --- | --- | --- | --- |
| Board supply current at idle | Stable and within power budget. | TBD | TBD |
| ESP32-S2 3.3 V rail | Within regulator tolerance during Wi-Fi TX and LED updates. | TBD | TBD |
| I2C pull-up voltage | Matches BME280 and MCP45HVX1 logic limits. | TBD | TBD |
| BME280 I2C address | 0x76 or 0x77 visible in `i2c scan`. | TBD | TBD |
| MCP45HVX1 I2C address | 0x3C..0x3F visible in `i2c scan`. | TBD | TBD |
| MCP45HVX1 high-voltage terminals | Terminal voltages stay inside datasheet limits for the selected supply rails. | TBD | TBD |
| LG sensor-pin open-circuit voltage | Safe for MCP45HVX1 terminal ratings and board resistor network. | TBD | TBD |
| LG sensor-pin current at min resistance | Safe for MCP45HVX1, series resistors, and LG input. | TBD | TBD |
| Effective resistance at safe code | Matches firmware estimate within acceptable tolerance. | TBD | TBD |
| Effective resistance at min/max allowed code | Never leaves the allowed LG sensor range. | TBD | TBD |
| Resistance during MCU reset | Falls to a safe value or documented hardware failsafe state. | TBD | TBD |
| Resistance during brownout/power loss | Falls to a safe value or documented hardware failsafe state. | TBD | TBD |
| LIN recessive voltage | Matches LG bus and TLIN1027 expectations. | TBD | TBD |
| LIN dominant voltage | Matches LG bus and TLIN1027 expectations. | TBD | TBD |
| LIN ground reference | Controller ground reference is compatible with the LG wired-controller bus. | TBD | TBD |
| 104 baud TX bit timing | Measured bit width matches protocol tolerance. | TBD | TBD |

If any high-voltage terminal, LG sensor-pin, or reset-state measurement is unknown, do not leave the unit connected unattended.

## Open Hardware Items

| Item | Risk | Required verification |
| --- | --- | --- |
| I2C SDA/SCL pins | Medium | Schematic or continuity test. |
| LED topology | Low | Confirm one chain vs two outputs. |
| MCP45HVX1 terminal wiring | High | Measure resistance at LG sensor pins by wiper code. |
| Series resistors | High | Schematic/BOM plus measurement. |
| Original LG thermistor curve | High | Sensor measurements or service manual. |
| TLIN1027 enable polarity | Medium | Schematic/transceiver datasheet pin wiring. |
| Boot-time analog failsafe | High | Measure LG sensor pins while MCU resets, boots, and crashes. |

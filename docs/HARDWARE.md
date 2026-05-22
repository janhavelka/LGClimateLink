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

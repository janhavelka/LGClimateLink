# LGClimateLink

Production-oriented Arduino + PlatformIO firmware for an ESP32-S2-MINI-2-N4 wired LG HVAC controller with local BME280 sensing, MCP45HVX1 virtual thermistor output, USB CDC CLI, WS2812-class status LEDs, and Home Assistant integration over MQTT Discovery.

This is not an ESPHome YAML project. The LG protocol behavior is based on Jan M321's reverse engineering work:

- https://github.com/JanM321/esphome-lg-controller
- https://github.com/JanM321/esphome-lg-controller/blob/main/protocol.md

The firmware uses the requested driver libraries directly:

- `janhavelka/MCP45HVX1`
- `janhavelka/StatusLED`
- `janhavelka/BME280`

Supporting upstream protocol notes, component datasheets, library manuals, and Home Assistant MQTT reference pages are vendored under `docs/reference/`.

## Hardware Assumptions

Target MCU: ESP32-S2-MINI-2-N4, Arduino framework, USB CDC enabled on boot.

Pin mapping currently implemented:

| Function | GPIO | Notes |
| --- | ---: | --- |
| LIN transceiver enable | 16 | Assumed active-high TLIN1027 normal mode. Verify against schematic. |
| LIN TXD | 17 | UART1 TX at 104 baud, 8N1. |
| LIN RXD | 18 | UART1 RX, also sampled for 500 ms idle-before-send guard. |
| Status LED chain | 36 | `STAT_LED`; default topology is one chain with two pixels. |
| Pair LED output | 37 | `PAIR`; supported as second independent output by setting topology in firmware config. |
| I2C SDA | 8 | Placeholder until schematic confirms final pins. |
| I2C SCL | 9 | Placeholder until schematic confirms final pins. |
| BME280 I2C | 0x76 | Configurable to 0x77. |
| MCP45HVX1 I2C | 0x3C | Configurable in 0x3C..0x3F. |

Critical hardware verification is still required for I2C pins, LED topology, MCP45HVX1 terminal wiring, any series resistors, and the original LG thermistor curve.

## Build, Upload, Monitor

```powershell
pio run
pio run -e esp32-s2-mini-2-n4 -t upload
pio device monitor -b 115200
pio test -e native
```

USB CDC is enabled with:

```ini
-DARDUINO_USB_MODE=0
-DARDUINO_USB_CDC_ON_BOOT=1
```

## Home Assistant

Configure Wi-Fi and MQTT from the USB CLI:

```text
wifi config <ssid> <password>
mqtt config <broker-host> 1883 [user] [password]
config save
reboot confirm
```

On MQTT connection the firmware publishes a retained device discovery payload to:

```text
homeassistant/device/<device_id>/config
```

Runtime topics use:

```text
<mqtt_base>/<device_id>/availability
<mqtt_base>/<device_id>/availability/lg_bus
<mqtt_base>/<device_id>/availability/bme280
<mqtt_base>/<device_id>/state/climate
<mqtt_base>/<device_id>/state/bme280
<mqtt_base>/<device_id>/state/health
<mqtt_base>/<device_id>/event/error
<mqtt_base>/<device_id>/cmd/mode
<mqtt_base>/<device_id>/cmd/target_temp
<mqtt_base>/<device_id>/cmd/fan_mode
<mqtt_base>/<device_id>/cmd/swing_mode
<mqtt_base>/<device_id>/cmd/thermistor_mode
<mqtt_base>/<device_id>/cmd/digipot_wiper
```

Discovery exposes the LG climate entity, BME280 temperature/humidity/pressure, thermistor mode, digipot resistance, fault state, and LG bus connectivity. Command topics are not retained; on MQTT reconnect the firmware clears retained command topics before subscribing to reduce stale-command risk.

## CLI Reference

Open `pio device monitor -b 115200`.

Core commands:

```text
help
status
health
uptime
reboot confirm
wifi status
wifi config <ssid> <password>
wifi clear
mqtt status
mqtt config <host> <port> [user] [password]
mqtt clear
lg status
lg trace <on|off>
lg send arm
lg send <13 hex bytes>
lg test
bme status
bme read
digipot status
digipot set arm
digipot set code <0..255>
digipot test
digipot calibrate
ntc calc <temp_c>
led status
led test <r> <g> <b>
i2c scan
config show
config set <key> <value>
config save
config reset
logs level
watchdog status
```

Dangerous operations require arming. Raw LG frames and raw digipot writes are single-shot.

## Safety Behavior

- LG TX is only attempted after the RX line has been high/idle for at least 500 ms.
- The parser is sliding-window based and resynchronizes after boot garbage or corrupted bytes.
- The virtual thermistor path clamps all target resistance and wiper outputs.
- On boot the MCP45HVX1 is initialized to a safe configured wiper before normal BME280-driven control.
- On stale or invalid BME280 data, the digipot holds the last safe value for a bounded interval, then moves to a safe fixed output.
- MQTT and Wi-Fi failures do not block local LG communication or the virtual thermistor path.
- Settings writes are delayed and coalesced to reduce flash wear.
- The watchdog is fed only when the health quorum is acceptable.

## Calibration

The shipped thermistor defaults are intentionally conservative and reachable with the 5 kOhm MCP45HV51-502E:

```text
Rref: 5000 ohm at 25 C
Beta: 3950 K
Allowed virtual resistance: 1000..5075 ohm
Safe resistance: about 2565 ohm
```

These are not confirmed LG constants. Before unattended operation, measure the original LG room sensor or validate the service manual values, then update:

- thermistor model: beta, Steinhart-Hart, or table
- R25/reference resistance
- beta or Steinhart-Hart coefficients
- min/max valid temperature
- min/max valid resistance
- MCP45HVX1 terminal topology and series resistance

See [docs/DIGIPOT_NTC_EMULATION.md](docs/DIGIPOT_NTC_EMULATION.md).

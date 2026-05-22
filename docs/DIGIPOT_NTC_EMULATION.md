# Digipot NTC Emulation

The MCP45HVX1 output is treated as a safety-critical virtual room sensor. The firmware does not allow MQTT or CLI to write arbitrary raw wiper values unless the user explicitly arms a one-shot manual command.

## Conversion Path

```text
BME280 temperature
  -> validated fresh temperature
  -> thermistor model resistance
  -> clamp to allowed resistance
  -> convert resistance to MCP45HVX1 wiper code
  -> clamp code
  -> write wiper and read back
```

Supported thermistor models:

- beta equation
- Steinhart-Hart
- monotonic calibration table

The beta model uses:

```text
R = Rref * exp(beta * (1/T - 1/Tref))
```

Temperatures are Kelvin in the equation. PTC polarity can be selected by inverting the beta sign.

## Digipot Model

The default part is MCP45HV51-502E/ST:

```text
nominal RAB: 5000 ohm
resolution: 8 bit, code 0..255
default topology: rheostat B-W
default wiper resistance estimate: 75 ohm
```

Effective resistance estimate:

```text
B-W: series + wiper + (code / max_code) * RAB
A-W: series + wiper + (1 - code / max_code) * RAB
```

`invertCode` can be enabled if the board wiring makes the logical code direction opposite to the physical sensor curve.

## Safe Defaults

The defaults are reachable with a 5 kOhm digipot:

```text
Rref: 5000 ohm at 25 C
beta: 3950 K
allowed target resistance: 1000..5075 ohm
safe wiper code: 127
safe resistance estimate: about 2565 ohm
```

These constants are not claimed to be the original LG sensor. They are safe software placeholders until the real thermistor and board topology are verified.

## Failure Behavior

On boot:

1. Validate calibration.
2. Initialize MCP45HVX1.
3. Set terminal topology.
4. Write the configured safe wiper code.

During operation:

- Fresh plausible BME280 temperature drives normal emulation.
- Invalid temperature immediately moves to safe fixed state.
- Stale BME280 input holds last good output for `holdLastGoodMs`.
- After hold expires, safe fixed output is written.
- I2C/write/readback faults move the service to `Fault`.

## Hardware Verification TODOs

Missing information:

- original LG sensor type: NTC or PTC
- resistance at reference temperatures
- beta or Steinhart-Hart coefficients
- MCP45HVX1 A/W/B terminal wiring
- series resistor values around the digipot
- WLAT/SHDN strap behavior
- allowed voltage/current at the LG sensor input

Safe current behavior:

- output is clamped
- safe fixed wiper is written on boot/fault/stale sensor
- raw wiper writes require CLI arming

Verification method:

- measure original sensor resistance at several known temperatures
- measure effective resistance from LG sensor pins for several wiper codes
- confirm boot/reset/power-loss resistance with the MCU held in reset
- validate LG unit behavior across min/max simulated room temperatures

Risk level: high until the original sensor curve and board resistor network are verified.

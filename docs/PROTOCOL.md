# LG Protocol Implementation

This firmware implements the modern LG wired-controller 13-byte protocol documented by JanM321:

- https://github.com/JanM321/esphome-lg-controller/blob/main/protocol.md
- https://github.com/JanM321/esphome-lg-controller/blob/main/esphome/components/lg_controller/lg-controller.h

## Link Layer

The LG CN-REMO wired-controller bus is a very slow single-wire serial link through a LIN-compatible transceiver.

```text
Baud: 104
Framing: 8N1
Frame length: 13 bytes
Checksum: (sum(bytes[0..11]) & 0xff) ^ 0x55
```

There is no start-of-frame byte. `LgProtocol::FrameParser` therefore uses a sliding 13-byte window, validates product/source bits, and checks checksum before accepting a frame. This is intentional; fixed 13-byte chunking can remain desynchronized after boot noise.

## Source And Type

Byte 0 contains source, product type, and low 3-bit message type.

```text
0xA8..0xAF master controller
0x28..0x2F slave controller
0xC8..0xCF indoor unit
low 3 bits: message type 0..7
```

Only normal HVAC product framing is accepted.

## Implemented Types

Type 0 status (`A8/C8/28`) drives normal climate state:

- power and HVAC mode
- target temperature
- current room temperature
- fan mode
- vertical/horizontal swing
- thermistor installer mode
- purifier
- sleep timer
- defrost, preheat, outdoor active
- error code

Type 1 capabilities (`C9`) updates capability flags:

- supported modes
- fan capabilities
- swing support
- vane count
- purifier and auto-dry
- installer feature support
- min setpoint hint

Type 2 settings (`AA/CA/2A`) updates:

- fan installer speed values
- vane positions 1..4
- auto-dry enable

Type 3 settings/status (`AB/CB/2B`) updates:

- over-heating installer value
- pipe temperatures through the known lookup table
- timed request for a `CB` response

Types 4..7 are parsed as valid frames but not yet mapped into control state.

## Timing

The controller only transmits after the RX line is idle/high for at least 500 ms. This follows the reference behavior and reduces bus collisions because LG controllers often repeat frames with short spacing.

The master sends:

- status at least every 20 seconds
- status immediately when desired state changes
- type B request every 10 minutes for pipe temperature/status data

The firmware expects to receive its own transmitted bytes as echo through the single-wire bus. Missing echo increments a missed-echo counter and the command is retried through the pending state machine.

## Golden Vectors

Known checksum/parser vectors used in tests:

```text
00 00 00 00 00 00 00 00 00 00 00 00 => checksum 55
C9 C4 EA 1F 81 71 00 80 02 40 04 81 9A
A8 22 00 00 00 00 16 20 40 00 80 00 95
A8 10 00 00 00 00 08 14 00 00 00 00 81
```

## Known Limits

- Capability bits are reverse engineered and must be validated with real unit captures.
- LG multi-split outdoor-active behavior can reflect another indoor unit, so climate action is reported conservatively.
- The 6-byte older controller protocol is not implemented.
- Ventilation/ERV product framing is not implemented.

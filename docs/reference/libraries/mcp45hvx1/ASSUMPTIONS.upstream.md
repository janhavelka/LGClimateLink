# MCP45HVX1 Implementation Assumptions

- The default I2C address range is `0x3C-0x3F`, derived from DS20005304B Rev B
  Table 6-2 and the text-extracted official PDF. The extracted markdown notes a
  conflicting `0x5C-0x5F` range; the driver rejects that range unless
  `Config::allowAlternateAddressRange` is explicitly enabled for hardware
  verification. Bench results should be recorded in `docs/hardware_validation.md`.
- The device is treated as volatile-only. No user-accessible non-volatile memory
  API is exposed because the register map documents only Wiper 0 and TCON0 RAM.
- TCON reserved bits `[7:4]` are always written as `1`.
- The undocumented `GCEN` bit is not exposed. General Call command helpers only
  send the documented broadcast frames.
- Address `0x01` is treated as reserved despite a continuous-write figure note
  mentioning it.
- Nominal resistance helpers are ideal calculations from the ordering option and
  wiper code. They do not model tolerance, wiper resistance, leakage, INL/DNL, or
  high-voltage operating conditions.
- The core driver cannot generate the documented software-reset waveform because
  it is transport-agnostic. `Config::busReset` lets board code provide that
  sequence.

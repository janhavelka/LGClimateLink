# Hardening Report

Date: 2026-05-22

## Audit Passes Performed

1. Reference/protocol audit
   - Reviewed JanM321 protocol documentation and ESPHome component behavior.
   - Implemented 13-byte parser, checksum, sender/type classification, status mapping, capability handling, and timing assumptions.
   - Added native golden-vector tests.

2. Hardware/library audit
   - Inspected MCP45HVX1, StatusLED, and BME280 public APIs.
   - Used injected I2C transports for BME280 and MCP45HVX1.
   - Used StatusLED nonblocking tick API.
   - Documented missing schematic/board facts.

3. Architecture audit
   - Kept services small: LG, BME280, digipot, MQTT/HA, status LED, storage, health, watchdog, CLI.
   - Kept pure logic separate from Arduino adapters where practical.
   - Avoided direct MQTT/CLI raw writes into safety outputs.

4. Safety/reliability audit
   - Added stale BME280 detection.
   - Added digipot boot-safe, hold-last-good, safe-fixed, fault, and manual modes.
   - Added watchdog quorum model.
   - Added delayed settings writes.
   - Added reset reason and boot count reporting.

5. Home Assistant/MQTT audit
   - Added MQTT Discovery device payload.
   - Added availability, state, health, BME280, and command topics.
   - Added command validation and rejection reason tracking.
   - Clears retained command topics before subscribing after connect.

6. Test/QA audit
   - Native tests cover LG parser/checksum/mapping, MQTT command validation, thermistor/digipot conversion, BME stale logic, settings validation, and watchdog quorum.
   - Firmware build passes for the ESP32-S2 target.

7. Documentation/provenance audit
   - Added `docs/reference/` with upstream protocol/library documentation, source licenses, hardware datasheets, Home Assistant MQTT pages, and platform API references.
   - Recorded upstream repository commits and download sources in `docs/reference/README.md`.

## Findings And Fixes

| Finding | Severity | Fix |
| --- | --- | --- |
| Fixed 13-byte protocol parsing can desynchronize after boot noise. | High | Implemented sliding-window parser with checksum/source validation. |
| Virtual thermistor constants were not reachable with 5 kOhm digipot defaults. | High | Changed defaults to reachable 5 kOhm placeholder values and documented mandatory calibration. |
| Raw digipot writes could be dangerous if exposed directly. | High | CLI/MQTT raw wiper writes require a one-shot arming state. |
| Stale BME280 data could drive false room temperature. | High | Added freshness tracking, hold-last-good timeout, and safe fixed fallback. |
| Logging/CLI could block hot paths. | Medium | CLI drains a bounded byte budget per loop and avoids long blocking waits. |
| MQTT retained command payloads could replay after reboot. | Medium | Firmware publishes empty retained payloads to command topics before subscribing. |
| Settings writes could wear flash. | Medium | Added delayed/coalesced NVS save path. |
| USB CDC Serial macro was wrong for native USB mode. | Medium | Set `ARDUINO_USB_MODE=0` with `ARDUINO_USB_CDC_ON_BOOT=1`. |
| StatusLED legacy RMT backend produced deprecated driver warning. | Low | Switched build flag to `STATUSLED_BACKEND_IDF5_WS2812=1`. |

## Remaining Hardware-Verification Items

These are not software blockers, but they must be closed before unattended production use.

| Item | Missing information | Safe current behavior | How to verify | Risk |
| --- | --- | --- | --- | --- |
| I2C pins | Final SDA/SCL nets are not present in this workspace. | Uses GPIO8/GPIO9 placeholders. | Check schematic/PCB netlist and run `i2c scan`. | Medium |
| LED topology | Unknown whether GPIO36/GPIO37 are one chain or two independent outputs. | Defaults to one chain; code supports two outputs. | Inspect PCB netlist or run `led test`. | Low |
| MCP45HVX1 topology | A/W/B terminal wiring, series resistors, WLAT/SHDN wiring unknown. | Uses clamped B-W rheostat model and safe wiper. | Measure effective resistance at LG sensor pins over wiper codes. | High |
| Original LG thermistor curve | NTC/PTC type and curve unknown. | Uses reachable 5 kOhm placeholder curve. | Measure original sensor or obtain service manual values. | High |
| Analog failsafe | Resistance seen by LG unit during MCU reset/crash unknown. | Firmware writes safe code on boot; hardware default not proven. | Measure sensor-pin resistance during reset, power cycling, and forced watchdog. | High |
| TLIN1027 enable polarity | EN/SLP wiring not verified. | Assumes active-high enable. | Confirm schematic and scope bus idle/TX. | Medium |
| 104 baud UART tolerance | ESP32-S2 Arduino UART low-baud behavior not hardware-validated. | Firmware compiles and uses UART1 at 104 baud with parser tolerance. | Scope TX bit timing and test real LG traffic. | High |

## Final Audit Status

No known critical software issues remain in the compiled and tested code path. The unresolved risks are hardware-verification items, mainly the virtual thermistor analog topology and the original LG sensor curve. The firmware therefore should be treated as ready for bench bring-up, not yet approved for unattended connection to an HVAC unit until those items are measured and calibration is updated.

## Verification Results

```text
pio test -e native
8 test cases: 8 succeeded

pio run -e esp32-s2-mini-2-n4
SUCCESS
RAM: 20.4%
Flash: 77.8%

pio run
SUCCESS
RAM: 20.4%
Flash: 77.8%
```

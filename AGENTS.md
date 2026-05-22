# Agent Notes

This repository was generated as a greenfield firmware implementation.

Reference passes performed:

- LG protocol/reference behavior from JanM321's ESPHome controller.
- Hardware/library API pass for MCP45HVX1, StatusLED, and BME280.
- Architecture pass for small service ownership.
- Safety/reliability pass for watchdog, stale data, and failsafe behavior.
- Home Assistant/MQTT pass for discovery and topic design.
- Test/QA pass for native coverage.

Implementation constraints:

- Pure protocol, thermistor, settings, MQTT payload, BME freshness, and health logic must remain testable under `pio test -e native`.
- Arduino hardware access should stay in service/adaptor files.
- Raw LG send and raw digipot writes must remain guarded by arming commands.
- Do not persist telemetry or high-rate counters to flash.
- Update `HARDENING_REPORT.md` whenever safety behavior changes.

# Changelog

## 0.1.0 - 2026-05-22

- Initial Arduino + PlatformIO firmware scaffold for ESP32-S2-MINI-2-N4.
- Added LG 13-byte protocol parser, checksum, status mapping, and transmit state machine.
- Added BME280 service using `janhavelka/BME280`.
- Added MCP45HVX1 digipot service using `janhavelka/MCP45HVX1`.
- Added safe virtual thermistor conversion and clamping logic.
- Added StatusLED service using `janhavelka/StatusLED`.
- Added USB CDC serial CLI.
- Added Wi-Fi/MQTT Home Assistant Discovery service.
- Added NVS-backed settings store with delayed saves.
- Added health monitor and watchdog quorum.
- Added native PlatformIO tests.
- Added README, protocol, hardware, digipot, and hardening documentation.
- Added structured `docs/reference/` bundle with upstream protocol/library docs, hardware datasheets, Home Assistant MQTT references, and platform API references.

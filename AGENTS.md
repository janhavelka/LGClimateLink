# Agent Notes

## Git workflow

- Before editing, fetch and inspect the current branch and upstream; fast-forward
  only when safe.
- Keep the whole promptset on its existing branch. Do not create a branch or
  worktree per prompt or agent unless the user asks.
- Assume concurrent agents. Preserve unrelated changes; never stash, discard,
  overwrite, or commit them. A dirty worktree alone is not a blocker.
- After relevant checks pass, stage only your own files or hunks, then commit
  and push each meaningful completed chunk, including multiple times within
  one prompt and before finishing. No further permission is needed.
- When using subagents, the lead owns Git mutations for their shared work.
- Confirm upstream synchronization and check applicable CI for the pushed commit.
  Report conflicts or sync failures; never force-push to resolve them.

## Project guidance

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

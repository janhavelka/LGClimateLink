# Agent Notes

## CI and local verification

- Work with CI in mind from the start: inspect the relevant workflows and checks
  before implementation, reuse their commands, and keep changes compatible with
  their platforms, pinned dependencies, generated files and test registration.
- Run focused local checks for each change. Reserve remote CI dispatch and waiting
  for major changes: substantial behavior/API changes, cross-module integration,
  persistence/security changes, build/toolchain/dependency/workflow changes, and
  release or major integration milestones. Judge impact, not just diff size.
- Small documentation, comment, formatting and low-risk isolated edits need
  appropriate local verification, not a CI run after every commit or push. Batch
  related work before requesting CI; do not repeatedly dispatch unchanged suites.
- For major changes, use existing CI and verify the exact final commit through
  terminal results; dispatch it if needed. Fix confirmed failures without weakening
  checks. Report checks not run, blocked or failed honestly; never claim an older
  green run verifies a new commit. Honor required merge/release checks and existing
  hooks; do not change workflow triggers or bypass checks to avoid CI.

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
- Confirm upstream synchronization. Follow the CI and local verification policy
  above; report conflicts or sync failures and never force-push to resolve them.

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

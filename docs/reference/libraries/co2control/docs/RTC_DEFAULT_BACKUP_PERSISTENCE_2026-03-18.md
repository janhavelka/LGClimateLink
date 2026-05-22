# RTC Default Backup Persistence

This note documents why fresh runtime settings enable RV3032 backup persistence by default.

## Current Default

Fresh settings start with:

- `i2cRtcBackupMode = 1` (`Level`)
- `i2cRtcEnableEepromWrites = true`

The intent is that a new or reset device brings the RV3032 up with a persisted backup-switch configuration without requiring a separate manual commissioning step.

## Runtime Implications

- RTC I2C operations use an effective timeout floor of `50 ms` while backup persistence is active, because EEPROM-backed RTC operations can take longer than the generic bus timeout.
- The web helper that applies RTC backup setup may temporarily enable EEPROM writes, program the backup mode, and then restore the previous runtime EEPROM-write setting.
- The persisted backup configuration is a device-configuration concern; normal time reads still use the same task-owned I2C path and status/health model as the rest of the firmware.

## Why This Exists

Without persisted backup configuration, a factory-reset device can appear correctly wired but still fail to retain RTC behavior across power events until the user performs a separate setup step. The default favors predictable field behavior over a "minimum side effects" reset profile.

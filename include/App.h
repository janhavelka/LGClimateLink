#pragma once

/**
 * @file App.h
 * @brief Top-level Arduino application wiring for all firmware services.
 */

#ifdef ARDUINO

#include <Arduino.h>

#include "cli/SerialCli.h"
#include "config/RuntimeSettings.h"
#include "digipot/DigipotService.h"
#include "ha/MqttService.h"
#include "health/HealthMonitor.h"
#include "health/WatchdogService.h"
#include "lg/LgBus.h"
#include "lg/LgControllerService.h"
#include "sensors/Bme280Service.h"
#include "status/StatusLedService.h"
#include "storage/SettingsStore.h"

namespace lgcl {

/**
 * @brief Owns service instances and implements Arduino setup/loop behavior.
 *
 * App is intentionally the only broad composition object. Lower-level services
 * remain focused and testable where possible.
 */
class App final : public cli::ICliHandler {
 public:
  App();
  /// Initialize hardware, load settings, start services, and print boot status.
  void begin();
  /// Run one bounded iteration of all firmware services.
  void loop();
  /// Handle one parsed CLI command.
  void handleCliCommand(const cli::CliCommand& command, Print& out) override;

 private:
  void applyMqttCommand(const ha::MqttCommand& command);
  void updateHealth(uint32_t nowMs);
  status::DeviceLedState ledStateFromHealth(const health::HealthSnapshot& snapshot) const;
  void printHelp(Print& out) const;
  void printStatus(Print& out);
  void printHealth(Print& out) const;
  void printConfig(Print& out) const;
  void scanI2c(Print& out) const;
  bool saveSettings(Print& out);
  bool parseBool(const char* text, bool& out) const;
  bool parseFloat(const char* text, float& out) const;
  bool parseU32(const char* text, uint32_t& out) const;
  void reconfigureNetwork(uint32_t nowMs);
  uint32_t uptimeSec() const;
  const char* resetReason() const;

  config::RuntimeSettings settings_;
  storage::SettingsStore store_;
  lg::LgBus lgBus_;
  lg::LgControllerService lgService_;
  sensors::Bme280ArduinoDriver bmeDriver_;
  sensors::Bme280Service bmeService_;
  digipot::Mcp45hvx1ArduinoDriver digipotDriver_;
  digipot::DigipotService digipotService_;
  ha::MqttService mqtt_;
  status::StatusLedService leds_;
  health::HealthMonitor health_;
  health::EspTaskWatchdogPort watchdogPort_;
  health::WatchdogService watchdog_;
  cli::SerialCli cli_;

  uint32_t bootMs_ = 0;
  uint32_t lastHealthMs_ = 0;
  uint32_t lastMqttPublishMs_ = 0;
  uint32_t maxLoopLatencyUs_ = 0;
  bool dangerousLgSendArmed_ = false;
  bool dangerousDigipotArmed_ = false;
};

}  // namespace lgcl

#endif

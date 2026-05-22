#pragma once

/**
 * @file HealthMonitor.h
 * @brief Service health aggregation used by LEDs, MQTT, and watchdog gating.
 */

#include <stdint.h>

namespace lgcl::health {

/// Aggregated health level.
enum class HealthLevel : uint8_t {
  Ok = 0,
  Degraded,
  Fault,
};

/// Component slots tracked by the health monitor.
enum class ComponentId : uint8_t {
  MainLoop = 0,
  LgBus,
  Bme280,
  Digipot,
  I2c,
  Mqtt,
  Wifi,
  Storage,
  Count,
};

/// Runtime health state for one component.
struct HealthItem {
  const char* name = "";
  uint32_t lastOkMs = 0;
  uint32_t deadlineMs = 0;
  bool requiredForWatchdog = false;
  bool fault = false;
  bool degraded = false;
  const char* message = "not updated";
};

/// Full health evaluation result.
struct HealthSnapshot {
  HealthLevel level = HealthLevel::Fault;
  bool watchdogQuorum = false;
  const char* firstFailingComponent = "none";
  const char* firstFailingReason = "OK";
  HealthItem items[static_cast<uint8_t>(ComponentId::Count)] = {};
};

/**
 * @brief Tracks freshness, degraded state, and fault state for all services.
 *
 * Components required for watchdog feed must be configured with
 * requiredForWatchdog=true. evaluate() computes both user-visible health and
 * the watchdog quorum decision.
 */
class HealthMonitor {
 public:
  HealthMonitor();

  /// Configure one component slot.
  void configure(ComponentId id, const char* name, uint32_t deadlineMs, bool requiredForWatchdog);
  /// Mark a component healthy at nowMs.
  void markOk(ComponentId id, uint32_t nowMs, const char* message = "OK");
  /// Mark a component degraded but not fatal.
  void markDegraded(ComponentId id, uint32_t nowMs, const char* message);
  /// Mark a component faulted.
  void markFault(ComponentId id, uint32_t nowMs, const char* message);
  /// Evaluate all components against deadlines and explicit fault flags.
  HealthSnapshot evaluate(uint32_t nowMs) const;

 private:
  static uint8_t index(ComponentId id) { return static_cast<uint8_t>(id); }
  HealthItem items_[static_cast<uint8_t>(ComponentId::Count)] = {};
};

/// Human-readable health level name for CLI and MQTT.
const char* healthLevelName(HealthLevel level);

}  // namespace lgcl::health

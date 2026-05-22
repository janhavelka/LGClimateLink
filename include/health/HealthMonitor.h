#pragma once

#include <stdint.h>

namespace lgcl::health {

enum class HealthLevel : uint8_t {
  Ok = 0,
  Degraded,
  Fault,
};

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

struct HealthItem {
  const char* name = "";
  uint32_t lastOkMs = 0;
  uint32_t deadlineMs = 0;
  bool requiredForWatchdog = false;
  bool fault = false;
  bool degraded = false;
  const char* message = "not updated";
};

struct HealthSnapshot {
  HealthLevel level = HealthLevel::Fault;
  bool watchdogQuorum = false;
  const char* firstFailingComponent = "none";
  const char* firstFailingReason = "OK";
  HealthItem items[static_cast<uint8_t>(ComponentId::Count)] = {};
};

class HealthMonitor {
 public:
  HealthMonitor();

  void configure(ComponentId id, const char* name, uint32_t deadlineMs, bool requiredForWatchdog);
  void markOk(ComponentId id, uint32_t nowMs, const char* message = "OK");
  void markDegraded(ComponentId id, uint32_t nowMs, const char* message);
  void markFault(ComponentId id, uint32_t nowMs, const char* message);
  HealthSnapshot evaluate(uint32_t nowMs) const;

 private:
  static uint8_t index(ComponentId id) { return static_cast<uint8_t>(id); }
  HealthItem items_[static_cast<uint8_t>(ComponentId::Count)] = {};
};

const char* healthLevelName(HealthLevel level);

}  // namespace lgcl::health

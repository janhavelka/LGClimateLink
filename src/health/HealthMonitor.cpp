#include "health/HealthMonitor.h"

namespace lgcl::health {

HealthMonitor::HealthMonitor() {
  configure(ComponentId::MainLoop, "main_loop", 2000, true);
  configure(ComponentId::LgBus, "lg_bus", 180000, true);
  configure(ComponentId::Bme280, "bme280", 30000, true);
  configure(ComponentId::Digipot, "digipot", 30000, true);
  configure(ComponentId::I2c, "i2c", 30000, true);
  configure(ComponentId::Mqtt, "mqtt", 120000, false);
  configure(ComponentId::Wifi, "wifi", 120000, false);
  configure(ComponentId::Storage, "storage", 60000, false);
}

void HealthMonitor::configure(ComponentId id,
                              const char* name,
                              uint32_t deadlineMs,
                              bool requiredForWatchdog) {
  HealthItem& item = items_[index(id)];
  item.name = name;
  item.deadlineMs = deadlineMs;
  item.requiredForWatchdog = requiredForWatchdog;
}

void HealthMonitor::markOk(ComponentId id, uint32_t nowMs, const char* message) {
  HealthItem& item = items_[index(id)];
  item.lastOkMs = nowMs;
  item.fault = false;
  item.degraded = false;
  item.message = message;
}

void HealthMonitor::markDegraded(ComponentId id, uint32_t nowMs, const char* message) {
  HealthItem& item = items_[index(id)];
  item.lastOkMs = nowMs;
  item.fault = false;
  item.degraded = true;
  item.message = message;
}

void HealthMonitor::markFault(ComponentId id, uint32_t nowMs, const char* message) {
  HealthItem& item = items_[index(id)];
  item.lastOkMs = nowMs;
  item.fault = true;
  item.degraded = false;
  item.message = message;
}

HealthSnapshot HealthMonitor::evaluate(uint32_t nowMs) const {
  HealthSnapshot out;
  out.level = HealthLevel::Ok;
  out.watchdogQuorum = true;
  for (uint8_t i = 0; i < static_cast<uint8_t>(ComponentId::Count); ++i) {
    out.items[i] = items_[i];
    const HealthItem& item = items_[i];
    const bool stale = item.deadlineMs > 0 && (nowMs - item.lastOkMs) > item.deadlineMs;
    const bool failed = item.fault || stale;
    if (failed && out.level != HealthLevel::Fault) {
      out.level = HealthLevel::Fault;
    } else if (item.degraded && out.level == HealthLevel::Ok) {
      out.level = HealthLevel::Degraded;
    }
    if (failed && item.requiredForWatchdog && out.watchdogQuorum) {
      out.watchdogQuorum = false;
      out.firstFailingComponent = item.name;
      out.firstFailingReason = stale ? "deadline stale" : item.message;
    }
  }
  if (out.watchdogQuorum) {
    out.firstFailingComponent = "none";
    out.firstFailingReason = "OK";
  }
  return out;
}

const char* healthLevelName(HealthLevel level) {
  switch (level) {
    case HealthLevel::Ok:
      return "ok";
    case HealthLevel::Degraded:
      return "degraded";
    case HealthLevel::Fault:
      return "fault";
    default:
      return "unknown";
  }
}

}  // namespace lgcl::health

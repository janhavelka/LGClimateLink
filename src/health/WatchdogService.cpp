#include "health/WatchdogService.h"

#ifdef ARDUINO
#include <Arduino.h>
#include <esp_idf_version.h>
#include <esp_task_wdt.h>
#endif

namespace lgcl::health {

bool WatchdogService::begin(uint32_t timeoutSec) {
  timeoutSec_ = timeoutSec;
  lastFeedAllowed_ = false;
  lastBlockReason_ = "waiting for quorum";
  if (port_ == nullptr) {
    lastBlockReason_ = "watchdog port missing";
    return false;
  }
  return port_->begin(timeoutSec_);
}

bool WatchdogService::tick(uint32_t nowMs, const HealthMonitor& monitor) {
  const HealthSnapshot snapshot = monitor.evaluate(nowMs);
  lastFeedAllowed_ = snapshot.watchdogQuorum;
  if (!snapshot.watchdogQuorum) {
    lastBlockReason_ = snapshot.firstFailingComponent;
    return false;
  }
  if (port_ != nullptr) {
    port_->feed();
    lastFeedMs_ = nowMs;
    lastBlockReason_ = "OK";
    return true;
  }
  lastBlockReason_ = "watchdog port missing";
  return false;
}

#ifdef ARDUINO
bool EspTaskWatchdogPort::begin(uint32_t timeoutSec) {
#if ESP_IDF_VERSION_MAJOR >= 5
  esp_task_wdt_config_t cfg = {};
  cfg.timeout_ms = timeoutSec * 1000U;
  cfg.idle_core_mask = 1;
  cfg.trigger_panic = true;
  esp_err_t err = esp_task_wdt_init(&cfg);
  if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
    return false;
  }
#else
  esp_err_t err = esp_task_wdt_init(timeoutSec, true);
  if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
    return false;
  }
#endif
  err = esp_task_wdt_add(nullptr);
  return err == ESP_OK || err == ESP_ERR_INVALID_STATE;
}

void EspTaskWatchdogPort::feed() {
  (void)esp_task_wdt_reset();
}
#endif

}  // namespace lgcl::health

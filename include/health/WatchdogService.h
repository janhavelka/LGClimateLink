#pragma once

/**
 * @file WatchdogService.h
 * @brief Hardware watchdog feed gate based on HealthMonitor quorum.
 */

#include <stdint.h>

#include "health/HealthMonitor.h"

namespace lgcl::health {

/// Minimal hardware watchdog port used by WatchdogService.
class IWatchdogPort {
 public:
  virtual ~IWatchdogPort() = default;
  virtual bool begin(uint32_t timeoutSec) = 0;
  virtual void feed() = 0;
};

/**
 * @brief Feeds the hardware watchdog only when required services are healthy.
 */
class WatchdogService {
 public:
  /// Install the platform watchdog implementation.
  void setPort(IWatchdogPort* port) { port_ = port; }
  /// Start the watchdog port.
  bool begin(uint32_t timeoutSec);
  /// Evaluate health and feed only when the watchdog quorum is true.
  bool tick(uint32_t nowMs, const HealthMonitor& monitor);
  /// Return whether the last tick allowed a feed.
  bool lastFeedAllowed() const { return lastFeedAllowed_; }
  /// Return the first reason that blocked the last feed.
  const char* lastBlockReason() const { return lastBlockReason_; }
  /// Return the last successful feed timestamp.
  uint32_t lastFeedMs() const { return lastFeedMs_; }

 private:
  IWatchdogPort* port_ = nullptr;
  uint32_t timeoutSec_ = 0;
  uint32_t lastFeedMs_ = 0;
  bool lastFeedAllowed_ = false;
  const char* lastBlockReason_ = "not started";
};

#ifdef ARDUINO
/// ESP task watchdog adapter for Arduino builds.
class EspTaskWatchdogPort final : public IWatchdogPort {
 public:
  bool begin(uint32_t timeoutSec) override;
  void feed() override;
};
#endif

}  // namespace lgcl::health

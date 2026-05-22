#pragma once

#include <stdint.h>

#include "health/HealthMonitor.h"

namespace lgcl::health {

class IWatchdogPort {
 public:
  virtual ~IWatchdogPort() = default;
  virtual bool begin(uint32_t timeoutSec) = 0;
  virtual void feed() = 0;
};

class WatchdogService {
 public:
  void setPort(IWatchdogPort* port) { port_ = port; }
  bool begin(uint32_t timeoutSec);
  bool tick(uint32_t nowMs, const HealthMonitor& monitor);
  bool lastFeedAllowed() const { return lastFeedAllowed_; }
  const char* lastBlockReason() const { return lastBlockReason_; }
  uint32_t lastFeedMs() const { return lastFeedMs_; }

 private:
  IWatchdogPort* port_ = nullptr;
  uint32_t timeoutSec_ = 0;
  uint32_t lastFeedMs_ = 0;
  bool lastFeedAllowed_ = false;
  const char* lastBlockReason_ = "not started";
};

#ifdef ARDUINO
class EspTaskWatchdogPort final : public IWatchdogPort {
 public:
  bool begin(uint32_t timeoutSec) override;
  void feed() override;
};
#endif

}  // namespace lgcl::health

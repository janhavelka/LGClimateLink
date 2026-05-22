#pragma once

#include <stdint.h>

#include "config/RuntimeSettings.h"

namespace lgcl::storage {

struct StorageSnapshot {
  bool initialized = false;
  bool dirty = false;
  uint32_t lastLoadMs = 0;
  uint32_t lastSaveMs = 0;
  uint32_t saveCount = 0;
  uint32_t bootCount = 0;
  const char* lastError = "not initialized";
};

class SettingsStore {
 public:
  bool begin(uint32_t nowMs);
  bool load(config::RuntimeSettings& out, uint32_t nowMs);
  bool scheduleSave(const config::RuntimeSettings& settings, uint32_t nowMs, uint32_t delayMs);
  void tick(uint32_t nowMs);
  bool clear();
  const StorageSnapshot& snapshot() const { return snapshot_; }
  uint32_t bootCount() const { return snapshot_.bootCount; }

 private:
  bool saveNow(const config::RuntimeSettings& settings, uint32_t nowMs);

  StorageSnapshot snapshot_;
  config::RuntimeSettings pending_;
  uint32_t commitDueMs_ = 0;
};

}  // namespace lgcl::storage

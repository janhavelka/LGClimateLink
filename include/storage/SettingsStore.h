#pragma once

/**
 * @file SettingsStore.h
 * @brief NVS-backed settings store with delayed writes.
 */

#include <stdint.h>

#include "config/RuntimeSettings.h"

namespace lgcl::storage {

/// Storage counters and last-error state for CLI diagnostics.
struct StorageSnapshot {
  bool initialized = false;
  bool dirty = false;
  uint32_t lastLoadMs = 0;
  uint32_t lastSaveMs = 0;
  uint32_t saveCount = 0;
  uint32_t bootCount = 0;
  const char* lastError = "not initialized";
};

/**
 * @brief Loads, validates, and persists RuntimeSettings.
 *
 * scheduleSave() stores a pending copy and commits later from tick(). This
 * coalesces repeated CLI changes and reduces flash wear.
 */
class SettingsStore {
 public:
  /// Initialize the underlying storage namespace.
  bool begin(uint32_t nowMs);
  /// Load settings, falling back to defaults when no valid record exists.
  bool load(config::RuntimeSettings& out, uint32_t nowMs);
  /// Schedule a delayed save of a validated settings object.
  bool scheduleSave(const config::RuntimeSettings& settings, uint32_t nowMs, uint32_t delayMs);
  /// Commit a pending save when its delay has elapsed.
  void tick(uint32_t nowMs);
  /// Clear persisted settings.
  bool clear();
  /// Return current storage status.
  const StorageSnapshot& snapshot() const { return snapshot_; }
  /// Return persisted boot counter.
  uint32_t bootCount() const { return snapshot_.bootCount; }

 private:
  bool saveNow(const config::RuntimeSettings& settings, uint32_t nowMs);

  StorageSnapshot snapshot_;
  config::RuntimeSettings pending_;
  uint32_t commitDueMs_ = 0;
};

}  // namespace lgcl::storage

#include "storage/SettingsStore.h"

#include <string.h>

#ifdef ARDUINO
#include <Preferences.h>
#endif

namespace lgcl::storage {

namespace {

static constexpr uint32_t kSchemaVersion = 1;
static constexpr uint32_t kMagic = 0x4C47434CUL;  // LGCL

struct PersistedSettings {
  uint32_t magic = kMagic;
  uint32_t version = kSchemaVersion;
  config::RuntimeSettings settings;
};

#ifdef ARDUINO
Preferences prefs;
#endif

}  // namespace

bool SettingsStore::begin(uint32_t nowMs) {
  snapshot_ = StorageSnapshot{};
#ifdef ARDUINO
  if (!prefs.begin("lgclimate", false)) {
    snapshot_.lastError = "Preferences begin failed";
    return false;
  }
  snapshot_.bootCount = prefs.getUInt("boot_count", 0) + 1U;
  prefs.putUInt("boot_count", snapshot_.bootCount);
#else
  snapshot_.bootCount = 1;
#endif
  snapshot_.initialized = true;
  snapshot_.lastLoadMs = nowMs;
  snapshot_.lastError = "OK";
  return true;
}

bool SettingsStore::load(config::RuntimeSettings& out, uint32_t nowMs) {
  out = config::defaults();
  if (!snapshot_.initialized) {
    snapshot_.lastError = "store not initialized";
    return false;
  }
#ifdef ARDUINO
  PersistedSettings persisted;
  const size_t got = prefs.getBytes("settings", &persisted, sizeof(persisted));
  if (got == sizeof(persisted) && persisted.magic == kMagic &&
      persisted.version == kSchemaVersion && config::validate(persisted.settings).ok) {
    out = persisted.settings;
  }
#endif
  snapshot_.lastLoadMs = nowMs;
  snapshot_.lastError = "OK";
  return true;
}

bool SettingsStore::scheduleSave(const config::RuntimeSettings& settings,
                                 uint32_t nowMs,
                                 uint32_t delayMs) {
  if (!config::validate(settings).ok) {
    snapshot_.lastError = "refusing invalid settings";
    return false;
  }
  pending_ = settings;
  snapshot_.dirty = true;
  commitDueMs_ = nowMs + delayMs;
  snapshot_.lastError = "OK";
  return true;
}

void SettingsStore::tick(uint32_t nowMs) {
  if (!snapshot_.dirty) {
    return;
  }
  if ((int32_t)(nowMs - commitDueMs_) < 0) {
    return;
  }
  (void)saveNow(pending_, nowMs);
}

bool SettingsStore::clear() {
  if (!snapshot_.initialized) {
    return false;
  }
#ifdef ARDUINO
  if (!prefs.clear()) {
    snapshot_.lastError = "Preferences clear failed";
    return false;
  }
#endif
  snapshot_.dirty = false;
  snapshot_.lastError = "OK";
  return true;
}

bool SettingsStore::saveNow(const config::RuntimeSettings& settings, uint32_t nowMs) {
  if (!config::validate(settings).ok) {
    snapshot_.lastError = "invalid settings at save";
    return false;
  }
#ifdef ARDUINO
  PersistedSettings persisted;
  persisted.settings = settings;
  const size_t written = prefs.putBytes("settings", &persisted, sizeof(persisted));
  if (written != sizeof(persisted)) {
    snapshot_.lastError = "Preferences write failed";
    return false;
  }
#endif
  snapshot_.dirty = false;
  snapshot_.lastSaveMs = nowMs;
  snapshot_.saveCount++;
  snapshot_.lastError = "OK";
  return true;
}

}  // namespace lgcl::storage

#pragma once

#include <stdint.h>

namespace lgcl::config {

static constexpr const char* kFirmwareName = "LGClimateLink";
static constexpr const char* kFirmwareVersion = "0.1.0";

static constexpr int kLinEnablePin = 16;
static constexpr int kLinTxPin = 17;
static constexpr int kLinRxPin = 18;
static constexpr uint32_t kLinBaud = 104;

// Hardware TODO: verify the final board's I2C pins. GPIO8/GPIO9 are safe
// ESP32-S2 defaults used until the schematic/PCB netlist confirms otherwise.
static constexpr int kI2cSdaPin = 8;
static constexpr int kI2cSclPin = 9;
static constexpr uint32_t kI2cClockHz = 100000;
static constexpr uint32_t kI2cTimeoutMs = 50;

static constexpr int kStatusLedPin = 36;
static constexpr int kPairLedPin = 37;
static constexpr uint8_t kDefaultLedBrightness = 32;

static constexpr uint32_t kBmePollMs = 5000;
static constexpr uint32_t kBmeStaleMs = 30000;
static constexpr uint32_t kLgStatusPeriodMs = 20000;
static constexpr uint32_t kLgTypeBRequestPeriodMs = 10UL * 60UL * 1000UL;
static constexpr uint32_t kLgIdleBeforeTxMs = 500;
static constexpr uint32_t kLgFrameStaleMs = 180000;
static constexpr uint32_t kMqttStateMinPeriodMs = 1000;
static constexpr uint32_t kMqttStateHeartbeatMs = 60000;
static constexpr uint32_t kStorageCommitDelayMs = 5000;
static constexpr uint32_t kWatchdogTimeoutSec = 15;

}  // namespace lgcl::config

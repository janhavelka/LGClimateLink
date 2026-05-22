#pragma once

/**
 * @file BuildConfig.h
 * @brief Compile-time pin map, firmware identity, and service timing constants.
 *
 * Values in this file are hardware assumptions. Items marked as TODO must be
 * verified against the final schematic and bench measurements before production
 * deployment.
 */

#include <stdint.h>

namespace lgcl::config {

/// Firmware name reported through MQTT, CLI, and generated documentation.
static constexpr const char* kFirmwareName = "LGClimateLink";

/// Semantic firmware version for release tracking and Home Assistant metadata.
static constexpr const char* kFirmwareVersion = "0.1.0";

/// TLIN1027 enable pin. The current firmware assumes active-high normal mode.
static constexpr int kLinEnablePin = 16;
/// UART TX pin connected to TLIN1027 TXD.
static constexpr int kLinTxPin = 17;
/// UART RX pin connected to TLIN1027 RXD.
static constexpr int kLinRxPin = 18;
/// LG wired-controller bus speed from the reverse-engineered protocol.
static constexpr uint32_t kLinBaud = 104;

// Hardware TODO: verify the final board's I2C pins. GPIO8/GPIO9 are safe
// ESP32-S2 defaults used until the schematic/PCB netlist confirms otherwise.
static constexpr int kI2cSdaPin = 8;
static constexpr int kI2cSclPin = 9;
/// Conservative I2C clock for bring-up and long wiring tolerance.
static constexpr uint32_t kI2cClockHz = 100000;
/// Per-transaction I2C timeout used by hardware adapter wrappers.
static constexpr uint32_t kI2cTimeoutMs = 50;

/// WS2812-class status LED data pin.
static constexpr int kStatusLedPin = 36;
/// Optional second WS2812-class output if the board does not use one chain.
static constexpr int kPairLedPin = 37;
/// Default LED brightness, intentionally low for enclosure use.
static constexpr uint8_t kDefaultLedBrightness = 32;

/// Default BME280 polling interval.
static constexpr uint32_t kBmePollMs = 5000;
/// Maximum age for BME280 samples used by safety decisions.
static constexpr uint32_t kBmeStaleMs = 30000;
/// Periodic LG status-frame interval.
static constexpr uint32_t kLgStatusPeriodMs = 20000;
/// Periodic request interval for LG type-B status/pipe data.
static constexpr uint32_t kLgTypeBRequestPeriodMs = 10UL * 60UL * 1000UL;
/// Required bus idle time before transmitting to reduce collision risk.
static constexpr uint32_t kLgIdleBeforeTxMs = 500;
/// LG bus freshness deadline used by health monitoring.
static constexpr uint32_t kLgFrameStaleMs = 180000;
/// Minimum MQTT state publish spacing.
static constexpr uint32_t kMqttStateMinPeriodMs = 1000;
/// MQTT heartbeat interval when state is otherwise unchanged.
static constexpr uint32_t kMqttStateHeartbeatMs = 60000;
/// Delay used to coalesce NVS settings writes.
static constexpr uint32_t kStorageCommitDelayMs = 5000;
/// Hardware watchdog timeout. Feed is gated by health quorum.
static constexpr uint32_t kWatchdogTimeoutSec = 15;

}  // namespace lgcl::config

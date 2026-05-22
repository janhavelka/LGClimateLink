#pragma once

/**
 * @file LgProtocol.h
 * @brief Timing-independent LG frame parsing, checksum, and formatting helpers.
 */

#include <stddef.h>
#include <stdint.h>

#include "lg/LgTypes.h"

namespace lgcl::lg {

/// Result returned after feeding one byte into the sliding parser.
struct ParseResult {
  bool hasFrame = false;
  bool checksumError = false;
  bool formatError = false;
  LgFrame frame;
};

/**
 * @brief Sliding-window parser for the 13-byte LG frame format.
 *
 * The bus has no start-of-frame byte. The parser therefore retains the latest
 * 13 bytes and accepts a frame only when header classification and checksum are
 * valid. This allows recovery from boot noise and dropped bytes.
 */
class FrameParser {
 public:
  /// Feed one byte. Returns hasFrame=true only when a full valid frame is found.
  ParseResult feed(uint8_t byte, uint32_t nowMs);
  /// Clear all buffered bytes.
  void reset();
  /// Number of bytes currently retained in the parser window.
  uint8_t bufferedLength() const { return len_; }

 private:
  uint8_t buffer_[kFrameLength] = {};
  uint8_t len_ = 0;
  uint32_t lastByteMs_ = 0;
};

/// Calculate the LG checksum for the first 12 frame bytes.
uint8_t calcChecksum(const uint8_t* bytes12);
/// Calculate the checksum that should be present in a frame.
uint8_t calcChecksum(const FrameBytes& frame);
/// Return true when byte 12 matches the checksum over bytes 0..11.
bool hasValidChecksum(const FrameBytes& frame);
/// Copy 12 bytes and append the calculated checksum.
FrameBytes withChecksum(const uint8_t* bytes12);
/// Validate header/checksum and fill a classified LgFrame.
bool classifyFrame(const FrameBytes& bytes, LgFrame& out);
/// Decode sender bits from a frame header byte.
Sender senderFromHeader(uint8_t header);
/// Decode frame type bits from a frame header byte.
FrameType typeFromHeader(uint8_t header);
/// Return true when the header matches the supported AC product framing.
bool isAcProductHeader(uint8_t header);

/// Human-readable sender name for CLI and diagnostics.
const char* senderName(Sender sender);
/// Human-readable frame type name for CLI and diagnostics.
const char* frameTypeName(FrameType type);

/// Parse a 13-byte hex string into frame bytes.
bool parseHexFrame(const char* text, FrameBytes& out);
/// Format frame bytes as space-separated uppercase hex.
void frameToHex(const FrameBytes& frame, char* out, size_t outLen);

}  // namespace lgcl::lg

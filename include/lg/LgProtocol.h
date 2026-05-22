#pragma once

#include <stddef.h>
#include <stdint.h>

#include "lg/LgTypes.h"

namespace lgcl::lg {

struct ParseResult {
  bool hasFrame = false;
  bool checksumError = false;
  bool formatError = false;
  LgFrame frame;
};

class FrameParser {
 public:
  ParseResult feed(uint8_t byte, uint32_t nowMs);
  void reset();
  uint8_t bufferedLength() const { return len_; }

 private:
  uint8_t buffer_[kFrameLength] = {};
  uint8_t len_ = 0;
  uint32_t lastByteMs_ = 0;
};

uint8_t calcChecksum(const uint8_t* bytes12);
uint8_t calcChecksum(const FrameBytes& frame);
bool hasValidChecksum(const FrameBytes& frame);
FrameBytes withChecksum(const uint8_t* bytes12);
bool classifyFrame(const FrameBytes& bytes, LgFrame& out);
Sender senderFromHeader(uint8_t header);
FrameType typeFromHeader(uint8_t header);
bool isAcProductHeader(uint8_t header);

const char* senderName(Sender sender);
const char* frameTypeName(FrameType type);

bool parseHexFrame(const char* text, FrameBytes& out);
void frameToHex(const FrameBytes& frame, char* out, size_t outLen);

}  // namespace lgcl::lg

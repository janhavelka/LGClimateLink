#include "lg/LgProtocol.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

namespace lgcl::lg {

uint8_t calcChecksum(const uint8_t* bytes12) {
  uint8_t sum = 0;
  for (uint8_t i = 0; i < kFrameLength - 1; ++i) {
    sum = static_cast<uint8_t>(sum + bytes12[i]);
  }
  return static_cast<uint8_t>(sum ^ 0x55U);
}

uint8_t calcChecksum(const FrameBytes& frame) {
  return calcChecksum(frame.data());
}

bool hasValidChecksum(const FrameBytes& frame) {
  return calcChecksum(frame) == frame[kFrameLength - 1];
}

FrameBytes withChecksum(const uint8_t* bytes12) {
  FrameBytes frame = {};
  memcpy(frame.data(), bytes12, kFrameLength - 1);
  frame[kFrameLength - 1] = calcChecksum(bytes12);
  return frame;
}

bool isAcProductHeader(uint8_t header) {
  return (header & 0x18U) == 0x08U;
}

Sender senderFromHeader(uint8_t header) {
  switch (header & 0xE0U) {
    case 0x20:
      return Sender::SlaveController;
    case 0xA0:
      return Sender::MasterController;
    case 0xC0:
      return Sender::Unit;
    default:
      return Sender::Unknown;
  }
}

FrameType typeFromHeader(uint8_t header) {
  return static_cast<FrameType>(header & 0x07U);
}

bool classifyFrame(const FrameBytes& bytes, LgFrame& out) {
  if (!isAcProductHeader(bytes[0])) {
    return false;
  }
  const Sender sender = senderFromHeader(bytes[0]);
  if (sender == Sender::Unknown) {
    return false;
  }
  if (!hasValidChecksum(bytes)) {
    return false;
  }
  out.bytes = bytes;
  out.sender = sender;
  out.type = typeFromHeader(bytes[0]);
  return true;
}

const char* senderName(Sender sender) {
  switch (sender) {
    case Sender::Unit:
      return "unit";
    case Sender::MasterController:
      return "master";
    case Sender::SlaveController:
      return "slave";
    case Sender::Unknown:
    default:
      return "unknown";
  }
}

const char* frameTypeName(FrameType type) {
  switch (type) {
    case FrameType::Status:
      return "status";
    case FrameType::Capabilities:
      return "capabilities";
    case FrameType::TypeASettings:
      return "type_a_settings";
    case FrameType::TypeBSettings:
      return "type_b_settings";
    case FrameType::TypeCStatus:
      return "type_c_status";
    case FrameType::TypeDAdvanced:
      return "type_d_advanced";
    case FrameType::TypeEExtended:
      return "type_e_extended";
    case FrameType::TypeFPower:
      return "type_f_power";
    default:
      return "unknown";
  }
}

void FrameParser::reset() {
  len_ = 0;
  lastByteMs_ = 0;
}

ParseResult FrameParser::feed(uint8_t byte, uint32_t nowMs) {
  ParseResult result;
  if (len_ > 0 && (nowMs - lastByteMs_) > kInterByteTimeoutMs) {
    reset();
  }
  lastByteMs_ = nowMs;

  if (len_ < kFrameLength) {
    buffer_[len_++] = byte;
  }

  while (len_ == kFrameLength) {
    FrameBytes candidate = {};
    memcpy(candidate.data(), buffer_, kFrameLength);
    if (!isAcProductHeader(candidate[0]) || senderFromHeader(candidate[0]) == Sender::Unknown) {
      result.formatError = true;
    } else if (!hasValidChecksum(candidate)) {
      result.checksumError = true;
    } else {
      result.hasFrame = true;
      (void)classifyFrame(candidate, result.frame);
      reset();
      return result;
    }

    memmove(buffer_, buffer_ + 1, kFrameLength - 1);
    len_ = kFrameLength - 1;
  }

  return result;
}

namespace {

int hexValue(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  if (c >= 'a' && c <= 'f') {
    return 10 + c - 'a';
  }
  if (c >= 'A' && c <= 'F') {
    return 10 + c - 'A';
  }
  return -1;
}

}  // namespace

bool parseHexFrame(const char* text, FrameBytes& out) {
  if (text == nullptr) {
    return false;
  }
  uint8_t count = 0;
  const char* p = text;
  while (*p != '\0' && count < kFrameLength) {
    while (*p == ' ' || *p == '\t' || *p == ':' || *p == '-' || *p == '.') {
      ++p;
    }
    if (*p == '\0') {
      break;
    }
    const int hi = hexValue(*p++);
    if (hi < 0) {
      return false;
    }
    while (*p == ' ' || *p == '\t') {
      ++p;
    }
    const int lo = hexValue(*p++);
    if (lo < 0) {
      return false;
    }
    out[count++] = static_cast<uint8_t>((hi << 4) | lo);
  }
  while (*p == ' ' || *p == '\t') {
    ++p;
  }
  return count == kFrameLength && *p == '\0';
}

void frameToHex(const FrameBytes& frame, char* out, size_t outLen) {
  if (out == nullptr || outLen == 0) {
    return;
  }
  size_t pos = 0;
  for (uint8_t i = 0; i < kFrameLength; ++i) {
    const int written = snprintf(out + pos, outLen - pos, "%02X%s", frame[i],
                                 i + 1 == kFrameLength ? "" : " ");
    if (written < 0) {
      out[0] = '\0';
      return;
    }
    if (static_cast<size_t>(written) >= outLen - pos) {
      out[outLen - 1] = '\0';
      return;
    }
    pos += static_cast<size_t>(written);
  }
}

}  // namespace lgcl::lg

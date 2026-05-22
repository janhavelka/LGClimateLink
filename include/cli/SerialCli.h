#pragma once

#ifdef ARDUINO

#include <Arduino.h>

namespace lgcl::cli {

struct CliCommand {
  int argc = 0;
  char* argv[12] = {};
  const char* raw = "";
};

class ICliHandler {
 public:
  virtual ~ICliHandler() = default;
  virtual void handleCliCommand(const CliCommand& command, Print& out) = 0;
};

class SerialCli {
 public:
  bool begin(Stream& io, ICliHandler& handler);
  void tick(uint32_t nowMs);
  void setColorEnabled(bool enabled) { colorEnabled_ = enabled; }
  bool colorEnabled() const { return colorEnabled_; }
  void printPrompt();

 private:
  void dispatch();
  int tokenize(char* line, char* argv[], int maxArgv);

  Stream* io_ = nullptr;
  ICliHandler* handler_ = nullptr;
  char line_[192] = {};
  char rawLine_[192] = {};
  uint8_t lineLen_ = 0;
  bool colorEnabled_ = true;
  uint32_t lastPromptMs_ = 0;
};

const char* colorGreen(bool enabled);
const char* colorYellow(bool enabled);
const char* colorRed(bool enabled);
const char* colorCyan(bool enabled);
const char* colorReset(bool enabled);

}  // namespace lgcl::cli

#endif

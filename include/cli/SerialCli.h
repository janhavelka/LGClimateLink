#pragma once

/**
 * @file SerialCli.h
 * @brief Nonblocking USB CDC serial command parser.
 */

#ifdef ARDUINO

#include <Arduino.h>

namespace lgcl::cli {

/// Tokenized CLI command passed to the application handler.
struct CliCommand {
  int argc = 0;
  char* argv[12] = {};
  const char* raw = "";
};

/// Application callback for parsed CLI commands.
class ICliHandler {
 public:
  virtual ~ICliHandler() = default;
  virtual void handleCliCommand(const CliCommand& command, Print& out) = 0;
};

/**
 * @brief Small line-oriented serial shell.
 *
 * The parser consumes a bounded amount of input per tick and stores commands in
 * fixed-size buffers. It is intended for diagnostics and provisioning, not for
 * time-critical LG bus work.
 */
class SerialCli {
 public:
  /// Attach the stream and command handler.
  bool begin(Stream& io, ICliHandler& handler);
  /// Drain a bounded amount of input and dispatch complete commands.
  void tick(uint32_t nowMs);
  /// Enable or disable ANSI color output.
  void setColorEnabled(bool enabled) { colorEnabled_ = enabled; }
  /// Return current ANSI color setting.
  bool colorEnabled() const { return colorEnabled_; }
  /// Print a prompt when attached to a stream.
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

/// ANSI green sequence, or empty string when color is disabled.
const char* colorGreen(bool enabled);
/// ANSI yellow sequence, or empty string when color is disabled.
const char* colorYellow(bool enabled);
/// ANSI red sequence, or empty string when color is disabled.
const char* colorRed(bool enabled);
/// ANSI cyan sequence, or empty string when color is disabled.
const char* colorCyan(bool enabled);
/// ANSI reset sequence, or empty string when color is disabled.
const char* colorReset(bool enabled);

}  // namespace lgcl::cli

#endif

#include "cli/SerialCli.h"

#ifdef ARDUINO

#include <ctype.h>
#include <string.h>

namespace lgcl::cli {

const char* colorGreen(bool enabled) { return enabled ? "\033[32m" : ""; }
const char* colorYellow(bool enabled) { return enabled ? "\033[33m" : ""; }
const char* colorRed(bool enabled) { return enabled ? "\033[31m" : ""; }
const char* colorCyan(bool enabled) { return enabled ? "\033[36m" : ""; }
const char* colorReset(bool enabled) { return enabled ? "\033[0m" : ""; }

bool SerialCli::begin(Stream& io, ICliHandler& handler) {
  io_ = &io;
  handler_ = &handler;
  lineLen_ = 0;
  printPrompt();
  return true;
}

void SerialCli::tick(uint32_t nowMs) {
  if (io_ == nullptr || handler_ == nullptr) {
    return;
  }
  uint8_t budget = 32;
  while (budget-- > 0 && io_->available() > 0) {
    const int value = io_->read();
    if (value < 0) {
      break;
    }
    const char c = static_cast<char>(value);
    if (c == '\r') {
      continue;
    }
    if (c == '\n') {
      io_->println();
      dispatch();
      printPrompt();
      lastPromptMs_ = nowMs;
      continue;
    }
    if (c == '\b' || c == 0x7F) {
      if (lineLen_ > 0) {
        lineLen_--;
        io_->print("\b \b");
      }
      continue;
    }
    if (isprint(static_cast<unsigned char>(c)) && lineLen_ + 1 < sizeof(line_)) {
      line_[lineLen_++] = c;
      io_->write(c);
    }
  }
}

void SerialCli::printPrompt() {
  if (io_ != nullptr) {
    io_->print(colorCyan(colorEnabled_));
    io_->print("lgclimate> ");
    io_->print(colorReset(colorEnabled_));
  }
}

int SerialCli::tokenize(char* line, char* argv[], int maxArgv) {
  int argc = 0;
  char* p = line;
  while (*p != '\0' && argc < maxArgv) {
    while (*p != '\0' && isspace(static_cast<unsigned char>(*p))) {
      *p++ = '\0';
    }
    if (*p == '\0') {
      break;
    }
    argv[argc++] = p;
    while (*p != '\0' && !isspace(static_cast<unsigned char>(*p))) {
      *p = static_cast<char>(tolower(static_cast<unsigned char>(*p)));
      ++p;
    }
  }
  return argc;
}

void SerialCli::dispatch() {
  line_[lineLen_] = '\0';
  if (lineLen_ == 0) {
    return;
  }
  strncpy(rawLine_, line_, sizeof(rawLine_));
  rawLine_[sizeof(rawLine_) - 1] = '\0';
  CliCommand command;
  command.raw = rawLine_;
  command.argc = tokenize(line_, command.argv, 12);
  if (command.argc > 0) {
    handler_->handleCliCommand(command, *io_);
  }
  lineLen_ = 0;
}

}  // namespace lgcl::cli

#endif

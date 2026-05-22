#include "App.h"

#ifdef ARDUINO

#include <Wire.h>
#include <esp_system.h>

#include "config/BuildConfig.h"

namespace lgcl {

namespace {

void printOk(Print& out, const char* msg) {
  out.print("\033[32mOK\033[0m ");
  out.println(msg);
}

void printErr(Print& out, const char* msg) {
  out.print("\033[31mERR\033[0m ");
  out.println(msg);
}

void printWarn(Print& out, const char* msg) {
  out.print("\033[33mWARN\033[0m ");
  out.println(msg);
}

}  // namespace

App::App()
    : lgService_(lgBus_),
      bmeDriver_(Wire, config::kI2cTimeoutMs),
      digipotDriver_(Wire, config::kI2cTimeoutMs) {}

void App::begin() {
  bootMs_ = millis();
  Serial.begin(115200);
  const uint32_t waitStart = millis();
  while (!Serial && (millis() - waitStart) < 1500) {
    delay(10);
  }
  Serial.println();
  Serial.println("LGClimateLink boot");

  settings_ = config::defaults();
  (void)store_.begin(millis());
  (void)store_.load(settings_, millis());
  if (!config::validate(settings_).ok) {
    settings_ = config::defaults();
  }

  Wire.begin(config::kI2cSdaPin, config::kI2cSclPin);
  Wire.setClock(config::kI2cClockHz);
  Wire.setTimeOut(config::kI2cTimeoutMs);

  (void)leds_.begin(settings_.ledTopology, settings_.ledBrightness);
  bmeService_.setDriver(&bmeDriver_);
  (void)bmeService_.begin(settings_.bmeAddress, settings_.bmePollMs, settings_.bmeStaleMs,
                          millis());

  digipotService_.setDriver(&digipotDriver_);
  (void)digipotService_.begin(settings_.mcp45hvx1Address,
                              settings_.ntc,
                              settings_.digipot,
                              millis());

  (void)lgBus_.begin(config::kLinEnablePin, config::kLinTxPin, config::kLinRxPin,
                     config::kLinBaud);
  lgService_.begin(settings_.lgSlaveController, millis());

  (void)mqtt_.begin(settings_, millis());
  watchdog_.setPort(&watchdogPort_);
  (void)watchdog_.begin(settings_.watchdogTimeoutSec);

  (void)cli_.begin(Serial, *this);
  health_.markOk(health::ComponentId::MainLoop, millis());
  Serial.printf("reset=%s boot_count=%lu\n", resetReason(),
                static_cast<unsigned long>(store_.bootCount()));
}

void App::loop() {
  const uint32_t startUs = micros();
  const uint32_t now = millis();

  cli_.tick(now);
  lgService_.tick(now);

  bmeService_.tick(now);
  float roomC = 0.0f;
  const bool roomFresh = bmeService_.freshTemperature(roomC, now);
  lgService_.setLocalRoomTemperature(roomC, roomFresh);
  digipotService_.tick(now, roomFresh, roomC);

  mqtt_.tick(now);
  ha::MqttCommand command;
  while (mqtt_.popCommand(command)) {
    applyMqttCommand(command);
  }

  store_.tick(now);
  updateHealth(now);
  const health::HealthSnapshot hs = health_.evaluate(now);
  leds_.tick(now, ledStateFromHealth(hs));
  if ((now - lastMqttPublishMs_) > config::kMqttStateHeartbeatMs) {
    (void)mqtt_.publishState(lgService_.state(),
                             bmeService_.snapshot(now),
                             hs,
                             uptimeSec(),
                             digipotService_.snapshot().code,
                             digipotService_.snapshot().effectiveOhms,
                             true);
    lastMqttPublishMs_ = now;
  }
  (void)watchdog_.tick(now, health_);

  const uint32_t elapsedUs = micros() - startUs;
  if (elapsedUs > maxLoopLatencyUs_) {
    maxLoopLatencyUs_ = elapsedUs;
  }
}

void App::applyMqttCommand(const ha::MqttCommand& command) {
  lg::DesiredClimate desired = lgService_.desired();
  switch (command.kind) {
    case ha::MqttCommandKind::Mode:
      desired.mode = command.mode;
      lgService_.setDesired(desired);
      break;
    case ha::MqttCommandKind::TargetTemperature:
      desired.targetTemperatureC = command.temperatureC;
      lgService_.setDesired(desired);
      break;
    case ha::MqttCommandKind::FanMode:
      desired.fan = command.fan;
      lgService_.setDesired(desired);
      break;
    case ha::MqttCommandKind::SwingMode:
      desired.swing = command.swing;
      lgService_.setDesired(desired);
      break;
    case ha::MqttCommandKind::ThermistorMode:
      desired.thermistor = command.thermistor;
      lgService_.setDesired(desired);
      break;
    case ha::MqttCommandKind::DigipotWiper:
      if (dangerousDigipotArmed_) {
        (void)digipotService_.setManualCode(command.wiper, millis());
        dangerousDigipotArmed_ = false;
      }
      break;
    case ha::MqttCommandKind::None:
    default:
      break;
  }
}

void App::updateHealth(uint32_t nowMs) {
  health_.markOk(health::ComponentId::MainLoop, nowMs);

  const lg::LgBusSnapshot& bus = lgBus_.snapshot();
  if (bus.lastFrameMs == 0 || (nowMs - bus.lastFrameMs) > config::kLgFrameStaleMs) {
    health_.markDegraded(health::ComponentId::LgBus, nowMs, "LG bus stale/offline");
  } else {
    health_.markOk(health::ComponentId::LgBus, nowMs);
  }

  const sensors::Bme280Snapshot& bme = bmeService_.snapshot(nowMs);
  if (!bme.initialized || bme.stale) {
    health_.markDegraded(health::ComponentId::Bme280, nowMs, bme.lastError);
  } else {
    health_.markOk(health::ComponentId::Bme280, nowMs);
  }

  const digipot::DigipotSnapshot& dig = digipotService_.snapshot();
  if (!dig.initialized || dig.mode == digipot::DigipotMode::Fault) {
    health_.markFault(health::ComponentId::Digipot, nowMs, dig.lastError);
  } else if (dig.degraded) {
    health_.markDegraded(health::ComponentId::Digipot, nowMs, dig.lastError);
  } else {
    health_.markOk(health::ComponentId::Digipot, nowMs);
  }

  if (bme.consecutiveErrors > 5 || dig.consecutiveErrors > 0) {
    health_.markDegraded(health::ComponentId::I2c, nowMs, "I2C device errors");
  } else {
    health_.markOk(health::ComponentId::I2c, nowMs);
  }

  const ha::MqttSnapshot& mqtt = mqtt_.snapshot();
  if (mqtt.mqttConnected) {
    health_.markOk(health::ComponentId::Mqtt, nowMs);
  } else {
    health_.markDegraded(health::ComponentId::Mqtt, nowMs, mqtt.lastError);
  }
  if (mqtt.wifiConnected) {
    health_.markOk(health::ComponentId::Wifi, nowMs);
  } else {
    health_.markDegraded(health::ComponentId::Wifi, nowMs, mqtt.lastError);
  }
  health_.markOk(health::ComponentId::Storage, nowMs, store_.snapshot().lastError);
  lastHealthMs_ = nowMs;
}

status::DeviceLedState App::ledStateFromHealth(const health::HealthSnapshot& snapshot) const {
  if (snapshot.level == health::HealthLevel::Fault) {
    return status::DeviceLedState::Fatal;
  }
  if (snapshot.level == health::HealthLevel::Degraded) {
    if (!mqtt_.snapshot().wifiConnected) {
      return status::DeviceLedState::WifiConnecting;
    }
    if (!mqtt_.snapshot().mqttConnected) {
      return status::DeviceLedState::MqttDisconnected;
    }
    if (lgBus_.snapshot().lastFrameMs == 0) {
      return status::DeviceLedState::LgBusOffline;
    }
    return status::DeviceLedState::Degraded;
  }
  return status::DeviceLedState::Normal;
}

void App::handleCliCommand(const cli::CliCommand& command, Print& out) {
  if (command.argc == 0) {
    return;
  }
  const char* cmd = command.argv[0];
  if (strcmp(cmd, "help") == 0 || strcmp(cmd, "?") == 0) {
    printHelp(out);
  } else if (strcmp(cmd, "status") == 0) {
    printStatus(out);
  } else if (strcmp(cmd, "health") == 0) {
    printHealth(out);
  } else if (strcmp(cmd, "uptime") == 0) {
    out.printf("uptime=%lu sec\n", static_cast<unsigned long>(uptimeSec()));
  } else if (strcmp(cmd, "reboot") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "confirm") == 0) {
      out.println("rebooting");
      delay(50);
      ESP.restart();
    } else {
      printWarn(out, "use: reboot confirm");
    }
  } else if (strcmp(cmd, "wifi") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "status") == 0) {
      out.printf("wifi connected=%s rssi=%d attempts=%lu\n",
                 mqtt_.snapshot().wifiConnected ? "yes" : "no",
                 mqtt_.snapshot().wifiRssiDbm,
                 static_cast<unsigned long>(mqtt_.snapshot().wifiAttempts));
    } else if (command.argc >= 4 && strcmp(command.argv[1], "config") == 0) {
      strlcpy(settings_.wifiSsid, command.argv[2], sizeof(settings_.wifiSsid));
      strlcpy(settings_.wifiPassword, command.argv[3], sizeof(settings_.wifiPassword));
      reconfigureNetwork(millis());
      printOk(out, "wifi configured in RAM; use config save");
    } else if (command.argc >= 2 && strcmp(command.argv[1], "clear") == 0) {
      settings_.wifiSsid[0] = '\0';
      settings_.wifiPassword[0] = '\0';
      reconfigureNetwork(millis());
      printOk(out, "wifi cleared in RAM");
    } else {
      out.println("usage: wifi status | wifi config <ssid> <password> | wifi clear");
    }
  } else if (strcmp(cmd, "mqtt") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "status") == 0) {
      out.printf("mqtt enabled=%s connected=%s host=%s attempts=%lu\n",
                 settings_.mqttEnabled ? "yes" : "no",
                 mqtt_.snapshot().mqttConnected ? "yes" : "no",
                 settings_.mqttHost,
                 static_cast<unsigned long>(mqtt_.snapshot().mqttAttempts));
    } else if (command.argc >= 4 && strcmp(command.argv[1], "config") == 0) {
      strlcpy(settings_.mqttHost, command.argv[2], sizeof(settings_.mqttHost));
      uint32_t port = 1883;
      (void)parseU32(command.argv[3], port);
      settings_.mqttPort = static_cast<uint16_t>(port);
      settings_.mqttEnabled = true;
      if (command.argc >= 5) strlcpy(settings_.mqttUser, command.argv[4], sizeof(settings_.mqttUser));
      if (command.argc >= 6) strlcpy(settings_.mqttPassword, command.argv[5], sizeof(settings_.mqttPassword));
      reconfigureNetwork(millis());
      printOk(out, "mqtt configured in RAM; use config save");
    } else if (command.argc >= 2 && strcmp(command.argv[1], "clear") == 0) {
      settings_.mqttEnabled = false;
      settings_.mqttHost[0] = '\0';
      reconfigureNetwork(millis());
      printOk(out, "mqtt cleared in RAM");
    } else {
      out.println("usage: mqtt status | mqtt config <host> <port> [user] [password] | mqtt clear");
    }
  } else if (strcmp(cmd, "lg") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "status") == 0) {
      const lg::ClimateState s = lgService_.state();
      out.printf("lg mode=%s target=%.1f fan=%s swing=%s last_frame=%lu rx=%lu tx=%lu\n",
                 lg::modeName(s.mode),
                 static_cast<double>(s.targetTemperatureC),
                 lg::fanModeName(s.fan),
                 lg::swingModeName(s.swing),
                 static_cast<unsigned long>(lgBus_.snapshot().lastFrameMs),
                 static_cast<unsigned long>(lgBus_.snapshot().rxFrames),
                 static_cast<unsigned long>(lgBus_.snapshot().txFrames));
    } else if (command.argc >= 3 && strcmp(command.argv[1], "trace") == 0) {
      bool on = false;
      if (parseBool(command.argv[2], on)) {
        lgService_.setTraceEnabled(on);
        printOk(out, on ? "LG trace enabled" : "LG trace disabled");
      }
    } else if (command.argc >= 3 && strcmp(command.argv[1], "send") == 0) {
      if (strcmp(command.argv[2], "arm") == 0) {
        dangerousLgSendArmed_ = true;
        printWarn(out, "raw LG send armed for one command");
      } else if (dangerousLgSendArmed_) {
        lg::FrameBytes frame;
        if (lg::parseHexFrame(command.raw + 8, frame) && lgService_.sendRaw(frame, millis())) {
          dangerousLgSendArmed_ = false;
          printOk(out, "raw frame queued");
        } else {
          printErr(out, "invalid frame or bus busy");
        }
      } else {
        printWarn(out, "use: lg send arm");
      }
    } else if (command.argc >= 2 && strcmp(command.argv[1], "test") == 0) {
      lg::DesiredClimate d = lgService_.desired();
      d.mode = d.mode == lg::HvacMode::Off ? lg::HvacMode::Cool : lg::HvacMode::Off;
      lgService_.setDesired(d);
      printOk(out, "toggled desired LG mode");
    } else {
      out.println("usage: lg status | lg trace <on|off> | lg send arm | lg send <13 hex bytes> | lg test");
    }
  } else if (strcmp(cmd, "bme") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "read") == 0) {
      bmeService_.forceRead(millis());
      printOk(out, "BME280 measurement requested");
    } else {
      const sensors::Bme280Snapshot& b = bmeService_.snapshot(millis());
      out.printf("bme init=%s stale=%s t=%.2f h=%.2f p=%.1f last_error=%s\n",
                 b.initialized ? "yes" : "no",
                 b.stale ? "yes" : "no",
                 static_cast<double>(b.sample.temperatureC),
                 static_cast<double>(b.sample.humidityPct),
                 static_cast<double>(b.sample.pressurePa),
                 b.lastError);
    }
  } else if (strcmp(cmd, "digipot") == 0) {
    const digipot::DigipotSnapshot& d = digipotService_.snapshot();
    if (command.argc >= 3 && strcmp(command.argv[1], "set") == 0 &&
        strcmp(command.argv[2], "arm") == 0) {
      dangerousDigipotArmed_ = true;
      printWarn(out, "manual digipot write armed for one command");
    } else if (command.argc >= 4 && strcmp(command.argv[1], "set") == 0 &&
               strcmp(command.argv[2], "code") == 0) {
      uint32_t code = 0;
      if (dangerousDigipotArmed_ && parseU32(command.argv[3], code) &&
          digipotService_.setManualCode(static_cast<uint8_t>(code), millis())) {
        dangerousDigipotArmed_ = false;
        printOk(out, "manual digipot code written");
      } else {
        printErr(out, "not armed or invalid code");
      }
    } else if (command.argc >= 2 && strcmp(command.argv[1], "test") == 0) {
      (void)digipotService_.setSafeFixed(millis());
      printOk(out, "digipot moved to safe fixed state");
    } else if (command.argc >= 2 && strcmp(command.argv[1], "calibrate") == 0) {
      printWarn(out, "calibration is CLI-configured via config set ntc_* after hardware verification");
    } else {
      out.printf("digipot mode=%s code=%u ohms=%.1f degraded=%s error=%s\n",
                 digipot::digipotModeName(d.mode),
                 d.code,
                 static_cast<double>(d.effectiveOhms),
                 d.degraded ? "yes" : "no",
                 d.lastError);
    }
  } else if (strcmp(cmd, "ntc") == 0 && command.argc >= 3 &&
             strcmp(command.argv[1], "calc") == 0) {
    float temp = 0.0f;
    if (parseFloat(command.argv[2], temp)) {
      const digipot::WiperResult r =
          digipot::wiperForTemperature(temp, settings_.ntc, settings_.digipot);
      out.printf("temp=%.2fC target=%.1fohm code=%u effective=%.1fohm %s\n",
                 static_cast<double>(temp),
                 static_cast<double>(r.requestedResistanceOhms),
                 r.code,
                 static_cast<double>(r.effectiveResistanceOhms),
                 r.message);
    }
  } else if (strcmp(cmd, "led") == 0) {
    if (command.argc >= 5 && strcmp(command.argv[1], "test") == 0) {
      uint32_t r = 0, g = 0, b = 0;
      if (parseU32(command.argv[2], r) && parseU32(command.argv[3], g) &&
          parseU32(command.argv[4], b)) {
        (void)leds_.setTestColor(static_cast<uint8_t>(r), static_cast<uint8_t>(g),
                                 static_cast<uint8_t>(b));
      }
    } else {
      out.printf("led state=%s error=%s\n", status::ledStateName(leds_.currentState()),
                 leds_.lastError());
    }
  } else if (strcmp(cmd, "i2c") == 0 && command.argc >= 2 &&
             strcmp(command.argv[1], "scan") == 0) {
    scanI2c(out);
  } else if (strcmp(cmd, "config") == 0) {
    if (command.argc >= 2 && strcmp(command.argv[1], "show") == 0) {
      printConfig(out);
    } else if (command.argc >= 4 && strcmp(command.argv[1], "set") == 0) {
      const char* key = command.argv[2];
      const char* value = command.argv[3];
      if (strcmp(key, "device_id") == 0) strlcpy(settings_.deviceId, value, sizeof(settings_.deviceId));
      else if (strcmp(key, "mqtt_base") == 0) strlcpy(settings_.mqttBaseTopic, value, sizeof(settings_.mqttBaseTopic));
      else if (strcmp(key, "bme_addr") == 0) {
        uint32_t addr = 0;
        if (parseU32(value, addr)) settings_.bmeAddress = static_cast<uint8_t>(addr);
      } else if (strcmp(key, "safe_ohms") == 0) {
        float v = 0.0f;
        if (parseFloat(value, v)) settings_.ntc.safeResistanceOhms = v;
      } else {
        printErr(out, "unknown config key");
        return;
      }
      const config::ValidationResult valid = config::validate(settings_);
      if (!valid.ok) {
        out.printf("ERR settings invalid: %s\n", valid.message);
      } else {
        printOk(out, "config updated in RAM");
      }
    } else if (command.argc >= 2 && strcmp(command.argv[1], "save") == 0) {
      (void)saveSettings(out);
    } else if (command.argc >= 2 && strcmp(command.argv[1], "reset") == 0) {
      settings_ = config::defaults();
      printOk(out, "defaults loaded in RAM; use config save");
    } else {
      out.println("usage: config show | config set <key> <value> | config save | config reset");
    }
  } else if (strcmp(cmd, "logs") == 0) {
    out.println("logs level: compile-time CORE_DEBUG_LEVEL currently used");
  } else if (strcmp(cmd, "watchdog") == 0) {
    out.printf("watchdog allowed=%s last_feed=%lu block=%s\n",
               watchdog_.lastFeedAllowed() ? "yes" : "no",
               static_cast<unsigned long>(watchdog_.lastFeedMs()),
               watchdog_.lastBlockReason());
  } else {
    printErr(out, "unknown command; type help");
  }
}

void App::printHelp(Print& out) const {
  out.println("Commands:");
  out.println("  help, status, health, uptime, reboot confirm");
  out.println("  wifi status|config <ssid> <password>|clear");
  out.println("  mqtt status|config <host> <port> [user] [password]|clear");
  out.println("  lg status|trace <on|off>|send arm|send <13 hex bytes>|test");
  out.println("  bme status|read|config");
  out.println("  digipot status|set arm|set code <0..255>|test|calibrate");
  out.println("  ntc calc <temp_c>");
  out.println("  led status|test <r> <g> <b>");
  out.println("  i2c scan");
  out.println("  config show|set <key> <value>|save|reset");
  out.println("  logs level, watchdog status");
}

void App::printStatus(Print& out) {
  const digipot::DigipotSnapshot& d = digipotService_.snapshot();
  const sensors::Bme280Snapshot& b = bmeService_.snapshot(millis());
  const lg::ClimateState l = lgService_.state();
  out.printf("uptime=%lu reset=%s heap=%lu max_loop_us=%lu\n",
             static_cast<unsigned long>(uptimeSec()),
             resetReason(),
             static_cast<unsigned long>(ESP.getFreeHeap()),
             static_cast<unsigned long>(maxLoopLatencyUs_));
  out.printf("lg mode=%s target=%.1f last_frame=%lu error=%u\n",
             lg::modeName(l.mode),
             static_cast<double>(l.targetTemperatureC),
             static_cast<unsigned long>(lgBus_.snapshot().lastFrameMs),
             l.errorCode);
  out.printf("bme stale=%s temp=%.2fC error=%s\n",
             b.stale ? "yes" : "no",
             static_cast<double>(b.sample.temperatureC),
             b.lastError);
  out.printf("digipot mode=%s code=%u ohms=%.1f error=%s\n",
             digipot::digipotModeName(d.mode),
             d.code,
             static_cast<double>(d.effectiveOhms),
             d.lastError);
}

void App::printHealth(Print& out) const {
  const health::HealthSnapshot hs = health_.evaluate(millis());
  out.printf("health=%s watchdog_quorum=%s first_fail=%s reason=%s\n",
             health::healthLevelName(hs.level),
             hs.watchdogQuorum ? "yes" : "no",
             hs.firstFailingComponent,
             hs.firstFailingReason);
  for (uint8_t i = 0; i < static_cast<uint8_t>(health::ComponentId::Count); ++i) {
    const health::HealthItem& item = hs.items[i];
    out.printf("  %-10s required=%s fault=%s degraded=%s last_ok=%lu msg=%s\n",
               item.name,
               item.requiredForWatchdog ? "yes" : "no",
               item.fault ? "yes" : "no",
               item.degraded ? "yes" : "no",
               static_cast<unsigned long>(item.lastOkMs),
               item.message);
  }
}

void App::printConfig(Print& out) const {
  out.printf("device_id=%s name=%s\n", settings_.deviceId, settings_.deviceName);
  out.printf("wifi_ssid=%s mqtt_enabled=%s mqtt=%s:%u base=%s\n",
             settings_.wifiSsid,
             settings_.mqttEnabled ? "yes" : "no",
             settings_.mqttHost,
             settings_.mqttPort,
             settings_.mqttBaseTopic);
  out.printf("bme_addr=0x%02X poll=%lu stale=%lu\n",
             settings_.bmeAddress,
             static_cast<unsigned long>(settings_.bmePollMs),
             static_cast<unsigned long>(settings_.bmeStaleMs));
  out.printf("ntc r25=%.1f beta=%.1f safe=%.1f minmax_ohm=%.1f..%.1f\n",
             static_cast<double>(settings_.ntc.rRefOhms),
             static_cast<double>(settings_.ntc.betaK),
             static_cast<double>(settings_.ntc.safeResistanceOhms),
             static_cast<double>(settings_.ntc.minResistanceOhms),
             static_cast<double>(settings_.ntc.maxResistanceOhms));
  out.printf("digipot rab=%.1f series=%.1f wiper=%u..%u safe=%u topology=%s\n",
             static_cast<double>(settings_.digipot.nominalRabOhms),
             static_cast<double>(settings_.digipot.seriesOhms),
             settings_.digipot.minWiperCode,
             settings_.digipot.maxAllowedWiperCode,
             settings_.digipot.safeWiperCode,
             settings_.digipot.topology == digipot::TerminalTopology::RheostatBToW ? "b-w" : "a-w");
}

void App::scanI2c(Print& out) const {
  out.println("I2C scan:");
  for (uint8_t addr = 1; addr < 0x7F; ++addr) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      out.printf("  0x%02X\n", addr);
    }
    delay(1);
  }
}

bool App::saveSettings(Print& out) {
  const config::ValidationResult valid = config::validate(settings_);
  if (!valid.ok) {
    out.printf("ERR settings invalid: %s\n", valid.message);
    return false;
  }
  if (!store_.scheduleSave(settings_, millis(), settings_.settingsCommitDelayMs)) {
    printErr(out, store_.snapshot().lastError);
    return false;
  }
  printOk(out, "settings save scheduled");
  return true;
}

bool App::parseBool(const char* text, bool& out) const {
  if (strcmp(text, "1") == 0 || strcmp(text, "on") == 0 || strcmp(text, "true") == 0 ||
      strcmp(text, "yes") == 0) {
    out = true;
    return true;
  }
  if (strcmp(text, "0") == 0 || strcmp(text, "off") == 0 || strcmp(text, "false") == 0 ||
      strcmp(text, "no") == 0) {
    out = false;
    return true;
  }
  return false;
}

bool App::parseFloat(const char* text, float& out) const {
  char* end = nullptr;
  const float value = strtof(text, &end);
  if (end == text || *end != '\0' || !isfinite(value)) {
    return false;
  }
  out = value;
  return true;
}

bool App::parseU32(const char* text, uint32_t& out) const {
  if (text == nullptr || text[0] == '-') {
    return false;
  }
  char* end = nullptr;
  const unsigned long value = strtoul(text, &end, 0);
  if (end == text || *end != '\0') {
    return false;
  }
  out = static_cast<uint32_t>(value);
  return true;
}

void App::reconfigureNetwork(uint32_t nowMs) {
  (void)mqtt_.begin(settings_, nowMs);
}

uint32_t App::uptimeSec() const {
  return (millis() - bootMs_) / 1000UL;
}

const char* App::resetReason() const {
  switch (esp_reset_reason()) {
    case ESP_RST_POWERON:
      return "poweron";
    case ESP_RST_EXT:
      return "external";
    case ESP_RST_SW:
      return "software";
    case ESP_RST_PANIC:
      return "panic";
    case ESP_RST_INT_WDT:
      return "interrupt_watchdog";
    case ESP_RST_TASK_WDT:
      return "task_watchdog";
    case ESP_RST_WDT:
      return "other_watchdog";
    case ESP_RST_BROWNOUT:
      return "brownout";
    default:
      return "unknown";
  }
}

}  // namespace lgcl

#endif

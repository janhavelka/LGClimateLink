#include <unity.h>

#include <math.h>
#include <string.h>

#include "config/RuntimeSettings.h"
#include "digipot/NtcEmulator.h"
#include "ha/HaDiscovery.h"
#include "health/HealthMonitor.h"
#include "health/WatchdogService.h"
#include "lg/LgClimateModel.h"
#include "lg/LgProtocol.h"
#include "sensors/Bme280Service.h"

using namespace lgcl;

void setUp() {}
void tearDown() {}

namespace {

struct FakeBme final : sensors::IBme280Driver {
  bool beginOk = true;
  bool ready = false;
  bool requestOk = true;
  float t = 22.5f;
  float h = 45.0f;
  float p = 101325.0f;
  const char* err = "fake error";

  bool begin(uint8_t) override { return beginOk; }
  void tick(uint32_t) override {}
  bool requestMeasurement() override {
    ready = requestOk;
    return requestOk;
  }
  bool measurementReady() const override { return ready; }
  bool readMeasurement(float& temperatureC, float& humidityPct, float& pressurePa) override {
    if (!ready) return false;
    temperatureC = t;
    humidityPct = h;
    pressurePa = p;
    ready = false;
    return true;
  }
  const char* lastError() const override { return err; }
  bool recover() override { return true; }
};

struct FakeWatchdog final : health::IWatchdogPort {
  bool started = false;
  uint32_t feeds = 0;
  bool begin(uint32_t) override {
    started = true;
    return true;
  }
  void feed() override { feeds++; }
};

}  // namespace

void test_lg_checksum_vectors() {
  uint8_t zeros[12] = {};
  TEST_ASSERT_EQUAL_UINT8(0x55, lg::calcChecksum(zeros));

  lg::FrameBytes cap = {0xC9, 0xC4, 0xEA, 0x1F, 0x81, 0x71, 0x00,
                        0x80, 0x02, 0x40, 0x04, 0x81, 0x9A};
  TEST_ASSERT_TRUE(lg::hasValidChecksum(cap));
  lg::LgFrame frame;
  TEST_ASSERT_TRUE(lg::classifyFrame(cap, frame));
  TEST_ASSERT_EQUAL(lg::Sender::Unit, frame.sender);
  TEST_ASSERT_EQUAL(lg::FrameType::Capabilities, frame.type);
}

void test_lg_parser_resyncs_after_garbage() {
  lg::FrameBytes status = {0xA8, 0x22, 0x00, 0x00, 0x00, 0x00, 0x16,
                           0x20, 0x40, 0x00, 0x80, 0x00, 0x95};
  lg::FrameParser parser;
  lg::ParseResult r;
  r = parser.feed(0x00, 1);
  TEST_ASSERT_FALSE(r.hasFrame);
  r = parser.feed(0xFF, 2);
  TEST_ASSERT_FALSE(r.hasFrame);
  for (uint8_t i = 0; i < lg::kFrameLength; ++i) {
    r = parser.feed(status[i], 3 + i);
  }
  TEST_ASSERT_TRUE(r.hasFrame);
  TEST_ASSERT_EQUAL_UINT8_ARRAY(status.data(), r.frame.bytes.data(), lg::kFrameLength);
}

void test_lg_status_mapping_and_build() {
  lg::LgFrame frame;
  frame.sender = lg::Sender::Unit;
  frame.type = lg::FrameType::Status;
  frame.bytes = {0xC8, 0x02, 0x80, 0x00, 0x00, 0x04, 0x0C,
                 0x1B, 0x00, 0x00, 0x00, 0x00, 0xA0};
  frame.bytes[12] = lg::calcChecksum(frame.bytes);
  lg::ClimateState state;
  lg::ApplyResult applied = lg::applyFrameToState(frame, 100, state);
  TEST_ASSERT_TRUE(applied.accepted);
  TEST_ASSERT_EQUAL(lg::HvacMode::Cool, state.mode);
  TEST_ASSERT_EQUAL(lg::SwingMode::Vertical, state.swing);
  TEST_ASSERT_FLOAT_WITHIN(0.01f, 27.0f, state.targetTemperatureC);
  TEST_ASSERT_FLOAT_WITHIN(0.01f, 23.5f, state.currentTemperatureC);

  lg::DesiredClimate desired;
  desired.mode = lg::HvacMode::Heat;
  desired.fan = lg::FanMode::High;
  desired.targetTemperatureC = 22.5f;
  desired.swing = lg::SwingMode::Both;
  lg::FrameBytes built = lg::buildStatusFrame(desired, state, false, true);
  TEST_ASSERT_TRUE(lg::hasValidChecksum(built));
  TEST_ASSERT_EQUAL_UINT8(0xA8, built[0]);
  TEST_ASSERT_BITS_HIGH(0x02, built[1]);
  TEST_ASSERT_BITS_HIGH(0xC0, built[2]);
}

void test_ntc_and_digipot_conversion_clamping() {
  digipot::NtcCalibration ntc;
  digipot::DigipotCalibration pot;
  pot.minEffectiveOhms = 0.0f + 1.0f;
  pot.maxEffectiveOhms = 6000.0f;
  digipot::NtcResult r25 = digipot::resistanceForTemperature(25.0f, ntc);
  TEST_ASSERT_TRUE(r25.ok);
  TEST_ASSERT_FLOAT_WITHIN(5.0f, 5000.0f, r25.targetResistanceOhms);

  digipot::WiperResult low = digipot::wiperForResistance(-10.0f, pot);
  TEST_ASSERT_FALSE(low.ok);
  digipot::WiperResult high = digipot::wiperForResistance(1000000.0f, pot);
  TEST_ASSERT_TRUE(high.ok);
  TEST_ASSERT_TRUE(high.clamped);
  TEST_ASSERT_LESS_OR_EQUAL_UINT8(pot.maxAllowedWiperCode, high.code);
}

void test_bme_stale_logic() {
  FakeBme fake;
  sensors::Bme280Service svc;
  svc.setDriver(&fake);
  TEST_ASSERT_TRUE(svc.begin(0x76, 1000, 3000, 0));
  svc.tick(0);
  svc.tick(10);
  float t = 0.0f;
  TEST_ASSERT_TRUE(svc.freshTemperature(t, 10));
  TEST_ASSERT_FLOAT_WITHIN(0.01f, fake.t, t);
  TEST_ASSERT_FALSE(svc.snapshot(2000).stale);
  TEST_ASSERT_TRUE(svc.snapshot(4000).stale);
}

void test_settings_validation() {
  config::RuntimeSettings s = config::defaults();
  TEST_ASSERT_TRUE(config::validate(s).ok);
  s.deviceId[0] = '\0';
  TEST_ASSERT_FALSE(config::validate(s).ok);
  s = config::defaults();
  strcpy(s.mqttBaseTopic, "/bad");
  TEST_ASSERT_FALSE(config::validate(s).ok);
  s = config::defaults();
  s.bmeStaleMs = s.bmePollMs;
  TEST_ASSERT_FALSE(config::validate(s).ok);
}

void test_mqtt_topic_payload_decode() {
  config::RuntimeSettings s = config::defaults();
  strcpy(s.deviceId, "abc123");
  char topic[128];
  TEST_ASSERT_TRUE(ha::makeBaseTopic(s, topic, sizeof(topic)));
  TEST_ASSERT_EQUAL_STRING("lgclimatelink/abc123", topic);
  strcat(topic, "/cmd/target_temp");
  ha::DecodeResult d = ha::decodeCommand(s, topic, "22.5", false);
  TEST_ASSERT_TRUE(d.accepted);
  TEST_ASSERT_EQUAL(ha::MqttCommandKind::TargetTemperature, d.command.kind);
  TEST_ASSERT_FLOAT_WITHIN(0.01f, 22.5f, d.command.temperatureC);
  d = ha::decodeCommand(s, topic, "22.3", false);
  TEST_ASSERT_FALSE(d.accepted);
  d = ha::decodeCommand(s, topic, "22.5", true);
  TEST_ASSERT_TRUE(d.ignored);
}

void test_watchdog_quorum() {
  health::HealthMonitor monitor;
  FakeWatchdog port;
  health::WatchdogService watchdog;
  watchdog.setPort(&port);
  TEST_ASSERT_TRUE(watchdog.begin(10));
  monitor.markOk(health::ComponentId::MainLoop, 100);
  monitor.markOk(health::ComponentId::LgBus, 100);
  monitor.markOk(health::ComponentId::Bme280, 100);
  monitor.markOk(health::ComponentId::Digipot, 100);
  monitor.markOk(health::ComponentId::I2c, 100);
  TEST_ASSERT_TRUE(watchdog.tick(100, monitor));
  TEST_ASSERT_EQUAL_UINT32(1, port.feeds);
  monitor.markFault(health::ComponentId::Digipot, 200, "fault");
  TEST_ASSERT_FALSE(watchdog.tick(200, monitor));
  TEST_ASSERT_EQUAL_UINT32(1, port.feeds);
}

int main(int, char**) {
  UNITY_BEGIN();
  RUN_TEST(test_lg_checksum_vectors);
  RUN_TEST(test_lg_parser_resyncs_after_garbage);
  RUN_TEST(test_lg_status_mapping_and_build);
  RUN_TEST(test_ntc_and_digipot_conversion_clamping);
  RUN_TEST(test_bme_stale_logic);
  RUN_TEST(test_settings_validation);
  RUN_TEST(test_mqtt_topic_payload_decode);
  RUN_TEST(test_watchdog_quorum);
  return UNITY_END();
}

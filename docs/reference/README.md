# Reference Documentation Bundle

This directory vendors supporting documentation used while implementing LGClimateLink. It is kept separate from the project-authored docs in `docs/` so upstream references, datasheets, and downloaded integration pages remain easy to audit.

## Layout

- `lg-esphome-controller/`: JanM321 protocol, Home Assistant behavior reference, and available upstream board artifacts.
- `libraries/`: documentation for the required MCP45HVX1, BME280, StatusLED, and CO2Control reference libraries.
- `hardware/`: official or distributor-hosted component datasheets for ESP32-S2-MINI-2, TLIN1027-Q1, and SK6805D-EC2018.
- `home-assistant/mqtt/`: Home Assistant MQTT discovery/entity integration reference pages.
- `platform-libraries/`: ArduinoJson, PubSubClient, and Arduino-ESP32 API references used by the firmware.

## Upstream Repository Sources

| Source | Local reference path | Commit |
| --- | --- | --- |
| `https://github.com/JanM321/esphome-lg-controller` | `lg-esphome-controller/` | `19ef72a4189e8b4186490a17219b4e29e4403f69` |
| `https://github.com/janhavelka/MCP45HVX1` | `libraries/mcp45hvx1/` | `88f27dafe3cb88778269bd4df3f0b16be15904b9` |
| `https://github.com/janhavelka/BME280` | `libraries/bme280/` | `ab1622296fe2386f7fcb7d0ab4c27a013a1ae5bc` |
| `https://github.com/janhavelka/StatusLED` | `libraries/statusled/` | `194c00a8a4341208bd38fe0999a9230bd2e0524c` |
| `https://github.com/janhavelka/CO2Control` | `libraries/co2control/` | `51f341489ac6ccef808b643359e15bea0d35e12b` |

Each upstream repository copy includes its upstream license file where one was available.

## Downloaded Official References

| File | Source |
| --- | --- |
| `hardware/esp32-s2-mini-2/ESP32-S2-MINI-2_MINI-2U_Datasheet_Espressif.pdf` | `https://www.espressif.com/sites/default/files/documentation/esp32-s2-mini-2_esp32-s2-mini-2u_datasheet_en.pdf` |
| `hardware/esp32-s2-mini-2/ESP32-S2-MINI-2_MINI-2U_Datasheet_Espressif.html` | `https://documentation.espressif.com/esp32-s2-mini-2_esp32-s2-mini-2u_datasheet_en.html` |
| `hardware/tlin1027-q1/TLIN1027-Q1_Datasheet_TI.pdf` | `https://www.ti.com/lit/ds/symlink/tlin1027-q1.pdf` |
| `hardware/tlin1027-q1/TLIN1027-Q1_Product_Page_TI.html` | `https://www.ti.com/product/TLIN1027-Q1` |
| `hardware/sk6805d-ec2018/SK6805D-EC2018_Datasheet_OPSCO_JLCPCB.pdf` | `https://jlcpcb.com/partdetail/OPSCOOptoelectronics-SK6805DEC2018/C5440835` |
| `libraries/mcp45hvx1/datasheets/MCP45HVX1_Datasheet_Microchip_official.pdf` | `https://ww1.microchip.com/downloads/aemDocuments/documents/MSLD/ProductDocuments/DataSheets/MCP45HVX1-Data-Sheet-DS20005304.pdf` |
| `libraries/bme280/datasheets/BME280_Datasheet_Bosch_official.pdf` | `https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf` |
| `libraries/bme280/docs/BME280_Product_Page_Bosch.html` | `https://www.bosch-sensortec.com/en/products/environmental-sensors/humidity-sensors-bme280/` |
| `home-assistant/mqtt/*.html` | `https://www.home-assistant.io/integrations/mqtt/` and MQTT entity platform pages |
| `platform-libraries/*.html` | ArduinoJson, Arduino-ESP32 API documentation, and ESP-IDF watchdog reference |
| `platform-libraries/PubSubClient_*.upstream.*` | `https://github.com/knolleary/pubsubclient` raw files |

## Notes

- Datasheets and upstream documents were captured on 2026-05-22 and retained as reference material; check vendor sites for updates before hardware release.
- The SK6805D datasheet was downloaded through JLCPCB's time-limited signed file link from the public part page.
- Do not treat copied upstream hardware files as verified for this board. They are protocol and topology references only.

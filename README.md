# ESPHome + ADXL345 on ESP-IDF
ESPHome doesn't ship a native ADXL345 accelerometer component. This repo shows how to read X/Y/Z acceleration data anyway, by pulling in the espp/adxl345 ESP-IDF component via esp32.framework.components and initializing/reading it from a lambda in a template sensor.

#pragma once
#include "esphome/core/component.h"
#include <esphome/core/hal.h>
#include "adxl345.hpp"
#include "i2c.hpp"

static espp::I2c *adxl_i2c = nullptr;
static espp::Adxl345 *adxl_sensor = nullptr;

inline void adxl_init() {
  if (adxl_sensor != nullptr) return;  // already initialized

  adxl_i2c = new espp::I2c(espp::I2c::Config{
      .port = I2C_NUM_0,
      .sda_io_num = GPIO_NUM_21,
      .scl_io_num = GPIO_NUM_22,
  });

  std::error_code ec;
  auto dev = adxl_i2c->add_device<uint8_t>({
      .device_address = espp::Adxl345::DEFAULT_ADDRESS,
      .timeout_ms = static_cast<int>(adxl_i2c->config().timeout_ms),
      .scl_speed_hz = adxl_i2c->config().clk_speed,
  }, ec);

  adxl_sensor = new espp::Adxl345(espp::Adxl345::Config{
      .device_address = espp::Adxl345::DEFAULT_ADDRESS,
      .range = espp::Adxl345::RANGE_2G,
      .data_rate = espp::Adxl345::RATE_100_HZ,
      .write = espp::make_i2c_addressed_write(dev),
      .read = espp::make_i2c_addressed_read(dev),
  });
}
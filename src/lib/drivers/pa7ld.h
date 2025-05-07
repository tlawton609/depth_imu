#pragma once

#include "stm32u5xx_hal.h"
#include "abstract_i2c.h"
#include "io.h"
#include "abstract_pressure_sensor.h"

// Using the PA-7LD

typedef enum {
  CUST_ID0 = 0x00,
  CUST_ID1 = 0x01,

  NA = 0x11,
  SCALING0 = 0x12,
  SCALING1 = 0x13,
  SCALING2 = 0x14,
  SCALING3 = 0x15,
  SCALING4 = 0x16,

  REQUEST_MEASURMENT = 0xAC,
} PA7LDCmd_t;

class PA7LD : public AbstractI2C, public AbstractPressureSensor {
public:
  PA7LD(I2CInterface_t* i2cInterface, uint8_t address);

  bool init();
  bool reset();
  bool readPTRaw(float &pressure, float &temperature);
  bool checkPROM();
  uint32_t signature();

private:
  bool readPROM();
  bool sendCommand(PA7LDCmd_t command, uint32_t timeoutMs);
  bool readData(uint8_t *data, size_t dataSize);
  bool getRawValue(uint32_t *value, uint32_t timeoutMs);

};
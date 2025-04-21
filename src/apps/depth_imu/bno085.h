#pragma once
#include "sh2_hal.h"
#include "abstract_i2c.h"

// So I'm thinking of using this class as the provider of the functions that
// the sh2 library needs for its sh2.h api calls. Then we should be able
// to just create an instance of this class, create a struct that
// uses this class to create an sh2_hal struct, call the init
// and then we should be able to use the sh2 apis... atleast I think

class Bno085 : public AbstractI2C {
public:
  Bno085(I2CInterface_t* i2cInterface, uint8_t address);
  bool init();
  int open(sh2_Hal_t *self);
  void close(sh2_Hal_t *self);
  int read(sh2_Hal_t *self, uint8_t *pBuffer, unsigned len, uint32_t *t_us);
  int write(sh2_Hal_t *self, uint8_t *pBuffer, unsigned len);
  uint32_t getTimeUs(sh2_Hal_t *self);

public:
  static constexpr uint8_t I2C_ADDR = 0x4A;


private:
  bool device_open;
  sh2_Hal_t sh2_hal;
};
#include "pa7ld.h"
#include "debug.h"

PA7LD::PA7LD(I2CInterface_t* i2cInterface, uint8_t address) {
  _interface = i2cInterface;
  _addr = static_cast<uint8_t>(address);
}

bool PA7LD::init() {
  // In here we can do the PROM reading and get
  // the Pmin and Pmax for later
  return true;
}

bool PA7LD::reset() {
  // Do nothing for now
  return true;
}
bool PA7LD::readPTRaw(float &pressure, float &temperature) {
  pressure = 0.5;
  temperature = 0.5;
  uint32_t value;
  getRawValue(&value, 10);
  return true;
}

bool PA7LD::checkPROM() {
  return true;
}

uint32_t PA7LD::signature() {
  return 1;
}

bool PA7LD::readPROM() {
  return true;
}

bool PA7LD::sendCommand(PA7LDCmd_t command, uint32_t timeoutMs) {
  (void) timeoutMs;
  return (writeBytes((uint8_t*)&command, sizeof(uint8_t)) == I2C_OK);
}

bool PA7LD::readData(uint8_t *data, size_t dataSize) {
  // How do we issue no command, just an address with the read bit set?
  // we can look at the i2c scan for how it does the address probing
  // and use the same method to just send the address? maybe?
  I2CResponse_t rval;

  do {
    // rval = writeBytes((uint8_t*)&command, sizeof(uint8_t));
    // if(rval != I2C_OK){
    //   printf("error writing to PA7LD: %d\n", rval);
    //   break;
    // }

    rval = readBytes(data, dataSize);
    if(rval != I2C_OK){
      printf("error reading bytes from PA7LD: %d\n", rval);
    }

  } while (0);

  return (rval == I2C_OK);
}

bool PA7LD::getRawValue(uint32_t *value, uint32_t timeoutMs) {
  (void)value;
  (void)timeoutMs;
  bool rval = true;
  configASSERT(value != NULL);

  do {
    rval = sendCommand(REQUEST_MEASURMENT, timeoutMs);
    if (!rval) {
      break;
    }

    vTaskDelay(pdMS_TO_TICKS(10));

    uint8_t adc[5] = {0,0,0,0,0};
    rval = readData(adc, sizeof(adc));
    if (!rval) {
      break;
    }

    for (int i = 0; i < 5; i++) {
      printf("our bytes: %" PRIx8 "\n", adc[i]);
    }

  } while (0);

  return rval;
}
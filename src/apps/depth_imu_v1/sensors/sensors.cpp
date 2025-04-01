#include <stdbool.h>
#include <stdint.h>
#include "bsp.h"
#include "sensors.h"
#include "abstract_pressure_sensor.h"
#include "FreeRTOS.h"

// Sensor driver includes
#include "ina232.h"

// Sampler initialization functions (so we don't need individual headers)
void powerSamplerInit(INA::INA232 **sensors); // implemented in src/lib/sensor_sampler/powerSampler.cpp

static INA::INA232 debugIna2(&i2c1, I2C_INA_PODL_ADDR);
static INA::INA232 *debugIna[NUM_INA232_DEV] = {
  &debugIna2,
};

void sensorsInit() {
  // Power monitor
  powerSamplerInit(debugIna); // There's technically one INA232 on the mote and one on Bristlefin,
  // keep the init functions out of Bristlefin now for convinience.
}

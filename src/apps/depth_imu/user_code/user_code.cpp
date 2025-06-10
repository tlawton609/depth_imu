#include "user_code.h"
#include "spotter.h"
#include "pubsub.h"
#include "bsp.h"
#include "configuration.h"
#include "debug.h"
#include "lwip/inet.h"
#include "sensors.h"
#include "stm32_rtc.h"
#include "task_priorities.h"
#include "uptime.h"
#include "app_util.h"
#include "bno085.h"
#include "sh2.h"
#include "pa7ld.h"


double gravity = 9.80665; // m/s^2
double rho_salt = 1023.6; // kg/m^3
double rho_fresh =  997.0474; // kg/m^3

#define PRESSURE_IN_PASCALS(pressure) ((pressure * 100000))
static constexpr char FRESH_WATER_FLAG[]  = "fresh_water";
static constexpr uint8_t DEPTH_SENSOR_ADDR = 0x40;

static bool fresh_water = false;

sh2_Hal_t sh2_hal_driver;

static Bno085 bno085_imu(&i2c1, IMU_ADDR);

// TODO - create a #define or constant somewhere for the depth address
static PA7LD depth_sensor(&i2c1, DEPTH_SENSOR_ADDR);

void setup(void) {
  /* USER ONE-TIME SETUP CODE GOES HERE */
  vTaskDelay(10000);
  depth_sensor.init();

  get_config_bool(BM_CFG_PARTITION_SYSTEM, FRESH_WATER_FLAG, strlen(FRESH_WATER_FLAG), &fresh_water);

}

void loop(void) {
  /* USER LOOP CODE GOES HERE */
  uint32_t curr_time_ms = bno085_imu.getTimeUs(&sh2_hal_driver)/1000;
  static uint32_t prev_time_ms = 0;
  if (curr_time_ms - 5000 > prev_time_ms) {
    printf("time: %" PRIu32 " ms\n", curr_time_ms);
    prev_time_ms = curr_time_ms;
    float pressure, temp;
    depth_sensor.readPTRaw(pressure, temp);
    double depth = 0.0;
    if (fresh_water) {
      depth = PRESSURE_IN_PASCALS(pressure) / (gravity * rho_fresh);
    } else {
      depth = PRESSURE_IN_PASCALS(pressure) / (gravity * rho_salt);
    }

    printf("pressure: %f bar, temp: %f °C, depth: %fm\n", pressure, temp, depth);

    // TODO - publis the depth on the BM bus so we can use it to make decisions in other systems?
    // Or we subscribe to other systems and tell them what to do to make sure we are correct here?

  }
}

#include "user_code.h"
#include "spotter.h"
#include "pubsub.h"
#include "bsp.h"
#include "debug.h"
#include "lwip/inet.h"
#include "sensors.h"
#include "stm32_rtc.h"
#include "task_priorities.h"
#include "uptime.h"
#include "app_util.h"
#include "bno085.h"
#include "sh2.h"

sh2_Hal_t sh2_hal_driver;

static Bno085 bno085_imu(&i2c1, IMU_ADDR);

void setup(void) {
  /* USER ONE-TIME SETUP CODE GOES HERE */
}

void loop(void) {
  /* USER LOOP CODE GOES HERE */
  uint32_t curr_time_ms = bno085_imu.getTimeUs(&sh2_hal_driver)/1000;
  static uint32_t prev_time_ms = 0;
  if (curr_time_ms - 1000 > prev_time_ms) {
    printf("time: %" PRIu32 " ms\n", curr_time_ms);
    prev_time_ms = curr_time_ms;
  }
}

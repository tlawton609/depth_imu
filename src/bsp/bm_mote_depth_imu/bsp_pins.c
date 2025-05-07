#include "bsp.h"
#include "stm32_io.h"

IOPinHandle_t GPIO2 = {&STM32PinDriver, &(STM32Pin_t){GPIO2_GPIO_Port, GPIO2_Pin, NULL, NULL}};
IOPinHandle_t EOC_INT = {&STM32PinDriver, &(STM32Pin_t){EOC_INT_GPIO_Port, EOC_INT_Pin, NULL, NULL}};
IOPinHandle_t VUSB_DETECT = {&STM32PinDriver, &(STM32Pin_t){VUSB_DETECT_GPIO_Port, VUSB_DETECT_Pin, NULL, NULL}};
IOPinHandle_t IMU_INT = {&STM32PinDriver, &(STM32Pin_t){IMU_INT_GPIO_Port, IMU_INT_Pin, NULL, NULL}};
IOPinHandle_t IMU_RESET = {&STM32PinDriver, &(STM32Pin_t){IMU_RESET_GPIO_Port, IMU_RESET_Pin, NULL, NULL}};
IOPinHandle_t BM_CS = {&STM32PinDriver, &(STM32Pin_t){BM_CS_GPIO_Port, BM_CS_Pin, NULL, NULL}};
IOPinHandle_t BM_SCK_RX3 = {&STM32PinDriver, &(STM32Pin_t){BM_SCK_RX3_GPIO_Port, BM_SCK_RX3_Pin, NULL, NULL}};
IOPinHandle_t BM_MISO = {&STM32PinDriver, &(STM32Pin_t){BM_MISO_GPIO_Port, BM_MISO_Pin, NULL, NULL}};
IOPinHandle_t BM_MOSI_TX3 = {&STM32PinDriver, &(STM32Pin_t){BM_MOSI_TX3_GPIO_Port, BM_MOSI_TX3_Pin, NULL, NULL}};
IOPinHandle_t BM_INT = {&STM32PinDriver, &(STM32Pin_t){BM_INT_GPIO_Port, BM_INT_Pin, NULL, NULL}}; // TODO setup int handlers?
IOPinHandle_t VBUS_BF_EN = {&STM32PinDriver, &(STM32Pin_t){VBUS_BF_EN_GPIO_Port, VBUS_BF_EN_Pin, NULL, NULL}};
IOPinHandle_t FLASH_SCK = {&STM32PinDriver, &(STM32Pin_t){FLASH_SCK_GPIO_Port, FLASH_SCK_Pin, NULL, NULL}};
IOPinHandle_t FLASH_MISO = {&STM32PinDriver, &(STM32Pin_t){FLASH_MISO_GPIO_Port, FLASH_MISO_Pin, NULL, NULL}};
IOPinHandle_t FLASH_MOSI = {&STM32PinDriver, &(STM32Pin_t){FLASH_MOSI_GPIO_Port, FLASH_MOSI_Pin, NULL, NULL}};
IOPinHandle_t FLASH_CS= {&STM32PinDriver, &(STM32Pin_t){FLASH_CS_GPIO_Port, FLASH_CS_Pin, NULL, NULL}};
IOPinHandle_t ADIN_PWR = {&STM32PinDriver, &(STM32Pin_t){ADIN_PWR_GPIO_Port, ADIN_PWR_Pin, NULL, NULL}};
IOPinHandle_t ADIN_RST = {&STM32PinDriver, &(STM32Pin_t){ADIN_RST_GPIO_Port, ADIN_RST_Pin, NULL, NULL}};
IOPinHandle_t ADIN_CS = {&STM32PinDriver, &(STM32Pin_t){ADIN_CS_GPIO_Port, ADIN_CS_Pin, NULL, NULL}};
IOPinHandle_t ADIN_SCK = {&STM32PinDriver, &(STM32Pin_t){ADIN_SCK_GPIO_Port, ADIN_SCK_Pin, NULL, NULL}};
IOPinHandle_t ADIN_MISO = {&STM32PinDriver, &(STM32Pin_t){ADIN_MISO_GPIO_Port, ADIN_MISO_Pin, NULL, NULL}};
IOPinHandle_t ADIN_MOSI = {&STM32PinDriver, &(STM32Pin_t){ADIN_MOSI_GPIO_Port, ADIN_MOSI_Pin, NULL, NULL}};
IOPinHandle_t ADIN_INT = {&STM32PinDriver, &(STM32Pin_t){ADIN_INT_GPIO_Port, ADIN_INT_Pin, NULL, NULL}};
IOPinHandle_t BOOT_LED = {&STM32PinDriver, &(STM32Pin_t){BOOT_LED_GPIO_Port, BOOT_LED_Pin, NULL, NULL}};
IOPinHandle_t PAYLOAD_RX = {&STM32PinDriver, &(STM32Pin_t){PAYLOAD_RX_GPIO_Port, PAYLOAD_RX_Pin, NULL, NULL}};
IOPinHandle_t PAYLOAD_TX = {&STM32PinDriver, &(STM32Pin_t){PAYLOAD_TX_GPIO_Port, PAYLOAD_TX_Pin, NULL, NULL}};

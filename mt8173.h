#include <inttypes.h>

char SOC_NAME[] = "mt8173";

void (*send_usb_response)(int, int, int) = (void*)0x4c5f;

int (*usbdl_put_data)() = (void*)0xA0C7;
int (*usbdl_get_data)() = (void*)0xA041;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG = (volatile uint32_t **)0x1226E8;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

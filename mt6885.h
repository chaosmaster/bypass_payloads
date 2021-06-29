#include <inttypes.h>

char SOC_NAME[] = "mt6885";

void (*send_usb_response)(int, int, int) = (void*)0x505B;

int (*usbdl_put_data)() = (void*)0xE6DF;
int (*usbdl_get_data)() = (void*)0xE651;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102B0C;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027C0;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

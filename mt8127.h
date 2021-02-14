#include <inttypes.h>

char SOC_NAME[] = "mt8127";

void (*send_usb_response)(int, int, int) = (void*)0x62a1;

int (*usbdl_put_data)() = (void*)0xB29B;
int (*usbdl_get_data)() = (void*)0xB215;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x1027E4;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

#include <inttypes.h>

char SOC_NAME[] = "mt6755";

void (*send_usb_response)(int, int, int) = (void*)0x449f;

int (*usbdl_put_data)() = (void*)0x9A4F;
int (*usbdl_get_data)() = (void*)0x99C9;

volatile uint32_t mode=0;
volatile uint32_t *SEC_REG2=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x1026DC;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

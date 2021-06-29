#include <inttypes.h>

char SOC_NAME[] = "mt6795";

void (*send_usb_response)(int, int, int) = (void*)0x4347;

int (*usbdl_put_data)() = (void*)0x976F;
int (*usbdl_get_data)() = (void*)0x96E9;

const int mode=0;
volatile uint32_t **SEC_REG=0;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1026D8;
volatile uint32_t SEC_OFFSET=0x48;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

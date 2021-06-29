#include <inttypes.h>

char SOC_NAME[] = "mt6779";

void (*send_usb_response)(int, int, int) = (void*)0x4CDB;

int (*usbdl_put_data)() = (void*)0xE02F;
int (*usbdl_get_data)() = (void*)0xDFA1;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102ACC;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027B0;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

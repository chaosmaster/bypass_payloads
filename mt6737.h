#include <inttypes.h>

char SOC_NAME[] = "mt6737";

void (*send_usb_response)(int, int, int) = (void*)0x42A3;

int (*usbdl_put_data)() = (void*)0x95EB;
int (*usbdl_get_data)() = (void*)0x9565;

const int mode=0;
volatile uint32_t **SEC_REG2=0x0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x1026D4;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

#include <inttypes.h>

char SOC_NAME[] = "mt6771";

void (*send_usb_response)(int, int, int) = (void*)0x4DAF;

int (*usbdl_put_data)() = (void*)0xDE9F;
int (*usbdl_get_data)() = (void*)0xDE11;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102ACC;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x01027B0;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

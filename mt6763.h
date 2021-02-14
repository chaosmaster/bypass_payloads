#include <inttypes.h>

char SOC_NAME[] = "mt6763";

void (*send_usb_response)(int, int, int) = (void*)0x4877;

int (*usbdl_put_data)() = (void*)0xD64F;
int (*usbdl_get_data)() = (void*)0xD5C9;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102B0C;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027B0;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

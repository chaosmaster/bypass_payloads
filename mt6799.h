#include <inttypes.h>

char SOC_NAME[] = "mt6799";

void (*send_usb_response)(int, int, int) = (void*)0x66AF;

int (*usbdl_put_data)() = (void*)0xF58F;
int (*usbdl_get_data)() = (void*)0xF509;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x10334C;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027EC;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11020014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11020000;

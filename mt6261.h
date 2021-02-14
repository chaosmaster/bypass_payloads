#include <inttypes.h>

char SOC_NAME[] = "mt6261";

void (*send_usb_response)(int, int, int) = (void*)0x16B1;

int (*usbdl_put_data)() = (void*)0x58D7;
int (*usbdl_get_data)() = (void*)0x5893;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x700041E4;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0xA0080014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0xA0080000;

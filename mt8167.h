#include <inttypes.h>

char SOC_NAME[] = "mt8167";

void (*send_usb_response)(int, int, int) = (void*)0x6C7D;

int (*usbdl_put_data)() = (void*)0xD2C7;
int (*usbdl_get_data)() = (void*)0xD241;

const int mode=1;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1028E4;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x10340C;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000;

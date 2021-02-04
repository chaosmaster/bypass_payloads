#include <inttypes.h>

char SOC_NAME[] = "mt6785";

void (*send_usb_response)(int, int, int) = (void*)0x53AF;

int (*usbdl_put_data)() = (void*)0xEA5B;
int (*usbdl_get_data)() = (void*)0xE9CD;

volatile uint32_t mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102B0C;
volatile uint32_t *SEC_REG2=(volatile uint32_t *)0x102B14;
volatile uint32_t SEC_OFFSET=0x0;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

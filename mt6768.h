#include <inttypes.h>

char SOC_NAME[] = "mt6768";

void (*send_usb_response)(int, int, int) = (void*)0x2C2F;

int (*usbdl_put_data)() = (void*)0xC173;
int (*usbdl_get_data)() = (void*)0xC0E5;

volatile uint32_t mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102A8C;
volatile uint32_t *SEC_REG2=(volatile uint32_t *)0x102A94;
volatile uint32_t SEC_OFFSET=0x0;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

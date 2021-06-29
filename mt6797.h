#include <inttypes.h>

char SOC_NAME[] = "mt6797";

void (*send_usb_response)(int, int, int) = (void*)0x4807;

int (*usbdl_put_data)() = (void*)0x9E8F;
int (*usbdl_get_data)() = (void*)0x9E09;

const int mode=0;
volatile uint32_t **SEC_REG=0;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1026DC;
volatile uint32_t SEC_OFFSET=0x48;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

#include <inttypes.h>

char SOC_NAME[] = "mt6582";

void (*send_usb_response)(int, int, int) = (void*)0x568D;

int (*usbdl_put_data)() = (void*)0xA5DF;
int (*usbdl_get_data)() = (void*)0xA559;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG= (volatile uint32_t **)0x1026FC;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

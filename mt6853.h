#include <inttypes.h>

char SOC_NAME[] = "mt6853";

void (*send_usb_response)(int, int, int) = (void*)0x538f;

int (*usbdl_put_data)() = (void*)0xea47;
int (*usbdl_get_data)() = (void*)0xe9b9;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102b0c;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027c4;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

int (*cmd_handler)() = (void*)0xf831;

void prehandshake() {
    volatile uint32_t *blacklist = (volatile uint32_t*)0x10284c;
    blacklist[0] = 0xA;
    blacklist[-1] &= ~0xFF000000;
}

#define PREHANDSHAKE prehandshake();
#define POSTHANDSHAKE cmd_handler();

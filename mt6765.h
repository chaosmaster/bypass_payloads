#include <inttypes.h>

char SOC_NAME[] = "mt6765";

void (*send_usb_response)(int, int, int) = (void*)0x2D2B;

int (*usbdl_put_data)() = (void*)0xBDA3;
int (*usbdl_get_data)() = (void*)0xBD15;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102A8C;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027A4;
volatile uint32_t SEC_OFFSET=0x28;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

int (*cmd_handler)() = (void*)0xcaed;

void prehandshake() {
    volatile uint32_t *blacklist = (volatile uint32_t*)0x102828;
    blacklist[0] = 0xA;
    blacklist[-1] &= ~0x40000000;
}

#define PREHANDSHAKE prehandshake();
#define POSTHANDSHAKE cmd_handler();

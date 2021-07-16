#include <inttypes.h>

char SOC_NAME[] = "mt8695";

void (*send_usb_response)(int, int, int) = (void*)0x55bb;

int (*usbdl_put_data)() = (void*)0xBED1;
int (*usbdl_get_data)() = (void*)0xBE4B;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG= (volatile uint32_t **)0x102FBC;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11003014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11003000;

int (*cmd_handler)() = (void*)0xcaa7;

void prehandshake() {
    volatile uint32_t *blacklist = (volatile uint32_t*)0x103048;
    blacklist[0] = 0xA;
    blacklist[-1] &= ~0x40000000;
}

#define PREHANDSHAKE prehandshake();
#define POSTHANDSHAKE cmd_handler();

#include <inttypes.h>
#define PAYLOAD_2_0
char SOC_NAME[] = "mt6885";

void (*send_usb_response)(int, int, int) = (void*)0x505b;
int (*(*usbdl_ptr))() = (void*)0xe6b8;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102b0c;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027c0;
volatile uint32_t SEC_OFFSET=0x28;
volatile uint32_t *bladdr=(volatile uint32_t *)0x102848;
volatile uint32_t *bladdr2=(volatile uint32_t *)0x106b60;
volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

int (*cmd_handler)() = (void*)0xf431;

#include <inttypes.h>
#define PAYLOAD_2_0
char SOC_NAME[] = "mt6761";

void (*send_usb_response)(int, int, int) = (void*)0x2cdf;
int (*(*usbdl_ptr))() = (void*)0xbc8c;

const int mode=1;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x102a8c;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x1027a4;
volatile uint32_t SEC_OFFSET=0x28;
volatile uint32_t *bladdr=(volatile uint32_t *)0x102828;
volatile uint32_t *bladdr2=(volatile uint32_t *)0x105994;
volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

int (*cmd_handler)() = (void*)0xc9b9;

#include <inttypes.h>
#define PAYLOAD_2_0
char SOC_NAME[] = "mt6261";

void (*send_usb_response)(int, int, int) = (void*)0xfff016b1;
int (*(*usbdl_ptr))() = (void*)0xfff05b18;

const int mode=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x700041e4;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x0;
volatile uint32_t SEC_OFFSET=0x40;
volatile uint32_t *bladdr=(volatile uint32_t *)0xf7ff9a00;
volatile uint32_t *bladdr2=(volatile uint32_t *)0x0;
volatile uint32_t *uart_reg0 = (volatile uint32_t*)0xa0080014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0xa0080000;

int (*cmd_handler)() = (void*)0xfff07001;

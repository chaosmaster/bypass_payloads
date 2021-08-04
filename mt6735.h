#include <inttypes.h>
#define PAYLOAD_2_0

char SOC_NAME[] = "mt6735";
void (*send_usb_response)(int, int, int) = (void*)0x4293;
int (*(*usbdl_ptr))() = (void*)0x95f8;

const int mode=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x1026d4;
volatile uint32_t **SEC_REG2=(volatile uint32_t **)0x0;
volatile uint32_t SEC_OFFSET=0x40;
volatile uint32_t *bladdr=(volatile uint32_t *)0x102760;
volatile uint32_t *bladdr2=(volatile uint32_t *)0x105704;
volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

int (*cmd_handler)() = (void*)0xa17f;

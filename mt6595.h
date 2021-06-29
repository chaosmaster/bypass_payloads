#include <inttypes.h>

char SOC_NAME[] = "mt6595";

void (*send_usb_response)(int, int, int) = (void*)0x5E2B;

int (*usbdl_put_data)() = (void*)0xB1FB;
int (*usbdl_get_data)() = (void*)0xB175;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG= (volatile uint32_t **)0x1026DC;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

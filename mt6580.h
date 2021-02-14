#include <inttypes.h>

char SOC_NAME[] = "mt6580";

void (*send_usb_response)(int, int, int) = (void*)0x62E5;

int (*usbdl_put_data)() = (void*)0xB5EF;
int (*usbdl_get_data)() = (void*)0xB569;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG= (volatile uint32_t **)0x1026D8;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000;

#include <inttypes.h>

char SOC_NAME[] = "mt6572";

void (*send_usb_response)(int, int, int) = (void*)0x00400000+0x6AC9;

int (*usbdl_put_data)() = (void*)0x00400000+0xBA4B;
int (*usbdl_get_data)() = (void*)0x00400000+0xB9C5;

volatile uint32_t mode=0;
volatile uint32_t *SEC_REG2=0;
volatile uint32_t **SEC_REG=(volatile uint32_t **)0x11141E80;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000;

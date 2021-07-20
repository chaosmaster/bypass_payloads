#include <inttypes.h>

#define PAYLOAD_2_0

char SOC_NAME[] = "mt8695";

void (*send_usb_response)(int, int, int) = (void*)0x55bb;

int (*(*usbdl_ptr))() = (void *)0xBEEC;

//int (*usbdl_put_data)() = (void*)0xBED1;
//int (*usbdl_get_data)() = (void*)0xBE4B;

const int mode=0;
volatile uint32_t **SEC_REG2=0;
volatile uint32_t **SEC_REG= (volatile uint32_t **)0x102FBC;
volatile uint32_t SEC_OFFSET=0x40;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11003014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11003000;

int (*cmd_handler)() = (void*)0xcaa7;

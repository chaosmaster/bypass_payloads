#include "common.h"

char SOC_NAME[] = "mt6580";

void (*send_usb_response)(int, int, int) = (void*)0x62E5;

int (*send_dword)() = (void*)0xB527;
int (*recv_dword)() = (void*)0xB4F3;
// addr, sz
int (*send_data)() = (void*)0xB5EF;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xB569;

uint16_t* sbc = (uint16_t *)0x6F9E;
uint16_t* sla = (uint16_t *)0x6FB6;
uint16_t* daa = (uint16_t *)0x6FDA;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000;
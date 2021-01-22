#include "common.h"

char SOC_NAME[] = "mt8695";

void (*send_usb_response)(int, int, int) = (void*)0x55bb;

int (*send_dword)() = (void*)0xBE09;
int (*recv_dword)() = (void*)0xBDD5;
// addr, sz
int (*send_data)() = (void*)0xBED1;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xBE4B;

uint16_t* sbc = (uint16_t *)0x63de;
uint16_t* sla = (uint16_t *)0x63f8;
uint16_t* daa = (uint16_t *)0x6420;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11003014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11003000;

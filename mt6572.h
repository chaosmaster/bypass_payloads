#include "common.h"

char SOC_NAME[] = "mt6572";

void (*send_usb_response)(int, int, int) = (void*)0x406AC9;

int (*send_dword)() = (void*)0x40B983;
int (*recv_dword)() = (void*)0x40B8D3;
// addr, sz
int (*send_data)() = (void*)0x40BA4B;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0x40B9C5;

uint16_t* sbc = (uint16_t *)0x4077BE;
uint16_t* sla = (uint16_t *)0x4077D6;
uint16_t* daa = (uint16_t *)0x4077FA;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11005014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11005000;
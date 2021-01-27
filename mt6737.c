#include "common.h"

char SOC_NAME[] = "mt6737";

void (*send_usb_response)(int, int, int) = (void*)0x42A3;

int (*send_dword)() = (void*)0x9523;
int (*recv_dword)() = (void*)0x94EF;
// addr, sz
int (*send_data)() = (void*)0x95EB;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0x9565;

uint16_t* sbc = (uint16_t *)0x4F62;
uint16_t* sla = (uint16_t *)0x4F7A;
uint16_t* daa = (uint16_t *)0x4F9E;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;
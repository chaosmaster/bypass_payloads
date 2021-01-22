#include "common.h"

char SOC_NAME[] = "mt8173";

void (*send_usb_response)(int, int, int) = (void*)0x4c5f;

int (*send_dword)() = (void*)0x9FFF;
int (*recv_dword)() = (void*)0x9FCB;
// addr, sz
int (*send_data)() = (void*)0xA0C7;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xA041;

uint16_t* sbc = (uint16_t *)0x59ba;
uint16_t* sla = (uint16_t *)0x59d2;
uint16_t* daa = (uint16_t *)0x59f6;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

#include "common.h"

char SOC_NAME[] = "mt8127";

void (*send_usb_response)(int, int, int) = (void*)0x62a1;

int (*send_dword)() = (void*)0xB1D3;
int (*recv_dword)() = (void*)0xB19F;
// addr, sz
int (*send_data)() = (void*)0xB29B;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xB215;

uint16_t* sbc = (uint16_t *)0x6f8e;
uint16_t* sla = (uint16_t *)0x6fa6;
uint16_t* daa = (uint16_t *)0x6fca;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

#include "common.h"

char SOC_NAME[] = "mt8163";

void (*send_usb_response)(int, int, int) = (void*)0x6d6f;

int (*send_dword)() = (void*)0xC047;
int (*recv_dword)() = (void*)0xC013;
// addr, sz
int (*send_data)() = (void*)0xC10F;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xC089;

uint16_t* sbc = (uint16_t *)0x7a2e;
uint16_t* sla = (uint16_t *)0x7a64;
uint16_t* daa = (uint16_t *)0x7a6a;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;

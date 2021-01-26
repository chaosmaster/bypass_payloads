#include "common.h"

char SOC_NAME[] = "mt6750";

void (*send_usb_response)(int, int, int) = (void*)0x449f;

int (*send_dword)() = (void*)0x9987;
int (*recv_dword)() = (void*)0x9953;
// addr, sz
int (*send_data)() = (void*)0x9A4F;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0x99C9;

uint16_t* sbc = (uint16_t *)0x520a;
uint16_t* sla = (uint16_t *)0x5222;
uint16_t* daa = (uint16_t *)0x5246;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;
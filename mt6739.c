#include "common.h"

char SOC_NAME[] = "mt6739";

void (*send_usb_response)(int, int, int) = (void*)0x508B;

int (*send_dword)() = (void*)0xDE2F;
int (*recv_dword)() = (void*)0xDDFB;
// addr, sz
int (*send_data)() = (void*)0xDEFF;
// addr, sz, flags (=0)
int (*recv_data)() = (void*)0xDE71;

uint16_t* sbc = (uint16_t *)0x5D74;
uint16_t* sla = (uint16_t *)0x5D8A;
uint16_t* daa = (uint16_t *)0x5DAE;

volatile uint32_t *uart_reg0 = (volatile uint32_t*)0x11002014;
volatile uint32_t *uart_reg1 = (volatile uint32_t*)0x11002000;
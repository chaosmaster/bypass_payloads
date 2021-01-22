#ifndef _COMMON_H_
#define _COMMON_H_

#include <inttypes.h>

extern char SOC_NAME[];

void (*send_usb_response)(int, int, int);

int (*send_dword)();
int (*recv_dword)();
// addr, sz
int (*send_data)();
// addr, sz, flags (=0)
int (*recv_data)();

uint16_t* sbc;
uint16_t* sla;
uint16_t* daa;

volatile uint32_t *uart_reg0;
volatile uint32_t *uart_reg1;

void low_uart_put(int ch);

void _putchar(char character);

#endif

#include "common.h"

uint16_t mov_r0_0 = 0x2000;
uint16_t bx_lr = 0x4770;

void low_uart_put(int ch) {

    while ( !((*uart_reg0) & 0x20) )
    {}

    *uart_reg1 = ch;
}

void _putchar(char character)
{
    if (character == '\n')
        low_uart_put('\r');
    low_uart_put(character);
}

int print(char* s){
    char c = s[0];
    int i = 0;
    while(c){
        _putchar(c);
        c = s[++i];
    }
    return i;
}

int main() {

    print("Entered ");
    print(SOC_NAME);
    print(" brom patcher\n");

    print("Copyright k4y0z 2021\n");

    //This is so we don't get a USB-Timeout
    print("Send USB response\n");
    send_usb_response(1,0,1);
    
    print("Sending ACK\n");
    send_dword(0xA1A2A3A4);

    // sec_cfg_sbc_enabled
    print("Patching SBC\n");
    *sbc++ = mov_r0_0;
    *sbc = bx_lr;

    // sec_cfg_sla_enabled
    print("Patching SLA\n");
    *sla++ = mov_r0_0;
    *sla = bx_lr;

    // sec_cfg_daa_enabled
    print("Patching DAA\n");
    *daa++ = mov_r0_0;
    *daa = bx_lr;

    //invalidate icache
    asm volatile ("mcr p15, 0, %0, c7, c5, 0" : : "r" (0));

    const char sequence[] = {0xA0, 0x0A, 0x50, 0x05};
    unsigned int index = 0;
    unsigned char hs = 0;

    print("Waiting for handshake...\n");

    do {
        while ( ((*uart_reg0) & 1) ) {}
        while ( 1 ) {
            recv_data(&hs, 1);
	    if(sequence[index] == hs) break;
	    index = 0;
	    print("\nHandshake failed!\n");
	}
        hs = ~hs;
        send_data(&hs, 1);
	index += 1;
	print(".");
    } while(index != 4);

    print("\nHandshake completed!\n");
}

#include <stdint.h>

volatile uint32_t *wdt = (volatile uint32_t *)0x10007000;

int (*send_word)() = 0;
int (*send_dword)() = 0;

int send_double_word(uint32_t dword){
	send_word(dword >> 16);
	send_word(dword);
	return 0;
}

__attribute__ ((section(".text.main"))) int main() {
    send_word = 0;
    send_dword = 0;
    int cnt = 0;
    for (uint32_t offset = 0x100; offset < 0x10000; offset++) {
    if (((uint32_t *)offset)[0] == 0x4FF8E92D && ((uint32_t *)offset)[1] == 0x468A4680) {
            if (cnt++ > 0) {
                send_dword = (void*)(offset | 1);
                break;
            }
            else {
                send_word = (void*)(offset | 1);
            }
        }
    }

    // If we didn't find send_dword, use send_word
    if (!send_dword && send_word) {
        send_dword = &send_double_word;
    }

    if (send_dword){
    	send_dword(0xC1C2C3C4);
        uint32_t rev = 0;
        for (uint32_t * address = 0; address < (uint32_t *)0x20000; address++) {
            rev = (*address & 0x000000FF) << 24;
            rev |= (*address & 0x0000FF00) << 8;
            rev |= (*address & 0x00FF0000) >> 8;
            rev |= (*address & 0xFF000000) >> 24;
            send_dword(rev);
        }
    }

    // Reboot device, so we still get feedback in case the above didn't work
    wdt[8/4] = 0x1971;
    wdt[0/4] = 0x22000014;
    wdt[0x14/4] = 0x1209;

    while (1) {

    }

}

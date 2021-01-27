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
    uint32_t brom_base = 0;
    for (int i =  0; i < 2; ++i) {
        for (uint32_t offset = brom_base + 0x100; offset < brom_base + 0x10000 ; offset++) {
            if (((char *)offset)[3] == 0x4F && ((char *)offset)[2] == 0xF8 && ((char *)offset)[1] == 0xE9 && ((char *)offset)[0] == 0x2D
                && ((char *)offset)[7] == 0x46 && ((char *)offset)[6] == 0x8A && ((char *)offset)[5] == 0x46 && ((char *)offset)[4] == 0x80 ) {
                if (cnt++ > 0) {
                    send_dword = (void*)(offset | 1);
                    break;
                }
                else {
                    send_word = (void*)(offset | 1);
                }
            }
        }
        if (send_dword || send_word) break;
        else brom_base = 0x00400000;
    }

    // If we didn't find send_dword, use send_word
    if (!send_dword && send_word) {
        send_dword = &send_double_word;
    }

    if (send_dword){
        send_dword(0xC1C2C3C4);
        uint32_t rev = 0;
        for (uint32_t * address = (uint32_t *)(brom_base) ; address < (uint32_t *)(brom_base + 0x20000); address++) {
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

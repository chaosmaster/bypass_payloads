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
    int i=0;
    uint32_t brom_bases[3] = {0x0, 0x00400000, 0x48000000};
    for (i =  0; i < 3; ++i) {
        for (uint32_t offset = brom_bases[i] + 0x100; offset < brom_bases[i] + 0x10000 ; offset+=2) {
            uint16_t *ptr=((uint16_t*)(offset));
            if (ptr[0]==0xE92D && ptr[1]==0x4FF8 && ptr[2]==0x4680 && ptr[3]==0x468A) {
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
    }

    // If we didn't find send_dword, use send_word
    if (!send_dword && send_word) {
        send_dword = &send_double_word;
    }

    if (send_dword){
        send_dword(0xC1C2C3C4);
        uint32_t rev = 0;
        for (uint32_t * address = (uint32_t *)(brom_bases[i]) ; address < (uint32_t *)(brom_bases[i] + 0x20000); address++) {
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

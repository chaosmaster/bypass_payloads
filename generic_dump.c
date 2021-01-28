#include <stdint.h>

volatile uint32_t *wdt = (volatile uint32_t *)0x10007000;

uint32_t brom_bases[] = {0x0, 0x00400000, 0x48000000};
uint16_t search_pattern[] = {0xE92D, 0x4FF8, 0x4680, 0x468A};

uint32_t (*send_word)() = 0;
uint32_t (*send_dword)() = 0;

uint32_t send_double_word(uint32_t dword) {
    send_word(dword >> 16);
    send_word(dword);
    return 0;
}

uint32_t searchfunc(uint32_t startoffset, uint32_t endoffset, uint16_t *pattern, uint32_t patternsize) {
    uint32_t matched = 0;
    for (uint32_t offset = startoffset; offset < endoffset; offset += 2) {
        for (uint32_t i = 0; i < patternsize; i++) {
            if (((uint16_t *)offset)[i] != pattern[i]) {
                matched = 0;
                break;
            }
            if (++matched == patternsize) return offset | 1;
        }
    }
    return 0;
}

__attribute__ ((section(".text.main"))) int main() {
    send_word = 0;
    send_dword = 0;
    uint32_t i = 0;
    for (uint32_t i =  0; i < (sizeof(brom_bases) / sizeof(*brom_bases)); ++i) {
        send_word = (void *)searchfunc(brom_bases[i] + 0x100, brom_bases[i] + 0x10000, search_pattern, 4);
        if (send_word){
            send_dword = (void *)searchfunc((uint32_t)send_word + 1, brom_bases[i] + 0x10000, search_pattern, 4);
            if (send_dword) break;
        }
        if (send_word || send_dword) break;
    }

    // If we didn't find send_dword, use send_word
    if (!send_dword && send_word) {
        send_dword = &send_double_word;
    }

    if (send_dword) {
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

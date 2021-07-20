#include <stdint.h>

volatile uint32_t *wdt = (volatile uint32_t *)0x10007000;

uint32_t brom_bases[] = {0x0, 0x00400000, 0x48000000};
uint16_t search_pattern[] = {0xE92D, 0x4FF8, 0x4680, 0x468A};

uint32_t (*send_word)() = 0;
uint32_t (*send_dword)() = 0;

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

uint32_t * ldr_lit(const uint32_t curpc, uint16_t instr, uint8_t *Rt) {
    //#LDR (literal), LDR R1, =SEC_REG
    uint8_t imm8 = instr & 0xFF;
    if (Rt) *Rt = (instr >> 8) & 7;
    uint32_t pc = (((uint32_t)curpc) / 4 * 4);
    return (uint32_t *)(pc + (imm8 * 4) + 4);
}


__attribute__ ((section(".text.main"))) int main() {
    send_word = 0;
    uint32_t i = 0;
    for (i = 0; i < (sizeof(brom_bases) / sizeof(*brom_bases)); ++i) {
        send_word = (void *)searchfunc(brom_bases[i] + 0x100, brom_bases[i] + 0x10000, search_pattern, 4);
        if (send_word) break;
    }

    if (send_word) {

        int (*(*usbdl_ptr))() = (void *)(ldr_lit((uint32_t)send_word + 7, ((uint16_t*)(send_word + 7))[0], 0));
        //Fix ptr_send
        *(volatile uint32_t *)(usbdl_ptr[0] + 8) = (uint32_t)usbdl_ptr[2];

        int usbdl_put_data(void* data, uint32_t size) {;
            (usbdl_ptr[2])(data, size);
            return (usbdl_ptr[3])();
        }

        int ack = __builtin_bswap32(0xC1C2C3C4);
        usbdl_put_data(&ack, 4);

        usbdl_put_data((void *)brom_bases[i], 0x20000);
    }

    // Reboot device, so we still get feedback in case the above didn't work
    wdt[8/4] = 0x1971;
    wdt[0/4] = 0x22000014;
    wdt[0x14/4] = 0x1209;

    while (1) {

    }

}

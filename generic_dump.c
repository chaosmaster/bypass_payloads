#include <stdint.h>

volatile uint32_t *wdt = (volatile uint32_t *)0x10007000;

int (*send_word)() = 0;
int (*send_dword)() = 0;

int send_double_word(uint32_t dword){
    send_word(dword >> 16);
    send_word(dword);
    return 0;
}

uint32_t searchfunc(uint32_t startoffset,uint32_t endoffset,uint16_t *pattern,int patternsize){
    int found=0;
    for (uint32_t offset=startoffset; offset < endoffset ; offset+=2) {
        uint16_t *ptr=((uint16_t*)(offset));
        for (int i=0;i<patternsize;i++)
        {
            if (ptr[i]!=pattern[i]) { found=0; break; }
            found+=1;
            if (found==patternsize) return offset;
        }
    }
    return 0;
}

__attribute__ ((section(".text.main"))) int main() {
    send_word = 0;
    send_dword = 0;
    int i=0;
    uint32_t offs1=0;
    uint32_t offs2=0;
    uint32_t brom_bases[3] = {0x0, 0x00400000, 0x48000000};
    uint16_t senddwordptr[4]={0xE92D,0x4FF8,0x4680,0x468A};
    for (i =  0; i < 3; ++i) {
        offs1=searchfunc(brom_bases[i] + 0x100,brom_bases[i] + 0x10000,senddwordptr,4);
        if (offs1!=0){
            offs2=searchfunc(offs1+2,brom_bases[i] + 0x10000,senddwordptr,4);
            if (offs2!=0) break;
        }
    }

    // If we didn't find send_dword, use send_word
    if (!offs2 && offs1) {
        send_word=(void*)(offs1|1);
        send_dword = &send_double_word;
    }
    else
    {
        send_dword=(void*)(offs2|1);
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

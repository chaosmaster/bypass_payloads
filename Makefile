CC := arm-none-eabi-gcc
AS := arm-none-eabi-as
LD := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy

SOCS := mt6261 mt6572 mt6580 mt6582 mt6595 mt6735 mt6737 mt6739 mt6753 mt6755 mt6757 mt6761 mt6763 mt6765 mt6779 mt6768 mt6771 mt6785 mt6795 mt6797 mt6799 mt6833 mt6853 mt6873 mt6885 mt8127 mt8163 mt8167 mt8173 mt8695 generic_dump generic_reboot generic_uart_dump generic_loader
PAYLOADS := $(SOCS:%=payloads/%_payload.bin)

CFLAGS := -std=gnu99 -Os -mthumb -mcpu=cortex-a9 -fno-builtin-printf -fno-strict-aliasing -fno-builtin-memcpy -fPIE -mno-unaligned-access -Wall -Wextra
LDFLAGS := -nodefaultlibs -nostdlib -lgcc

all: $(PAYLOADS)

payloads/%_payload.bin: payloads/%.elf
	$(OBJCOPY) -O binary $^ $@

payloads/%_loader.elf: payloads/%_loader.o loader.ld
	$(LD) -o $@ payloads/$*_loader.o $(LDFLAGS) -T loader.ld

payloads/%.elf: payloads/%.o payloads/start.o generic.ld
	$(LD) -o $@ payloads/$*.o payloads/start.o $(LDFLAGS) -T generic.ld

payloads/generic_%.o: generic_%.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

payloads/%_loader.o: %_loader.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

payloads/%.o: common.c %.h
	mkdir -p $(@D)
	$(CC) -c -o $@ common.c -D DEVICE_HEADER=$*.h $(CFLAGS)

payloads/%.o: %.S
	mkdir -p $(@D)
	$(AS) -o $@ $<

clean:
	-rm -rf payloads

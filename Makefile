BOOTLOADER_SOURCE_FILES := $(shell find Source/Boot -name *.c)
BOOTLOADER_OBJECT_FILES := $(patsubst Source/Boot/%.c, Build/Boot/%.o, $(BOOTLOADER_SOURCE_FILES))

OBJECT_FILES := $(BOOTLOADER_OBJECT_FILES)

CC = gcc
LD = ld

OUTPUT_DIR = Output

BOOTLOADER_CFLAGS =-fno-stack-protector -fpic -fshort-wchar -mno-red-zone -I /usr/include/efi/ -I /usr/include/efi/x86_64/ -I Includes/ -DEFI_FUNCTION_WRAPPER
BOOTLOADER_LDFLAGS =/usr/lib/crt0-efi-x86_64.o -nostdlib -znocombreloc -T /usr/lib/elf_x86_64_efi.lds -shared -Bsymbolic -L /usr/lib/ -l:libgnuefi.a -l:libefi.a

$(BOOTLOADER_OBJECT_FILES): Build/Boot/%.o : Source/Boot/%.c
	mkdir -p $(dir $@) && \
	$(CC) $(BOOTLOADER_CFLAGS) -c $(patsubst Build/Boot/%.o, Source/Boot/%.c, $@) -o $@
	$(LD) $(patsubst Source/Boot/%.c, Build/Boot/%.o, $@) $(BOOTLOADER_LDFLAGS) -o BOOTX64.SO

.PHONY: bootloader
bootloader: $(OBJECT_FILES)
	mkdir -p $(OUTPUT_DIR)/EFI/BOOT/ && \
	objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela -j .reloc --target=efi-app-x86_64 BOOTX64.SO $(OUTPUT_DIR)/EFI/BOOT/BOOTX64.EFI

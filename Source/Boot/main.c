
#include <efi.h>
#include <efilib.h>

#include <Boot/Console/console.h>

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {

    InitializeLib(ImageHandle, SystemTable);

    clearScreen();

    changeFontColor(EFI_LIGHTRED, EFI_BLACK);

    Print(L"Hello from mediaOS-Blub UEFI Bootloader!\n");
    Print(L"Now we have colors. AMAZING");

    while(1){};

    return EFI_SUCCESS;
}
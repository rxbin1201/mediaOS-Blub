
#include <Boot/Console/console.h>

VOID clearScreen(VOID) {
    uefi_call_wrapper(ST->ConOut->ClearScreen, 1, ST->ConOut);
}

VOID changeFontColor(UINTN FOREGROUND, UINTN BACKGROUND) {
    uefi_call_wrapper(ST->ConOut->SetAttribute, 1, ST->ConOut, FOREGROUND);
    uefi_call_wrapper(ST->ConOut->SetAttribute, 1, ST->ConOut, BACKGROUND);
}

VOID setCursorPosition(UINTN x, UINTN y) {
    uefi_call_wrapper(ST->ConOut->SetCursorPosition, 3, ST->ConOut, x, y);
}

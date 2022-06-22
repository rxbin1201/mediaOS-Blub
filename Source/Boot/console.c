
#include <Boot/console.h>

VOID clearScreen(VOID) {
    uefi_call_wrapper(ST->ConOut->ClearScreen, 1, ST->ConOut);
}

VOID changeFontColor(UINTN FOREGROUND) {
    uefi_call_wrapper(ST->ConOut->SetAttribute, 2, ST->ConOut, FOREGROUND);
}

VOID setCursorPosition(UINTN x, UINTN y) {
    uefi_call_wrapper(ST->ConOut->SetCursorPosition, 3, ST->ConOut, x, y);
}

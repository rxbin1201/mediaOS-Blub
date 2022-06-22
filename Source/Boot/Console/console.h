
#ifndef BOOTLOADER_CONSOLE_H
#define BOOTLOADER_CONSOLE_H

#include <efi.h>
#include <efilib.h>

VOID clearScreen(VOID);
VOID changeFontColor(UINTN FOREGROUND, UINTN BACKGROUND);
VOID setCursorPosition(UINTN x, UINTN y);

#endif

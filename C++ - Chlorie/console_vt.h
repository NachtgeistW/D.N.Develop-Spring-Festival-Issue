#pragma once

#ifdef _WIN32

#define DEFINE_CONSOLEV2_PROPERTIES
#include "Windows.h"

inline bool enable_virtual_terminal_mode()
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (out_handle == INVALID_HANDLE_VALUE) return false;
    DWORD mode = 0;
    if (!GetConsoleMode(out_handle, &mode)) return false;
    return SetConsoleMode(out_handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

#undef DEFINE_CONSOLEV2_PROPERTIES

#else

inline bool enable_virtual_terminal_mode() { return true; }

#endif

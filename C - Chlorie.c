#define DEFINE_CONSOLEV2_PROPERTIES

#include <Windows.h>
#include <stdio.h>

void enable_vt()
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(out_handle, &mode);
    SetConsoleMode(out_handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void print(int r, int g, int b, char* c)
{
    char ch[3] = { c[0], c[1], 0 };
    printf("\033[38;2;%d;%d;%dm%s", r, g, b, ch);
}

int main()
{
    char str[] =
    {
        -46, -71, -62, -42, -76, -13, -76, -13, -68, -14,
        -42, -79, -54, -57, -52, -20, -54, -71, -93, -95,
        -80, -95, -80, -95, -80, -95, -80, -95, -68, -92,
        -74, -81, -75, -67, -59, -36, -56, -90, -93, -95,
        -93, -95, -93, -95, -93, -95
    };
    int str_len = 23;
    int clr[3] = { 255, 0, 0 };
    int chnl = 0;
    int dir = 1;
    int i;
    enable_vt();
    while (1)
    {
        for (i = 0; i < str_len; i++)
        {
            if (dir == 1) { if (++clr[(chnl + 1) % 3] == 255) dir = -1; }
            else { if (--clr[chnl % 3] == 0) { dir = 1; chnl++; } }
            print(clr[0], clr[1], clr[2], str + 2 * i);
            Sleep(1);
        }
    }
}

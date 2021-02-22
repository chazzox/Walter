#include "windows.h"
#include <cstdio> 
#include <tchar.h>
 

int _cdecl _tmain(
    int argc,
    TCHAR* argv[])
{
    if (RegisterHotKey(
        NULL,
        1,
        MOD_ALT | MOD_NOREPEAT,
        0x42))  //0x42 is 'b'
    {
        _tprintf(_T("Hotkey 'ALT+b' registered, using MOD_NOREPEAT flag\n"));
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            _tprintf(_T("WM_HOTKEY received\n"));
        }
    }

    return 0;
}

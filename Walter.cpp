#include "windows.h"
#include <iostream>

int main() {
    if (RegisterHotKey(NULL,1,MOD_ALT,0x42)) {
        std::cout << "registered the hotkey correctly" << std::endl;
    }

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        if (msg.message == WM_HOTKEY)
        {
            std::cout << "WM_HOTKEY received" << std::endl;
        }
    }
    return 0;
}

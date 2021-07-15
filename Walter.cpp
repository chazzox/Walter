#include "windows.h"
#include <iostream>

int main() {
	bool is_open = false;
	// hot key is on alt+b
	if (RegisterHotKey(NULL,1,MOD_ALT,0x42)) {
       		std::cout << "registered the hotkey correctly" << std::endl;
    	}

    	MSG msg = { 0 };

    	while (GetMessage(&msg, NULL, 0, 0) != 0) {
	        if (msg.message == WM_HOTKEY)
       		{
	            std::cout << "WM_HOTKEY received" << std::endl;
		    is_open = !is_open;
		    if(is_open){
			    std::cout << "open gui" << std::endl;
		    }
		    else{
			    std::cout << "close gui" << std::endl;
			}
       		}
    	}
   	 return 0;
}


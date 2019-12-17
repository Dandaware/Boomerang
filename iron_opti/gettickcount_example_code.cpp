#include <windows.h>
#include <iostream>

int main(void)
{
    HMODULE winmmDLL = LoadLibraryA("winmm.dll");

    if (!winmmDLL) {
        std::cerr << "LoadLibrary failed." << std::endl;
        return 1;
    }

    typedef DWORD (WINAPI *timeGetTime_fn)(void);
    timeGetTime_fn pfnTimeGetTime = (timeGetTime_fn)GetProcAddress(winmmDLL, "timeGetTime");

    if (!pfnTimeGetTime) {
        std::cerr << "GetProcAddress failed." << std::endl;
        return 2;
    }

    std::cout << (*pfnTimeGetTime)() << std::endl;
    return 0;
}
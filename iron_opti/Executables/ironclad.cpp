#include <Windows.h>
#include <BaseTsd.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <wchar.h>

void atosProcessError(LPCSTR n) {
    char c1;
    HANDLE hF;
    uint uI;
    char c2;
    DWORD dwProcessId;
    CHAR cProcessId[512];

    if (n < (LPCSTR)0x1f4) {
        wsprintfA(cProcessId, cErr)
    } else {
        lstrcpyA(cProcessId, n);
    }
    //Ngi32.dll
    //Self-Writ Functions...

    if (DAT_1003a190 != (HMODULE)0x0){
       //To-Do: !
       FreeLibrary(/*DAT_1003a190*/);
       /*DAT_1003a190*/ = (HMODULE)0x0;
    }
    ExitProcess(4);
    return;
}

UINT_PTR atosGetProcessAddress(int n) {
    return *(UINT_PTR*)(&g_fastproc + n * 4);
}

void* atosAlloc(size_t n) {
    void* x;
    x = malloc(n);
    if (x == (void*)0x0) {
        atosProcessError(&cErr);
    }
    return x;
}
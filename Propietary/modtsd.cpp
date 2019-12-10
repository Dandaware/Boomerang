#include <Windows.h>
#include <BaseTsd.h>

#include <SAL.h>
#include <TlHelp32.h>

#include <iostream>
#include <string>

#include <tchar.h>
#include <wchar.h>

typedef int* ListProcessParameters(
    _In_opt_ LPCSTR ProcessName,
    _In_ LPDWORD ProcessThreadModule,
    _In_ LPDWORD ProcessThreadId,
    _In_ LPINT ProcessModuleBuffer
);

//Module Write/Read Region

typedef struct __CREATE_PROCESS_MODULE(_In_ LPDWORD dwProcessModulePid) {
    HANDLE handleProcessModule = dwProcessModulePid;
    HANDLE handleprocessSnapshot;
    DWORD dwThreadPid;
    DWORD dwThreadProcessValue;
} CreateProcessModule, *PtrCreateProcessModule;

typedef struct __UNREAD_PROCESS_INTEGRITY(_In_read_bytes(argv) LPDWORD dwProcessModulePid) {
    HANDLE handleProcessModule;
    HANDLE handleProcessSnapshot;
    DWORD dwProcessModule;
    BOOL isProcessModule;
    Bool hasReadProcessModule;
} ReadProcessModule;

unsigned* __READ_PROCESS_MODULE(_In_read_bytes(argv) LPDWORD dwProcessModulePid) {
    //To-Do: Need to check files and their integrities,
    // following the byte size corresponding to main(int argc, char *argv[])
    // and create a SafeRead() accomplice.
}

unsigned* __WRITE_WITH_BUFFER(_Out_writes_(argv) LPDWORD dwProcessModulePid) {
    char buffer[0x08] = 0;

    if (!_Out_writes_(argv))
        _Out_writes_z_(buffer);
}

unsigned* __UPDATE_REPLACE_MODULE(_In_updates_bytes_(argv) LPDWORD dwProcessModulePid) {
    HANDLE handleProcessModule;
    DWORD dwProcessModule;
    DWORD dwProcessManned;
    BOOL isExistingProcessModule;
    BOOL hasUpdatedProcessModule;

    memcpy(dwProcessModule = new dwProcessManned, dwProcessModulePid, NULL);

    if (isExistingProcessModule == 0 ? NULL : dwProcessManned = dwProcessModule)
        memmove(dwProcessManned, dwProcessModule, 0x08);
}

void* __DELETE_PROCESS_BUFFER(_Inout_opt_ dword dwProcessModulePid) {
    //To-Do: Delete and check and verify/validate file(s) integrities.
}

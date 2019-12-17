#include <Windows.h>
#include <iostream>

DWORD WINAPI SuspenThread(__in HANDLE handThread);

NTSTATUS WINAPI NTQueryInformationProcess ()
    __in HANDLE ProcessHandle,
    __in PROCESSINFOCLASS ProcessInformationClass,
    __out PVOID ProcessInformation,
    __in ULONG ProcessInformationLength,
    __out_opt PULONG ReturnLength
);

typedef struct _PROCESS_BASIC_INFORMATION {
    PVOID ExitStatus;
    PPEB PEBBaseAddress;
    PVOID AffinityMask;
    PVOID BasePriority;
    ULONG_PTR UniqueProcessID;
    PVOID InheritedFromUniqueProcessID;
} PROCESS_BASIC_INFORMATION;

BOOL WINAPI ReadProcessMemory (
    __in HANDLE handleProcesss,
    __in LPCVOID lpcBaseAddress,
    __out LPVOID lpcBuffer,
    __in SIZE_T nSize,
    __out SIZE_T lpcNumberOfBytesRead
);

BOOL WINAPI VirtualProtectEx (
    __in HANDLE handleProcess,
    __in LPVOID lpAddress,
    __in SIZE_T flNewProtect,
    __in PDWORD lpflOldProtect
);
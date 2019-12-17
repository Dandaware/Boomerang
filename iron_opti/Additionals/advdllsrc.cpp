// Common headers/libraries
#include <windows.h>
#include <iostream>
#include <string>
// Memory manipulation headers/libraries
#include <thread>
#include <memory>
#include <queue>

BOOL WINAPI CreateProcess (
    __in_opt    LPCTSTR adlpAppName,
    __inout_opt LPTSTR adlpCommandLine,
    __in_opt    LPSECURITY_ATTRIBUTES adlpProcessAttributes,
    __in_opt    LPSECURITY_ATTRIBUTES adlpThreadAttributes,
    __in BOOL   boolInheritHandles,
    __in DWORD  dwCreationFlags,
    __in_opt    LPVOID adlpEnvironment,
    __in_opt    LPCTSTR adlpCurrentDirectory,
    __in        LPSTARTINFO adlpStartupInfo,
    __out       LPPROCESS_INFORMATION adlpProcessInformation
);

typedef struct _PROCESS_INFORMATION {
    HANDLE handProcess;
    HANDLE handThread;
    DWORD dwProcessID;
    DWORD dwThreadID;
} PROCESS_INFORMATION, *LPPROCESS_INFORMATION;

BOOL WINAPI WriteProcessMemory (
    __in HANDLE handProcess,
    __in LPVOID adlpBaseAddress,
    __in LPCVOID adlpBuffer,
    __in SIZE_T nSize,
    __out SIZE_T*adlpNumberOfBytesWritten
);

HANDLE WINAPI CreateRemoteThread (
    __in HANDLE handProcess,
    __in LPSECURITY_ATTRIBUTES adlpThreadAttributes,
    __in SIZE_T dwStackSize,
    __in LPTHREAD_START_ROUTINE,
    __in LPVOID adlpParameter,
    __in DWORD dwCreationFlags,
    __out LPDWORD adlpThreadID
);
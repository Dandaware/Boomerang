/*
Bibliography:
	External C++ Trainer by Guided Hacking
	Faking KERNEL32.DLL - an Amateur Sandbox by Alexey Lyashkov
*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <SAL.h>

#include <BaseTsd.h>
#include <TlHelp32.h>

#include <tchar.h>
#include <wchar.h>

#include <vector>

/*
intptr_t GetProcessList(const wchar_t *exprocessId);
BOOL ListProcessModules(DWORD dwId);
BOOL ListProcessThread(DWORD dwOwnerPid);
*/

typedef struct _PROCESS_LIST {
    HANDLE handleProcessSnapshot;
    HANDLE handleProcess;
    PROCESSENTRY32 i3d32process;
    DWORD dwPriorityClass;
} PROCESS_LIST, *PIN_PROCESS_LIST;

// CreateProcessList()

BOOL WINAPI ListProcessModules (
	_In_opt_ LPCTSTR listProcessId,
	_In_opt_ LPSECURITY_ATTRIBUTES listProcessAttributes,
	_Out_ LPPROCESS_INFORMATION listProcessInformation,
);

BOOL WINAPI ListThreadModules (
	_In_ DWORD dwFlags=0,
	_In_ DWORD dwThreadId,
	_In_ LPCTSTR stringThreadId,
	_In_ LPTHREAD_START_ROUTINE,
	_In_opt_ LPSECURITY_ATTRIBUTES listThreadAttributes,
	_Out_ LPDWORD listThreadId
);

// GetProcessList()

intptr_t GetProcessList(const wchar_t *exprocessId) : public PROCESS_LIST {

    handleProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS|TH32CS_SNAPMODULE32, (exprocessId) ? 0 : (unsigned)-1);
	if (handleProcessSnapshot == INVALID_HANDLE_VALUE) {
		printf("Invalid HANDLE usage (- of process/es)");

		i3d32process.dwSize = sizeof(i3d32process);
		if (!Process32First(handleProcessSnapshot, &i3d32process)) {
			Process32FirstW;
		}

		do {
			_tprintf(TEXT(R"(PROCESS NAME:\t %s\n")", i3d32process.szExeFile));

			dwPriorityclass = i3d32process.th32ProcessID;

			if (!_wcsicmp(i3d32process.szExeFile, exprocessId)) {
				_wcsinc(i3d32process.szExeFile);
				return FALSE;
			}

			handleProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, i3d32process.th32ProcessID);

			if (handleProcess == NULL)
				OpenProcess((NULL)?PROCESS_TERMINATE:PROCESS_QUERY_INFORMATION|PROCESS_VM_READ, FALSE, i3d32process.th32ProcessID);
			else {
				dwPriorityclass = GetPriorityClass(handleProcess);
				if (!dwPriorityclass)
					GetPriorityClass(handleProcess);
				CloseHandle(handleProcess);
			}

			printf(R"(
			Process ID:	0x%08X			
			Thread Count:	%d			
			Parent Process ID:	0x%08X			
			Priority Base:	%d)",
				i3d32process.th32ProcessID,
				i3d32process.cntThreads,
				i3d32process.th32ParentProcessID,
				i3d32process.pcPriClassBase);

			ListProcessModules(i3d32process.th32ProcessID);
			ListProcessThreads(i3d32process.th32ProcessID);
		} while (Process32Next(handleProcessSnapshot, &i3d32process));

	}

	CloseHandle(handleProcessSnapshot);
	return 0;
}

BOOL ListProcessModules(DWORD dwPID) {
	HANDLE handleModuleSnapshot = INVALID_HANDLE_VALUE;
	MODULEENTRY32 mode32;

	handleModuleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPID);

	if (handleModuleSnapshot == INVALID_HANDLE_VALUE) {
		printf("CreateToolhelp32Snapshot (- of modules)");
		return FALSE;
	}

	mode32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(handleModuleSnapshot, &mode32)) {
		printf("Module32First");
		CloseHandle(handleModuleSnapshot);
		return FALSE;
	}

	do {
		printf(R"(\n%s
			\n%s
			\n%0x%08X
			\n%0x%04X
			\n%0x%04X
			\n%0x%08X
			\n%d)",
			mode32.szModule,
			mode32.szExePath,
			mode32.th32ProcessID,
			mode32.GlblcntUsage,
			mode32.ProccntUsage,
			(DWORD)mode32.modBaseAddr,
			mode32.modBaseSize);
	} while (Module32Next(handleModuleSnapshot, &mode32));

	CloseHandle(handleModuleSnapshot);
	return TRUE;
}
BOOL ListProcessThreads(DWORD dwOwnerPID) {
	HANDLE handleThreadSnapshot = INVALID_HANDLE_VALUE;
	THREADENTRY32 the32;

	handleThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, dwOwnerPID);

	if (handleThreadSnapshot == INVALID_HANDLE_VALUE)
		return FALSE;

	the32.dwSize = sizeof(THREADENTRY32);

	if (!Thread32First(handleThreadSnapshot, &the32)) {
		printf("Thread32First");
		CloseHandle(handleThreadSnapshot);
		return FALSE;
	}

	do {
		if (the32.th32OwnerProcessID == dwOwnerPID) {
			printf(R"(\n%x%08X
				\n%d
				\n%d\n)");
		}
	} while (Thread32Next(handleThreadSnapshot, &the32));

	CloseHandle(handleThreadSnapshot);
	return TRUE;
}
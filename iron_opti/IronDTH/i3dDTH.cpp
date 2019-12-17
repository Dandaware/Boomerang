#include "i3dDTH.h"
#include "pch.h"

intptr_t GetProcessList(const wchar_t *exprocessID);
BOOL ListProcessModules(DWORD dwPID);
BOOL ListProcessThreads(DWORD dwOwnerPID);

HWND ironwinhandle = (HWND)"Parkan. Iron Strategy";

int main()
{
	(const wchar_t)GetProcessList(L"iron3d.exe");
}

intptr_t GetProcessList(const wchar_t *exprocessID) {
	HANDLE handleProcessSnapshot;
	HANDLE handleProcess;
	PROCESSENTRY32 i3d32process;
	DWORD dwPriorityclass;

	handleProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS|TH32CS_SNAPMODULE32, (exprocessID) ? 0 : (unsigned)-1);
	if (handleProcessSnapshot == INVALID_HANDLE_VALUE) {
		printf("Invalid HANDLE usage (- of process/es)");

		i3d32process.dwSize = sizeof(i3d32process);
		if (!Process32First(handleProcessSnapshot, &i3d32process)) {
			Process32FirstW;
		}

		do {
			_tprintf(TEXT(R"(PROCESS NAME:\t %s\n")", i3d32process.szExeFile));

			dwPriorityclass = i3d32process.th32ProcessID;

			if (!_wcsicmp(i3d32process.szExeFile, exprocessID)) {
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
	HANDLE hModuleSnapshot = INVALID_HANDLE_VALUE;
	MODULEENTRY32 mode32;

	hModuleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPID);

	if (hModuleSnapshot == INVALID_HANDLE_VALUE) {
		printf("CreateToolhelp32Snapshot (- of modules)");
		return FALSE;
	}

	mode32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(hModuleSnapshot, &mode32)) {
		printf("Module32First");
		CloseHandle(hModuleSnapshot);
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
	} while (Module32Next(hModuleSnapshot, &mode32));

	CloseHandle(hModuleSnapshot);
	return TRUE;
}
BOOL ListProcessThreads(DWORD dwOwnerPID) {
	HANDLE hThreadSnapshot = INVALID_HANDLE_VALUE;
	THREADENTRY32 the32;

	hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, dwOwnerPID);

	if (hThreadSnapshot == INVALID_HANDLE_VALUE)
		return FALSE;

	the32.dwSize = sizeof(THREADENTRY32);

	if (!Thread32First(hThreadSnapshot, &the32)) {
		printf("Thread32First");
		CloseHandle(hThreadSnapshot);
		return FALSE;
	}

	do {
		if (the32.th32OwnerProcessID == dwOwnerPID) {
			printf(R"(\n%x%08X
				\n%d
				\n%d\n)");
		}
	} while (Thread32Next(hThreadSnapshot, &the32));

	CloseHandle(hThreadSnapshot);
	return TRUE;
}

unsigned addrOffset(HANDLE hprocess, unsigned int ptr, std::vector<unsigned int>offset) {
	unsigned int addr = ptr;
	for (unsigned int i = 0; i < offset.size(); ++i) {
		ReadProcessMemory(hprocess, (unsigned char*)addr, &addr, sizeof(addr), 0);
		addr += offset[i];
	}
	return addr;
}
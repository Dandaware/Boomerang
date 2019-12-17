// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#if defined(_WIN32)||defined(WIN32)
	#define IS_WINDOWS_OS 1
	// Windows API
	#include <Windows.h>
	// Windows Session
	#include <WtsApi32.h>
	// Standard Library
	#include <stdio.h>
	// String API
	#include <string.h>
	#include <strsafe.h>
	// File I/O
	#include <fstream>
	// Maths
	#include <vector>
	// Complementary Library
	#include <TlHelp32.h>
	#include <tchar.h>
	#include <wchar.h>

	#elif __UNIX__
	#define IS_WINDOWS_OS 0
	#endif

// We can use the Directive: #line - for debugging.
	#pragma region SAFE_READWRITE
	#define SAFE_RW_O
	#define MAXFILES 4
	#define MINFILES 1
	INT32 typedef initfile(char* filename);
	INT32 typedef dopenload(char* filename, int openloadapi);

	INT32 typedef diread8(INT32 handle, UINT8 buffer); // DandaIntRead8
	INT32 typedef diread16(INT32 handle, UINT16 buffer); // DandaIntRead16
	INT32 typedef diread32(INT32 handle, UINT32 buffer); // DandaIntRead32

	#pragma endregion

	char* getgamecall(void);
	char getgameapi(const char* gameapi);
	void getgamesource(char* gamesource);

#endif //PCH_H

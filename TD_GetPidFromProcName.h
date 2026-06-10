#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

DWORD TD_GetPidFromProcNameW(const wchar_t* ProcName);
DWORD TD_GetPidFromProcNameA(const char* ProcName);
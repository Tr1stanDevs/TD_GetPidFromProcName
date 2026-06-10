#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

DWORD TD_GetPidFromProcName(const wchar_t* ProcName);
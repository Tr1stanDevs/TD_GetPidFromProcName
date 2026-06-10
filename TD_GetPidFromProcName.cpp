#include "TD_GetPidFromProcName.h"
#include <string.h>

DWORD TD_GetPidFromProcNameW(const wchar_t* ProcName) {
    DWORD PID = 0;

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32W PE;
    PE.dwSize = sizeof(PE);
    
    if (hSnap == INVALID_HANDLE_VALUE) return 0;

    if(Process32FirstW(hSnap, &PE)) {
        do {
            if (_wcsicmp(ProcName, PE.szExeFile) == 0) {
                PID = PE.th32ProcessID;
                break;
            }
        } while (Process32NextW(hSnap, &PE));
    } 

    std::cout << PID << std::endl;

    return PID;
}

DWORD TD_GetPidFromProcNameA(const char* ProcName) {
    DWORD PID = 0;

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 PE;
    PE.dwSize = sizeof(PE);
    
    if (hSnap == INVALID_HANDLE_VALUE) return 0;

    if(Process32First(hSnap, &PE)) {
        do {
            if (_stricmp(ProcName, PE.szExeFile) == 0) {
                PID = PE.th32ProcessID;
                break;
            }
        } while (Process32Next(hSnap, &PE));
    } 

    std::cout << PID << std::endl;

    return PID;
}
#include "TD_GetPidFromProcName.h"

DWORD TD_GetPidFromProcName(const wchar_t* ProcName) {
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
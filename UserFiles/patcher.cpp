#include "patcher.h"
#include <string>
#include <detours/detours.h>

static _NtQuerySystemInformation FuncNtQuerySystemInformation;

const std::wstring BLACKLISTED_PROCESSES[] = {
    L"obs64.exe", // OBS
    L"livehime.exe" // B站直播姬
};

bool checkProcessName(const PWSTR processName) {
    for (const auto& name : BLACKLISTED_PROCESSES) {
        if (lstrcmpW(processName, name.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

NTSTATUS _stdcall HookNtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, SIZE_T SystemInformationLength, PSIZE_T ReturnLength) {
    const NTSTATUS Result = FuncNtQuerySystemInformation(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);

    if (NT_SUCCESS(Result) && SystemInformationClass == SystemProcessInformation) {
        PSYSTEM_PROCESS_INFO pSystemProcess = static_cast<PSYSTEM_PROCESS_INFO>(SystemInformation);
        PSYSTEM_PROCESS_INFO pNextSystemProcess = reinterpret_cast<PSYSTEM_PROCESS_INFO>(reinterpret_cast<PBYTE>(pSystemProcess) + pSystemProcess->NextEntryOffset);
        ULONG NextEntryOffset;

        do {
            NextEntryOffset = pNextSystemProcess->NextEntryOffset;

            if (checkProcessName(pNextSystemProcess->ImageName.Buffer)) {
                pSystemProcess->NextEntryOffset += pNextSystemProcess->NextEntryOffset;
            }
            pSystemProcess = pNextSystemProcess;
            pNextSystemProcess = reinterpret_cast<PSYSTEM_PROCESS_INFO>(reinterpret_cast<PBYTE>(pSystemProcess) + pSystemProcess->NextEntryOffset);
        } while (NextEntryOffset);
    }

    return Result;
}

void doFuckKook() {
    // Wait for app load
    Sleep(1000);

    const HMODULE hNtdll = GetModuleHandle(L"ntdll.dll");
    FuncNtQuerySystemInformation = reinterpret_cast<_NtQuerySystemInformation>(GetProcAddress(hNtdll, "NtQuerySystemInformation"));

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&reinterpret_cast<PVOID&>(FuncNtQuerySystemInformation), HookNtQuerySystemInformation);
    DetourTransactionCommit();
}

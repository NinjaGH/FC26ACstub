#include <windows.h>
#include <iostream>

int wmain() {
    std::wcout << L"[FakeEAAC] FC26 Anticheat Stub Initialized..." << std::endl;

    // Setup process startup info
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Attempt to launch FC26.exe
    BOOL success = CreateProcessW(
        L"FC26.exe",       // Wide string path to the game executable
        NULL,              // Command line arguments
        NULL,              // Process security attributes
        NULL,              // Thread security attributes
        FALSE,             // Inherit handles
        0,                 // Creation flags
        NULL,              // Environment
        NULL,              // Current directory
        &si,               // Startup info
        &pi                // Process info
    );

    if (success) {
        std::wcout << L"[FakeEAAC] FC26 launched successfully." << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        std::wcerr << L"[FakeEAAC] Failed to launch FC26. Error code: " << GetLastError() << std::endl;
    }

    return 0;
}

#include <windows.h>
#include <psapi.h>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>
#include <algorithm>

#pragma comment(lib, "psapi.lib")

// Точка входа DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CleanerThread, NULL, 0, NULL);
    }
    return TRUE;
}

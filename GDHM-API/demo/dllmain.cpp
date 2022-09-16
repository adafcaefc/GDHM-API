#include <Windows.h>

DWORD WINAPI _dll_main(LPVOID lpParam);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		const HANDLE _dll_main_handle = CreateThread(nullptr, NULL, dll_main, hModule, NULL, nullptr);
		if (_dll_main_handle != NULL) {
			return CloseHandle(_dll_main_handle) != 0;
		}
		break;
	}
	return TRUE;
}

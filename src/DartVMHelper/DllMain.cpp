#include "framework.h"

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH :
            DisableThreadLibraryCalls(hInstance);
            break;
		case DLL_PROCESS_DETACH :
		case DLL_THREAD_ATTACH  :
		case DLL_THREAD_DETACH  :
			break;
    }

    return TRUE;
}
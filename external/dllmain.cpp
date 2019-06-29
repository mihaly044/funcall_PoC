// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>

int external_add(int a, int b)
{
	return a + b;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	int a = 0;
	int b = 0;
	int c = 0;
	int x = 0;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		MessageBox(NULL, L"Injection successfull", L"Info", MB_OK);
		a = external_add(1, 2);
		b = external_add(3, 4);
		c = external_add(5, 6);
		x = a + b + c;
		std::cout << "c=" << x << std::endl;
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// funcall_PoC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <Psapi.h>
using namespace std;

int main()
{
	HINSTANCE hGetProcIDDLL = LoadLibraryA("external.dll");

	if (!hGetProcIDDLL) {
		std::cout << "could not load the dynamic library" << std::endl;
		return EXIT_FAILURE;
	}

	const auto hMod = GetModuleHandleA("external.dll");

	typedef int(__fastcall * external_add)(int a, int b);
	external_add eadd = (external_add)((uintptr_t)hMod + 0x1090);

	// This may be necessary 
	// VirtualProtect((LPVOID)(eadd), 0x15, PAGE_EXECUTE_READWRITE, NULL);

	int ret = eadd(10, 10);
	wcout << L"The result of external_add(10+10) is " << ret << endl;
}
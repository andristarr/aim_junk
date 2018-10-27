#pragma once
#include <Windows.h>

class AccessMemory
{
public:
	static bool ReadAddress(HANDLE*, DWORD, float*);
	static bool ReadAddress(HANDLE*, DWORD, double*);
	static bool ReadAddress(HANDLE*, DWORD, int*);
	static bool ReadAddress(HANDLE*, DWORD, DWORD*);

	static bool WriteAddress(HANDLE*, DWORD, float*);
	static bool WriteAddress(HANDLE*, DWORD, double*);
	static bool WriteAddress(HANDLE*, DWORD, int*);
private:
	AccessMemory() {}
};
#pragma once

#include <Windows.h>

class Helper
{
public:
	static bool GetGame(HANDLE*);
	static DWORD GetModuleAddress(HANDLE*);
private:
	Helper(){}
};
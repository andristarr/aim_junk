#include "stdafx.h"
#include "Helper.h"
#include "psapi.h"
#include <string>

using namespace std;

bool Helper::GetGame(HANDLE* hAndle)
{
	LPCWSTR WinProcessName = (LPCWSTR)"AssaultCube";
	HWND hWnd = FindWindow(0,(LPCSTR)WinProcessName);

	if (hWnd == 0)
	{
		return false;
	}
	else
	{
		DWORD pid;
		GetWindowThreadProcessId(hWnd,&pid);
		(*hAndle) = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (!(*hAndle))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

DWORD Helper::GetModuleAddress(HANDLE* hAndle)
{
	HMODULE hMods[1024];
	DWORD cbNeeded;
	unsigned int i;

	if (EnumProcessModules(*hAndle, hMods, sizeof(hMods), &cbNeeded))
	{
		for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(*hAndle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				string wstrModName = szModName;
				//you will need to change this to the name of the exe of the foreign process
				string wstrModContain = "ac_client.exe";
				if (wstrModName.find(wstrModContain) != string::npos)
				{
					return (DWORD)hMods[i];
				}
			}
		}
	}
	return 0;
}
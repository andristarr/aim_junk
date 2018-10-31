#include "stdafx.h"
#include "AccessMemory.h"
#include <sstream>
#include <iostream>

using namespace std;

bool AccessMemory::ReadAddress(HANDLE* hAndle, DWORD address, float* returnContainer)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfFloat = sizeof(float);
	return (ReadProcessMemory(*hAndle, (LPVOID)myaddie, returnContainer, sizeOfFloat, NULL));
}

bool AccessMemory::ReadAddress(HANDLE* hAndle, DWORD address, double* returnContainer)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfDouble = sizeof(double);
	return (ReadProcessMemory(*hAndle, (LPVOID)myaddie, returnContainer, sizeOfDouble, NULL));
}

bool AccessMemory::ReadAddress(HANDLE* hAndle, DWORD address, int* returnContainer)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfInt = sizeof(int);
	return (ReadProcessMemory(*hAndle, (LPVOID)myaddie, returnContainer, sizeOfInt, NULL));
}

bool AccessMemory::ReadAddress(HANDLE* hAndle, DWORD address, DWORD* returnContainer)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfDword = sizeof(DWORD);
	return (ReadProcessMemory(*hAndle, (LPVOID)myaddie, returnContainer, sizeOfDword, NULL));
}


bool AccessMemory::WriteAddress(HANDLE* hAndle, DWORD address, float* valueToWrite)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfFloat = sizeof(float);
	return (WriteProcessMemory(*hAndle, (LPVOID)myaddie, valueToWrite, sizeOfFloat, NULL));
}

bool AccessMemory::WriteAddress(HANDLE* hAndle, DWORD address, double* valueToWrite)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfDouble = sizeof(double);
	return (WriteProcessMemory(*hAndle, (LPVOID)myaddie, valueToWrite, sizeOfDouble, NULL));
}

bool AccessMemory::WriteAddress(HANDLE* hAndle, DWORD address, int* valueToWrite)
{
	intptr_t int_address;
	{
		std::stringstream stream;
		stream << std::hex << address;
		stream >> int_address;
	}
	void *myaddie = (void *)int_address;
	DWORD sizeOfInt = sizeof(int);
	
	return (WriteProcessMemory(*hAndle, (LPVOID)myaddie, valueToWrite, sizeOfInt, NULL));
}
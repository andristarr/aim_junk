// AssaultCubeMultihack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Aimbot.h"

using namespace std;



int main()
{
	Aimbot *a = new Aimbot();
	a->StartAiming();
	delete a;
    return 0;
}


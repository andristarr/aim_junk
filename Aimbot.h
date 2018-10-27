#pragma once

#include "AccessMemory.h"
#include "Helper.h"

class Aimbot
{
public:
	void StartAiming();
	void GetAddies();
	void RefreshValues();

	void AimAtTarget();
	float Get3dDistance();

	Aimbot();
private:
	HANDLE hProcess;

	//addies
	//player
	DWORD playerbase;
	DWORD playerPosX;
	DWORD playerPosY;
	DWORD playerPosZ;
	DWORD playerViewUD;
	DWORD playerViewLR;
	DWORD playerHP;

	//enemy coords
	DWORD enemyHP;
	DWORD enemyBase;
	DWORD enemyPosX;
	DWORD enemyPosY;
	DWORD enemyPosZ;
	DWORD enemyViewUD;
	DWORD enemyViewLR;

	int playerHPVal = 0;
	float playerPosXVal = 0, playerPosYVal = 0, playerPosZVal = 0;
	float playerViewUDVal = 0, playerViewLRVal = 0;

	int enemyHPVal = 0;
	float enemyPosXVal = 0, enemyPosYVal = 0, enemyPosZVal = 0;
};
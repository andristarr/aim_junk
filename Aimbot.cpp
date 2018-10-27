#include "stdafx.h"
#include "Aimbot.h"
#include <math.h>

#define PI 3.14159265

Aimbot::Aimbot()
{
	Helper::GetGame(&(this->hProcess));
	this->GetAddies();
}

void Aimbot::GetAddies()
{
	DWORD ACBASE = Helper::GetModuleAddress(&(this->hProcess));
	if (ACBASE == 0)
	{
		MessageBox(0, "Couldn't get base addie", "ERR", MB_OK);
	}
	DWORD tempPlHP = ACBASE + 0x109B74;
	DWORD temptwo = 0;
	AccessMemory::ReadAddress(&(this->hProcess), tempPlHP, &temptwo);
	this->playerHP = temptwo + 0xF8;
	DWORD tempBase = 0;
	//AccessMemory::ReadAddress(&(this->hProcess), this->playerHP, &tempBase);
	tempBase = this->playerHP - 0xD0;
	this->playerbase = tempBase;
	this->playerPosX = this->playerbase + 0xC;
	this->playerPosZ = this->playerbase + 0x10;
	this->playerPosY = this->playerbase + 0x14;
	this->playerViewLR = this->playerbase + 0x18;
	this->playerViewUD = this->playerbase + 0x1C;

	//enemy addresses:)
	DWORD redirect1 = ACBASE + 0x10F4F8;
	DWORD redirect2 = 0;
	AccessMemory::ReadAddress(&(this->hProcess), redirect1, &redirect2);
	redirect2 = redirect2 + 4;
	DWORD redirect3 = 0;
	AccessMemory::ReadAddress(&(this->hProcess), redirect2, &redirect3);
	DWORD enemyBS = redirect3 + 0xF8 - 0xD0;
	this->enemyBase = enemyBS;
	this->enemyHP = this->enemyBase + 0xD0;
	this->enemyPosX = this->enemyBase + 0xC;
	this->enemyPosZ = this->enemyBase + 0x10;
	this->enemyPosY = this->enemyBase + 0x14;
	this->enemyViewLR = this->enemyBase + 0x18;
	this->enemyViewUD = this->enemyBase + 0x1C;
}

void Aimbot::RefreshValues()
{
	AccessMemory::ReadAddress(&(this->hProcess), this->playerHP, &(this->playerHPVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->playerPosX, &(this->playerPosXVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->playerPosY, &(this->playerPosYVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->playerPosZ, &(this->playerPosZVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->playerViewLR, &(this->playerViewLRVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->playerViewUD, &(this->playerViewUDVal));

	AccessMemory::ReadAddress(&(this->hProcess), this->enemyHP, &(this->enemyHPVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->enemyPosX, &(this->enemyPosXVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->enemyPosY, &(this->enemyPosYVal));
	AccessMemory::ReadAddress(&(this->hProcess), this->enemyPosZ, &(this->enemyPosZVal));
}

void Aimbot::AimAtTarget()
{
	//float pitchY = (float)asin((( this->enemyPosZVal - this->playerPosZVal ) / this->Get3dDistance() * 180 / PI) );
	float pitchY = (float)atan2(this->enemyPosZVal - this->playerPosZVal, this->Get3dDistance()) *180 / PI;
	float yawX = -(float)atan2(this->enemyPosXVal - this->playerPosXVal, this->enemyPosYVal - this->playerPosYVal) / PI * 180 + 180;

	AccessMemory::WriteAddress(&(this->hProcess), this->playerViewUD, &pitchY);
	AccessMemory::WriteAddress(&(this->hProcess), this->playerViewLR, &yawX );
}

float Aimbot::Get3dDistance()
{
	/*
	return (float)(sqrt(
		((this->playerPosXVal - this->enemyPosXVal) * (this->playerPosXVal - this->enemyPosXVal)) +
		((this->playerPosYVal - this->enemyPosYVal) * (this->playerPosYVal - this->enemyPosYVal)) +
		((this->playerPosZVal - this->enemyPosZVal) * (this->playerPosZVal - this->enemyPosZVal))));
	*/
	float debug = (float)(sqrt(
		((this->enemyPosXVal - this->playerPosXVal) * (this->enemyPosXVal - this->playerPosXVal)) +
		((this->enemyPosYVal - this->playerPosYVal) * (this->enemyPosYVal - this->playerPosYVal)) +
		((this->enemyPosZVal - this->playerPosZVal) * (this->enemyPosZVal - this->playerPosZVal))));
	return debug;
}

void Aimbot::StartAiming()
{
	while (true)
	{
		this->RefreshValues();

		//if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
		//{
			if ((this->playerHPVal > 0) && (this->playerHPVal < 101))
			{
				if ((this->enemyHPVal > 0) && (this->enemyHPVal < 101))
				{
					this->AimAtTarget();
				}
			}
		//}

		Sleep(10);
	}
}
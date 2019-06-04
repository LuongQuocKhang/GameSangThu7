﻿#pragma once
#include "GameObject.h"
#include "Constants.h"
#include "Enemy.h"

class Boss :public Enemy
{
	int count;
public:
	Boss();
	Boss(float posx, float posy);
	void LoadResources();
	void Idle();
	void Walk();

	int GetStamina() { return this->stamina; }

	bool checkloc = true;
	bool initloc = true;
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


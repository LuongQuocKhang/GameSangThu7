#pragma once
#include "GameObject.h"
#include "Constants.h"
#include "Enemy.h"

class Boss :public Enemy
{
public:
	Boss();
	Boss(float posx, float posy);
	void LoadResources();
	void Idle();
	void Walk();

	bool checkloc = true;
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


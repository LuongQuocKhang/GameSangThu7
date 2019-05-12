﻿#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class PinkWitch :public Enemy
{

	Enemy * __instance;

	State * idleState;
	State * walkingState;
	State * state;

	//Vector chứa các animations
	static vector<Animation *> animations;
public:
	PinkWitch();
	PinkWitch(int posx, int posy);
	void LoadResources();
	void Idle();
	void Walk();

	/*void TurnLeft();
	void TurnRight();*/
	vector<Animation *> GetAnimationsList() { return this->animations; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

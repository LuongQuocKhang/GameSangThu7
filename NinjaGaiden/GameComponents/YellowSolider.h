#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class YellowSolider :public Enemy
{

	Enemy * __instance;

	State * idleState;
	State * walkingState;
	State * state;

	//Vector chứa các animations
	static vector<Animation *> animations;
public:
	YellowSolider();
	void LoadResources();
	vector<Animation *> GetAnimationsList() { return this->animations; }

	void Idle();
	void Walk();

	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};

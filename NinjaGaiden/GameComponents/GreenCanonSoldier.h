#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class GreenCanonSoldier :public Enemy
{

	Enemy * __instance;

	State * idleState;
	State * walkingState;
	State * state;

	//Vector chứa các animations
	static vector<Animation *> animations;
public:
	GreenCanonSoldier();
	GreenCanonSoldier(float posx, float posy);
	void LoadResources();
	void Idle();
	void Walk();

	vector<Animation *> GetAnimationsList() { return this->animations; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


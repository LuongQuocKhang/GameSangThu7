#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class Hud :public GameObject
{

	GameObject * __instance;
	vector<Animation *> animations;
public:
	Hud(float posx, float posy);
	void LoadResources();

	//Hàm c?p nh?t
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};



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

	//H�m c?p nh?t
	void Update(DWORD dt) override;
	void Reset();
	//H�m render
	void Render() override;
};



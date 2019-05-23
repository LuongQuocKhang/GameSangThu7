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
	Hud(int posx, int posy);
	void LoadResources();

	//H�m c?p nh?t
	void Update(DWORD dt) override;
	//H�m render
	void Render() override;
};



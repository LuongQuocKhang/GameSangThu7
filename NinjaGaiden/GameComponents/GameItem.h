#pragma once
#include "GameObject.h"
#include "Animation.h"

class GameItem :
	public GameObject
{
protected:
	vector<Animation *> animations;
	bool Active;
public:
	GameItem();
	~GameItem();

	virtual void Update(DWORD dt);
	virtual void Render();
};


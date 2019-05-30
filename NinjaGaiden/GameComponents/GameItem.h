#pragma once
#include "GameObject.h"
class GameItem :
	public GameObject
{
protected:
	vector<Animation *> animations;
	bool Active;

public:
	GameItem();
	~GameItem();

	bool IsActive() { return this->Active; }
	void SetActive(bool value) { this->Active = value; }

	virtual void Update(DWORD dt);
	virtual void Render();
};


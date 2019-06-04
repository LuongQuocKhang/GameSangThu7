#pragma once
#include "GameObject.h"

class Bullet :
	public GameObject
{
protected:
	vector<Animation *> animations;
	bool Active;
	float distance;
	int damage;

	int shootTime;
public:
	Bullet();

	int GetDamage() { return this->damage; }

	bool IsActive() { return this->Active; }
	bool SetActive(bool value) { this->Active = value; }

	virtual void Update(DWORD dt);
	virtual void Render();

	float GetDistance() { return this->distance; }

	int GetShootTime() { return this->shootTime; }
	void ResetShootTime() { this->shootTime = 0; }

	virtual void Reset();
	~Bullet();
};


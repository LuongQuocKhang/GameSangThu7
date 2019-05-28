#pragma once
#include "GameObject.h"

class Shuriken : public GameObject
{
	int damage = 10;

	vector<Animation *> animations;

	bool IsActive;
public:
	Shuriken();
	void CreateShuriken(float posx, float posy, float dt, bool isLeft);
	int GetDamage() { return this->damage; }
	//bool IsActive() { return this->IsActive; }
	//bool SetActive(bool value) { this->IsActive = value; }

	void LoadResources();

	void Update(DWORD dt) override;
	void Render() override;
	

	~Shuriken();
};


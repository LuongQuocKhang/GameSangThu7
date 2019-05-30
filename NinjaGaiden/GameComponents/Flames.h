#pragma once
#include "GameObject.h"

class Flames : public GameObject
{
	int damage = 10;

	static vector<Animation *> animations;
	static Flames * __instance;
	bool Active;

	float distance;
public:
	Flames();
	//void CreateFlames(float posx, float posy, float dt, bool isLeft);
	int GetDamage() { return this->damage; }
	bool IsActive() { return this->Active; }
	bool SetActive(bool value) { this->Active = value; }
	static Flames * GetInstance();
	void LoadResources();

	void Update(DWORD dt) override;
	void Render() override;

	float GetDistance() { return this->distance; }

	~Flames();
};




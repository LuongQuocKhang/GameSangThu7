#pragma once
#include "GameObject.h"

class DeathAnimation :
	public GameObject
{
private :
	vector<Animation *> animations;

	void LoadResources();

	bool Active;

	int time;
public:
	DeathAnimation();
	~DeathAnimation();

	static DeathAnimation* CreateDeateAnimation(GameObject* gameobject);
	void Update(DWORD dt) override;
	void Render() override;

	bool IsActive() { return this->Active; }
	void SetActive(bool value) { this->Active = value; }
};


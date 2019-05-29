#pragma once
#include "GameObject.h"

class DeathAnimation :
	public GameObject
{
private :
	vector<Animation *> animations;

	void LoadResources();
public:
	DeathAnimation();
	~DeathAnimation();

	static DeathAnimation* CreateDeateAnimation(GameObject* gameobject);
	void Update(DWORD dt) override;
	void Render() override;
};


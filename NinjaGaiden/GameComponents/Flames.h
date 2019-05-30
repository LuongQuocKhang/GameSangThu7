#pragma once
#include "GameItem.h"

class Flames : public GameItem
{
public:
	Flames();

	static Flames * CreateFlames(float posx, float posy, float dt);

	bool IsActive() { return this->Active; }
	bool SetActive(bool value) { this->Active = value; }
	void LoadResources();

	void Update(DWORD dt) override;
	void Render() override;

	~Flames();
};




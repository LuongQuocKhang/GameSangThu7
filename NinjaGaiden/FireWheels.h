#pragma once
#include "GameItem.h"
class FireWheels :
	public GameItem
{
private:
	void LoadResources();
public:
	FireWheels();
	~FireWheels();
	static FireWheels * CreateFireWheels(float posx, float posy, float dt);

	void Update(DWORD dt) override;
	void Render() override;
};




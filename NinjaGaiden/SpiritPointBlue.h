#pragma once
#include "GameItem.h"
class SpiritPointBlue :
	public GameItem
{
private:
	void LoadResources();
public:
	SpiritPointBlue();
	~SpiritPointBlue();
	static SpiritPointBlue * CreateSpiritPointBlue(float posx, float posy, float dt);

	void Update(DWORD dt) override;
	void Render() override;
};


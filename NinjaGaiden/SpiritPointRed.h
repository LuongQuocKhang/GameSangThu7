#pragma once
#include "GameItem.h"
class SpiritPointRed :
	public GameItem
{
private:
	void LoadResources();
public:
	SpiritPointRed();
	~SpiritPointRed();
	static SpiritPointRed * CreateSpiritPointRed(float posx, float posy, float dt);

	void Update(DWORD dt) override;
	void Render() override;
};



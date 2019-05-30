#pragma once
#include "GameItem.h"
class BonusPointRed :
	public GameItem
{
private:
	void LoadResources();
public:
	BonusPointRed();
	~BonusPointRed();
	static BonusPointRed * CreateBonusPointRed(float posx, float posy, float dt);

	void Update(DWORD dt) override;
	void Render() override;
};



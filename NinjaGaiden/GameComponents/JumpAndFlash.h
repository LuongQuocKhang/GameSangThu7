#pragma once
#include "GameItem.h"
class JumpAndFlash :
	public GameItem
{
private:
	void LoadResources();
public:
	JumpAndFlash();
	~JumpAndFlash();
	static JumpAndFlash * CreateJumpAndFlash(float posx, float posy, float dt);

	void Update(DWORD dt) override;
	void Render() override;
};


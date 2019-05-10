#include "YellowSolider.h"
#include "YellowSoliderState.h"

vector<Animation *> YellowSolider::animations = vector<Animation *>();
YellowSolider::YellowSolider()
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowSoliderState(this, ENEMY_ANI_IDLE);
	walkingState = new YellowSoliderState(this, ENEMY_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(270);
	this->SetPositionY(60);
}
void YellowSolider::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_WIDTH;
		rect.right = rect.left + ENEMY_SPRITE_WIDTH;
		rect.top = (i / ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_HEIGHT;
		rect.bottom = rect.top + ENEMY_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ENEMY_TEXTURE_LOCATION, rect, ENEMY_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(250);
	for (int i = 0; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_WIDTH;
		rect.right = rect.left + ENEMY_SPRITE_WIDTH;
		rect.top = (i / ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_HEIGHT;
		rect.bottom = rect.top + ENEMY_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ENEMY_TEXTURE_LOCATION, rect, ENEMY_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

//Các hàm hành động nhân vật

//Hàm cập nhật
void YellowSolider::Update(DWORD dt)
{
	state->Update(dt);
	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}
}
//Hàm render
void YellowSolider::Render()
{
	state->Render();
}
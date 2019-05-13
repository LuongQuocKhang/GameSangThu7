#include "YellowSolider.h"
#include "YellowSoliderState.h"
#include "Grid.h"

vector<Animation *> YellowSolider::animations = vector<Animation *>();
YellowSolider::YellowSolider()
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_IDLE);
	walkingState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(270);
	this->SetPositionY(100);

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = YELLOW_SOLIDER_SPRITE_WIDTH;
	collider.height = YELLOW_SOLIDER_SPRITE_HEIGHT;

}

YellowSolider::YellowSolider(int posx , int posy )
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_IDLE);
	walkingState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = YELLOW_SOLIDER_SPRITE_WIDTH;
	collider.height = YELLOW_SOLIDER_SPRITE_HEIGHT;
}
void YellowSolider::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + YELLOW_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(YELLOW_SOLIDER_TEXTURE_LOCATION, rect, YELLOW_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(250);
	for (int i = 0; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + YELLOW_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(YELLOW_SOLIDER_TEXTURE_LOCATION, rect, YELLOW_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void YellowSolider::Idle()
{
	state->Idle();
}
void YellowSolider::Walk()
{
	state->Walk();
}
//Hàm cập nhật
void YellowSolider::Update(DWORD dt)
{
	state->Update(dt);
	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 50)
	{
		this->TurnRight();
	}
}
//Hàm render
void YellowSolider::Render()
{
	state->Render();
}
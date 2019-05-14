#include "GreenSolider.h"
#include "GreenSoliderState.h"

vector<Animation *> GreenSolider::animations = vector<Animation *>();
GreenSolider::GreenSolider()
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenSoliderState(this, GREEN_SOLIDER_ANI_IDLE);
	walkingState = new GreenSoliderState(this, GREEN_SOLIDER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(400);
	this->SetPositionY(60);
}
GreenSolider::GreenSolider(int posx , int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenSoliderState(this, GREEN_SOLIDER_ANI_IDLE);
	walkingState = new GreenSoliderState(this, GREEN_SOLIDER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

}
void GreenSolider::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i %  GREEN_SOLIDER_TEXTURE_COLUMNS) *  GREEN_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / GREEN_SOLIDER_TEXTURE_COLUMNS) *  GREEN_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_SOLIDER_TEXTURE_LOCATION, rect, GREEN_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i %  GREEN_SOLIDER_TEXTURE_COLUMNS) *  GREEN_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / GREEN_SOLIDER_TEXTURE_COLUMNS) *  GREEN_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_SOLIDER_TEXTURE_LOCATION, rect, GREEN_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void GreenSolider::Idle()
{
	state->Idle();
}
void GreenSolider::Walk()
{
	state->Walk();
}
//Hàm c?p nh?t
void GreenSolider::Update(DWORD dt)
{
	state->Update(dt);
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}*/
}
//Hàm render
void GreenSolider::Render()
{
	state->Render();
}
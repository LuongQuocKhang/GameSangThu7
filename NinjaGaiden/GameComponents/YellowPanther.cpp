#include "YellowPanther.h"
#include "YellowPantherState.h"

vector<Animation *> YellowPanther::animations = vector<Animation *>();
YellowPanther::YellowPanther()
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowPantherState(this,  YELLOW_PANTHER_ANI_IDLE);
	walkingState = new YellowPantherState(this,  YELLOW_PANTHER_ANI_WALKING);
	state = walkingState;

	this->isLeft = false;
	this->vx = -0.2f;
	this->SetPositionX(350);
	this->SetPositionY(60);
}
YellowPanther::YellowPanther(int posx , int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowPantherState(this, YELLOW_PANTHER_ANI_IDLE);
	walkingState = new YellowPantherState(this, YELLOW_PANTHER_ANI_WALKING);
	state = walkingState;

	this->isLeft = false;
	this->vx = -0.2f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);
}
void YellowPanther::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i %  YELLOW_PANTHER_TEXTURE_COLUMNS) *  YELLOW_PANTHER_SPRITE_WIDTH;
		rect.right = rect.left +  YELLOW_PANTHER_SPRITE_WIDTH;
		rect.top = (i /  YELLOW_PANTHER_TEXTURE_COLUMNS) *  YELLOW_PANTHER_SPRITE_HEIGHT;
		rect.bottom = rect.top +  YELLOW_PANTHER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite( YELLOW_PANTHER_TEXTURE_LOCATION, rect,  YELLOW_PANTHER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(100);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i %  YELLOW_PANTHER_TEXTURE_COLUMNS) *  YELLOW_PANTHER_SPRITE_WIDTH;
		rect.right = rect.left +  YELLOW_PANTHER_SPRITE_WIDTH;
		rect.top = (i /  YELLOW_PANTHER_TEXTURE_COLUMNS) *  YELLOW_PANTHER_SPRITE_HEIGHT;
		rect.bottom = rect.top +  YELLOW_PANTHER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite( YELLOW_PANTHER_TEXTURE_LOCATION, rect,  YELLOW_PANTHER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void YellowPanther::Idle()
{
	state->Idle();
}
void YellowPanther::Walk()
{
	state->Walk();
}
//Hàm c?p nh?t
void YellowPanther::Update(DWORD dt)
{
	state->Update(dt);
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}*/
}
//Hàm render
void YellowPanther::Render()
{
	state->Render();
}
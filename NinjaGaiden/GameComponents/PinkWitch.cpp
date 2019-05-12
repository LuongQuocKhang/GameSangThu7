#include "PinkWitch.h"
#include "PinkWitchState.h"

vector<Animation *> PinkWitch::animations = vector<Animation *>();
PinkWitch::PinkWitch()
{
	__instance = NULL;
	LoadResources();

	idleState = new PinkWitchState(this, PINK_WITCH_ANI_IDLE);
	walkingState = new PinkWitchState(this, PINK_WITCH_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(450);
	this->SetPositionY(65);
}

PinkWitch::PinkWitch(int posx , int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new PinkWitchState(this, PINK_WITCH_ANI_IDLE);
	walkingState = new PinkWitchState(this, PINK_WITCH_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);
}

void PinkWitch::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i %  PINK_WITCH_TEXTURE_COLUMNS) *  PINK_WITCH_SPRITE_WIDTH;
		rect.right = rect.left + PINK_WITCH_SPRITE_WIDTH;
		rect.top = (i / PINK_WITCH_TEXTURE_COLUMNS) *  PINK_WITCH_SPRITE_HEIGHT;
		rect.bottom = rect.top + PINK_WITCH_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(PINK_WITCH_TEXTURE_LOCATION, rect, PINK_WITCH_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i %  PINK_WITCH_TEXTURE_COLUMNS) *  PINK_WITCH_SPRITE_WIDTH;
		rect.right = rect.left + PINK_WITCH_SPRITE_WIDTH;
		rect.top = (i / PINK_WITCH_TEXTURE_COLUMNS) *  PINK_WITCH_SPRITE_HEIGHT;
		rect.bottom = rect.top + PINK_WITCH_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(PINK_WITCH_TEXTURE_LOCATION, rect, PINK_WITCH_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void PinkWitch::Idle()
{
	state->Idle();
}
void PinkWitch::Walk()
{
	state->Walk();
}
//Hàm c?p nh?t
void PinkWitch::Update(DWORD dt)
{
	state->Update(dt);
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}*/
}
//Hàm render
void PinkWitch::Render()
{
	state->Render();
}
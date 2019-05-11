#include "YellowPanther.h"
#include "YellowPantherState.h"

vector<Animation *> YellowPanther::animations = vector<Animation *>();
YellowPanther::YellowPanther()
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowPantherState(this, BROWN_BIRD_ANI_IDLE);
	walkingState = new YellowPantherState(this, BROWN_BIRD_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(360);
	this->SetPositionY(70);
}
void YellowPanther::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BROWN_BIRD_TEXTURE_COLUMNS) * BROWN_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + BROWN_BIRD_SPRITE_WIDTH;
		rect.top = (i / BROWN_BIRD_TEXTURE_COLUMNS) * BROWN_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + BROWN_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BROWN_BIRD_TEXTURE_LOCATION, rect, BROWN_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % BROWN_BIRD_TEXTURE_COLUMNS) * BROWN_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + BROWN_BIRD_SPRITE_WIDTH;
		rect.top = (i / BROWN_BIRD_TEXTURE_COLUMNS) * BROWN_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + BROWN_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BROWN_BIRD_TEXTURE_LOCATION, rect, BROWN_BIRD_TEXTURE_TRANS_COLOR);

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
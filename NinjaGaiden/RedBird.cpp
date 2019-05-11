#include "RedBird.h"
#include "RedBirdState.h"

vector<Animation *> RedBird::animations = vector<Animation *>();
RedBird::RedBird()
{
	__instance = NULL;
	LoadResources();

	idleState = new RedBirdState(this, RED_BIRD_ANI_IDLE);
	walkingState = new RedBirdState(this, RED_BIRD_ANI_WALKING);
	state = walkingState;

	this->isLeft = false;
	this->vx = -0.2f;
	this->SetPositionX(350);
	this->SetPositionY(90);
}
void RedBird::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % RED_BIRD_TEXTURE_COLUMNS) * RED_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + RED_BIRD_SPRITE_WIDTH;
		rect.top = (i / RED_BIRD_TEXTURE_COLUMNS) * RED_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + RED_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(RED_BIRD_TEXTURE_LOCATION, rect, RED_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % RED_BIRD_TEXTURE_COLUMNS) * RED_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + RED_BIRD_SPRITE_WIDTH;
		rect.top = (i / RED_BIRD_TEXTURE_COLUMNS) * RED_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + RED_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(RED_BIRD_TEXTURE_LOCATION, rect, RED_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void RedBird::Idle()
{
	state->Idle();
}
void RedBird::Walk()
{
	state->Walk();
}
//Hàm c?p nh?t
void RedBird::Update(DWORD dt)
{
	state->Update(dt);
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}*/
}
//Hàm render
void RedBird::Render()
{
	state->Render();
}
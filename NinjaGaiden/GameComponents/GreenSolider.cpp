#include "GreenSolider.h"
#include "GreenSoliderState.h"

vector<Animation *> GreenSolider::animations = vector<Animation *>();
GreenSolider::GreenSolider()
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenSoliderState(this, GREEN_SOLDIER_ANI_IDLE);
	walkingState = new GreenSoliderState(this, GREEN_SOLDIER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(400);
	this->SetPositionY(90);

	Type = EnemyType::GREENSOLDIER;
}
GreenSolider::GreenSolider(int posx , int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenSoliderState(this, GREEN_SOLDIER_ANI_IDLE);
	walkingState = new GreenSoliderState(this, GREEN_SOLDIER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = GREEN_SOLDIER_SPRITE_WIDTH;
	collider.height = GREEN_SOLDIER_SPRITE_HEIGHT;

	Type = EnemyType::GREENSOLDIER;
}
void GreenSolider::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i %  GREEN_SOLDIER_TEXTURE_COLUMNS) *  GREEN_SOLDIER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_SOLDIER_SPRITE_WIDTH;
		rect.top = (i / GREEN_SOLDIER_TEXTURE_COLUMNS) *  GREEN_SOLDIER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_SOLDIER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_SOLDIER_TEXTURE_LOCATION, rect, GREEN_SOLDIER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i %  GREEN_SOLDIER_TEXTURE_COLUMNS) *  GREEN_SOLDIER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_SOLDIER_SPRITE_WIDTH;
		rect.top = (i / GREEN_SOLDIER_TEXTURE_COLUMNS) *  GREEN_SOLDIER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_SOLDIER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_SOLDIER_TEXTURE_LOCATION, rect, GREEN_SOLDIER_TEXTURE_TRANS_COLOR);

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
void GreenSolider::Update(DWORD dt)
{
	state->Update(dt);
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}*/
}
void GreenSolider::Render()
{
	state->Render();
}
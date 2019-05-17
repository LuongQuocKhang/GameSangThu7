#include "GreenRunningSoldier.h"
#include "GreenRunningSoldierState.h"

vector<Animation *> GreenRunningSoldier::animations = vector<Animation *>();
GreenRunningSoldier::GreenRunningSoldier()
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenRunningSoldierState(this, GREEN_RUNNING_SOLDIER_ANI_IDLE);
	walkingState = new GreenRunningSoldierState(this, GREEN_RUNNING_SOLDIER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(270);
	this->SetPositionY(80);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
	collider.height = GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;

	Type = EnemyType::GREENRUNNINGSOLDIER;
}
GreenRunningSoldier::GreenRunningSoldier(int posx, int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenRunningSoldierState(this, GREEN_RUNNING_SOLDIER_ANI_IDLE);
	walkingState = new GreenRunningSoldierState(this, GREEN_RUNNING_SOLDIER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
	collider.height = GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;

	Type = EnemyType::BLOODYBIRD;
}
void GreenRunningSoldier::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % GREEN_RUNNING_SOLDIER_TEXTURE_COLUMNS) * GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
		rect.top = (i / GREEN_RUNNING_SOLDIER_TEXTURE_COLUMNS) * GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_RUNNING_SOLDIER_TEXTURE_LOCATION, rect, GREEN_RUNNING_SOLDIER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % GREEN_RUNNING_SOLDIER_TEXTURE_COLUMNS) * GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
		rect.right = rect.left + GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
		rect.top = (i / GREEN_RUNNING_SOLDIER_TEXTURE_COLUMNS) * GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;
		rect.bottom = rect.top + GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(GREEN_RUNNING_SOLDIER_TEXTURE_LOCATION, rect, GREEN_RUNNING_SOLDIER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void GreenRunningSoldier::Idle()
{
	state->Idle();
}
void GreenRunningSoldier::Walk()
{
	state->Walk();
}
//Hàm c?p nh?t
void GreenRunningSoldier::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void GreenRunningSoldier::Render()
{
	state->Render();
}
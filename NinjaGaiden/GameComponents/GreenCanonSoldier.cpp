#include "GreenCanonSoldier.h"
#include "GreenCanonSoldierState.h"

vector<Animation *> GreenCanonSoldier::animations = vector<Animation *>();
GreenCanonSoldier::GreenCanonSoldier()
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenCanonSoldierState(this, BLOODY_BIRD_ANI_IDLE);
	walkingState = new GreenCanonSoldierState(this, BLOODY_BIRD_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(270);
	this->SetPositionY(80);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = BLOODY_BIRD_SPRITE_WIDTH;
	collider.height = BLOODY_BIRD_SPRITE_HEIGHT;

	Type = EnemyType::BLOODYBIRD;
}
GreenCanonSoldier::GreenCanonSoldier(int posx, int posy)
{
	__instance = NULL;
	LoadResources();

	idleState = new GreenCanonSoldierState(this, BLOODY_BIRD_ANI_IDLE);
	walkingState = new GreenCanonSoldierState(this, BLOODY_BIRD_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = BLOODY_BIRD_SPRITE_WIDTH;
	collider.height = BLOODY_BIRD_SPRITE_HEIGHT;

	Type = EnemyType::BLOODYBIRD;
}
void GreenCanonSoldier::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BLOODY_BIRD_TEXTURE_COLUMNS) * BLOODY_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + BLOODY_BIRD_SPRITE_WIDTH;
		rect.top = (i / BLOODY_BIRD_TEXTURE_COLUMNS) * BLOODY_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + BLOODY_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BLOODY_BIRD_TEXTURE_LOCATION, rect, BLOODY_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(200);
	for (int i = 0; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % BLOODY_BIRD_TEXTURE_COLUMNS) * BLOODY_BIRD_SPRITE_WIDTH;
		rect.right = rect.left + BLOODY_BIRD_SPRITE_WIDTH;
		rect.top = (i / BLOODY_BIRD_TEXTURE_COLUMNS) * BLOODY_BIRD_SPRITE_HEIGHT;
		rect.bottom = rect.top + BLOODY_BIRD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BLOODY_BIRD_TEXTURE_LOCATION, rect, BLOODY_BIRD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void GreenCanonSoldier::Idle()
{
	state->Idle();
}
void GreenCanonSoldier::Walk()
{
	state->Walk();
}
//H�m c?p nh?t
void GreenCanonSoldier::Update(DWORD dt)
{
	state->Update(dt);
}
//H�m render
void GreenCanonSoldier::Render()
{
	state->Render();
}
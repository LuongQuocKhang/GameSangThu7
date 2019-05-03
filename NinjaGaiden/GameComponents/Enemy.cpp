#include "Enemy.h"

vector<Animation *> Enemy::animations = vector<Animation *>();
Enemy::Enemy()
{
	__instance = NULL;
	LoadResources();

	idleState = new EnemyState(this,ENEMY_ANI_IDLE);
	walkingState = new EnemyState(this, ENEMY_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
}
void Enemy::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1 ; i++)
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
	anim = new Animation(100);
	for (int i = 0; i < 2; i++)
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

void Enemy::SetState(State * state)
{
	this->state = state;
}
State * Enemy::GetIdleState()
{
	return idleState;
}
State * Enemy::GetWalkingState()
{
	return walkingState;
}
//Các hàm hành động nhân vật
void Enemy::Idle()
{
	state->Idle();
}
void Enemy::Walk()
{
	state->Walk();
}
void Enemy::TurnLeft()
{
	isLeft = true;
}
void Enemy::TurnRight()
{
	isLeft = false;
}
//Hàm cập nhật
void Enemy::Update(DWORD dt)
{
	state->Update(dt);
}
//Hàm render
void Enemy::Render()
{
	state->Render();
}
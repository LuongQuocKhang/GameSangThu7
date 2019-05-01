#include "Enemy.h"


Enemy::Enemy()
{
	animations = vector<Animation *>();
	__instance = NULL;
	LoadResources();


	idleState = new State(this,ENEMY_ANI_IDLE);
	state = idleState;

}
Enemy * Enemy::GetInstance()
{
	if (__instance == NULL)
		__instance = new Enemy();
	return __instance;
}
void Enemy::LoadResources()
{
	
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_WIDTH;
		rect.right = rect.left + ENEMY_SPRITE_WIDTH;
		rect.top = (i / ENEMY_TEXTURE_COLUMNS) * ENEMY_SPRITE_HEIGHT;
		rect.bottom = rect.top + ENEMY_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ENEMY_TEXTURE_LOCATION, rect, ENEMY_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}
void Enemy::SetState(State * state)
{
	this->state = state;
}
State * Enemy::GetIdleState()
{
	return idleState;
}

//Các hàm hành động nhân vật
void Enemy::Idle()
{
	state->Idle();
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
#include "Enemy.h"

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
}
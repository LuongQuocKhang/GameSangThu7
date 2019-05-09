#include "Enemy.h"

Enemy::Enemy()
{
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
}
//Hàm render
void Enemy::Render()
{
}
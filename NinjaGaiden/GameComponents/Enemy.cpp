#include "Enemy.h"
#include "Constants.h"
#include "Grid.h"

Enemy::Enemy()
{
	//__instance = NULL;
	SetActive(false);
	LoadResources();
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

void Enemy::Idle()
{
}

void Enemy::Walk()
{
}

void Enemy::TurnLeft()
{
	isLeft = true;
}
void Enemy::TurnRight()
{
	isLeft = false;
}
void Enemy::TakeDamage(int damage)
{
	this->stamina -= damage;
}
//Hàm cập nhật
void Enemy::Update(DWORD dt)
{
	state->Update(dt);
	if (this->GetPositionX() <= 0)
	{
		int EnemyPosInGrid = Grid::GetInstance()->GetEnemyIndexById(this->Id);
		Grid::GetInstance()->DeleteEnemy(EnemyPosInGrid);
	}
}
//Hàm render
void Enemy::Render()
{
}
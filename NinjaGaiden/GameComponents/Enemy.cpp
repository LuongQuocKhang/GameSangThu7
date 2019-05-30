#include "Enemy.h"
#include "Constants.h"
#include "Grid.h"

Enemy::Enemy()
{
	SetActive(false);
	LoadResources();
}
void Enemy::LoadResources()
{
}

void Enemy::SetState(EnemyState * state)
{
	this->state = state;
}
EnemyState * Enemy::GetIdleState()
{
	return idleState;
}
EnemyState * Enemy::GetWalkingState()
{
	return walkingState;
}
void Enemy::Idle()
{
}

void Enemy::Walk()
{
}

void Enemy::SetGameItem(int itemtype)
{
	switch (itemtype)
	{
	case 1:
		this->itemtype = ItemType::FLAMES;
	default:
		break;
	}
}

void Enemy::TurnLeft()
{
	isLeft = true;
}
void Enemy::TurnRight()
{
	isLeft = false;
}
void Enemy::ResetCollider()
{
	this->collider.width = 0;
	this->collider.height = 0;
	this->collider.x = 0;
	this->collider.y = 0;
	this->collider.vx = 0;
	this->collider.vy = 0;
}
void Enemy::TakeDamage(int damage)
{
	this->stamina -= damage;
}
void Enemy::Update(DWORD dt)
{
	state->Update(dt);
	if (this->GetPositionX() <= 0)
	{
		int EnemyPosInGrid = Grid::GetInstance()->GetEnemyIndexById(this->Id);
		Grid::GetInstance()->DeleteEnemy(EnemyPosInGrid);
	}
}
void Enemy::Render()
{
}
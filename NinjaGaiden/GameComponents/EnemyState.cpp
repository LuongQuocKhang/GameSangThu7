#include "EnemyState.h"



EnemyState::EnemyState(Enemy * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

EnemyState::~EnemyState()
{
}

void EnemyState::Jump()
{
}

void EnemyState::Crouch()
{
}

void EnemyState::JumpAttack()
{
}

void EnemyState::Climb()
{
}

void EnemyState::Idle()
{
}

void EnemyState::Attack()
{
}

void EnemyState::Walk()
{
	switch (enemystate)
	{
	case ENEMY_ANI_WALKING:
	{
		enemy->SetSpeedX(ENEMY_WALKING_SPEED * (enemy->IsLeft() ? -1 : 1));
	}
		break;
	}
}

void EnemyState::Update(DWORD dt)
{
	
}

void EnemyState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = ENEMY_SPRITE_WIDTH;
		spriteEnemyData.height = ENEMY_SPRITE_HEIGHT;
		spriteEnemyData.x = 200;
		spriteEnemyData.y = 60;

		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		/*spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();*/
	}
	switch(enemystate) 
	{
		case ENEMY_ANI_IDLE:
		{
			enemy->GetAnimationsList()[ENEMY_ANI_IDLE]->Render(spriteEnemyData);
		}
			break;
		case ENEMY_ANI_WALKING:
		{
			enemy->GetAnimationsList()[ENEMY_ANI_WALKING]->Render(spriteEnemyData);
		}
			break;
	}
}

#include "YellowSoliderState.h"

YellowSoliderState::YellowSoliderState(YellowSolider * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

YellowSoliderState::~YellowSoliderState()
{
}

void YellowSoliderState::Jump()
{
}

void YellowSoliderState::Crouch()
{
}

void YellowSoliderState::JumpAttack()
{
}

void YellowSoliderState::Climb()
{
}

void YellowSoliderState::Idle()
{
}

void YellowSoliderState::Attack()
{
}

void YellowSoliderState::Walk()
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

void YellowSoliderState::Update(DWORD dt)
{

}

void YellowSoliderState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = ENEMY_SPRITE_WIDTH;
		spriteEnemyData.height = ENEMY_SPRITE_HEIGHT;
		//spriteEnemyData.x = 200;
		spriteEnemyData.x = enemy->GetPositionX();
		//spriteEnemyData.y = 60;
		spriteEnemyData.y = enemy->GetPositionY();


		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case ENEMY_ANI_IDLE:
	{
		enemy->GetAnimationsList()[ENEMY_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case ENEMY_ANI_WALKING:
	{
		enemy->GetAnimationsList()[ENEMY_ANI_WALKING]->Render(spriteEnemyData);

		enemy->Walk();
	}
	break;
	}
}


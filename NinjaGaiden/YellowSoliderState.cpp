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
	case YELLOW_SOLIDER_ANI_WALKING:
	{
		enemy->SetSpeedX(YELLOW_SOLIDER_WALKING_SPEED * (enemy->IsLeft() ? -1 : 1));
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
		spriteEnemyData.width = YELLOW_SOLIDER_SPRITE_WIDTH;
		spriteEnemyData.height = YELLOW_SOLIDER_SPRITE_HEIGHT;
		spriteEnemyData.x = enemy->GetPositionX();
		spriteEnemyData.y = enemy->GetPositionY();

		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case YELLOW_SOLIDER_ANI_IDLE:
	{
		enemy->GetAnimationsList()[YELLOW_SOLIDER_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case YELLOW_SOLIDER_ANI_WALKING:
	{
		enemy->GetAnimationsList()[YELLOW_SOLIDER_ANI_WALKING]->Render(spriteEnemyData);

		enemy->Walk();
	}
	break;
	}
}


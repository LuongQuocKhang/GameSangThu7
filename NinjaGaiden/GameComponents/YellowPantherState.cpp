#include "YellowPantherState.h"
#include "Grid.h"

YellowPantherState::YellowPantherState(YellowPanther * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

YellowPantherState::~YellowPantherState()
{
}

void YellowPantherState::Jump()
{
}

void YellowPantherState::Crouch()
{
}

void YellowPantherState::JumpAttack()
{
}

void YellowPantherState::Climb()
{
}

void YellowPantherState::Idle()
{
}

void YellowPantherState::Attack()
{
}

void YellowPantherState::Walk()
{
	switch (enemystate)
	{
	case YELLOW_PANTHER_ANI_WALKING:
	{
		enemy->SetSpeedX(YELLOW_PANTHER_WALKING_SPEED * (enemy->IsLeft() ? -1 : 1));
	}
	break;
	}
}

void YellowPantherState::Update(DWORD dt)
{
}

void YellowPantherState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = YELLOW_PANTHER_SPRITE_WIDTH;
		spriteEnemyData.height = YELLOW_PANTHER_SPRITE_HEIGHT;
		spriteEnemyData.x = enemy->GetPositionX();
		spriteEnemyData.y = enemy->GetPositionY();

		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case YELLOW_PANTHER_ANI_IDLE:
	{
		enemy->GetAnimationsList()[YELLOW_PANTHER_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case YELLOW_PANTHER_ANI_WALKING:
	{
		enemy->GetAnimationsList()[YELLOW_PANTHER_ANI_WALKING]->Render(spriteEnemyData);

		enemy->Walk();
	}
	break;
	}
}



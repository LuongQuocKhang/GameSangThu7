#include "GreenCanonSoldierState.h"

GreenCanonSoldierState::GreenCanonSoldierState(GreenCanonSoldier * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

GreenCanonSoldierState::~GreenCanonSoldierState()
{
}

void GreenCanonSoldierState::Jump()
{
}

void GreenCanonSoldierState::Crouch()
{
}

void GreenCanonSoldierState::JumpAttack()
{
}

void GreenCanonSoldierState::Climb()
{
}

void GreenCanonSoldierState::Idle()
{
}

void GreenCanonSoldierState::Attack()
{
}

void GreenCanonSoldierState::Walk()
{
}

void GreenCanonSoldierState::Update(DWORD dt)
{
	if (Viewport::GetInstance()->IsEnemyInCamera(enemy) == true)
	{
		enemy->SetActive(true);
	}
	else
	{
		enemy->SetActive(false);
	}
}

void GreenCanonSoldierState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = BROWN_BIRD_SPRITE_WIDTH;
		spriteEnemyData.height = BROWN_BIRD_SPRITE_HEIGHT;
		spriteEnemyData.x = enemy->GetPositionX();
		spriteEnemyData.y = enemy->GetPositionY();


		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case BROWN_BIRD_ANI_IDLE:
	{
		enemy->GetAnimationsList()[BROWN_BIRD_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case BROWN_BIRD_ANI_WALKING:
	{
		enemy->GetAnimationsList()[BROWN_BIRD_ANI_WALKING]->Render(spriteEnemyData);
	}
	break;
	}
}


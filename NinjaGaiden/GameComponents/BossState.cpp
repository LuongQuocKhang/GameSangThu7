#include "BossState.h"

BossState::BossState(Boss * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

BossState::~BossState()
{
}

void BossState::Jump()
{
}

void BossState::Crouch()
{
}

void BossState::JumpAttack()
{
}

void BossState::Climb()
{
}

void BossState::Idle()
{
}

void BossState::Attack()
{
}

void BossState::Walk()
{
}

void BossState::Update(DWORD dt)
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

void BossState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = BOSS_SPRITE_WIDTH;
		spriteEnemyData.height = BOSS_SPRITE_HEIGHT;
		spriteEnemyData.x = enemy->GetPositionX();
		spriteEnemyData.y = enemy->GetPositionY();


		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case BOSS_ANI_IDLE:
	{
		enemy->GetAnimationsList()[BOSS_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case BOSS_ANI_WALKING:
	{
		enemy->GetAnimationsList()[BOSS_ANI_WALKING]->Render(spriteEnemyData);
	}
	break;
	}
}


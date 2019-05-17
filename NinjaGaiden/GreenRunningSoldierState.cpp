#include "GreenRunningSoldierState.h"

GreenRunningSoldierState::GreenRunningSoldierState(GreenRunningSoldier * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

GreenRunningSoldierState::~GreenRunningSoldierState()
{
}

void GreenRunningSoldierState::Jump()
{
}

void GreenRunningSoldierState::Crouch()
{
}

void GreenRunningSoldierState::JumpAttack()
{
}

void GreenRunningSoldierState::Climb()
{
}

void GreenRunningSoldierState::Idle()
{
}

void GreenRunningSoldierState::Attack()
{
}

void GreenRunningSoldierState::Walk()
{
}

void GreenRunningSoldierState::Update(DWORD dt)
{

}

void GreenRunningSoldierState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = GREEN_RUNNING_SOLDIER_SPRITE_WIDTH;
		spriteEnemyData.height = GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT;
		spriteEnemyData.x = enemy->GetPositionX();
		spriteEnemyData.y = enemy->GetPositionY();


		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
		spriteEnemyData.isLeft = enemy->IsLeft();
		spriteEnemyData.isFlipped = enemy->IsFlipped();
	}
	switch (enemystate)
	{
	case GREEN_RUNNING_SOLDIER_ANI_IDLE:
	{
		enemy->GetAnimationsList()[GREEN_RUNNING_SOLDIER_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case GREEN_RUNNING_SOLDIER_ANI_WALKING:
	{
		enemy->GetAnimationsList()[GREEN_RUNNING_SOLDIER_ANI_WALKING]->Render(spriteEnemyData);
	}
	break;
	}
}


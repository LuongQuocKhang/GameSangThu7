#include "GreenSoliderState.h"

GreenSoliderState::GreenSoliderState(GreenSolider * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

GreenSoliderState::~GreenSoliderState()
{
}

void GreenSoliderState::Jump()
{
}

void GreenSoliderState::Crouch()
{
}

void GreenSoliderState::JumpAttack()
{
}

void GreenSoliderState::Climb()
{
}

void GreenSoliderState::Idle()
{
}

void GreenSoliderState::Attack()
{
}

void GreenSoliderState::Walk()
{
	/*switch (enemystate)
	{
	case ENEMY_ANI_WALKING:
	{
		enemy->SetSpeedX(ENEMY_WALKING_SPEED * (enemy->IsLeft() ? -1 : 1));
	}
	break;
	}*/
}

void GreenSoliderState::Update(DWORD dt)
{

}

void GreenSoliderState::Render()
{
	SpriteData spriteEnemyData;
	if (this->enemy != NULL)
	{
		spriteEnemyData.width = GREEN_SOLIDER_SPRITE_WIDTH;
		spriteEnemyData.height = GREEN_SOLIDER_SPRITE_HEIGHT;
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
	case  GREEN_SOLIDER_ANI_IDLE:
	{
		enemy->GetAnimationsList()[GREEN_SOLIDER_ANI_IDLE]->Render(spriteEnemyData);
	}
	break;
	case  GREEN_SOLIDER_ANI_WALKING:
	{
		enemy->GetAnimationsList()[GREEN_SOLIDER_ANI_WALKING]->Render(spriteEnemyData);

		/*enemy->Walk();*/
	}
	break;
	}
}


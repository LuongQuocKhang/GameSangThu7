#include "PinkWitchState.h"

PinkWitchState::PinkWitchState(PinkWitch * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

PinkWitchState::~PinkWitchState()
{
}

void PinkWitchState::Jump()
{
}

void PinkWitchState::Crouch()
{
}

void PinkWitchState::JumpAttack()
{
}

void PinkWitchState::Climb()
{
}

void PinkWitchState::Idle()
{
}

void PinkWitchState::Attack()
{
}

void PinkWitchState::Walk()
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

void PinkWitchState::Update(DWORD dt)
{

}

void PinkWitchState::Render()
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


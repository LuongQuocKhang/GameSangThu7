#include "BrownBirdState.h"

BrownBirdState::BrownBirdState(BrownBird * enemy, int enemystate)
{
	this->enemy = enemy;
	this->enemystate = enemystate;
}

BrownBirdState::~BrownBirdState()
{
}

void BrownBirdState::Jump()
{
}

void BrownBirdState::Crouch()
{
}

void BrownBirdState::JumpAttack()
{
}

void BrownBirdState::Climb()
{
}

void BrownBirdState::Idle()
{
}

void BrownBirdState::Attack()
{
}

void BrownBirdState::Walk()
{
}

void BrownBirdState::Update(DWORD dt)
{

}

void BrownBirdState::Render()
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


#include "YellowSoliderState.h"
#include "Grid.h"

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
	vector<LPGAMEOBJECT> coObjects; //Placeholder
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	vector<Tile *> tiles = Grid::GetInstance()->GetCollisionTiles();

	enemy->SetSpeedY(enemy->GetSpeedY() - NINJA_GRAVITY);

	coEvents.clear();
	enemy->SetDt(dt);
	enemy->CalcPotentialCollisions(tiles, coObjects, coEvents);

	if (coEvents.size() == 0)
	{
		float moveX = trunc(enemy->GetSpeedX()* dt);
		float moveY = trunc(enemy->GetSpeedY()* dt);

		enemy->SetPositionX(enemy->GetPositionX() + moveX);
		enemy->SetPositionY(enemy->GetPositionY() + moveY);
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		enemy->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		int moveX = min_tx * enemy->GetSpeedX() * dt + nx * 0.4;
		int moveY = min_ty * enemy->GetSpeedY() * dt + ny * 0.4;

		enemy->SetPositionX((int)(enemy->GetPositionX() + moveX));
		enemy->SetPositionY((int)(enemy->GetPositionY() + moveY));


		if (nx != 0) enemy->SetSpeedX(0);
		if (ny != 0) enemy->SetSpeedY(0);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				//enemy->SetIsGrounded(true);
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
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


#include "NinjaSate.h"

NinjaSate::NinjaSate(Ninja * ninja, int states)
{
	this->ninja = ninja;
	this->states = states;
}

NinjaSate::~NinjaSate()
{
}

void NinjaSate::Jump()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	case NINJA_ANI_CROUCHING_ATTACKING:
	case NINJA_ANI_CROUCHING:
	case NINJA_ANI_JUMPING:
	case NINJA_ANI_JUMPING_ATTACKING:
		break;
	case NINJA_ANI_IDLE:
	case NINJA_ANI_WALKING:
	{
		if (ninja->IsGrounded())
		{
			ninja->SetIsGrounded(false);
			ninja->SetSpeedY(NINJA_JUMP_SPEED_Y);
			ninja->SetState(ninja->GetJumpingState());
		}
	}
	break;

	}
}

void NinjaSate::Crouch()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	case NINJA_ANI_CROUCHING_ATTACKING:
	case NINJA_ANI_CROUCHING:
	case NINJA_ANI_JUMPING:
	case NINJA_ANI_JUMPING_ATTACKING:
		break;
	case NINJA_ANI_IDLE:
	{
		ninja->SetIsCrouching(true);
		ninja->SetState(ninja->GetCrouchingState());
	}
	break;
	case NINJA_ANI_WALKING:
	{
		ninja->SetSpeedX(0);
		ninja->SetIsCrouching(true);
		ninja->SetState(ninja->GetCrouchingState());
	}
	break;
	}
}

void NinjaSate::JumpAttack()
{
	int state = this->states;
	if (NINJA_ANI_JUMPING == state)
	{
		ninja->SetIsGrounded(false);
		ninja->SetState(ninja->GetJumpAttackState());
	}
}

void NinjaSate::Climb()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	case NINJA_ANI_CROUCHING:
	case NINJA_ANI_JUMPING_ATTACKING:
		break;
	case NINJA_ANI_IDLE:
	{
		/*ninja->SetIsClimbing(true);*/
		ninja->SetState(ninja->GetClimbState());
	}
	break;
	case NINJA_ANI_CROUCHING_ATTACKING:
		break;
	case NINJA_ANI_WALKING:
	{
		ninja->SetSpeedX(0);
		ninja->SetState(ninja->GetClimbState());
	}
	break;
	}
}

void NinjaSate::Idle()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	case NINJA_ANI_IDLE:
	case NINJA_ANI_JUMPING_ATTACKING:
	case NINJA_ANI_JUMPING_ATTACKED:
		break;
	case NINJA_ANI_CROUCHING:
	{
		ninja->SetIsCrouching(false);
		ninja->SetState(ninja->GetIdleState());
	}
	break;
	case NINJA_ANI_CROUCHING_ATTACKING:
		break;
	case NINJA_ANI_WALKING:
	{
		ninja->SetSpeedX(0);
		ninja->SetState(ninja->GetIdleState());
	}
	break;
	}
}

void NinjaSate::Attack()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
		break;
	case NINJA_ANI_IDLE:
	case NINJA_ANI_CROUCHING:
	{
		ninja->SetState(ninja->GetAttackingState());
		break;
	}
	break;
	case NINJA_ANI_WALKING:
	{
		ninja->SetSpeedX(0);
		ninja->SetState(ninja->GetAttackingState());
	}
	break;
	case NINJA_ANI_JUMPING_ATTACKING:
	{
		ninja->SetState(ninja->GetAttackingState());
		break;
	}
	break;
	}
	
}

void NinjaSate::Walk()
{
	int state = this->states;

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	case NINJA_ANI_CROUCHING_ATTACKING:
	case NINJA_ANI_CROUCHING:
	case NINJA_ANI_JUMPING:
	case NINJA_ANI_JUMPING_ATTACKING:
		break;
	case NINJA_ANI_IDLE:
	{
		ninja->SetSpeedX(NINJA_WALKING_SPEED * (ninja->IsLeft() ? -1 : 1));
		ninja->SetState(ninja->GetWalkingState());
	}
	break;
	case NINJA_ANI_WALKING:
	{
		ninja->SetSpeedX(NINJA_WALKING_SPEED * (ninja->IsLeft() ? -1 : 1));
	}
	break;
	}
}

void NinjaSate::Update(DWORD dt)
{
	int state = this->states;
	switch (state)
	{
	case NINJA_ANI_JUMPING:
	{
		if (ninja->IsGrounded())
		{
			ninja->SetState(ninja->GetIdleState());
		}
		if (ninja->GetPositionY() >= TiledMap::GetInstance()->GetHeight() + 20)
		{
			ninja->SetSpeedY(ninja->GetSpeedY() - NINJA_GRAVITY);
		}
	}
	break;
	case NINJA_ANI_JUMPING_ATTACKING:
	{
		if (ninja->IsGrounded())
		{
			ninja->SetState(ninja->GetIdleState());
		}
	}
	break;
	default:
		break;
	}
	vector<LPGAMEOBJECT> coObjects; //Placeholder
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	#pragma region xử lý khi chém vào quái
	if (state == NINJA_ANI_STANDING_ATTACKING || state == NINJA_ANI_JUMPING_ATTACKING || state == NINJA_ANI_CROUCHING_ATTACKING)
	{
		vector<Enemy* > enemies = Grid::GetInstance()->GetEnemies();
		ninja->CalcPotentialCollisionsAttackingEnemy(enemies, coObjects, coEvents);
	}
	#pragma endregion

	#pragma region xử lý va chạm với gạch
	coObjects.clear();

	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();
	ninja->SetSpeedY(ninja->GetSpeedY() - NINJA_GRAVITY);

	coEvents.clear();
	ninja->SetDt(dt);
	ninja->CalcPotentialCollisions(tiles, coObjects, coEvents);

	if (coEvents.size() == 0)
	{
		int moveX = trunc(ninja->GetSpeedX()* dt);
		int moveY = trunc(ninja->GetSpeedY()* dt);
		ninja->SetPositionX(ninja->GetPositionX() + moveX);
		ninja->SetPositionY(ninja->GetPositionY() + moveY);
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		ninja->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		int moveX = min_tx * ninja->GetSpeedX() * dt + nx * 0.4;
		int moveY = min_ty * ninja->GetSpeedY() * dt + ny * 0.4;

		ninja->SetPositionX((int)(ninja->GetPositionX() + moveX));
		ninja->SetPositionY((int)(ninja->GetPositionY() + moveY));


		if (nx != 0) ninja->SetSpeedX(0);
		if (ny != 0) ninja->SetSpeedY(0);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				ninja->SetIsGrounded(true);
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];
	#pragma endregion

	#pragma region Xử lý va chạm với quái

	#pragma endregion

	#pragma region Ninja chết
	if (ninja->GetPositionY() < 0)
	{
		ninja->SetPositionX(100);
		ninja->SetPositionY(100);
		Viewport::GetInstance()->Reset();
	}
	#pragma endregion
}

void NinjaSate::Render()
{
	int state = this->states;

	SpriteData spriteData;
	if (this->ninja != NULL)
	{
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();
	}

	switch (state)
	{
	case NINJA_ANI_STANDING_ATTACKING:
	{
		if (ninja->IsCrouching())
		{
			ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Render(spriteData);

			if (ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->IsDone())
			{
				ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Reset();
				ninja->SetIsCrouching(true);
				ninja->SetState(ninja->GetCrouchingState());
			}
		}
		else
		{
			ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Render(spriteData);
			if (ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->IsDone())
			{
				ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Reset();
				ninja->SetState(ninja->GetIdleState());
			}
		}
	}
	break;
	case NINJA_ANI_IDLE:
	{
		ninja->GetAnimationsList()[NINJA_ANI_IDLE]->Render(spriteData);
	}
	break;
	case NINJA_ANI_CROUCHING:
	{
		ninja->GetAnimationsList()[NINJA_ANI_CROUCHING]->Render(spriteData);
	}
	break;
	case NINJA_ANI_JUMPING:
	{
		ninja->GetAnimationsList()[NINJA_ANI_JUMPING]->Render(spriteData);
	}
	break;
	case NINJA_ANI_CLIMBING:
	{
		ninja->GetAnimationsList()[NINJA_ANI_CLIMBING]->Render(spriteData);

		if (ninja->GetAnimationsList()[NINJA_ANI_CLIMBING]->IsDone())
		{
			ninja->GetAnimationsList()[NINJA_ANI_CLIMBING]->Reset();
			ninja->SetState(ninja->GetIdleState());
		}
	}
	break;
	case NINJA_ANI_WALKING:
	{

		ninja->GetAnimationsList()[NINJA_ANI_WALKING]->Render(spriteData);
	}
	break;
	case NINJA_ANI_JUMPING_ATTACKING:
	{
		ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->Render(spriteData);

		if (ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->IsDone())
		{
			ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->Reset();
			ninja->SetState(ninja->GetJumpingState());
		}
	}
	break;
	}
}

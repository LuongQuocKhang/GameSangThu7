﻿#include "State.h"
#include "Ninja.h"
#include "Game.h"

State::State(Ninja * ninja, int states)
{
	this->ninja = ninja;
	this->states = states;
}
void State::Update(DWORD dt)
{
	int state = this->states;
	switch (state)
	{
		case 4: //jumping state
		{
			if (ninja->IsGrounded())
			{
				ninja->SetState(ninja->GetIdleState());
			}
		}break;
		default:break;
	}
	ninja->SetPositionX((int)(ninja->GetPositionX() + ninja->GetSpeedX()* dt));
	ninja->SetPositionY((int)(ninja->GetPositionY() + ninja->GetSpeedY()* dt));

	ninja->SetSpeedY(ninja->GetSpeedY() - NINJA_GRAVITY);
	if (ninja->GetPositionY() < NINJA_SPRITE_HEIGHT + TILES_HEIGHT_PER_TILE)
	{
		ninja->SetSpeedY(0);
		ninja->SetPositionY(NINJA_SPRITE_HEIGHT + TILES_HEIGHT_PER_TILE);
		ninja->SetSpeedX(0);
		ninja->SetIsGrounded(true);
	}
	if (ninja->GetSpeedX() > 0 && ninja->GetPositionX() > Game::GetInstance()->GetTiledMap()->GetWidth() - NINJA_SPRITE_WIDTH)
		ninja->SetPositionX(Game::GetInstance()->GetTiledMap()->GetWidth() - NINJA_SPRITE_WIDTH);
	if (ninja->GetSpeedX() < 0 && ninja->GetPositionX() < 0)
		ninja->SetPositionX(0);

	vector<Subweapon *> subweapons = ninja->GetSubweapon();
	if (subweapons.size() > 0)
	{
		for (int i = 0; i < subweapons.size(); i++)
		{
			if (subweapons[i]->GetSpeedX() > 0 && subweapons[i]->GetPositionX() > SCREEN_WIDTH - NINJA_SPRITE_WIDTH)
				subweapons.erase(subweapons.begin() + i);
			else if (subweapons[i]->GetSpeedX() < 0 && subweapons[i]->GetPositionX() < 0)
				subweapons.erase(subweapons.begin() + i);
		}
	}
}

void State::Render()
{
	/*vector <Subweapon *> subweapons = ninja->GetSubweapon();
	if (subweapons.size() > 0)
	{
		for (int i = 0; i < subweapons.size(); i++)
		{
			SpriteData spriteData;
			subweapons[i]->Render(spriteData);
		}
	}*/
	int state = this->states;
	switch (state)
	{
	case 23: //attackingState
	{
		SpriteData spriteData;
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();

		ninja->GetWhip()->SetPosition(ninja->GetPositionX(), ninja->GetPositionY(), ninja->IsCrouching());
		if (ninja->IsCrouching())
		{
			ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Render(spriteData);
			//ninja->GetWhip()->Render(spriteData);

			if (ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->IsDone())
			{
				ninja->GetAnimationsList()[NINJA_ANI_CROUCHING_ATTACKING]->Reset();
				ninja->GetWhip()->ResetAnim();
				ninja->SetIsCrouching(true);
				ninja->SetState(ninja->GetCrouchingState());
			}
		}
		else
		{
			ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Render(spriteData);
			//ninja->GetWhip()->Render(spriteData);

			if (ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->IsDone())
			{
				ninja->GetAnimationsList()[NINJA_ANI_STANDING_ATTACKING]->Reset();
				ninja->GetWhip()->ResetAnim();
				ninja->SetState(ninja->GetIdleState());
			}
		}
	}break;
	case 0://idleState
	{
		SpriteData spriteData;
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();

		ninja->GetAnimationsList()[NINJA_ANI_IDLE]->Render(spriteData);
	}break;
	case 5://crouchingState
	{
		SpriteData spriteData;
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();

		ninja->GetAnimationsList()[NINJA_ANI_CROUCHING]->Render(spriteData);
	}break;
	case 4://jumpingState
	{
		SpriteData spriteData;
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();

		ninja->GetAnimationsList()[NINJA_ANI_JUMPING]->Render(spriteData);
	}break;
	case 1://walkingState
	{
		SpriteData spriteData;
		spriteData.width = NINJA_SPRITE_WIDTH;
		spriteData.height = NINJA_SPRITE_HEIGHT;
		spriteData.x = ninja->GetPositionX();
		spriteData.y = ninja->GetPositionY();
		spriteData.scale = 1;
		spriteData.angle = 0;
		spriteData.isLeft = ninja->IsLeft();
		spriteData.isFlipped = ninja->IsFlipped();

		ninja->GetAnimationsList()[NINJA_ANI_WALKING]->Render(spriteData);
	}break;
	}

}

void State::Idle()
{
	int state = this->states;

	switch (state)
	{
	case 23://attackingState
	case 0://idleState
		break;
	case 5://crouchingState
	{
		ninja->SetIsCrouching(false);
		ninja->SetState(ninja->GetIdleState());
	}break;
	case 3:
		break;
	case 1://walkingState
	{
		ninja->SetSpeedX(0);
		ninja->SetState(ninja->GetIdleState());
	}break;
	}
}
void State::Attack()
{
	int state = this->states;

	switch (state)
	{
	case 23://attackingState
		break;
	case 0://idleState
	case 5://crouchingState
	case 4://jumpingState
	{
		ninja->SetState(ninja->GetAttackingState());
	}break;
	case 1://walkingState
	{
		ninja->SetSpeedX(0);
		ninja->SetState(ninja->GetAttackingState());
	}break;
	}
}
void State::Walk()
{
	int state = this->states;

	switch (state)
	{
	case 23://attackingState
	case 5://crouchingState
	case 4://jumpingState
		break;
	case 0://idleState
	{
		ninja->SetSpeedX(NINJA_WALKING_SPEED * (ninja->IsLeft() ? -1 : 1));
		ninja->SetState(ninja->GetWalkingState());
	}break;
	case 1://walkingState
	{
		ninja->SetSpeedX(NINJA_WALKING_SPEED * (ninja->IsLeft() ? -1 : 1));
	}break;
	}
}
//void State::Throw()
//{
//	int state = this->states;
//
//	switch (state)
//	{
//	case '0':
//		break;
//	case '2':
//	{
//		ninja->SetState(ninja->GetThrowingState());
//	}break;
//	case '1':
//	{
//		ninja->SetState(ninja->GetThrowingState());
//	}break;
//	case '3':
//	{
//		ninja->SetState(ninja->GetThrowingState());
//	}break;
//	case '4':
//	{
//		ninja->SetSpeedX(0);
//		ninja->SetState(ninja->GetThrowingState());
//	}break;
//	}
//}
void State::Jump()
{
	int state = this->states;

	switch (state)
	{
	case 23://attackingState
	case 5://crouchingState
	case 4://jumpingState
		break;
	case 0://idleState
	{
		if (ninja->IsGrounded())
		{
			ninja->SetIsGrounded(false);
			ninja->SetSpeedY(NINJA_JUMP_SPEED_Y);
			ninja->SetState(ninja->GetJumpingState());
		}
	}break;
	case 1://walkingState
	{
		if (ninja->IsGrounded())
		{
			ninja->SetIsGrounded(false);
			ninja->SetSpeedY(NINJA_JUMP_SPEED_Y);
			ninja->SetState(ninja->GetJumpingState());
		}
	}break;
	}
}
void State::Crouch()
{
	int state = this->states;

	switch (state)
	{
	case 23:
	case 5:
	case 4://attackingState,crouchingState,jumpingState
		break;
	case 0://idleState
	{
		ninja->SetIsCrouching(true);
		ninja->SetState(ninja->GetCrouchingState());
	}break;
	case 1://walkingState
	{
		ninja->SetSpeedX(0);
		ninja->SetIsCrouching(true);
		ninja->SetState(ninja->GetCrouchingState());
	}break;
	}
}
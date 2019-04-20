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
		case NINJA_ANI_JUMPING:
		{
			if (ninja->IsGrounded())
			{
				ninja->SetState(ninja->GetIdleState());
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
	{
		int map = (int)Game::GetInstance()->GetStage() + 1;
		if (map < 3)
		{
			Game::GetInstance()->SetStage(map);
			ninja->SetPositionX(0);
			if (STAGE_32 == Game::GetInstance()->GetStage())
			{
				Game::GetInstance()->SetTileMap(new TiledMap(TILES_MATRIX_STAGE_32));
				Game::GetInstance()->ResetViewPort();
				ninja->SetSpeedY(0);
			}
			else if (STAGE_BOSS == Game::GetInstance()->GetStage())
			{
				Game::GetInstance()->SetTileMap(new TiledMap(TILES_MATRIX_STAGE_BOSS));
				Game::GetInstance()->ResetViewPort();
				ninja->SetSpeedY(0);
				
			}
		}
		else if (STAGE_BOSS == Game::GetInstance()->GetStage())
		{
			ninja->SetPositionX(Game::GetInstance()->GetTiledMap()->GetWidth() - NINJA_SPRITE_WIDTH);
		}
	}
	if (ninja->GetSpeedX() < 0 && ninja->GetPositionX() < 0)
	{
		ninja->SetPositionX(0);
	}

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

	SpriteData spriteData;
	spriteData.width = NINJA_SPRITE_WIDTH;
	spriteData.height = NINJA_SPRITE_HEIGHT;
	spriteData.x = ninja->GetPositionX();
	spriteData.y = ninja->GetPositionY();
	spriteData.scale = 1;
	spriteData.angle = 0;
	spriteData.isLeft = ninja->IsLeft();
	spriteData.isFlipped = ninja->IsFlipped();

	switch (state)
	{
		case NINJA_ANI_STANDING_ATTACKING:
		{

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
				ninja->GetWhip()->ResetAnim();
				ninja->SetState(ninja->GetIdleState());
			}
		}
			break;
		case NINJA_ANI_WALKING:
		{
	
			ninja->GetAnimationsList()[NINJA_ANI_WALKING]->Render(spriteData);
		}
			break;
		case NINJA_ANI_JUMPING_ATTACKING :
		{
			ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->Render(spriteData);

			if (ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->IsDone())
			{
				ninja->GetAnimationsList()[NINJA_ANI_JUMPING_ATTACKING]->Reset();
				ninja->GetWhip()->ResetAnim();
				//ninja->SetIsGrounded(true);
				ninja->SetState(ninja->GetJumpingState());
			}
		}
		break;
	}

}

void State::Idle()
{
	int state = this->states;

	switch (state)
	{
		case NINJA_ANI_STANDING_ATTACKING:
		case NINJA_ANI_IDLE:
		case NINJA_ANI_JUMPING_ATTACKING:
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
void State::Attack()
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
		case NINJA_ANI_JUMPING:
		{
			// chỗ này cần sữa trạng thái cuộn tròn chém
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
void State::Walk()
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
void State::Jump()
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
void State::Crouch()
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

void State::JumpAttack()
{
	int state = this->states;
	if (NINJA_ANI_JUMPING == state)
	{
		ninja->SetIsGrounded(false);
		ninja->SetState(ninja->GetJumpAttackState());
	}
}

void State::Climb()
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
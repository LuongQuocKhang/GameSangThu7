#include "Ninja.h"

vector<Animation *> Ninja::animations = vector<Animation *>();
vector<Subweapon *> Ninja::subweapons = vector<Subweapon *>();
Ninja * Ninja::__instance = NULL;

Ninja::Ninja()
{
	LoadResources();

	whip = new Whip();

	idleState = new State(this, NINJA_ANI_IDLE);
	walkingState = new State(this, NINJA_ANI_WALKING);
	attackingState = new State(this, NINJA_ANI_STANDING_ATTACKING);
	jumpingState = new State(this, NINJA_ANI_JUMPING);
	crouchingState = new State(this, NINJA_ANI_CROUCHING);
	climbState = new State(this, NINJA_ANI_CLIMBING);
	jumpattackingState = new State(this, NINJA_ANI_JUMPING_ATTACKING);

	state = idleState;

}
Ninja * Ninja::GetInstance()
{
	if (__instance == NULL)
		__instance = new Ninja();
	return __instance;
}
void Ninja::LoadResources()
{
	// NINJA_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// NINJA_ANI_WALKING
	anim = new Animation(100);
	for (int i = 1; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// NINJA_ANI_STANDING_ATTACKING 
	anim = new Animation(100);
	for (int i = 10; i < 15; i++)
	{
		if (10 == i)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		else if (11 == i || 13 == i )
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH * 2;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);

	// NINJA_ANI_CROUCHING_ATTACKING
	anim = new Animation(100);
	for (int i = 25; i < 30; i++)
	{
		if (25 == i)
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		else if (26 == i || 28 == i )
		{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH * 2;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
	}
	animations.push_back(anim);

	// NINJA_ANI_JUMPING
	anim = new Animation(100);
	for (int i = 6; i < 10; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// NINJA_ANI_CROUCHING
	anim = new Animation(100);
	for (int i = 24; i < 25; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);

	// NINJA_ANI_CLIMBING
	anim = new Animation(100);
	for (int i = 4; i < 6; i++)
	{
		RECT rect;
		rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
		rect.right = rect.left + NINJA_SPRITE_WIDTH;
		rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
		rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
	// NINJA_ANI_JUMPING_ATTACKING
	anim = new Animation(70);
	RECT rect;
	rect.left = (7 % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
	rect.right = rect.left + NINJA_SPRITE_WIDTH;
	rect.top = (7 / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
	rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
	Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

	anim->AddFrame(sprite);

	for (int i = 16; i < 20; i++)
	{
			RECT rect;
			rect.left = (i % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
			rect.right = rect.left + NINJA_SPRITE_WIDTH;
			rect.top = (i / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
			rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
	}

	rect.left = (9 % NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_WIDTH;
	rect.right = rect.left + NINJA_SPRITE_WIDTH;
	rect.top = (9 / NINJA_TEXTURE_COLUMNS) * NINJA_SPRITE_HEIGHT;
	rect.bottom = rect.top + NINJA_SPRITE_HEIGHT;
	sprite = new Sprite(NINJA_TEXTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

	anim->AddFrame(sprite);

	animations.push_back(anim);
}
void Ninja::SetState(State * state)
{
	this->state = state;
}
State * Ninja::GetIdleState()
{
	return idleState;
}
State * Ninja::GetWalkingState()
{
	return walkingState;
}
State * Ninja::GetAttackingState()
{
	return attackingState;
}
//State * Ninja::GetThrowingState()
//{
//	return throwingState;
//}
State * Ninja::GetCrouchingState()
{
	return crouchingState;
}
State * Ninja::GetJumpingState()
{
	return jumpingState;
}
State * Ninja::GetClimbState()
{
	return climbState;
}

State * Ninja::GetJumpAttackState()
{
	return this->jumpattackingState;
}

//Các hàm hành động nhân vật
void Ninja::Idle()
{
	state->Idle();
}
void Ninja::Attack()
{
	state->Attack();
}
void Ninja::Walk()
{
	state->Walk();
}
//void Ninja::Throw()
//{
//	state->Throw();
//}
void Ninja::Jump()
{
	state->Jump();
}
void Ninja::Crouch()
{
	state->Crouch();
}
void Ninja::Climb()
{
	state->Climb();
}
void Ninja::JumpAttack()
{
	state->JumpAttack();
}
void Ninja::TurnLeft()
{
	whip->TurnLeft();
	isLeft = true;
}
void Ninja::TurnRight()
{
	whip->TurnRight();
	isLeft = false;
}
void Ninja::CreateThrownWeapon()
{
	Subweapon * subweapon;
	switch (curSubweapon)
	{
	case SUBWEAPON_KNIFE:
		subweapon = new Knife();
		if (isLeft)
			subweapon->TurnLeft();
		else
			subweapon->TurnRight();
		subweapon->SetThrownPosition(this->x, this->y, isCrouching);
		this->subweapons.push_back(subweapon);
		break;
	}
}
//Hàm cập nhật
void Ninja::Update(DWORD dt)
{
	whip->Update(dt);
	for (int i = 0; i < subweapons.size(); i++)
	{
		subweapons[i]->Update(dt);
	}
	this->SetPositionX((int)(this->GetPositionX() + this->GetSpeedX()* dt));
	this->SetPositionY((int)(this->GetPositionY() + this->GetSpeedY()* dt));



	this->SetSpeedY(this->GetSpeedY() - NINJA_GRAVITY);
	if (this->GetPositionY() < NINJA_SPRITE_HEIGHT + TILES_HEIGHT_PER_TILE)
	{
		this->SetSpeedY(0);
		this->SetPositionY(NINJA_SPRITE_HEIGHT + TILES_HEIGHT_PER_TILE);
		this->SetSpeedX(0);
		this->SetIsGrounded(true);
	}
	if (this->GetSpeedX() > 0 && this->GetPositionX() > Game::GetInstance()->GetTiledMap()->GetWidth() - NINJA_SPRITE_WIDTH)
	{
		int map = (int)Game::GetInstance()->GetStage() + 1;
		if (map < 3)
		{
			Game::GetInstance()->SetStage(map);
			this->SetPositionX(0);
			if (STAGE_32 == Game::GetInstance()->GetStage())
			{
				Game::GetInstance()->SetTileMap(new TiledMap(TILES_MATRIX_STAGE_32));
				Game::GetInstance()->ResetViewPort();
				this->SetSpeedY(0);
			}
			else if (STAGE_BOSS == Game::GetInstance()->GetStage())
			{
				Game::GetInstance()->SetTileMap(new TiledMap(TILES_MATRIX_STAGE_BOSS));
				Game::GetInstance()->ResetViewPort();
				this->SetSpeedY(0);

			}
		}
		else if (STAGE_BOSS == Game::GetInstance()->GetStage())
		{
			this->SetPositionX(Game::GetInstance()->GetTiledMap()->GetWidth() - NINJA_SPRITE_WIDTH);
		}
	}
	if (this->GetSpeedX() < 0 && this->GetPositionX() < 0)
	{
		this->SetPositionX(0);
	}
	state->Update(dt);
}
//Hàm render
void Ninja::Render()
{
	state->Render();
}
#include "Ninja.h"



Ninja::Ninja()
{
}


Ninja::~Ninja()
{
}

void Ninja::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	vy += NINJA_GRAVITY;
	if (y > 100)
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	/*if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;*/
	if (jp == true)
	{
		countTime += dt;
		if (countTime >= dt * 8 * 2)
		{
			countTime = 0;
			jp = false;
		}
	}
}

void Ninja::Render()
{
	int ani;
	if (vx == 0)
	{
		if (nx > 0) ani = NINJA_ANI_IDLE_RIGHT;
		else ani = NINJA_ANI_IDLE_LEFT;
		if (sd == true)
		{
			if (nx > 0) ani = NINJA_ANI_SIT_RIGHT;
			else ani = NINJA_ANI_SIT_LEFT;
		}
		if (jp == true)
		{
			if (nx > 0) ani = NINJA_ANI_JUMP_RUN_RIGHT;
			else ani = NINJA_ANI_JUMP_RUN_LEFT;
		}
	}
	else if (vx > 0)
	{
		ani = NINJA_ANI_WALKING_RIGHT;
		if (jp == true)
		{
			if (nx > 0) ani = NINJA_ANI_JUMP_RUN_RIGHT;
		}
	}
	else
	{
		ani = NINJA_ANI_WALKING_LEFT;
		if (jp == true)
		{
			if (nx <= 0) ani = NINJA_ANI_JUMP_RUN_LEFT;
		}
	}

	animations[ani]->Render(x, y);
}

void Ninja::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case NINJA_STATE_WALKING_RIGHT:
		vx = NINJA_WALKING_SPEED;
		nx = 1;
		break;
	case NINJA_STATE_WALKING_LEFT:
		vx = -NINJA_WALKING_SPEED;
		nx = -1;
		break;
	case NINJA_STATE_JUMP:
		if (y == 100)
			vy = -NINJA_JUMP_SPEED_Y;
		break;
	case NINJA_STATE_IDLE:
		vx = 0;
		break;
	case NINJA_STATE_JUMP_RIGHT:
		if (y == 100)
			vy = -NINJA_JUMP_SPEED_Y;
		vx = NINJA_WALKING_SPEED;
		break;
	case NINJA_STATE_JUMP_LEFT:
		if (y == 100)
			vy = -NINJA_JUMP_SPEED_Y;
		vx = -NINJA_WALKING_SPEED;
		break;
	}
}


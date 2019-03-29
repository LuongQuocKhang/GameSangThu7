#pragma once
#include "GameObject.h"

#define NINJA_WALKING_SPEED		0.1f
#define NINJA_JUMP_SPEED_Y		0.25f
#define NINJA_GRAVITY			0.02f

#define NINJA_STATE_IDLE			0
#define NINJA_STATE_WALKING_RIGHT	100
#define NINJA_STATE_WALKING_LEFT	200
#define NINJA_STATE_JUMP			300
#define NINJA_STATE_IDLE_SIT		400
#define NINJA_STATE_JUMP_RIGHT		500
#define NINJA_STATE_JUMP_LEFT		600


#define NINJA_ANI_IDLE_RIGHT		0
#define NINJA_ANI_IDLE_LEFT			1
#define NINJA_ANI_WALKING_RIGHT		2
#define NINJA_ANI_WALKING_LEFT		3
#define NINJA_ANI_SIT_RIGHT			4
#define NINJA_ANI_SIT_LEFT			5
#define NINJA_ANI_JUMP_RUN_RIGHT	6
#define NINJA_ANI_JUMP_RUN_LEFT		7

class Ninja : public CGameObject
{
public:
	Ninja();
	~Ninja();
	int getX() { return this->x; }
	int getY() { return this->y; }
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};
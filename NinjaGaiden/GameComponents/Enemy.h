#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class Enemy:public GameObject
{
protected:
	int Id;
	State * idleState;
	State * walkingState;
	State * state;

	DWORD lastFrameTime;

	bool active = true;

	int damage = 5;
	int stamina = 5;

	EnemyType Type;

	bool death = false;
	int point = 5;
public:
	Enemy();
	void LoadResources();
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetState(State * state);
	//Hàm get

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	State * GetIdleState();
	State * GetWalkingState();

	bool IsLeft() { return isLeft; }
	bool IsFlipped() { isFlipped = isLeft ? true : false; return isFlipped; }
	//Các hàm hành động nhân vật
	void Idle();
	void Walk();

	void TurnLeft();
	void TurnRight();
	void SetId(int Id)
	{
		this->Id = Id;
	}
	int GetId() { return this->Id; }
	void SetActive(bool value) { this->active = value; }
	int GetPoint() { return this->point; }

	bool IsActive()
	{
		return this->active;
	}
	void SetStatus(bool death)
	{
		death = death;
	}
	bool Isdeath()
	{
		return this->death;
	}

	void TakeDamage(int damage);

	int GetEnemyStamina() { return this->stamina; }
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


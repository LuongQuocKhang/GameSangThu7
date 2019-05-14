#pragma once
#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "EnemyState.h"

class State;
class Enemy:public GameObject
{
	
	State * idleState;
	State * walkingState;
	State * state;

	DWORD lastFrameTime;

	bool active = true;

	int damage = 5;
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

	void SetActive(bool value)
	{
		this->active = value;
	}
	bool IsActive()
	{
		return this->active;
	}
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


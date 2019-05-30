#pragma once
#include "GameObject.h"
#include "Constants.h"
#include "EnemyState.h"

class EnemyState;
class Enemy:public GameObject
{
protected:
	int Id;
	EnemyState * idleState;
	EnemyState * walkingState;
	EnemyState * Death;

	EnemyState * state;

	vector<Animation *> animations;

	DWORD lastFrameTime;

	bool active = true;

	int damage = 5;
	int stamina = 5;

	EnemyType Type;

	bool death = false;
	int point = 1;
public:
	Enemy();
	void LoadResources();
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetState(EnemyState * state);
	//Hàm get

	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	EnemyState * GetIdleState();
	EnemyState * GetWalkingState();
	EnemyType GetEnemyType() { return this->Type; }
	vector<Animation *> GetAnimationsList() { return this->animations; }

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

	void Setleft(bool value)
	{
		isLeft = value;
		if (isLeft == false)
		{
			vx = vx * (-1);
		}
	}
	void ResetCollider();

	int GetDamage() { return this->damage; }
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
	virtual void Update(DWORD dt);
	//Hàm render
	virtual void Render();
};


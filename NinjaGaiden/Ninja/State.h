#pragma once
#include "d3d9.h"

class Ninja;
class Enemy;
class State
{
protected:
	Ninja * ninja;
	int states;
	Enemy * enemy;
	int enemystates;
public:
	State(Ninja * ninja, int states);
	State(Enemy * enemy, int enemystates);
	void Idle();
	void Attack();
	void Walk();
	void Climb();
	//void Throw() ;
	void Jump();
	void Crouch();
	void JumpAttack();

	void Update(DWORD dt);
	void Render();
};


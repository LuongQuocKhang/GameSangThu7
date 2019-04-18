#pragma once
#include "d3d9.h"

class Ninja;
class State
{
protected:
	Ninja * ninja;
	int states;
public:
	State(Ninja * ninja, int states);
	void Idle();
	void Attack();
	void Walk();
	//void Throw() ;
	void Jump();
	void Crouch();
	void Update(DWORD dt);
	void Render();
};


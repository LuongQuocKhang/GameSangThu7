#pragma once
#include "State.h"
#include "Constants.h"
#include "Ninja.h"

class NinjaSate : public State
{
private:
	Ninja * ninja;
	int states;
public:
	NinjaSate(Ninja * ninja, int states);
	~NinjaSate();

	void Jump() override;
	void Crouch() override;
	void JumpAttack() override;
	void Climb() override;

	void Idle() override;
	void Attack() override;
	void Walk() override;

	void Update(DWORD dt) override;
	void Render() override;
};

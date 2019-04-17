#pragma once
#include "State.h"

class IdleState : public State
{
public:
	IdleState(Ninja * ninja);
	void Idle() override;
	void Attack() override;
	void Walk() override;
	void Throw() override;
	void Jump() override;
	void Crouch() override;
	void Update(DWORD dt) override;
	void Render() override;
};


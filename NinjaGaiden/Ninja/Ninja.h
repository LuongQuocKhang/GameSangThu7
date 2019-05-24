#pragma once

#include "GameObject.h"
#include "State.h"
#include "Constants.h"
#include "Game.h"
#include "NinjaSate.h"

class State;
class Ninja : public GameObject
{
	Ninja();
	static Ninja * __instance;

	State * idleState;
	State * walkingState;
	State * crouchingState;
	State * jumpingState;
	State * attackingState;
	State * jumpattackingState;
	State * jumpattackedState;
	State * throwingState;
	State * climbState;

	State * state;

	bool isGrounded = false;
	bool isCrouching = false;
	bool isClimbing = false;

	//Vector chứa các animations
	static vector<Animation *> animations;
	DWORD lastFrameTime;


	int stamina;
public:
	void LoadResources();
	//Hàm set
	void SetIsGrounded(bool isGrounded) { this->isGrounded = isGrounded; }
	void SetIsCrouching(bool isCrouching) { this->isCrouching = isCrouching; }
	void SetIsClimbing(bool isClimbing) { this->isClimbing = isClimbing; }
	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	void SetState(State * state);
	//Hàm get
	static Ninja * GetInstance();

	DWORD GetLastFrameTime() { return this->lastFrameTime; }

	State * GetIdleState();
	State * GetWalkingState();
	State * GetAttackingState();
	State * GetAttackedState();
	//State * GetThrowingState();
	State * GetCrouchingState();
	State * GetJumpingState();
	State * GetClimbState();
	State * GetJumpAttackState();

	//Hàm trạng thái
	bool IsAttacking() { return state == attackingState || state == throwingState; }
	bool IsGrounded() { return isGrounded; }
	bool IsCrouching() { return isCrouching; }
	bool IsClimbing() { return isClimbing; }
	bool IsLeft() { return isLeft; }
	bool IsFlipped() { isFlipped = isLeft ? true : false; return isFlipped; }

	vector<Animation *> GetAnimationsList() { return animations; }
	//Các hàm hành động nhân vật
	void Idle();
	void Attack();
	void Walk();
	//void Throw();
	void Jump();
	void Crouch();
	void Climb();
	void JumpAttack();

	void SetColliderDemension(float width, float height)
	{
		this->collider.width = width;
		this->collider.height = height;
	}
	void CreateThrownWeapon();
	void TurnLeft();
	void TurnRight();
	//Hàm cập nhật
	void Update(DWORD dt) override;
	//Hàm render
	void Render() override;
};


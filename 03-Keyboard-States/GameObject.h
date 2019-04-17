#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"


using namespace std;

class CGameObject
{
protected:

	float x; 
	float y;

	float vx;
	float vy;

	int nx;
	float countTime=0;

	int state;									

	bool isLeft;
	bool isFlipped;

public: 
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }

	void SetPositionX(float x) { this->x = x; }
	void SetPositionY(float y) { this->y = y; }
	//Hàm đặt tốc độ
	void SetSpeedX(float vx) { this->vx = vx; }
	void SetSpeedY(float vy) { this->vy = vy; }

	float GetPositionX() { return this->x; }
	float GetPositionY() { return this->y; }

	float GetSpeedX() { return this->vx; }
	float GetSpeedY() { return this->vy; }

	void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }

	bool sd;
	bool jp;

	void AddAnimation(int aniId);

	CGameObject();

	virtual void Update(DWORD dt);
	virtual void Render();
	~CGameObject();
};
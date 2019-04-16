#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>
#include "Sprites.h"
#include "Game.h"

using namespace std;
class Animation
{
	DWORD lastFrameTime;

	vector< pair<Sprite *, DWORD> > frames;
	int curFrame;
	bool done = false;
public:
	Animation() { };

	void SetLastFrameTime(DWORD lastFrameTime) { this->lastFrameTime = lastFrameTime; }
	DWORD GetLastFrameTime() { return this->lastFrameTime; }
	int GetCurFrame() { return curFrame; }
	bool IsDone() { return done; }

	void Reset() { curFrame = -1; }
	void AddFrame(Sprite * sprite, DWORD time = 0);
	void Render(SpriteData spriteData);
};


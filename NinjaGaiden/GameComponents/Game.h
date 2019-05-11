#pragma once
#include "Constants.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ninja.h"
#include "TiledMap.h"
#include "Enemy.h"
#include "Grid.h"
#include "YellowSolider.h"
#include "BrownBird.h"
#include "RedBird.h"
#include "YellowPanther.h"
#include "GreenSolider.h"
#include "PinkWitch.h"

#include <chrono>

class Graphics;
class Keyboard;
class Grid;

class Game
{
	bool initialized = false;

	static Game * __instance;
	static HINSTANCE hInstance;
	HWND hWnd;									

	Keyboard * keyboard;
	Graphics * graphics;

	Ninja * ninja;
	YellowSolider * enemy;
	BrownBird * brownbird;
	RedBird * redbird;
	YellowPanther * yellowpanther;
	GreenSolider * greensolider;
	PinkWitch * pinkwitch;

	TiledMap * tiledMap;
	Viewport * viewport;

	Grid * grid;

	Stage stage;
public:
	Stage GetStage() { return this->stage; }
	void SetStage(int stage) { this->stage = (Stage)stage; }

	void Init();
	HWND CreateGameWindow(HINSTANCE hInstance, int ScreenWidth, int ScreenHeight);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void LoadResources();


	void Update(DWORD dt);
	void Render();
	int Run();
	Ninja * GetNinja();
	YellowSolider * GetEnemy();
	BrownBird * GetBrownBirdEnemy();
	RedBird * GetRedBirdEnemy();
	YellowPanther * GetYellowPantherEnemy();
	GreenSolider * GetGreenSoliderEnemy();
	PinkWitch * GetPinkWitchEnemy();
	TiledMap * GetTiledMap() { return tiledMap; }
	void SetTileMap(TiledMap * tiledMap) {
		this->tiledMap = tiledMap;
	}
	void ResetViewPort() { this->viewport->Reset(); }

	static float SweptAABB(Collider c1, Collider c2, float &normalx, float &normaly);
	static Game * GetInstance();
	~Game();
};



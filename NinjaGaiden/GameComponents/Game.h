#pragma once
#include "Constants.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ninja.h"
#include "TiledMap.h"
#include "Enemy.h"
#include "YellowSolider.h"
#include "BrownBird.h"

class Graphics;
class Keyboard;

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
	BrownBird * bird;
	 
	TiledMap * tiledMap;
	Viewport * viewport;

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
	BrownBird * GetBirdEnemy();
	TiledMap * GetTiledMap() { return tiledMap; }
	void SetTileMap(TiledMap * tiledMap) {
		this->tiledMap = tiledMap;
	}
	void ResetViewPort() { this->viewport->Reset(); }
	static Game * GetInstance();
	~Game();
};



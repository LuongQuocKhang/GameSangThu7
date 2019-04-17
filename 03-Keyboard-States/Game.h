#pragma once
#include "Ninja.h"
#include "TiledMap.h"

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#define KEYBOARD_BUFFER_SIZE 1024
/*
Abstract class to define keyboard event handlers
*/


class CKeyEventHandler
{
public:
	virtual void KeyState(BYTE *state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};

typedef CKeyEventHandler * LPKEYEVENTHANDLER;

class CGame
{
	static CGame * __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;		
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen 

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data
	

	LPKEYEVENTHANDLER keyHandler;

	//TiledMap * tiledMap;

public:
	void InitKeyboard(LPKEYEVENTHANDLER handler);
	void Init(HWND hWnd);
	
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	HRESULT LoadTexture(LPCWSTR filePath, D3DCOLOR transColor, LPDIRECT3DTEXTURE9 &texture);

	void Draw(Sprite * sprite, D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255));
	/*TiledMap * GetTiledMap() { return tiledMap; }
	void SetTiledMap(TiledMap * TileMap) { tiledMap = TileMap; }*/
	static CGame * GetInstance();
	~CGame();
};



/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102
	
	SAMPLE 03 - KEYBOARD AND OBJECT STATE

	This sample illustrates how to:

		1/ Process keyboard input
		2/ Control object state with keyboard events
================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"
#include "camera.h"
#include "Brick.h"

#include "TiledMap.h"


CGame *game;
Ninja *ninja;
Camera *camera;
CBrick* brick;
TiledMap * tilemap;

class CSampleKeyHander: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander * keyHandler; 

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	/*DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		ninja->SetState(NINJA_STATE_JUMP);
		ninja->jp = true;
		break;
	case DIK_DOWN:
		ninja->sd = true;
		break;
	}*/
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_DOWN:
		//ninja->sd = false;
		break;
	}
}

void CSampleKeyHander::KeyState(BYTE *states)
{
	/*if (game->IsKeyDown(DIK_RIGHT))
		ninja->SetState(NINJA_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		ninja->SetState(NINJA_STATE_WALKING_LEFT);
	else ninja->SetState(NINJA_STATE_IDLE);*/
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

/*
	Load all game resources 
	In this example: load textures, sprites, animations and ninja object
*/
void LoadResources()
{
	//CTextures * textures = CTextures::GetInstance();

	//textures->Add(ID_TEX_NINJA, L"textures\\ninja.png",D3DCOLOR_XRGB(255, 163, 177));
	//textures->Add(ID_TEX_MISC, L"textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));

	//CSprites * sprites = CSprites::GetInstance();
	//CAnimations * animations = CAnimations::GetInstance();
	//
	//LPDIRECT3DTEXTURE9 texninja = textures->Get(ID_TEX_NINJA);


	//sprites->Add(10000, 3, 5, 20, 37, texninja); //SPRITES FOR IDLE RIGHT

	//sprites->Add(10001, 339, 6, 359, 37, texninja); //SPRITES FOR RUN RIGHT
	//sprites->Add(10002, 368, 6, 390, 37, texninja);
	//sprites->Add(10003, 400, 6, 420, 37, texninja);

	//sprites->Add(10010, 856, 6, 873, 38, texninja);//SPRITES FOR IDLE LEFT

	//sprites->Add(10011, 456, 7, 476, 38, texninja);//SPRITES FOR RUN LEFT
	//sprites->Add(10012, 486, 7, 508, 38, texninja);
	//sprites->Add(10013, 517, 7, 537, 38, texninja);

	//sprites->Add(10021, 3, 44, 20, 76, texninja);//SPRITES FOR SIT RIGHT
	//sprites->Add(10022, 856, 45, 873, 77, texninja);//SPRITES FOR SIT LEFT


	//sprites->Add(10031, 142, 53, 158, 75, texninja);//SPRITES FOR JUMP AND RUN RIGHT
	//sprites->Add(10032, 166, 55, 188, 71, texninja);
	//sprites->Add(10033, 194, 53, 210, 75, texninja);
	//sprites->Add(10034, 217, 55, 239, 71, texninja);

	//sprites->Add(10041, 718, 54, 734, 76, texninja);//SPRITES FOR JUMP AND RUN LEFT
	//sprites->Add(10042, 688, 56, 710, 72, texninja);
	//sprites->Add(10043, 666, 54, 682, 76, texninja);
	//sprites->Add(10044, 637, 56, 659, 72, texninja);
	//LPANIMATION ani;

	//ani = new CAnimation(100);//ANIMATION FOR IDLE RIGHT
	//ani->Add(10000);
	//animations->Add(400, ani);

	//ani = new CAnimation(100);//ANIMATION FOR IDLE LEFT
	//ani->Add(10010);
	//animations->Add(401, ani);

	//ani = new CAnimation(100);//ANIMATION FOR SIT RIGHT
	//ani->Add(10021);
	//animations->Add(600, ani);

	//ani = new CAnimation(100);//ANIMATION FOR SIT LEFT
	//ani->Add(10022);
	//animations->Add(601, ani);

	//ani = new CAnimation(100);//ANIMATION FOR RUN RIGHT
	//ani->Add(10001);
	//ani->Add(10002);
	//ani->Add(10003);
	//animations->Add(500, ani);

	//ani = new CAnimation(100);//ANIMATION FOR RUN LEFT
	//ani->Add(10011);
	//ani->Add(10012);
	//ani->Add(10013);
	//animations->Add(501, ani);

	//ani = new CAnimation(100);//ANIMATION FOR JUMP AND RUN RIGHT
	//ani->Add(10031);
	//ani->Add(10032);
	//ani->Add(10033);
	//ani->Add(10034);
	//animations->Add(700, ani);

	//ani = new CAnimation(100);//ANIMATION FOR RUN AND JUMP LEFT
	//ani->Add(10041);
	//ani->Add(10042);
	//ani->Add(10043);
	//ani->Add(10044);
	//animations->Add(701, ani);

	//LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	//sprites->Add(20001, 408, 225, 424, 241, texMisc);

	//ani = new CAnimation(100);		// brick
	//ani->Add(20001);
	//animations->Add(651, ani);

	//ninja = new Ninja();
	//ninja->AddAnimation(400);		// idle right
	//ninja->AddAnimation(401);		// idle left
	//ninja->AddAnimation(500);		// walk right
	//ninja->AddAnimation(501);		// walk left
	//ninja->AddAnimation(600);		//sit right
	//ninja->AddAnimation(601);		//sit left
	//ninja->AddAnimation(700);		//jump right
	//ninja->AddAnimation(701);		//jump left

	/*camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
	camera->Follow(ninja);*/

	//ninja->SetPosition(0.0f, 100.0f);

	//brick = new CBrick();
	//brick->AddAnimation(651);
	//brick->SetPosition(100 + 2 * 48.0f, 74);

	if (tilemap == NULL)
		tilemap = new TiledMap(TILES_MATRIX);
}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void Update(DWORD dt)
{
	//camera->Update();
	/*ninja->Update(dt);
	brick->Update(dt);*/
}

/*
	Render a frame 
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		/*camera->SetTransform(game);
		ninja->Render();
		brick->Render();*/
		tilemap->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd) 
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();
			
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);	
	}

	return 1;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH*1.5, SCREEN_HEIGHT * 2);

	game = CGame::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);


	LoadResources();
	Run();

	return 0;
}
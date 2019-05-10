﻿#pragma once


//Tên ứng dụng
#define WINDOW_CLASS_NAME L"Ninja Gaiden"
#define MAIN_WINDOW_TITLE L"Ninja Gaiden"
//Màu background, kích cỡ màn hình
#define BACKGROUND_COLOR D3DCOLOR_XRGB(200, 200, 255)
#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 250

//Framerate tối đa
#define MAX_FRAME_RATE 90
//Id texture của các vật thể
#define ID_TEX_NINJA 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
//

#define GRID_SIZE 64
enum Stage {
	STAGE_31,
	STAGE_32,
	STAGE_BOSS
};

enum ObjectType
{
	DEFAULT,
	BRICK
};
//TiledMap
//
// MAP
#define BACKGROUND_3_1 L"Resources\\TiledMap\\MAP_31.png"
#define BACKGROUND_3_2 L"Resources\\TiledMap\\MAP_32.png"
#define BACKGROUND_BOSS L"Resources\\TiledMap\\MAP_BOSS.png"
// TiLE
#define TILES_MATRIX_STAGE_31 L"Resources\\TiledMap\\MAP_31_Matrix.txt"
#define TILES_MATRIX_STAGE_32 L"Resources\\TiledMap\\MAP_32_Matrix.txt"
#define TILES_MATRIX_STAGE_BOSS L"Resources\\TiledMap\\MAP_BOSS_Matrix.txt"

#define TILES_MATRIX_DELIMITER ","
#define TILES_WIDTH_PER_TILE	16
#define TILES_HEIGHT_PER_TILE	16
#define TILES_TRANSCOLOR D3DCOLOR_XRGB(255, 0, 255)

//
//Ryu
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define NINJA_WALKING_SPEED		0.125f
#define NINJA_JUMP_SPEED_Y		0.4f
#define NINJA_GRAVITY			0.025f
//Các số để chạy animation của Ninja
#define NINJA_ANI_IDLE					0
#define NINJA_ANI_WALKING 				1
#define NINJA_ANI_STANDING_ATTACKING 	2
#define NINJA_ANI_CROUCHING_ATTACKING 	3
#define NINJA_ANI_JUMPING 				4
#define NINJA_ANI_CROUCHING 			5
#define NINJA_ANI_CLIMBING				6
#define NINJA_ANI_JUMPING_ATTACKING 	7

#define NINJA_TEXTURE_LOCATION L"Resources\\Ninja\\Ninja.png"
#define NINJA_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define NINJA_TEXTURE_COLUMNS 10
#define NINJA_TEXTURE_ROWS 3
#define NINJA_SPRITE_WIDTH 26
#define NINJA_SPRITE_HEIGHT 36

//
//Enemy
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define ENEMY_WALKING_SPEED		0.100f
#define ENEMY_JUMP_SPEED_Y		0.4f
#define ENEMY_GRAVITY			0.025f
//Các số để chạy animation của ENEMY
#define ENEMY_ANI_IDLE					0
#define ENEMY_ANI_WALKING 				1
#define ENEMY_ANI_STANDING_ATTACKING 	2
#define ENEMY_ANI_CROUCHING_ATTACKING 	3
#define ENEMY_ANI_JUMPING 				4
#define ENEMY_ANI_CROUCHING 			5
#define ENEMY_ANI_CLIMBING				6
#define ENEMY_ANI_JUMPING_ATTACKING 	7

#define ENEMY_TEXTURE_LOCATION L"Resources\\Enemy\\Enemy.png"
#define ENEMY_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define ENEMY_TEXTURE_COLUMNS 3
#define ENEMY_TEXTURE_ROWS 1
#define ENEMY_SPRITE_WIDTH 30
#define ENEMY_SPRITE_HEIGHT 40

//
//Whip
//
#define WHIP_NORMAL			0
#define WHIP_SHORT_CHAIN	1
#define WHIP_LONG_CHAIN		2

#define WHIP_TEXTURE_LOCATION L"Resources\\Weapons\\Whips\\Whips.png"
#define WHIP_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define WHIP_TEXTURE_COLUMNS 3
#define WHIP_TEXTURE_ROWS 6
#define WHIP_SPRITE_WIDTH 240
#define WHIP_SPRITE_HEIGHT 66

//
//Subweapon
//
#define SUBWEAPON_SPEED_X		0.3f
#define SUBWEAPON_SPEED_Y		0.5f
#define SUBWEAPON_GRAVITY		0.025f
////Knife
#define SUBWEAPON_KNIFE		0
#define SUBWEAPON_KNIFE_TEXTURE_LOCATION		L"Resources\\Weapons\\Subweapons\\Knife.png"
#define SUBWEAPON_KNIFE_TEXTURE_TRANS_COLOR		D3DCOLOR_XRGB(255, 0, 255)
#define SUBWEAPON_KNIFE_TEXTURE_COLUMNS 1
#define SUBWEAPON_KNIFE_TEXTURE_ROWS 1
#define SUBWEAPON_KNIFE_SPRITE_WIDTH 32
#define SUBWEAPON_KNIFE_SPRITE_HEIGHT 18
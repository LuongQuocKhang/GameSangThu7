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

enum Stage {
	STAGE_31,
	STAGE_32,
	STAGE_BOSS
};

enum ObjectType
{
	DEFAULT,
	BRICK,
	VINES
};

enum EnemyType {
	YELLOWSOLDIER,
	REDBIRD,
	BROWNBIRD,
	YELLOWPANTHER,
	PINKWITCH,
	GREENSOLDIER
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
#define NINJA_JUMP_SPEED_Y		0.5f
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
#define YELLOW_SOLDIER_WALKING_SPEED		0.025f
#define YELLOW_SOLDIER_JUMP_SPEED_Y		0.4f
#define YELLOW_SOLDIER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY YELLOW SOLDIER
#define YELLOW_SOLDIER_ANI_IDLE					0
#define YELLOW_SOLDIER_ANI_WALKING 				1

#define YELLOW_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\Enemy.png"
#define YELLOW_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define YELLOW_SOLDIER_TEXTURE_COLUMNS 3
#define YELLOW_SOLDIER_TEXTURE_ROWS 1
#define YELLOW_SOLDIER_SPRITE_WIDTH 30
#define YELLOW_SOLDIER_SPRITE_HEIGHT 40

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define BROWN_BIRD_WALKING_SPEED		0.025f
#define BROWN_BIRD_JUMP_SPEED_Y		0.4f
#define BROWN_BIRD_GRAVITY			0.025f
//Các số để chạy animation của ENEMY BROWN BIRD
#define BROWN_BIRD_ANI_IDLE					0
#define BROWN_BIRD_ANI_WALKING 				1

#define BROWN_BIRD_TEXTURE_LOCATION L"Resources\\Enemy\\BROWN_BIRD.png"
#define BROWN_BIRD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BROWN_BIRD_TEXTURE_COLUMNS 2
#define BROWN_BIRD_TEXTURE_ROWS 1
#define BROWN_BIRD_SPRITE_WIDTH 30
#define BROWN_BIRD_SPRITE_HEIGHT 40
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define RED_BIRD_WALKING_SPEED		0.025f
#define RED_BIRD_JUMP_SPEED_Y		0.4f
#define RED_BIRD_GRAVITY			0.025f
//Các số để chạy animation của ENEMY RED BIRD
#define RED_BIRD_ANI_IDLE					0
#define RED_BIRD_ANI_WALKING 				1

#define RED_BIRD_TEXTURE_LOCATION L"Resources\\Enemy\\RED_BIRD.png"
#define RED_BIRD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define RED_BIRD_TEXTURE_COLUMNS 2
#define RED_BIRD_TEXTURE_ROWS 1
#define RED_BIRD_SPRITE_WIDTH 18
#define RED_BIRD_SPRITE_HEIGHT 20
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define YELLOW_PANTHER_WALKING_SPEED		0.065f
#define YELLOW_PANTHER_JUMP_SPEED_Y		0.4f
#define YELLOW_PANTHER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY YELLOW PANTHER
#define YELLOW_PANTHER_ANI_IDLE					0
#define YELLOW_PANTHER_ANI_WALKING 				1

#define YELLOW_PANTHER_TEXTURE_LOCATION L"Resources\\Enemy\\YELLOW_PANTHER.png"
#define YELLOW_PANTHER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define YELLOW_PANTHER_TEXTURE_COLUMNS 2
#define YELLOW_PANTHER_TEXTURE_ROWS 1
#define YELLOW_PANTHER_SPRITE_WIDTH 37
#define YELLOW_PANTHER_SPRITE_HEIGHT 40
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define	GREEN_SOLDIER_WALKING_SPEED		0.025f
#define	GREEN_SOLDIER_JUMP_SPEED_Y		0.4f
#define	GREEN_SOLDIER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY GREEN SOLDIER
#define	GREEN_SOLDIER_ANI_IDLE					0
#define	GREEN_SOLDIER_ANI_WALKING 				1

#define	GREEN_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\GREEN_SOLDIER.png"
#define	GREEN_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define	GREEN_SOLDIER_TEXTURE_COLUMNS 4
#define	GREEN_SOLDIER_TEXTURE_ROWS 1
#define	GREEN_SOLDIER_SPRITE_WIDTH 30
#define	GREEN_SOLDIER_SPRITE_HEIGHT 40
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define	PINK_WITCH_WALKING_SPEED		0.025f
#define	PINK_WITCH_JUMP_SPEED_Y		0.4f
#define	PINK_WITCH_GRAVITY			0.025f
//Các số để chạy animation của ENEMY PINK WITCH
#define	PINK_WITCH_ANI_IDLE					0
#define	PINK_WITCH_ANI_WALKING 				1

#define	PINK_WITCH_TEXTURE_LOCATION L"Resources\\Enemy\\PINK_WITCH.png"
#define	PINK_WITCH_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define	PINK_WITCH_TEXTURE_COLUMNS 3
#define	PINK_WITCH_TEXTURE_ROWS 1
#define	PINK_WITCH_SPRITE_WIDTH 30
#define	PINK_WITCH_SPRITE_HEIGHT 50
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

#define GRID_SIZE 64
#define GRID_MAX_X 48
#define GRID_MAX_Y 5
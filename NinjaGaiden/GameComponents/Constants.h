﻿#pragma once


//Tên ứng dụng
#define WINDOW_CLASS_NAME L"Ninja Gaiden"
#define MAIN_WINDOW_TITLE L"Ninja Gaiden"
//Màu background, kích cỡ màn hình
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 250
#define MAP_HEIGHT 176

//Framerate tối đa
#define MAX_FRAME_RATE 90
//Id texture của các vật thể
#define ID_TEX_NINJA 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

#define STAMINA 6.25
#define HEATH_LEFT 28
#define HEATH_LOST 29
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
	VINES,
	BRICK_NOCOLLISION_BOTTOM
};
enum Column
{
	No,
	Type,
	Direction,
	PosX,
	PosY,
	Width,
	Height,
	ItemType,
};
enum EnemyType {
	YELLOWSOLDIER,
	REDBIRD,
	BROWNBIRD,
	YELLOWPANTHER,
	PINKWITCH,
	GREENSOLDIER,
	BLOODYBIRD,
	GREENCANONSOLDIER,
	GREENRUNNINGSOLDIER,
	BOSS
};

enum CollisionWithEnemy
{
	ATACKING,
	COLLIDING
};

enum Item {
	NONE,
	FLAMES,
	SHURIKEN,
	JUMPANDFLASH,
	FIREWHEELS,
	SPIRITPOINTBLUE,
	SPIRITPOINTRED,
	TIMEFREEZE,
	THROWINGSTAR,
	BONUSPOINTBLUE,
	BONUSPOINTRED,
	HEALTHITEM
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

#define ENEMIES_MAP_31 L"Resources\\Enemy\\ENEMIES_MAP_31_Matrix.txt"
#define ENEMIES_MAP_32 L"Resources\\Enemy\\ENEMIES_MAP_32_Matrix.txt"
#define ENEMIES_MAP_BOSS L"Resources\\Enemy\\ENEMIES_MAP_BOSS_Matrix.txt"

#define TILES_MATRIX_DELIMITER ","
#define TILES_WIDTH_PER_TILE	16
#define TILES_HEIGHT_PER_TILE	16
#define TILES_TRANSCOLOR D3DCOLOR_XRGB(255, 0, 255)

// Bullet
#define GREEN_CANNON_SOLDIER_BULLET L"Resources\\Enemy\\Bullet\\GreenCanonSoldierBullet.png"
#define GREEN_CANNON_SOLDIER_BULLET_WIDTH 15
#define GREEN_CANNON_SOLDIER_BULLET_HEIGHT 14
#define GREEN_CANNON_SOLDIER_BULLET_SPEED 0.125f
#define GREEN_SOLDIER_BULLET L"Resources\\Enemy\\Bullet\\GreenSoldierBullet.png"
#define GREEN_SOLDIER_BULLET_WIDTH 17
#define GREEN_SOLDIER_BULLET_HEIGHT 13

#define PINK_WITCH_BULLET L"Resources\\Enemy\\Bullet\\WitcherBullet.png"
#define PINK_WITCH_BULLET_WIDTH 17
#define PINK_WITCH_BULLET_HEIGHT 25

#define BOSS_MAP_33_BULLET L"Resources\\Enemy\\Bullet\\BossBullet.png"
#define BOSS_MAP_33_BULLET_WIDTH 16
#define BOSS_MAP_33_BULLET_HEIGHT 16

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define NINJA_WALKING_SPEED		0.125f
#define NINJA_JUMP_SPEED_Y		0.5f
#define NINJA_GRAVITY			0.025f
#define NINJA_CLIMB_SPEED		0.5f
//Các số để chạy animation của Ninja
#define NINJA_ANI_IDLE					0
#define NINJA_ANI_WALKING 				1
#define NINJA_ANI_STANDING_ATTACKING 	2
#define NINJA_ANI_CROUCHING_ATTACKING 	3
#define NINJA_ANI_JUMPING 				4
#define NINJA_ANI_CROUCHING 			5
#define NINJA_ANI_CLIMBING				6
#define NINJA_ANI_JUMPING_ATTACKING 	7
#define NINJA_ANI_JUMPING_ATTACKED		8
#define NINJA_ANI_THROWING		9

#define NINJA_TEXTURE_LOCATION L"Resources\\Ninja\\Ninja.png"
#define NINJA_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define NINJA_TEXTURE_COLUMNS 10
#define NINJA_TEXTURE_ROWS 3
#define NINJA_SPRITE_WIDTH 26
#define NINJA_SPRITE_HEIGHT 36

#define SHURIKEN_TEXTTURE_LOCATION L"Resources\\Weapons\\Subweapons\\Shuriken.png"
#define SHURIKEN_WIDTH 22
#define SHURIKEN_HEIGHT 26

#define SHURIKEN_NUM 1
#define SHURIKEN_SPEED 0.125f
#define SHURIKEN_TEXTURE_COLUMNS 1

#define DEATH_EFFECT_TEXTTURE_LOCATION L"Resources\\Ninja\\Dead_Effect.png"
#define DEATH_EFFECT_WIDTH 40
#define DEATH_EFFECT_HEIGHT 40

#define DEATH_EFFECT_NUM 1
#define DEATH_EFFECT_SPEED 0.125f
#define DEATH_EFFECT_TEXTURE_COLUMNS 1
//
//Enemy
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define YELLOW_SOLDIER_WALKING_SPEED		0.025f
#define YELLOW_SOLDIER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY YELLOW SOLDIER
#define YELLOW_SOLDIER_ANI_IDLE					0
#define YELLOW_SOLDIER_ANI_WALKING 				1

#define YELLOW_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\Enemy.png"
#define YELLOW_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define YELLOW_SOLDIER_TEXTURE_COLUMNS 3
#define YELLOW_SOLDIER_TEXTURE_ROWS 1
#define YELLOW_SOLDIER_SPRITE_WIDTH 31
#define YELLOW_SOLDIER_SPRITE_HEIGHT 40

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define GREEN_CANON_SOLDIER_WALKING_SPEED		0.025f
#define GREEN_CANON_SOLDIER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY GREEN CANON SOLDIER
#define GREEN_CANON_SOLDIER_ANI_IDLE					0
#define GREEN_CANON_SOLDIER_ANI_WALKING 				1

#define GREEN_CANON_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\GREEN_CANON_SOLDIER.png"
#define GREEN_CANON_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define GREEN_CANON_SOLDIER_TEXTURE_COLUMNS 2
#define GREEN_CANON_SOLDIER_TEXTURE_ROWS 1
#define GREEN_CANON_SOLDIER_SPRITE_WIDTH 30
#define GREEN_CANON_SOLDIER_SPRITE_HEIGHT 40
//
//Các số để chạy animation của ENEMY GREEN RUNNING SOLDIER
#define GREEN_RUNNING_SOLDIER_ANI_IDLE					0
#define GREEN_RUNNING_SOLDIER_ANI_WALKING 				1

#define GREEN_RUNNING_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\GREEN_RUNNING_SOLDIER.png"
#define GREEN_RUNNING_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define GREEN_RUNNING_SOLDIER_TEXTURE_COLUMNS 2
#define GREEN_RUNNING_SOLDIER_TEXTURE_ROWS 1
#define GREEN_RUNNING_SOLDIER_SPRITE_WIDTH 20
#define GREEN_RUNNING_SOLDIER_SPRITE_HEIGHT 40
//
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
//Các số để chạy animation của ENEMY BLOODY BIRD
#define BLOODY_BIRD_ANI_IDLE					0
#define BLOODY_BIRD_ANI_WALKING 				1

#define BLOODY_BIRD_TEXTURE_LOCATION L"Resources\\Enemy\\BLOODY_BIRD.png"
#define BLOODY_BIRD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BLOODY_BIRD_TEXTURE_COLUMNS 2
#define BLOODY_BIRD_TEXTURE_ROWS 1
#define BLOODY_BIRD_SPRITE_WIDTH 20
#define BLOODY_BIRD_SPRITE_HEIGHT 30
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define BOSS_WALKING_SPEED		0.025f
#define BOSS_GRAVITY			0.025f
//Các số để chạy animation của ENEMY BOSS
#define BOSS_ANI_IDLE					0
#define BOSS_ANI_WALKING 				1

#define BOSS_TEXTURE_LOCATION L"Resources\\Enemy\\BOSS.png"
#define BOSS_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define BOSS_TEXTURE_COLUMNS 2
#define BOSS_TEXTURE_ROWS 1
#define BOSS_SPRITE_WIDTH 50
#define BOSS_SPRITE_HEIGHT 70
//
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
#define YELLOW_PANTHER_WALKING_SPEED		-0.075f
#define YELLOW_PANTHER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY YELLOW PANTHER
#define YELLOW_PANTHER_ANI_IDLE					0
#define YELLOW_PANTHER_ANI_WALKING 				1

#define YELLOW_PANTHER_TEXTURE_LOCATION L"Resources\\Enemy\\YELLOW_PANTHER.png"
#define YELLOW_PANTHER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define YELLOW_PANTHER_TEXTURE_COLUMNS 2
#define YELLOW_PANTHER_TEXTURE_ROWS 1
#define YELLOW_PANTHER_SPRITE_WIDTH 37
#define YELLOW_PANTHER_SPRITE_HEIGHT 25
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define	GREEN_SOLDIER_WALKING_SPEED		0.025f
#define	GREEN_SOLDIER_GRAVITY			0.025f
//Các số để chạy animation của ENEMY GREEN SOLDIER
#define	GREEN_SOLDIER_ANI_IDLE					0
#define	GREEN_SOLDIER_ANI_WALKING 				1

#define	GREEN_SOLDIER_TEXTURE_LOCATION L"Resources\\Enemy\\GREEN_SOLDIER.png"
#define	GREEN_SOLDIER_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define	GREEN_SOLDIER_TEXTURE_COLUMNS 5
#define	GREEN_SOLDIER_TEXTURE_ROWS 1
#define	GREEN_SOLDIER_SPRITE_WIDTH 25
#define	GREEN_SOLDIER_SPRITE_HEIGHT 40
//

//Giá trị tốc độ đi, tốc độ nhảy, trọng lực
#define	PINK_WITCH_WALKING_SPEED		0.025f
#define	PINK_WITCH_GRAVITY			0.025f
//Các số để chạy animation của ENEMY PINK WITCH
#define	PINK_WITCH_ANI_IDLE					0
#define	PINK_WITCH_ANI_WALKING 				1

#define	PINK_WITCH_TEXTURE_LOCATION L"Resources\\Enemy\\PINK_WITCH.png"
#define	PINK_WITCH_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define	PINK_WITCH_TEXTURE_COLUMNS 3
#define	PINK_WITCH_TEXTURE_ROWS 1
#define	PINK_WITCH_SPRITE_WIDTH 30
#define	PINK_WITCH_SPRITE_HEIGHT 45

//HUD
#define HUD_TEXTURE_LOCATION L"Resources\\Font\\FONT.jpg"
#define ITEM_HUD_TEXTURE_LOCATION L"Resources\\Font\\Item_Hud.png"
#define ITEM_HUD_2_TEXTURE_LOCATION L"Resources\\Font\\Item_Hud_2.png"
#define ITEM_HUD_BLOOD_TEXTURE_LOCATION L"Resources\\Font\\bloods.jpg"
#define HUD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define ITEM_HUD_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define HUD_TEXTURE_COLUMNS 17
#define HUD_TEXTURE_ROWS 6
#define ITEM_HUD_TEXTURE_COLUMNS 2
#define ITEM_HUD_TEXTURE_ROWS 1
#define ITEM_HUD_2_TEXTURE_COLUMNS 6
#define ITEM_HUD_2_TEXTURE_ROWS 1
#define ITEM_HUD_BLOOD_TEXTURE_COLUMNS 2
#define ITEM_HUD_BLOOD_TEXTURE_ROWS 1
#define HUD_SPRITE_WIDTH 10
#define HUD_SPRITE_HEIGHT 11
#define ITEM_HUD_SPRITE_WIDTH 15
#define ITEM_HUD_SPRITE_HEIGHT 10
#define ITEM_HUD_BLOOD_SPRITE_WIDTH 10
#define ITEM_HUD_BLOOD_SPRITE_HEIGHT 20

#define GRID_SIZE 64
#define GRID_MAX_X 48
#define GRID_MAX_Y 5

// ITEM



#define FLAMES_TEXTURE_LOCATION L"Resources\\Font\\ItemList.png"
#define FLAMES_TEXTURE_TRANS_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define FLAMES_TEXTURE_COLUMNS 17
#define FLAMES_TEXTURE_ROWS 1
#define FLAMES_SPRITE_WIDTH 15
#define FLAMES_SPRITE_HEIGHT 20

#define GAMEITEM_2 L"Resources\\Font\\Item_Hud_2.png"
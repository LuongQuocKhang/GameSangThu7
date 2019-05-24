#include "Hud.h"
#include "Ninja.h"

Hud::Hud(float posx, float posy)
{
	__instance = NULL;
	LoadResources();

	this->SetPositionX(posx);
	this->SetPositionY(posy);

}
void Hud::LoadResources()
{
	// S:0
	Animation * anim = new Animation(100);
	anim = new Animation(200);
	for (int i = 17; i < 18; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//C:1
	anim = new Animation(200);
	for (int i = 2; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH-2;
		rect.right = rect.left + HUD_SPRITE_WIDTH-3;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT+2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//O:2
	anim = new Animation(200);
	for (int i = 12; i < 13; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH-5;
		rect.right = rect.left + HUD_SPRITE_WIDTH-2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT+2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//R:3
	anim = new Animation(200);
	for (int i = 14; i < 15; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH-2;
		rect.right = rect.left + HUD_SPRITE_WIDTH -2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2 ;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//E:4
	anim = new Animation(200);
	for (int i = 4; i < 5; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH-6;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 4;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//.:5
	anim = new Animation(200);
	for (int i = 59; i < 60; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH+3;
		rect.right = rect.left + HUD_SPRITE_WIDTH -2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT -3;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// T:6
	anim = new Animation(200);
	for (int i = 18; i < 19; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH-2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//A:7
	anim = new Animation(200);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH+2;
		rect.right = rect.left + HUD_SPRITE_WIDTH -2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//G:8
	anim = new Animation(200);
	for (int i = 5; i < 6; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//1 : 9
	anim = new Animation(200);
	for (int i = 35; i < 36; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 5;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT +7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//3 : 10
	anim = new Animation(200);
	for (int i = 37; i < 38; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH-1;
		rect.right = rect.left + HUD_SPRITE_WIDTH -4;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//- :11
	anim = new Animation(200);
	for (int i = 40; i < 41; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 4;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 16;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//I :12
	anim = new Animation(200);
	for (int i = 6; i < 7; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH+7;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//M :13
	anim = new Animation(200);
	for (int i = 10; i < 11; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH -4;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT +2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

//Hàm c?p nh?t
void Hud::Update(DWORD dt)
{
	Ninja * ninja = Ninja::GetInstance();
	int right = (int)(Game::GetInstance()->GetTiledMap()->GetWidth() - SCREEN_WIDTH / 2);
	int left = (int)SCREEN_WIDTH / 2;
	if (ninja->GetPositionX() > left && ninja->GetPositionX() < right)
	{
		this->x = ninja->GetPositionX() - left;
	}
}
//Hàm render
void Hud::Render()
{
	int locx;
	SpriteData spriteEnemyData;
	spriteEnemyData.width = HUD_SPRITE_WIDTH;
	spriteEnemyData.height = HUD_SPRITE_HEIGHT;
	spriteEnemyData.x = this->GetPositionX();
	spriteEnemyData.y = this->GetPositionY();


	spriteEnemyData.scale = 1.8;
	spriteEnemyData.angle = 0;
	//S
	this->animations[0]->Render(spriteEnemyData);
	spriteEnemyData.x = this->GetPositionX() + 20;
	locx = spriteEnemyData.x;
	//CORE
	for (int i = 1; i < 6; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x+15;
	}
	//111111
	for (int i = 0; i < 6; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
	spriteEnemyData.x = locx + 30;
	//S
	this->animations[0]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 20;
	//TA
	for (int i = 6; i < 9; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	//GE
	for (int i = 4; i < 6; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	//3
	spriteEnemyData.x = locx;
	this->animations[10]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//-
	spriteEnemyData.x = locx;
	this->animations[11]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//3
	spriteEnemyData.x = locx;
	this->animations[10]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;

	//Row 2
	spriteEnemyData.x = this->GetPositionX() +5;
	spriteEnemyData.y = this->GetPositionY() - 20;
	//T
	this->animations[6]->Render(spriteEnemyData);	
	locx = spriteEnemyData.x+15;
	//IM
	for (int i = 12; i < 14; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 8;
	}
	locx = spriteEnemyData.x + 20;
	//ER
	for (int i = 4; i > 2; i--)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	//.
	for (int i = 5; i < 6; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	//111
	for (int i = 0; i < 3; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
}
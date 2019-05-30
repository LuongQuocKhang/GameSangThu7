#include "Hud.h"
#include "Ninja.h"
#include "Constants.h"

Hud * Hud::__instance = NULL;
Hud::Hud(float posx, float posy)
{
	__instance = NULL;
	LoadResources();

	this->SetPositionX(posx);
	this->SetPositionY(posy);

}
void Hud::Reset()
{
	x = 0;
	y = 250;
}
Hud * Hud::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Hud(0, 250);
	}
	return __instance;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 2;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 3;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 5;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 2;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 6;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 3;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT - 3;
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
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 2;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
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
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 1;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 4;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 7;
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
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 4;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//N :14
	anim = new Animation(200);
	for (int i = 11; i < 12; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 4;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//J :15
	anim = new Animation(200);
	for (int i = 7; i < 8; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 4;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 3;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//P :16
	anim = new Animation(200);
	for (int i = 12; i < 13; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 3;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 2;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//Item :17
	anim = new Animation(200);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ITEM_HUD_TEXTURE_COLUMNS) * ITEM_HUD_SPRITE_WIDTH + 2;
		rect.right = rect.left + ITEM_HUD_SPRITE_WIDTH;
		rect.top = (i / ITEM_HUD_TEXTURE_COLUMNS) * ITEM_HUD_SPRITE_HEIGHT;
		rect.bottom = rect.top + ITEM_HUD_SPRITE_HEIGHT + 4;
		Sprite * sprite = new Sprite(ITEM_HUD_TEXTURE_LOCATION, rect, ITEM_HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//Item2 :18
	anim = new Animation(200);
	for (int i = 4; i < 5; i++)
	{
		RECT rect;
		rect.left = (i % ITEM_HUD_2_TEXTURE_COLUMNS) * ITEM_HUD_SPRITE_WIDTH;
		rect.right = rect.left + ITEM_HUD_SPRITE_WIDTH + 4;
		rect.top = (i / ITEM_HUD_2_TEXTURE_COLUMNS) * ITEM_HUD_SPRITE_HEIGHT;
		rect.bottom = rect.top + ITEM_HUD_SPRITE_HEIGHT + 8;
		Sprite * sprite = new Sprite(ITEM_HUD_2_TEXTURE_LOCATION, rect, ITEM_HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//Y :19
	anim = new Animation(200);
	for (int i = 22; i < 23; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 1;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 2;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//2 : 20
	anim = new Animation(200);
	for (int i = 36; i < 37; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 5;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//4 : 21
	anim = new Animation(200);
	for (int i = 38; i < 39; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 5;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 3;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//5 : 22
	anim = new Animation(200);
	for (int i = 38; i < 39; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 2;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 1;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//6 : 23
	anim = new Animation(200);
	for (int i = 39; i < 40; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//7 : 24
	anim = new Animation(200);
	for (int i = 40; i < 41; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 2;
		rect.right = rect.left + HUD_SPRITE_WIDTH - 1;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//8 : 25
	anim = new Animation(200);
	for (int i = 41; i < 42; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH - 5;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//9 : 26
	anim = new Animation(200);
	for (int i = 41; i < 42; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH + 4;
		rect.right = rect.left + HUD_SPRITE_WIDTH + 4;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	//0 : 27
	anim = new Animation(200);
	for (int i = 34; i < 35; i++)
	{
		RECT rect;
		rect.left = (i % HUD_TEXTURE_COLUMNS) * HUD_SPRITE_WIDTH;
		rect.right = rect.left + HUD_SPRITE_WIDTH;
		rect.top = (i / HUD_TEXTURE_COLUMNS) * HUD_SPRITE_HEIGHT + 7;
		rect.bottom = rect.top + HUD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(HUD_TEXTURE_LOCATION, rect, HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);

	//ItemBlood :28
	anim = new Animation(200);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % ITEM_HUD_BLOOD_TEXTURE_COLUMNS) * ITEM_HUD_BLOOD_SPRITE_WIDTH;
		rect.right = rect.left + ITEM_HUD_BLOOD_SPRITE_WIDTH;
		rect.top = (i / ITEM_HUD_BLOOD_TEXTURE_COLUMNS) * ITEM_HUD_BLOOD_SPRITE_HEIGHT;
		rect.bottom = rect.top + ITEM_HUD_BLOOD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ITEM_HUD_BLOOD_TEXTURE_LOCATION, rect, ITEM_HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);

	// HP lost
	anim = new Animation(200);
	for (int i = 1; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % ITEM_HUD_BLOOD_TEXTURE_COLUMNS) * ITEM_HUD_BLOOD_SPRITE_WIDTH;
		rect.right = rect.left + ITEM_HUD_BLOOD_SPRITE_WIDTH;
		rect.top = (i / ITEM_HUD_BLOOD_TEXTURE_COLUMNS) * ITEM_HUD_BLOOD_SPRITE_HEIGHT;
		rect.bottom = rect.top + ITEM_HUD_BLOOD_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(ITEM_HUD_BLOOD_TEXTURE_LOCATION, rect, ITEM_HUD_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

//H�m c?p nh?t
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
//H�m render
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
	
	#pragma region Row 1
	//S
	this->animations[0]->Render(spriteEnemyData);
	spriteEnemyData.x = this->GetPositionX() + 20;
	locx = spriteEnemyData.x;
	//CORE
	for (int i = 1; i < 6; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	//111111
	int scores = Ninja::GetInstance()->GetScore();

	if (scores > 9)
	{
		switch (scores / 10)
		{
		case 0:
		{
			spriteEnemyData.x = locx;
			this->animations[27]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 1:
		{
			spriteEnemyData.x = locx;
			this->animations[9]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 2:
		{
			spriteEnemyData.x = locx;
			this->animations[20]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 3:
		{
			spriteEnemyData.x = locx;
			this->animations[10]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 4:
		{
			spriteEnemyData.x = locx;
			this->animations[21]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 5:
		{
			spriteEnemyData.x = locx;
			this->animations[22]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 6:
		{
			spriteEnemyData.x = locx;
			this->animations[23]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 7:
		{
			spriteEnemyData.x = locx;
			this->animations[24]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 8:
		{
			spriteEnemyData.x = locx;
			this->animations[25]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 9:
		{
			spriteEnemyData.x = locx;
			this->animations[26]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		}

		switch (scores % 10)
		{
		case 0:
		{
			spriteEnemyData.x = locx;
			this->animations[27]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 1:
		{
			spriteEnemyData.x = locx;
			this->animations[9]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 2:
		{
			spriteEnemyData.x = locx;
			this->animations[20]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 3:
		{
			spriteEnemyData.x = locx;
			this->animations[10]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 4:
		{
			spriteEnemyData.x = locx;
			this->animations[21]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 5:
		{
			spriteEnemyData.x = locx;
			this->animations[22]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 6:
		{
			spriteEnemyData.x = locx;
			this->animations[23]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 7:
		{
			spriteEnemyData.x = locx;
			this->animations[24]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 8:
		{
			spriteEnemyData.x = locx;
			this->animations[25]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 9:
		{
			spriteEnemyData.x = locx;
			this->animations[26]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		}
		spriteEnemyData.x = locx + 50;
	}
	else
	{
		switch (scores)
		{
		case 0:
		{
			spriteEnemyData.x = locx;
			this->animations[27]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 1:
		{
			spriteEnemyData.x = locx;
			this->animations[9]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 2:
		{
			spriteEnemyData.x = locx;
			this->animations[20]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 3:
		{
			spriteEnemyData.x = locx;
			this->animations[10]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 4:
		{
			spriteEnemyData.x = locx;
			this->animations[21]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 5:
		{
			spriteEnemyData.x = locx;
			this->animations[22]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 6:
		{
			spriteEnemyData.x = locx;
			this->animations[23]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 7:
		{
			spriteEnemyData.x = locx;
			this->animations[24]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 8:
		{
			spriteEnemyData.x = locx;
			this->animations[25]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		case 9:
		{
			spriteEnemyData.x = locx;
			this->animations[26]->Render(spriteEnemyData);
			locx = spriteEnemyData.x + 15;
		}break;
		}
		spriteEnemyData.x = locx + 65;
	}

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
	this->animations[5]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//3
	if (Game::GetInstance()->GetStage() == Stage::STAGE_31)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	else if (Game::GetInstance()->GetStage() == Stage::STAGE_32)
	{
		spriteEnemyData.x = locx;
		this->animations[20]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	else
	{
		spriteEnemyData.x = locx;
		this->animations[10]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 15;
	}
	#pragma endregion

	#pragma region  Row 2
	spriteEnemyData.x = this->GetPositionX() + 5;
	spriteEnemyData.y = this->GetPositionY() - 20;
	//T
	this->animations[6]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
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
		locx = spriteEnemyData.x + 13;
	}
	//111
	for (int i = 0; i < 3; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
	spriteEnemyData.x = locx + 50;
	//N
	this->animations[14]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//I
	spriteEnemyData.x = locx;
	this->animations[12]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;
	//NJ
	for (int i = 14; i < 16; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[i]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
	//A
	spriteEnemyData.x = locx;
	this->animations[7]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//.
	spriteEnemyData.x = locx;
	this->animations[5]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;
	//Health

	spriteEnemyData.scale = 1;

	float ninjaheath = Ninja::GetInstance()->GetStamina() / STAMINA;
	for (int i = 0; i < (int)round(ninjaheath); i++)
	{
		spriteEnemyData.x = locx;
		this->animations[HEATH_LEFT]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 10;
	}

	for (int i = 0; i < 16 - (int)round(ninjaheath); i++)
	{
		spriteEnemyData.x = locx;
		this->animations[HEATH_LOST]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 10;
	}
	#pragma endregion
	spriteEnemyData.scale = 1.8;

	#pragma region Row 3

	spriteEnemyData.x = this->GetPositionX() + 10;
	spriteEnemyData.y = this->GetPositionY() - 40;
	//P
	this->animations[16]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;
	//.
	spriteEnemyData.x = locx;
	this->animations[5]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;
	//11
	for (int i = 0; i < 2; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
	spriteEnemyData.x = locx;
	this->animations[17]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 30;
	//.
	spriteEnemyData.x = locx;
	this->animations[5]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 10;
	//11
	for (int i = 0; i < 2; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[9]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 13;
	}
	spriteEnemyData.x = locx;
	spriteEnemyData.y = this->GetPositionY() - 25;
	this->animations[18]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 50;

	//E
	spriteEnemyData.x = locx;
	spriteEnemyData.y = this->GetPositionY() - 40;
	this->animations[4]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;

	//N
	spriteEnemyData.x = locx;
	this->animations[14]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 15;

	//E
	spriteEnemyData.x = locx;
	this->animations[4]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 10;

	//M
	spriteEnemyData.x = locx;
	this->animations[13]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 20;

	//Y
	spriteEnemyData.x = locx;
	this->animations[19]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;
	//.
	spriteEnemyData.x = locx;
	this->animations[5]->Render(spriteEnemyData);
	locx = spriteEnemyData.x + 13;

	//Health
	spriteEnemyData.scale = 1;
	for (int i = 0; i < 16; i++)
	{
		spriteEnemyData.x = locx;
		this->animations[28]->Render(spriteEnemyData);
		locx = spriteEnemyData.x + 10;
	}
	spriteEnemyData.scale = 1.8;
	#pragma endregion

}
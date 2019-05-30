#include "DeathAnimation.h"
#include "Flames.h"

void DeathAnimation::LoadResources()
{
	
}

DeathAnimation::DeathAnimation(EnemyType enemytype)
{
	this->enemytype = enemytype;
	Active = true;
	time = 200;
	LPCWSTR effectPath = L"";
	if (enemytype == EnemyType::BOSS)
	{
		effectPath = L"";
	}
	else if (enemytype == EnemyType::REDBIRD)
	{
		Animation * anim = new Animation(100);
		for (int i = 0; i < 1; i++)
		{
			RECT rect;
			rect.left = (i % FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_WIDTH;
			rect.right = rect.left + FLAMES_SPRITE_WIDTH;
			rect.top = (i / FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_HEIGHT;
			rect.bottom = rect.top + FLAMES_SPRITE_HEIGHT;
			Sprite * sprite = new Sprite(FLAMES_TEXTURE_LOCATION, rect, FLAMES_TEXTURE_TRANS_COLOR);

			anim->AddFrame(sprite);
		}
		animations.push_back(anim);
	}
	else 
	{
		effectPath = DEATH_EFFECT_TEXTTURE_LOCATION;
	}
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % DEATH_EFFECT_TEXTURE_COLUMNS) * DEATH_EFFECT_WIDTH;
		rect.right = rect.left + DEATH_EFFECT_WIDTH;
		rect.top = (i / DEATH_EFFECT_TEXTURE_COLUMNS) * DEATH_EFFECT_HEIGHT;
		rect.bottom = rect.top + DEATH_EFFECT_HEIGHT;
		Sprite * sprite = new Sprite(effectPath, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}


DeathAnimation::~DeathAnimation()
{
}

DeathAnimation * DeathAnimation::CreateDeateAnimation(Enemy * enemy)
{
	DeathAnimation* Animation = new DeathAnimation(enemy->GetEnemyType());
	Animation->x = enemy->GetPositionX();
	Animation->y = enemy->GetPositionY();

	Animation->width = DEATH_EFFECT_WIDTH;
	Animation->height = DEATH_EFFECT_HEIGHT;

	return Animation;
}

void DeathAnimation::Update(DWORD dt)
{
	time -= dt;
	if (this->enemytype != EnemyType::REDBIRD)
	{
		if (time <= 0)
		{
			this->Active = false;
		}
	}
}

void DeathAnimation::Render()
{
	SpriteData spriteEnemyData;

	spriteEnemyData.width = DEATH_EFFECT_WIDTH + 20;
	spriteEnemyData.height = DEATH_EFFECT_HEIGHT + 20;
	spriteEnemyData.x = this->GetPositionX();
	spriteEnemyData.y = this->GetPositionY();

	spriteEnemyData.scale = 1;
	spriteEnemyData.angle = 0;
	spriteEnemyData.isLeft = false;
	spriteEnemyData.isFlipped = false;

	this->animations[0]->Render(spriteEnemyData);
}

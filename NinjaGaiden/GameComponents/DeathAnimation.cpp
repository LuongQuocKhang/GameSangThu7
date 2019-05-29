#include "DeathAnimation.h"



void DeathAnimation::LoadResources()
{
	
}

DeathAnimation::DeathAnimation()
{
	Active = true;
	time = 200;

	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % DEATH_EFFECT_TEXTURE_COLUMNS) * DEATH_EFFECT_WIDTH;
		rect.right = rect.left + DEATH_EFFECT_WIDTH;
		rect.top = (i / DEATH_EFFECT_TEXTURE_COLUMNS) * DEATH_EFFECT_HEIGHT;
		rect.bottom = rect.top + DEATH_EFFECT_HEIGHT;
		Sprite * sprite = new Sprite(DEATH_EFFECT_TEXTTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	animations.push_back(anim);
}


DeathAnimation::~DeathAnimation()
{
}

DeathAnimation * DeathAnimation::CreateDeateAnimation(GameObject * gameobject)
{
	DeathAnimation* Animation = new DeathAnimation();
	Animation->x = gameobject->GetPositionX();
	Animation->y = gameobject->GetPositionY();

	Animation->width = DEATH_EFFECT_WIDTH;
	Animation->height = DEATH_EFFECT_HEIGHT;

	return Animation;
}

void DeathAnimation::Update(DWORD dt)
{
	time -= dt;
	if (time <= 0)
	{
		this->Active = false;
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

#include "DeathAnimation.h"



void DeathAnimation::LoadResources()
{
	
}

DeathAnimation::DeathAnimation()
{
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % SHURIKEN_TEXTURE_COLUMNS) * SHURIKEN_WIDTH;
		rect.right = rect.left + SHURIKEN_WIDTH;
		rect.top = (i / SHURIKEN_TEXTURE_COLUMNS) * SHURIKEN_HEIGHT;
		rect.bottom = rect.top + SHURIKEN_HEIGHT;
		Sprite * sprite = new Sprite(SHURIKEN_TEXTTURE_LOCATION, rect, NINJA_TEXTURE_TRANS_COLOR);

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

	Animation->width = SHURIKEN_WIDTH;
	Animation->height = SHURIKEN_HEIGHT;

	return Animation;
}

void DeathAnimation::Update(DWORD dt)
{
}

void DeathAnimation::Render()
{
	SpriteData spriteEnemyData;

	spriteEnemyData.width = SHURIKEN_WIDTH + 20;
	spriteEnemyData.height = SHURIKEN_HEIGHT + 20;
	spriteEnemyData.x = this->GetPositionX();
	spriteEnemyData.y = this->GetPositionY();

	spriteEnemyData.scale = 1;
	spriteEnemyData.angle = 0;
	spriteEnemyData.isLeft = false;
	spriteEnemyData.isFlipped = false;

	this->animations[0]->Render(spriteEnemyData);
}

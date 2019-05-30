#include "Flames.h"
#include "Grid.h"
vector<Animation *> Flames::animations = vector<Animation *>();
Flames * Flames::__instance = NULL;

Flames::Flames()
{
	LoadResources();

	//IsActive = false;

	width = FLAMES_SPRITE_WIDTH;
	height = FLAMES_SPRITE_HEIGHT;

	//vx = SHURIKEN_SPEED;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = FLAMES_SPRITE_WIDTH;
	collider.height = FLAMES_SPRITE_HEIGHT;
}
Flames * Flames::GetInstance()
{
	if (__instance == NULL)
		__instance = new Flames();
	return __instance;
}
void Flames::LoadResources()
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

void Flames::Update(DWORD dt)
{
	/*this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));

	distance += this->GetSpeedX() * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<Enemy* > enemies = Grid::GetInstance()->GetAllEnemies();
	if (Game::GetInstance()->GetStage() == Stage::STAGE_BOSS)
	{
		enemies = Grid::GetInstance()->GetAllEnemies();
	}
	this->CalcPotentialCollisionsAttackingEnemy(enemies, coEvents);*/
}

void Flames::Render()
{
	//Ninja * ninja = Ninja::GetInstance();
	//if (ninja->IsThrowing() == true)
	//{
		SpriteData spriteEnemyData;

		spriteEnemyData.width = FLAMES_SPRITE_WIDTH + 20;
		spriteEnemyData.height = FLAMES_SPRITE_HEIGHT + 20;
		spriteEnemyData.x = this->GetPositionX();
		spriteEnemyData.y = this->GetPositionY();

		spriteEnemyData.scale = 1;
		spriteEnemyData.angle = 0;
	/*	spriteEnemyData.isLeft = ninja->IsLeft();
		spriteEnemyData.isFlipped = ninja->IsFlipped();*/

		this->animations[0]->Render(spriteEnemyData);
	//}
}

Flames::~Flames()
{
}

//void Flames::CreateFlames(float posx, float posy, float dt, bool isLeft)
//{
//	this->Active = true;
//	this->x = posx;
//	this->y = posy;
//
//	float vx = Flames_SPEED * (isLeft == true ? -1 : 1);
//	this->vx = vx;
//	this->collider.vx = vx;
//
//	collider.x = posx;
//	collider.y = posy;
//	this->dt = dt;
//}
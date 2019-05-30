#include "Flames.h"
#include "Grid.h"

Flames::Flames()
{
	LoadResources();

	//this->Active = true;

	width = FLAMES_SPRITE_WIDTH;
	height = FLAMES_SPRITE_HEIGHT;

	vy = -NINJA_GRAVITY;

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = vy;
	collider.width = FLAMES_SPRITE_WIDTH;
	collider.height = FLAMES_SPRITE_HEIGHT;
}
Flames* Flames::CreateFlames(float posx, float posy, float dt)
{
	Flames* flame = new Flames();
	flame->SetPositionX(posx);
	flame->SetPositionY(posy);
	flame->SetDt(dt);

	flame->collider.x = posx;
	flame->collider.y = posy;

	return flame;
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
	if (Viewport::GetInstance()->IsGameObjectInCamera(this) == true)
	{
		this->Active = true;
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		vector<Tile *> tiles = Grid::GetInstance()->GetCollisionTiles();

		this->SetSpeedY(this->GetSpeedY() - NINJA_GRAVITY);

		coEvents.clear();
		this->SetDt(dt);
		this->CalcPotentialCollisions(tiles, coEvents);

		if (coEvents.size() == 0)
		{
			float moveX = trunc(this->GetSpeedX()* dt);
			float moveY = trunc(this->GetSpeedY()* dt);

			this->SetPositionX(this->GetPositionX() + moveX);
			this->SetPositionY(this->GetPositionY() + moveY);
		}
		else
		{
			float min_tx, min_ty, nx = 0, ny;

			this->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
			float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

			this->SetPositionX(this->GetPositionX() + moveX);
			this->SetPositionY(this->GetPositionY() + moveY);

			if (nx != 0) this->SetSpeedX(0);
			if (ny != 0) this->SetSpeedY(0);
		}
		for (UINT i = 0; i < coEvents.size(); i++)
			delete coEvents[i];
	}
	else
	{
		this->Active = false;
		vy = 0;
	}
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
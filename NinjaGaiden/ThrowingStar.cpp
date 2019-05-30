#include "ThrowingStar.h"
#include "Grid.h"

ThrowingStar::ThrowingStar()
{
	LoadResources();

	Active = true;

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

void ThrowingStar::LoadResources()
{
	Animation * anim = new Animation(100);
	for (int i = 3; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_WIDTH;
		rect.right = rect.left + FLAMES_SPRITE_WIDTH ;
		rect.top = (i / FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_HEIGHT;
		rect.bottom = rect.top + FLAMES_SPRITE_HEIGHT + 2;
		Sprite * sprite = new Sprite(FLAMES_TEXTURE_LOCATION, rect, FLAMES_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}

	animations.push_back(anim);

}

void ThrowingStar::Update(DWORD dt)
{
	if (Viewport::GetInstance()->IsObjectInCamera(this) == true)
	{
		this->SetActive(true);
		vector<LPCOLLISIONEVENT> coEvents;
		vector<LPCOLLISIONEVENT> coEventsResult;

		vector<Tile *> tiles = Grid::GetInstance()->GetCollisionTiles();

		this->SetSpeedY(this->GetSpeedY() - NINJA_GRAVITY);

		coEvents.clear();
		this->SetDt(dt);
		this->CalcPotentialCollisions(tiles, coEvents);

		if (coEvents.size() == 0)
		{
			//float moveX = trunc(this->GetSpeedX()* dt);
			float moveY = trunc(this->GetSpeedY()* dt);

			//this->SetPositionX(this->GetPositionX() + moveX);
			this->SetPositionY(this->GetPositionY() + moveY);
		}
		else
		{
			float min_tx, min_ty, nx = 0, ny;

			this->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			float moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
			float moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

			//this->SetPositionX(this->GetPositionX() + moveX);
			this->SetPositionY(this->GetPositionY() + moveY);


			//if (nx != 0) this->SetSpeedX(0);
			if (ny != 0) this->SetSpeedY(0);
		}
		for (UINT i = 0; i < coEvents.size(); i++)
			delete coEvents[i];
	}
	else
	{
		this->SetActive(false);
		this->SetSpeedX(0);
	}
}

void ThrowingStar::Render()
{
	Animation * anim = new Animation(100);
	for (int i = 3; i < 4; i++)
	{
		RECT rect;
		rect.left = (i % FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_WIDTH;
		rect.right = rect.left + FLAMES_SPRITE_WIDTH + 4;
		rect.top = (i / FLAMES_TEXTURE_COLUMNS) * FLAMES_SPRITE_HEIGHT;
		rect.bottom = rect.top + FLAMES_SPRITE_HEIGHT + 2;
		Sprite * sprite = new Sprite(FLAMES_TEXTURE_LOCATION, rect, FLAMES_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}

	animations.push_back(anim);
}

ThrowingStar *  ThrowingStar::CreateThrowingStar(float posx, float posy, float dt)
{
	ThrowingStar * star = new ThrowingStar();
	star->Active = true;
	star->x = posx;
	star->y = posy;

	//float vx = Flames_SPEED * (isLeft == true ? -1 : 1);
	//this->vx = vx;
	//this->collider.vx = vx;

	star->collider.x = posx;
	star->collider.y = posy;
	star->dt = dt;

	return star;
}
ThrowingStar::~ThrowingStar()
{
}
#include "YellowSolider.h"
#include "YellowSoliderState.h"
#include "Grid.h"

vector<Animation *> YellowSolider::animations = vector<Animation *>();
YellowSolider::YellowSolider()
{
	__instance = NULL;
	LoadResources();

	idleState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_IDLE);
	walkingState = new YellowSoliderState(this, YELLOW_SOLIDER_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = -0.2f;
	this->SetPositionX(270);
	this->SetPositionY(60);

	collider.x = x;
	collider.y = y;
	collider.vx = 0;
	collider.vy = 0;
	collider.width = NINJA_SPRITE_WIDTH;
	collider.height = NINJA_SPRITE_HEIGHT;
}
void YellowSolider::LoadResources()
{
	// Enemy_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + YELLOW_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(YELLOW_SOLIDER_TEXTURE_LOCATION, rect, YELLOW_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NINJA_ANI_WALKING
	anim = new Animation(250);
	for (int i = 0; i < 3; i++)
	{
		RECT rect;
		rect.left = (i % YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.right = rect.left + YELLOW_SOLIDER_SPRITE_WIDTH;
		rect.top = (i / YELLOW_SOLIDER_TEXTURE_COLUMNS) * YELLOW_SOLIDER_SPRITE_HEIGHT;
		rect.bottom = rect.top + YELLOW_SOLIDER_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(YELLOW_SOLIDER_TEXTURE_LOCATION, rect, YELLOW_SOLIDER_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void YellowSolider::Idle()
{
	state->Idle();
}
void YellowSolider::Walk()
{
	state->Walk();
}
//Hàm cập nhật
void YellowSolider::Update(DWORD dt)
{
	state->Update(dt);
	this->SetPositionX((float)(this->GetPositionX() + this->GetSpeedX()* dt));
	if (this->GetSpeedX() < 0 && this->GetPositionX() <= 0)
	{
		this->TurnRight();
	}

	vector<LPGAMEOBJECT> coObjects; //Placeholder
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	vector<Tile *> tiles = Grid::GetInstance()->GetCurTiles();

	this->SetSpeedY(this->GetSpeedY() - NINJA_GRAVITY);

	coEvents.clear();
	this->SetDt(dt);
	this->CalcPotentialCollisions(tiles, coObjects, coEvents);


	if (coEvents.size() == 0)
	{
		int moveX = trunc(this->GetSpeedX()* dt);
		int moveY = trunc(this->GetSpeedY()* dt);

		this->SetPositionX(this->GetPositionX() + moveX);
		this->SetPositionY(this->GetPositionY() + moveY);

	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		this->FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		int moveX = min_tx * this->GetSpeedX() * dt + nx * 0.4;
		int moveY = min_ty * this->GetSpeedY() * dt + ny * 0.4;

		this->SetPositionX((int)(this->GetPositionX() + moveX));
		this->SetPositionY((int)(this->GetPositionY() + moveY));


		if (nx != 0) this->SetSpeedX(0);
		if (ny != 0) this->SetSpeedY(0);

		if (coEventsResult[0]->collisionID == 1)
		{
			if (ny == 1)
			{
				this->SetIsGrounded(true);
			}
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++)
		delete coEvents[i];


}
//Hàm render
void YellowSolider::Render()
{
	state->Render();
}
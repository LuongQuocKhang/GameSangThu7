#include "Boss.h"
#include "BossState.h"

Boss::Boss()
{
	LoadResources();

	idleState = new BossState(this, BOSS_ANI_IDLE);
	walkingState = new BossState(this, BOSS_ANI_WALKING);
	state = walkingState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(270);
	this->SetPositionY(80);

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = BOSS_SPRITE_WIDTH;
	collider.height = BOSS_SPRITE_HEIGHT;

	stamina = 100;

	Type = EnemyType::BOSS;
}
Boss::Boss(float posx, float posy)
{
	LoadResources();

	idleState = new BossState(this, BOSS_ANI_IDLE);
	walkingState = new BossState(this, BOSS_ANI_WALKING);
	state = idleState;

	this->isLeft = true;
	this->vx = 0.0f;
	this->SetPositionX(posx);
	this->SetPositionY(posy);

	width = BOSS_SPRITE_WIDTH;
	height = BOSS_SPRITE_HEIGHT;

	collider.x = x;
	collider.y = y;
	collider.vx = vx;
	collider.vy = vy;
	collider.width = BOSS_SPRITE_WIDTH;
	collider.height = BOSS_SPRITE_HEIGHT;

	Type = EnemyType::BOSS;

	stamina = 100;
	count = 0;
}
void Boss::LoadResources()
{
	// BOSS_ANI_IDLE
	Animation * anim = new Animation(100);
	for (int i = 0; i < 1; i++)
	{
		RECT rect;
		rect.left = (i % BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_WIDTH;
		rect.right = rect.left + BOSS_SPRITE_WIDTH;
		rect.top = (i / BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_HEIGHT;
		rect.bottom = rect.top + BOSS_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BOSS_TEXTURE_LOCATION, rect, BOSS_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
	// NOSS_ANI_WALKING
	anim = new Animation(200);
	for (int i = 1; i < 2; i++)
	{
		RECT rect;
		rect.left = (i % BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_WIDTH;
		rect.right = rect.left + BOSS_SPRITE_WIDTH;
		rect.top = (i / BOSS_TEXTURE_COLUMNS) * BOSS_SPRITE_HEIGHT;
		rect.bottom = rect.top + BOSS_SPRITE_HEIGHT;
		Sprite * sprite = new Sprite(BOSS_TEXTURE_LOCATION, rect, BOSS_TEXTURE_TRANS_COLOR);

		anim->AddFrame(sprite);
	}
	this->animations.push_back(anim);
}

void Boss::Idle()
{
	state->Idle();
}
void Boss::Walk()
{
	state->Walk();
}
//H�m c?p nh?t
void Boss::Update(DWORD dt)
{
	state->Update(dt);
	if (checkloc)
	{
		count += dt;
		if (count >= 2000)
		{
			this->SetState(walkingState);
			this->isLeft = true;
			this->SetPositionX((int)(this->GetPositionX() + -0.1*dt));
			float locx = this->GetPositionX();
			float y = (((double)-4 / 1445) * pow(this->GetPositionX(), 2) + this->GetPositionX()* ((double)16 / 17) + 80);
			this->SetPositionY(y);

			if (locx < 2)
			{	
				checkloc = false;
				count = 0;
			}
		}
		else
		{
			this->SetState(idleState);
			this->SetPositionX(340);
			this->SetPositionY(80);
			//this->isLeft = true;
		}
	}
	else
	{
		count += dt;
		if (count >= 2000)
		{
			this->SetState(walkingState);
			this->isLeft = false;
			this->SetPositionX((int)(this->GetPositionX() + 0.15*dt));
			float locx = this->GetPositionX();
			float y = (((double)-4 / 1445) * pow(this->GetPositionX(), 2) + this->GetPositionX()* ((double)16 / 17) + 80);
			this->SetPositionY(y);
			if (locx > 330)
			{
				checkloc = true;
				count = 0;
			}
		}
		else
		{
			this->SetState(idleState);
			this->SetPositionX(30);
			this->SetPositionY(80);
			//this->isLeft = false;
		}	
	}
}
//H�m render
void Boss::Render()
{
	state->Render();
}
#pragma once
#include "Bullet.h"
#include  "Enemy.h"

class GreenCannonSoldierBullet :
	public Bullet
{
	Enemy* enemy;
public:
	GreenCannonSoldierBullet(Enemy* enemy );
	void LoadResources();
	void Update(DWORD dt) override;
	void Render() override;

	void Reset() override;

	~GreenCannonSoldierBullet();
};


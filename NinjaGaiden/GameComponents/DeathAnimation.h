#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Enemy;
class DeathAnimation :
	public GameObject
{
private :
	vector<Animation *> animations;

	void LoadResources();

	bool Active;
	EnemyType enemytype;

	int time;
public:
	DeathAnimation(EnemyType enemytype);
	~DeathAnimation();

	static DeathAnimation* CreateDeateAnimation(Enemy* gameobject);
	void Update(DWORD dt) override;
	void Render() override;

	bool IsActive() { return this->Active; }
	void SetActive(bool value) { this->Active = value; }
};


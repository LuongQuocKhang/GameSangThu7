#pragma once
#include "GameObject.h"

class Sword : public GameObject
{
private :

	Sword();
	static Sword * __instance;

public:
	static Sword * GetInstance();
	void SetPosition(int posx, int posy , float dt)
	{
		this->x = posx;
		this->y = posy;
		collider.x = posx;
		collider.y = posy;
		this->dt = dt;
	}

	~Sword();
};


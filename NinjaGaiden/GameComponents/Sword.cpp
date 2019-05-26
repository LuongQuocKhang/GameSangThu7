#include "Sword.h"

Sword * Sword::__instance = NULL;
Sword::Sword()
{
	width = NINJA_SPRITE_WIDTH + 10;
	height = NINJA_SPRITE_HEIGHT - 20;

	vy = 0;
}


Sword * Sword::GetInstance()
{
	if (__instance == NULL)
	{
		__instance = new Sword();
	}
	return __instance;
}

Sword::~Sword()
{
}

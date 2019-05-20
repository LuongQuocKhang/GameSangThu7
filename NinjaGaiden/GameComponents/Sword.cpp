#include "Sword.h"

Sword * Sword::__instance = NULL;
Sword::Sword()
{
	width = NINJA_SPRITE_WIDTH;
	height = NINJA_SPRITE_HEIGHT / 2;
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

#pragma once

#include "Hero.h"
#include "Block.h"


class toxicMush : public Block
{
public:
	toxicMush();
	~toxicMush();

	//check the collision between toxicmush and hero
	void collideHero(Hero* hero);
};
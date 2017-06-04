#pragma once
#include "Hero.h"
#include "Block.h"

class fakePrincess : public Block
{
public:
	fakePrincess();
	~fakePrincess();
	void collideHero(Hero* myHero);
};
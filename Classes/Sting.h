#pragma once
#include "Block.h"

class Sting :public Block
{
public:
	Sting();
	~Sting();
	void collideHero(Hero* hero);
};
#pragma once

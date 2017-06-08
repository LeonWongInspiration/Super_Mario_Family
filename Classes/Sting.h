#pragma once
#include "Block.h"

class Sting :public Block
{
public:
	Sting();
	~Sting();

	///check if blocks coliiide hero
	virtual void collideHero(Hero* hero) override;
};
#pragma once

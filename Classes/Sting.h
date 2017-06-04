#pragma once
#include "Block.h"
#include "Hero.h"

class Sting :public Block
{
public:
	Sting();
	~Sting();
	void collideHero(Hero* hero) override;
};
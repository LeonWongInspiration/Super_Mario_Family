#pragma once
#include "Block.h"
using namespace std;

class Cloud : public Block
{
public:
	bool show;
	Cloud();
	~Cloud();

	///check the collision between cloud and hero
	void collideHero(Hero* hero);
};

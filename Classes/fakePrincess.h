#pragma once
#include "Hero.h"
#include "Block.h"

class fakePrincess : public Block
{
public:
	fakePrincess(const char* fileName,float x,float y);
	~fakePrincess();

	///set the event of collision between fakeprincess and hero
	void killMario(Hero* hero);
private:
	float width = 32;
	float height = 64;
};
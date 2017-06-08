#pragma once
#include "Hero.h"
#include "Block.h"

class FakePrincess : public Block
{
public:
	FakePrincess(const char* fileName,float x,float y);
	~FakePrincess();

	///set the event of collision between fakeprincess and hero
	void killMario(Hero* hero);
private:
	float width = 32;
	float height = 64;
};
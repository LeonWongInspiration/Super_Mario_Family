#pragma once
#include "Block.h"
using namespace std;

class Cloud : public Block
{
public:
	Cloud(const char* filename,float x,float y);
	~Cloud();

	///set the event of collision between cloud and hero
	void killMario(Hero* hero);

private:
	PhysicsBody * body;
	float width=128;
	float height=64;
};

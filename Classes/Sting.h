#pragma once
#include "Block.h"

class Sting :public Block
{
public:
	Sting(const char* fileName,float x,float y);
	~Sting();

private:
	PhysicsBody * body;
	float width = 32;
	float height = 32;
};
#pragma once

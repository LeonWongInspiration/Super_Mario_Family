#pragma once
#include "Block.h"
using namespace std;

class Cloud : public Block
{
public:
	Cloud(const char* filename,float x,float y);
	~Cloud();


private:
	PhysicsBody * body;
	float width=128;
	float height=64;
};

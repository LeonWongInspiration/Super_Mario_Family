#pragma once
#include "Hero.h"
#include "Block.h"

class FakePrincess : public Block
{
public:
	FakePrincess(const char* fileName,float x,float y);
	~FakePrincess();

private:
	PhysicsBody* body;
	float width = 32;
	float height = 64;
};
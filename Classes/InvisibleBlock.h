#pragma once
#include "Hero.h"
#include "cocos2d.h"

using namespace cocos2d;

class InvisibleBlock
{
private:
	Sprite* nowsprite;
	PhysicsBody* body;
	float width;
	float height;

public:
	InvisibleBlock(float x,float y);
	~InvisibleBlock(){};

	Sprite* getSprite() { return nowsprite; }
	PhysicsBody* getBody() { return body; }
	void collideHero(Hero* hero);
};
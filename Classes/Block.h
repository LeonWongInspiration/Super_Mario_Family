#pragma once
#include "Hero.h"
#include "Utility.h"

using namespace cocos2d;

struct setRect
{
	int left;
	int right;
	int top;
	int bottom;
};

bool rectIntersect(setRect* rect1, setRect* rect2);
bool pointInrect(setRect* rect1, int rect2x, int rect2y);

class Block
{
public:
	Block(const char* fileName,float x,float y);
	~Block();
	Sprite* nowSprite;
	//check the collision
	virtual bool collideHero(Hero* hero,float width,float height);
};
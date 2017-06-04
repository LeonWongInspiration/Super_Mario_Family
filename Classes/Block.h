#pragma once
#include "Hero.h"
#include "cocos2d.h"

using namespace std;
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
	int blockHeight, blockWidth;
	Block();
	~Block();
	Sprite* nowSprite;
	//check the collision
	virtual void collideHero(Hero* hero);
};
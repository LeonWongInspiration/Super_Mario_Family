#pragma once
#include "Hero.h"
#include "Utility.h"

USING_NS_CC;

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
private:
	Sprite* nowSprite;
public:
	
	Sprite* getSprite()
	{
		return nowSprite;
	}

	void changeSprite()
	{
		nowSprite = Sprite::create("Block//hurtfulCloud.png");
		this->getSprite()->setScaleX(0.15f);
		this->getSprite()->setScaleY(0.11f);
	}

	Block(const char * fileName,float x,float y);
	~Block();
	
	//check the collision
	bool collideHero(Hero* hero,float width,float height);
};
#pragma once
#include "Hero.h"
#include "Utility.h"

USING_NS_CC;


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
		nowSprite->setTexture("Block//hurtfulCloud.png");
	}

	Block(const char * fileName,float x,float y);
	~Block();
	
};
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
		nowSprite = Sprite::create("Block//hurtfulCloud.png");
		this->getSprite()->setScaleX(0.15);
		this->getSprite()->setScaleY(0.11);
	}

	Block(const char * fileName,float x,float y);
	~Block();
	
};
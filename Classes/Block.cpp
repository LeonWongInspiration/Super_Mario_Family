#include "Block.h"

Block::Block(const char * fileName,float x,float y)
{
	nowSprite = Sprite::create(fileName);
	nowSprite->setPositionX(x);
	nowSprite->setPositionY(y);
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
}

Block::~Block()
{
}






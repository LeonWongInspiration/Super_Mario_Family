#include "InvisibleBlock.h"

InvisibleBlock::InvisibleBlock(float x,float y)
{
	//cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(frameName);
	//nowsprite = cocos2d::Sprite::createWithSpriteFrameName(filename);
	nowsprite->setPositionX(x);
	nowsprite->setPositionY(y);
	nowsprite->setAnchorPoint(cocos2d::Point(0, 0));
	nowsprite->setScale(0.125, 0.125);
	nowsprite->setVisible(false);
	width = nowsprite->getContentSize().width;
	height = nowsprite->getContentSize().height;
	
}

InvisibleBlock::~InvisibleBlock(){}

void InvisibleBlock::collideHero(Hero* hero)
{
	if (hero->getSprite()->getPosition().x >= nowsprite->getPosition().x + 0.1*width
		&& hero->getSprite()->getPosition().x <= nowsprite->getPosition().x - 0.1*width
		&& hero->getSprite()->getPosition().y < nowsprite->getPosition().y)
	{
		nowsprite->setVisible(true);
		body = cocos2d::PhysicsBody::createBox(getSprite()->getContentSize());

		body->setRotationEnable(false);

		this->getSprite()->setPhysicsBody(body);
		this->getSprite()->getPhysicsBody()->setContactTestBitmask(0xFFFF);
	}
}
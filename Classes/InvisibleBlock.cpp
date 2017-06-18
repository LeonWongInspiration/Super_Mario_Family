#include "InvisibleBlock.h"

InvisibleBlock::InvisibleBlock(Sprite * sprite):nowsprite(sprite),added(false)
{
	//cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(frameName);
	//nowsprite = cocos2d::Sprite::createWithSpriteFrameName(filename);
    width = nowsprite->getContentSize().width;
    
    height = nowsprite->getContentSize().height;
    
    nowsprite->setVisible(false);
	
}



void InvisibleBlock::collideHero(Vec2 & hero)
{
    if(added)
    {
        return;
    }
	if (hero.x <= nowsprite->getPosition().x + 0.1*width
		&& hero.x >= nowsprite->getPosition().x - 0.1*width
		&& hero.y < nowsprite->getPosition().y-40)
	{
		
		body = cocos2d::PhysicsBody::createBox(getSprite()->getContentSize());

		body->setRotationEnable(false);
        body->setDynamic(false);
        body->getShape(0)->setFriction(0.5f);
        body->getShape(0)->setRestitution(0.0f);

		this->getSprite()->setPhysicsBody(body);
		this->getSprite()->getPhysicsBody()->setContactTestBitmask(SpriteBitmask::hidden);
        added = true;
	}
}

void InvisibleBlock::show()
{
    nowsprite->setVisible(true);
}

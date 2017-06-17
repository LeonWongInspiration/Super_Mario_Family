//
//  Koopa.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/4.
//
//

#include "Koopa.hpp"

Koopa::Koopa(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,KOOPA),count(0),flag(false)
{
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    auto animation = cocos2d::Animation::create();
    animation->addSpriteFrameWithFile("Koopa_256.png");
    animation->addSpriteFrameWithFile("Koopa_Run_256.png");
    animation->setDelayPerUnit(5.0f/20);
    animation->setRestoreOriginalFrame(true);
    moveAcition = cocos2d::Animate::create(animation);
    this->getBody()->setCollisionBitmask(SpriteBitmask::koopa);
    setMoveSpeed(30.0f);
    getSprite()->runAction(moveAcition);
}

void Koopa::action(float x)
{
    if(getSprite()->getPositionX() - x < 800)
    {
        if(!getTrigger())
        {
            setTrigger();
        }
    }
    if(x - getSprite()->getPositionX() > 500)
    {
        getSprite()->setPositionY(-10);
    }
    
    if(count == 1)
    {
        
        
        
        if(!flag)
        {
            flag = true;
            
            replacePic();
            this->setMoveSpeed(60.0f);
            this->getSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(getMoveSpeed(),0));
            this->getSprite()->getPhysicsBody()->setDynamic(true);
            
        }
    }
    
    this->update();
}



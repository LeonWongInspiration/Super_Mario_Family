//
//  FallBricks.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "FallBricks.hpp"

FallBricks::FallBricks(int x,int y,int i):trigger(false),fallSpeed(200.0f),outScene(false)
{
    std::string fallName;
    CCLOG("i: %d",i);
    if(Hero::getLevelState() == 1)
    {
        fallName = "Level1Falling1.png";
    }
    else
    {
        if(i == 1)
        {
            fallName = "Level2Falling1.png";
        }
        else
        {
            fallName = "Level2Falling2.png";
        }
    }
    sprite = cocos2d::Sprite::create(fallName);
    width = sprite->getContentSize().width;
    height = sprite->getContentSize().height;
    sprite->setAnchorPoint(cocos2d::Point(0,0));
    sprite->setPositionX(x);
    sprite->setPositionY(y);
    
    body = cocos2d::PhysicsBody::createBox(this->getSprite()->getContentSize());
    this->getSprite()->setPhysicsBody(body);
    this->getSprite()->getPhysicsBody()->setDynamic(false);
    
    this->getSprite()->getPhysicsBody()->setContactTestBitmask(0xFFFF);
    
    this->getSprite()->getPhysicsBody()->setCollisionBitmask(SpriteBitmask::fallingBricks);
    
    
    
    
    
}

void FallBricks::fall(float x)
{
    if(!trigger)
    {
        return;
    }
    CCLOG("fall!!!");    //here need to be adjusted when the map's position is changed
    
    sprite->getPhysicsBody()->setDynamic(true);
    sprite->getPhysicsBody()->setVelocity(cocos2d::Vec2(0,-fallSpeed));
    if(sprite->getPositionY() < -100 || sprite->getPositionX() - x < -600)
    {
        outScene = true;
    }
    
    
}

void FallBricks::isAbove(float x,float y)
{
    auto spriteX = sprite->getPositionX();
    auto spriteY = sprite->getPositionY();
    if(x >= spriteX&&x <= spriteX + width)
    {
        trigger = true;
        if(y > spriteY)
        {
            above = true;
        }
        else
        {
            above = false;
        }
    }
    
}

void FallBricks::run(float x)
{
    if(x - getSprite()->getPositionX()  > -5 && x - getSprite()->getPositionX() <= 96)
    {
        if(!trigger)
        {
            trigger = true;
            getSprite()->getPhysicsBody()->setDynamic(true);
        }
    }
    if(!trigger)
    {
        return;
    }
    fall(x);
}

//
//  FallBricks.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "FallBricks.hpp"

FallBricks::FallBricks(int x,int y):trigger(false),fallSpeed(200.0f),outScene(false)
{
    sprite = cocos2d::Sprite::create("Level1Falling1.png");
    width = sprite->getContentSize().width;
    height = sprite->getContentSize().height;
    sprite->setAnchorPoint(cocos2d::Point(0,0));
    sprite->setPositionX(x);
    sprite->setPositionY(y);
    
    body = cocos2d::PhysicsBody::createBox(this->getSprite()->getContentSize());
    this->getSprite()->setPhysicsBody(body);
    this->getSprite()->getPhysicsBody()->setDynamic(false);
    
    this->getSprite()->getPhysicsBody()->setCollisionBitmask(0xFFFF);
    
    
    
    
    
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

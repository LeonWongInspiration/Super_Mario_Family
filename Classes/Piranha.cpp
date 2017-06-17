//
//  Piranha.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "Piranha.hpp"


Piranha::Piranha(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,Enemy::PIRANHA),upCount(0),upSpeed(40.0f)
{
    getBody()->setCollisionBitmask(SpriteBitmask::piranha);
};
void Piranha::up(float heroPositionX)
{
    if(isAbove(heroPositionX))
    {
        if(!getTrigger())
        {
            setTrigger();
        }
        ++upCount;
    }
    if(heroPositionX - getSprite()->getPositionX() > 100)
    {
        if(!getTrigger())
        {
            setTrigger();
        }
        ++upCount;
    }
    
    if(!this->getTrigger()||upCount <= 30)
    {
        return;
    }
    this->getSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0,upSpeed));
    
}

bool Piranha::isAbove(float x)
{
    if(x - getSprite()->getPositionX() < 32&&x - getSprite()->getPositionX()  > -32)
        return true;
    else
        return false;
}



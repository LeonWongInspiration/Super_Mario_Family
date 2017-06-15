//
//  Piranha.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "Piranha.hpp"


Piranha::Piranha(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,Enemy::PIRANHA),upCount(0),upSpeed(0.5f)
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
    if(!this->getTrigger()&&upCount >= 100)
    {
        return;
    }
    this->getSprite()->setPositionY(getSprite()->getPositionY() + upSpeed);
        
}

bool Piranha::isAbove(float x)
{
    if(x > getSprite()->getPositionX() - 32&&x < getSprite()->getPositionX() + 32)
        return true;
    else
        return false;
}

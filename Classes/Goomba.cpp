//
//  Goomba.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "Goomba.hpp"
Goomba::Goomba(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,Enemy::GOOMBA)
{
    this->getBody()->setCollisionBitmask(SpriteBitmask::goomba);
}

void Goomba::run(float x)
{
    if(getSprite()->getPositionX() - x <500)
    {
        this->setTrigger();
        
    }
    if(x - getSprite()->getPositionX() > 500)
    {
        this->getSprite()->setPositionY(-10);
    }
    this->update();
}

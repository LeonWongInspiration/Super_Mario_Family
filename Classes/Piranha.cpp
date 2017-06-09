//
//  Piranha.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "Piranha.hpp"


Piranha::Piranha(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,Enemy::PIRANHA),upCount(0),upSpeed(2.0f)
{
    
};

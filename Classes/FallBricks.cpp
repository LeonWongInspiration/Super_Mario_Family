//
//  FallBricks.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#include "FallBricks.hpp"

FallBricks::FallBricks(int x,int y):trigger(false),fallSpeed(1.0f)
{
    sprite = cocos2d::Sprite::create("1.png");
    width = sprite->getContentSize().width;
    height = sprite->getContentSize().height;
}

void FallBricks::fall()
{
    if(!trigger)
    {
        return;
    }
    
    //here need to be adjusted when the map's position is changed
    
    sprite->setPositionY(sprite->getPositionY() - fallSpeed);
    
    
    
}

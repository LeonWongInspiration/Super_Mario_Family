//
//  Koopa.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/4.
//
//

#include "Koopa.hpp"

Koopa::Koopa(const char * frameName,const char * fileName,int x,int y):Enemy(frameName,fileName,x,y,KOOPA),count(2)
{
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    auto animation = cocos2d::Animation::create();
    animation->addSpriteFrameWithFile("Koopa_256.png");
    animation->addSpriteFrameWithFile("Koopa_Run_256.png");
    moveAcition = cocos2d::Animate::create(animation);
}

void Koopa::action()
{
    if(trigger)
    {
        sprite->runAction(moveAcition);
    }
}

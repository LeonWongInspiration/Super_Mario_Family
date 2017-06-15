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
    
    getSprite()->runAction(moveAcition);
}

void Koopa::action(cocos2d::TMXTiledMap * tmxmap)
{
    if(getTrigger()&&!flag)
    {
        flag = true;
    }
    if(count == 1)
    {
        
        
        
        if(!this->dead())
        {
            
            replacePic();
            this->setMoveSpeed(getMoveSpeed()*2);
            this->getSprite()->setPhysicsBody(this->getBody());
            
        }
    }
    this->update(tmxmap);
}



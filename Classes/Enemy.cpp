//
//  Enemy.cpp
//  SuperMarioFamily
//
//  Created by 梁永潮 on 2017/5/30.
//
//

#include "Enemy.hpp"
Enemy::Enemy(const char * filename,int x,int y,KIND monsterKind)
:
kind(monsterKind),
moveSpeed(1.0f),
jumpSpeed(3.0f),
fallSpeed(3.0f),
isDead(false),
normalSpeed(true),
isDeleted(false),
trigger(false),
fall(false),
setEnemyX(0),
setEnemyY(0),
moveTime(0),
dir(LEFT)
{
    sprite = cocos2d::Sprite::create(filename);
    sprite->setPositionX(x);
    sprite->setPositionY(y);
    sprite->setAnchorPoint(cocos2d::Point(0,0));
    width = sprite->getContentSize().width;
    height = sprite->getContentSize().height;
}

bool Enemy::move(cocos2d::TMXTiledMap * tmxmap)
{
    if(moveTime < 1)
    {
        moveTime++;
        return false;
    }
    else
    {
        moveTime = 0;
    }
    //here need a map to finish some codes(such as judge the bricks)
    
    if(dir == LEFT)
    {
        sprite-> setPositionX(sprite->getPositionX() - moveSpeed);
    }
    else
        if(dir == RIGHT)
        {
            sprite-> setPositionX(sprite->getPositionX() + moveSpeed);
        }
    return true;
}

bool Enemy::gravity(cocos2d::TMXTiledMap *tmxmap)
{
    
}

void Enemy::update(cocos2d::TMXTiledMap *tmxmap)
{
    if(sprite->getPositionY() - sprite->getContentSize().height/2 < 0)
    {
        isDeleted = true;
        return;
    }
    if(!trigger)
    {
        return;
    }
    move(tmxmap);
    gravity(tmxmap);
    
    bool picdir = dir==RIGHT?true:false;
    sprite->setFlippedX(picdir);
    
}



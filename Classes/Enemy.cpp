//
//  Enemy.cpp
//  SuperMarioFamily
//
//  Created by 梁永潮 on 2017/5/30.
//
//

#include "Enemy.hpp"
Enemy::Enemy(const char* frameName,const char * filename,int x,int y,KIND monsterKind)
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
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(frameName);
    sprite = cocos2d::Sprite::createWithSpriteFrameName(filename);
    sprite->setPositionX(x);
    sprite->setPositionY(y);
    sprite->setAnchorPoint(cocos2d::Point(0,0));
    sprite->setScale(0.125, 0.125);
    width = sprite->getContentSize().width;
    height = sprite->getContentSize().height;
}

bool Enemy::move(cocos2d::TMXTiledMap * tmxmap)
{
    int x = sprite->getPositionX();
    int y = sprite->getPositionY();
    int mapWidth = tmxmap->getMapSize().width;
    int mapHeight = tmxmap->getMapSize().height;
    if(moveTime < 1)
    {
        moveTime++;
        return false;
    }
    else
    {
        moveTime = 0;
    }
    if(x>=mapWidth)
    {
        tmxmap->setPositionX(tmxmap->getPositionX()-1);
        return true;
    }
 /*   if(x<10||x>mapWidth - 10)
    {
        dir = (dir == LEFT)?RIGHT:LEFT;
    }*/
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
    return true;
}

void Enemy::update(cocos2d::TMXTiledMap *tmxmap)
{
    if(sprite->getPositionY()  < 0)
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

void Enemy::judge(cocos2d::TMXTiledMap* tmxmap,float x, float y)
{
    auto spriteX = sprite->getPositionX();
    
    auto spriteY = sprite->getPositionY();
    
    auto mapSize = tmxmap->getMapSize().width;
    
    if(spriteX - x < mapSize/2)
    {
        trigger = true;
    }
}



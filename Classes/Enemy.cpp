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
moveSpeed(60.0f),
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
deathCount(0),
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
    body = cocos2d::PhysicsBody::createBox(getSprite()->getContentSize());
    
    body->setRotationEnable(false);
    
    
    this->getSprite()->setPhysicsBody(body);
    this->getSprite()->getPhysicsBody()->setContactTestBitmask(0xFFFF);
}

bool Enemy::move()
{
    
    
    
    if(getBody()->getVelocity().x < 50)
    {
        dir = dir == LEFT?RIGHT:LEFT;
    }
    
    
    
    
    //here need a map to finish some codes(such as judge the bricks)
    
    if(dir == LEFT)
    {
        getBody()->setVelocity(cocos2d::Vec2(-moveSpeed,0));
    }
    else
        if(dir == RIGHT)
        {
            getBody()->setVelocity(cocos2d::Vec2(moveSpeed,0));
        }
    return true;
}



void Enemy::update()
{
    if(dead()&&kind!=KOOPA)
    {
        deathCount++;
    }
    if(isDead&&!isDeleted&&deathCount >= 120)
    {
        getSprite()->removeFromParent();
        isDeleted = true;
        return;
    }
    
    
    if(sprite->getPositionY()  < 0)
    {
        dead(true);
        deathCount = 120;
        
    }
    if(!trigger)
    {
        return;
    }
    move();
        
    bool picdir = dir==RIGHT?true:false;
    sprite->setFlippedX(picdir);
    
}



void Enemy::dead(bool isDead)
{
    if(!dead())
    {
        this->isDead = isDead;
        replacePic();
        if(kind!=KOOPA)
        {
            trigger = false;
        }
        
    }
}

void Enemy::replacePic()
{
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    std::string enemyName;
    switch (kind) {
        case GOOMBA:
            enemyName = "Goomba_dead_256.png";
            break;
        case KOOPA:
            enemyName = "Koopa_dead_256.png";
        default:
            break;
    }
    auto frame = cocos2d::SpriteFrameCache::getInstance()->spriteFrameByName(enemyName);
    getSprite()->setDisplayFrame(frame);
    
}



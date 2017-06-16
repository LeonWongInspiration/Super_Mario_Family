//
//  Hero.cpp
//  SuperMarioFamily
//
//  Created by Leon Wong on 4/6月.
//
//

#include "Hero.h"

int Hero::lifeCount = 2;

Hero::Hero(std::map<cocos2d::EventKeyboard::KeyCode, bool>* _KeyCode):
heroState(STAND),
keyCode(_KeyCode){
    this->heroSpriteSheet = SpriteFrameCache::getInstance();
    this->heroSpriteSheet->addSpriteFramesWithFile("Mario_256.plist", "Mario_256.png");
    
    this->standFrame = this->heroSpriteSheet->getSpriteFrameByName("Mario_Stand.png");
    this->runFrame = this->heroSpriteSheet->getSpriteFrameByName("Mario_Run.png");
    this->deathFrame = this->heroSpriteSheet->getSpriteFrameByName("Mario_dead.png");
    
    // CCASSERT(this->standFrame != nullptr, "Fuck!");
    // CCASSERT(this->runFrame != nullptr, "Fuck!");
    
    this->heroSprite = Sprite::createWithSpriteFrameName("Mario_Stand.png");
    this->heroSprite->setScale(0.125);
    
    this->heroBody = PhysicsBody::createBox(this->heroSprite->getContentSize());
    this->heroBody->setRotationEnable(false);
    
    this->heroSprite->setPhysicsBody(this->heroBody);
    this->heroBody->setCollisionBitmask(SpriteBitmask::hero);
    this->heroBody->setContactTestBitmask(0xFFFF);
}

Hero::~Hero(){
}

void Hero::jump(){
    if (abs(this->heroBody->getVelocity().y) <= 0.0001f){
        this->heroBody->applyImpulse(Vec2(0, 20000));
        this->heroSprite->setDisplayFrame(this->runFrame);
    }
}

void Hero::moveRight(){
    this->heroSprite->setFlippedX(false);
    
    ++(this->runningSprite);
    if (!this->jumping && this->runningSprite >= 10){
        this->heroSprite->setDisplayFrame(this->runningFrame ? this->standFrame : this->runFrame);
        this->runningFrame = ! (this->runningFrame);
        this->runningSprite = 0;
    }
    
    const Vec2& currentVelocity = this->heroBody->getVelocity();
    if (currentVelocity.x <= this->maxXVelocity){
        this->heroBody->setVelocity(Vec2(currentVelocity.x + 8, currentVelocity.y));
    }
}

void Hero::moveLeft(){
    this->heroSprite->setFlippedX(true);
    
    ++(this->runningSprite);
    if (!this->jumping && this->runningSprite >= 10){
        this->heroSprite->setDisplayFrame(this->runningFrame ? this->standFrame : this->runFrame);
        this->runningFrame = ! (this->runningFrame);
        this->runningSprite = 0;
    }
    
    const Vec2& currentVelocity = this->heroBody->getVelocity();
    if (-currentVelocity.x <= this->maxXVelocity){
        this->heroBody->setVelocity(Vec2(currentVelocity.x - 8, currentVelocity.y));
    }
}

bool Hero::isGoing(const Direction& dir){
    switch (dir){
    case Direction::UP:
        return (*keyCode)[EventKeyboard::KeyCode::KEY_UP_ARROW];
        
    case Direction::LEFT:
        return (*keyCode)[EventKeyboard::KeyCode::KEY_LEFT_ARROW];
        
    case Direction::RIGHT:
        return (*keyCode)[EventKeyboard::KeyCode::KEY_RIGHT_ARROW];
        
    }
}

void Hero::checkDeath(){
    if (!this->dead && this->heroBody->getContactTestBitmask() == 0x0000){
        this->heroSprite->setDisplayFrame(this->deathFrame);
        this->heroBody->setVelocity(Vec2(0, this->heroBody->getVelocity().y));
        this->heroBody->applyImpulse(Vec2(0, 20000));
        this->heroBody->setCategoryBitmask(0x0000);
        this->dead = true;
    }
}

void Hero::run(){
    if (!this->dead){
        if (isGoing(Direction::UP)){
            jump();
            this->jumping = true;

        }
        else {
            this->jumping = false;
        }
        if (isGoing(Direction::LEFT))
            moveLeft();
        if (isGoing(Direction::RIGHT))
            moveRight();
    }
    this->checkDeath();
    //if (isHindered(DOWN)){
    //    this->heroBody->setVelocity(Vec2(this->heroBody->getVelocity().x, 0));
    //}
}

void Hero::collideEnemy(bool enemyCanBeSteppedOn, Sprite* enemyCollided){
    if (enemyCanBeSteppedOn && this->heroSprite->getPosition().x >=
        enemyCollided->getPosition().x + 0.1 * enemyCollided->getContentSize().width
        && this->heroSprite->getPosition().x <=
        enemyCollided->getPosition().x - 0.1 * enemyCollided->getContentSize().width){
        CCLOG("Enemy DIED");
        //TODO remove Enemy
        //TODO music
    }
    else {
        CCLOG("Hero DIED");
        //TODO music
        //this->death(0);
    }
}

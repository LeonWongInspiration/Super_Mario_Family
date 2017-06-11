//
//  Hero.cpp
//  SuperMarioFamily
//
//  Created by Leon Wong on 4/6月.
//
//

#include "Hero.h"

int Hero::lifeCount = 2;

Hero::Hero(std::map<cocos2d::EventKeyboard::KeyCode, bool> _KeyCode):
heroState(STAND),
keyCode(_KeyCode){
    this->heroSpriteSheet = SpriteFrameCache::getInstance();
    this->heroSpriteSheet->addSpriteFramesWithFile("Mario_256.plist", "Mario_256.png");
    this->heroSprite = Sprite::createWithSpriteFrameName("Mario_Stand.png");
    this->heroSprite->setScale(0.125);
    
    this->heroBody = PhysicsBody::createBox(this->heroSprite->getContentSize());
    
    this->heroSprite->setPhysicsBody(this->heroBody);
    this->heroBody->setCollisionBitmask(SpriteBitmask::hero);
}

Hero::~Hero(){
    CC_SAFE_DELETE(this->heroSprite);
    CC_SAFE_DELETE(this->heroBody);
}

void Hero::jump(){
    if (this->heroBody->getVelocity().y == 0){
        this->heroBody->applyImpulse(Vec2(0, 9800));
    }
}

void Hero::moveRight(){
    this->heroSprite->setFlippedX(false);
    const Vec2& currentVelocity = this->heroBody->getVelocity();
    if (currentVelocity.x <= this->maxXVelocity){
        this->heroBody->setVelocity(Vec2(currentVelocity + 1, currentVelocity.y));
    }
}

void Hero::moveLeft(){
    this->heroSprite->setFlippedX(true);
    const Vec2& currentVelocity = this->heroBody->getVelocity();
    if (-currentVelocity.x <= this->maxXVelocity){
        this->heroBody->setVelocity(Vec2(currentVelocity - 1, currentVelocity.y));
    }
}

bool Hero::isGoing(const Direction& dir){
    switch dir{
    case Direction::UP:
        return keyCode[EventKeyboard::keyCode::KEY_UP_ARROW];
        
    case Direction::LEFT:
        return keyCode[EventKeyboard::keyCode::KEY_LEFT_ARROW];
        
    case Direction::RIGHT:
        return keyCode[EventKeyboard::keyCode::KEY_RIGHT_ARROW];
        
    }
}

void Hero::run(){
    if (isGoing(Direction::UP))
        jump();
    if (isGoing(Direction::LEFT))
        moveLeft();
    if (isGoing(Direction::RIGHT))
        moveRight();
}

void Hero::collideEnemy(bool enemyCanBeSteppedOn, Sprite* enemyCollided){
    if (enemyCanBeSteppedOn && this->heroSprite->getPosition().x >=
        enemyCollided->getPosition().x + 0.1 * enemyCollided->getContentSize().width
        && this->heroSprite->getPosition().x <=
        enemyCollided->getPosition().x - 0.1 * enemyCollided->getContentSize().width){
        //TODO remove Enemy
        //TODO music
    }
    else {
        //TODO music
        this->death(0);
    }
}

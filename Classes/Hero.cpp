//
//  Hero.cpp
//  SuperMarioFamily
//
//  Created by Leon Wong on 4/6月.
//
//

#include "Hero.h"

int Hero::lifeCount = 2;

Hero::Hero(): heroState(STAND){
    this->heroSpriteSheet = SpriteFrameCache::getInstance();
    this->heroSpriteSheet->addSpriteFramesWithFile("Mario_256.plist", "Mario_256.png");
    this->heroSprite = Sprite::createWithSpriteFrameName("Mario_Stand.png");
    this->heroSprite->setScale(0.125);
    
    this->heroBody = PhysicsBody::createBox(this->heroSprite->getContentSize());
    
    this->heroSprite->setPhysicsBody(this->heroBody);
}

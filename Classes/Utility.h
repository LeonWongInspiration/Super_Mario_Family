/**
 * @brief Some Utilities
 * @file Utility.h
 * @author Leon Wong
 *
 * <changelog>
 *---------------------------------------------------------------------------------------------------------
 *     <Build>    |  <Author>  |  <Description>                                                           |
 *--------------------------------------------------------------------------------------------------------|
 *  201705261319  |  Leon Wong | Initialization                                                           |
 *---------------------------------------------------------------------------------------------------------
 */

#include "SimpleAudioEngine.h"

#ifndef Utility_h
#define Utility_h

/**
 * @brief An enum denoting which direction the object is going
 * 
 */
enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

namespace SpriteBitmask{
    const int dead = 0x0000;
    const int hero = 1;
    const int goomba = 1 << 1;
    const int koopa = 1 << 2;
    const int koopa_dead = 1 << 3;
    const int piranha = 1 << 4;
    const int quotation = 1 << 5;
    const int hidden = 1 << 6;
    const int pass = 1 << 7;
    const int cloud = 1 << 8;
    const int sting = 1 << 9;
    const int fakePrincess = 1 << 10;
};

class Utility{
public:
    static void loadMusic(){
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Level1.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Level2.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Jump.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Death.mp3");
        CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("StepOn.mp3");
    }
    
    static bool onContactBegin(const cocos2d::PhysicsContact& contact){
        cocos2d::Sprite* spriteA = static_cast<cocos2d::Sprite*>(contact.getShapeA()->getBody()->getNode());
        cocos2d::Sprite* spriteB = static_cast<cocos2d::Sprite*>(contact.getShapeB()->getBody()->getNode());
        if (spriteA->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero
            || spriteB->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero){
            cocos2d::Sprite* heroSprite =
            spriteA->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero ? spriteA : spriteB;
            cocos2d::Sprite* enemySprite =
            spriteA->getPhysicsBody()->getCollisionBitmask() != SpriteBitmask::hero ? spriteA : spriteB;
            
            int heroBitmask = heroSprite->getPhysicsBody()->getCollisionBitmask();
            int spriteBitmask = enemySprite->getPhysicsBody()->getCollisionBitmask();
            
            if (spriteBitmask == SpriteBitmask::piranha ||
                spriteBitmask == SpriteBitmask::cloud ||
                spriteBitmask == SpriteBitmask::sting ||
                spriteBitmask == SpriteBitmask::fakePrincess){
                heroSprite->getPhysicsBody()->setContactTestBitmask(0x0000);
            }
            
            if (spriteBitmask == SpriteBitmask::goomba ||
                spriteBitmask == SpriteBitmask::koopa){
                if (heroSprite->getPositionY() + 1 >= enemySprite->getPositionY() + 32){
                    enemySprite->getPhysicsBody()->setContactTestBitmask(0x0000);
                    enemySprite->getPhysicsBody()->setCollisionBitmask(SpriteBitmask::dead);
                    
                    CCLOG("Enemy DIED");
                    
                    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("StepOn.mp3");
                    heroSprite->getPhysicsBody()->applyImpulse(cocos2d::Vec2(0, 1000));
                }
            }
        }
        
        return true;  
    }
};

#endif /* Utility_h */

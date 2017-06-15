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
    bool onContactBegin(const cocos2d::PhysicsContact& contact){
        cocos2d::Sprite* spriteA = static_cast<cocos2d::Sprite*>(contact.getShapeA()->getBody()->getNode());
        cocos2d::Sprite* spriteB = static_cast<cocos2d::Sprite*>(contact.getShapeB()->getBody()->getNode());
        int bitMaskA = spriteA->getPhysicsBody()->getCollisionBitmask();
        int bitMaskB = spriteB->getPhysicsBody()->getCollisionBitmask();
        
        CCLOG("%d %d contact", bitMaskA, bitMaskB);
        
        return true;  
    }
};

#endif /* Utility_h */

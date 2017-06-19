/**
 * @brief Hero superclass
 * @file Classes/Hero.cpp
 * @Author Leon Wong
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
 * |201706131517 |   Leon Wong  | Add running & jumping animation for sprite                     |
 * |201706131405 |   Leon Wong  | Hero cannot jump in the air                                    |
 * |201706111913 |   Leon Wong  | Add methods for stepping on enemies and colliding with enemies |
 * |201706111850 |   Leon Wong  | Now it can move around                                         |
 * |201706081906 |   Leon Wong  | Remove Interface, and make them inside. Update more functions  |
 * |201706072145 |   Leon Wong  | Adopting a new interface                                       |
 * |201706041448 |   Leon Wong  | Add some basic features                                        |
 * |201705251928 |   Leon Wong  | Add some properties for hero                                   |
 * |201705251846 |   Leon Wong  | First time initialization                                      |
 * -----------------------------------------------------------------------------------------------
 */
#ifndef Hero_h
#define Hero_h

#include <list>
#include "Utility.h"

USING_NS_CC;
using namespace std;


/**
 * @brief An enum denoting the hero's status.
 *
 */
enum HeroState{
    STAND,
    UP_JUMP,
    LEFT_JUMP,
    RIGHT_JUMP,
    LEFT_MOVE,
    RIGHT_MOVE,
    DIE,
    FALL,
};

class Hero: public Layer{
private:
    
    Sprite* heroSprite;
    
    PhysicsBody* heroBody;
    
    HeroState heroState;
    
    SpriteFrameCache* heroSpriteSheet;
    
    std::map<cocos2d::EventKeyboard::KeyCode, bool>* keyCode;
    
    int maxXVelocity = 80;
    
    void moveRight();
    
    void moveLeft();
    
    bool isGoing(const Direction& dir);
    
    void jumpAfterStepOnEnemy(){
        this->heroBody->applyImpulse(Vec2(0, 4900));
    }
    
    SpriteFrame* standFrame;
    
    SpriteFrame* runFrame;
    
    SpriteFrame* deathFrame;
    
    int runningSprite = 0;
    
    bool runningFrame = false;
    
    bool jumping = false;
    
    TMXLayer* meta;
    
    void checkDeath();
    
    bool dead = false;
    
    static int lifeCount;
public:
    
    static const int getLifeCount(){
        return Hero::lifeCount;
    }
    
    void jump();
    
    Hero(std::map<cocos2d::EventKeyboard::KeyCode, bool>* _KeyCode);
    
    ~Hero();
    
    void run();
    
    Sprite* getSprite(){
        return this->heroSprite;
    }
    
    float getPositionX(){
        return this->heroSprite->getPositionX();
    }
    
    float getPositionY(){
        return this->heroSprite->getPositionY();
    }
    
    void collideEnemy(bool enemyCanBeSteppedOn, Sprite* enemyCollided);
    
    bool isDead(){
        return this->heroBody->getContactTestBitmask() == 0x0000;
    }
    
};

#endif /* Hero_h */

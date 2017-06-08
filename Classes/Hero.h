/**
 * @brief Hero superclass
 * @file Classes/Hero.cpp
 * @Author Leon Wong
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
 * |201706072145 |   Leon Wong  | Adopting a new interface                                       |
 * |201706041448 |   Leon Wong  | Add some basic features                                        |
 * |201705251928 |   Leon Wong  | Add some properties for hero                                   |
 * |201705251846 |   Leon Wong  | First time initialization                                      |
 * -----------------------------------------------------------------------------------------------
 */
#ifndef Hero_h
#define Hero_h

#include "HeroInterface.h"

#include <list>

USING_NS_CC;
using namespace std;


/**
 * @brief An enum denoting the hero's status.
 *
 */
enum HeroState{
    STAND,
    JUMP,
    LEFT,
    RIGHT,
    DIE,
    FALL,
};

class Hero: public Layer, implements HeroInterface{
private:
    Sprite* heroSprite;
    PhysicsBody* heroBody;
    HeroState heroState;
    SpriteFrameCache* heroSpriteSheet;
public:
    static int lifeCount;
    Hero();
    ~Hero();
    void run();
    
    Sprite* getSprite(){
        return this->heroSprite;
    }
};

#endif /* Hero_h */

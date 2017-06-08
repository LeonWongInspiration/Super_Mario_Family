/**
 * @brief Hero superclass
 * @file Classes/Hero.cpp
 * @Author Leon Wong
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
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
public:
    
    static int lifeCount;
    
    Hero();
    
    ~Hero();
    
    void run(TMXTiledMap* tMap, TMXLayer* tLayer);
    
    void death(int foo){};
    
    Sprite* getSprite(){
        return this->heroSprite;
    }
    
    float getPositionX(){
        return this->heroSprite->getPositionX();
    }
    
    float getPositionY(){
        return this->heroSprite->getPositionY();
    }
    
    void setAction(HeroState currentState){
        this->heroState = currentState;
    }
};

#endif /* Hero_h */

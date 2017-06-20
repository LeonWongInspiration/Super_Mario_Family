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
 * @author Leon Wong
 * @file Hero.h
 * @brief A class for Hero Control.
 *
 * This is a class which can create a Sprite with its PhysicsBody for hero,
 * ans use getSprite() to get the hero. Upon construction, you should pass-by-address
 * the map<EventKeyBoard::KeyCode, bool> of KeyBoard and the hero will automatically run.
 *
 */
class Hero: public Layer{
private:
    /// The Sprite of the hero
    Sprite* heroSprite;
    /// The Physics Body of the hero
    PhysicsBody* heroBody;
    /// Save an instance of SpriteFrameCache in order to easily change animation
    SpriteFrameCache* heroSpriteSheet;
    /// The pointer to the map of keyboard
    std::map<cocos2d::EventKeyboard::KeyCode, bool>* keyCode;
    /// The max velocity on X direction, will be doubled if pressing 'R'
    int maxXVelocity = 80;
    /**
     * @retval void
     * @brief Call this and get a positive x-velocity for hero.
     *
     * On every frame calling moveRight(), hero will receive a positive x-velocity until reach the maxXVelocity
     */
    void moveRight();
    /**
     * @retval void
     * @brief Call this and get a negative x-velocity for hero.
     *
     * On every frame calling moveRight(), hero will receive a negative x-velocity until reach the maxXVelocity
     */
    void moveLeft();
    /**
     * @brief Every frame call the method with four directions and it will return if hero is going toward the direction.
     *
     * @retval bool
     * @param dir the direction the hero is going toward
     * @return True if hero is going toward dir, false otherwise
     */
    bool isGoing(const Direction& dir);
    /// A SpriteFrame containing the standing frame of hero, for animation use
    SpriteFrame* standFrame;
    /// A SpriteFrame containing the running frame of hero, for animation use
    SpriteFrame* runFrame;
    /// A SpriteFrame containing the dying frame of hero, for animation use
    SpriteFrame* deathFrame;
    /// A control for running animation, after reaching a value it will be set to zero and hero will change its frame
    int runningSprite = 0;
    /// A bool to indicate which frame hero is using
    bool runningFrame = false;
    /// To indicate if hero is jumping
    bool jumping = false;
    /**
     * @retval void
     * @brief To check if hero is dead.
     *
     * This will check if hero is ALREADY dead within every frame
     */
    void checkDeath();
    /// True if hero is dead
    bool dead = false;
    /// A static int to show Mario times what
    static int lifeCount;
    /// A static int to denote which level hero is in
    static int levelState;
public:
    /**
     * @var Hero::lifeCount
     * @retval const int&
     * @return The static int Hero::lifeCount
     */
    static const int& getLifeCount(){
        return Hero::lifeCount;
    }
    /**
     * @var Hero::levelState
     * @retval static int&
     * @return The level number hero is in
     */
    static int& getLevelState(){
        return Hero::levelState;
    }
    /**
     * @brief With every calling, hero will check if it is able to jump and jump if available.
     */
    void jump();
    /**
     * @brief A constructor for this.
     * @param _KeyCode The pointer to the map of keyboard
     */
    Hero(std::map<cocos2d::EventKeyboard::KeyCode, bool>* _KeyCode);
    /**
     * @brief default destructor.
     *
     */
    ~Hero();
    /**
     * @brief run() will decide the hero's moving every frame.
     *
     * @see Hero::moveLeft()
     * @see Hero::moveRight()
     * @see Hero::jump()
     * @see Hero::checkDeath()
     *
     * With every calling, run() will use a series of methods and variables in this class
     * and decide hero's actions
     */
    void run();
    /**
     * @retval cocos2d::Sprite*
     * @return The Sprite of the hero, with its PhysicsBody already added.
     *
     */
    Sprite* getSprite(){
        return this->heroSprite;
    }
    /**
     * @retval float
     * @return The positionX of the hero's Sprite
     */
    float getPositionX(){
        return this->heroSprite->getPositionX();
    }
    /**
     * @retval float
     * @return The positionY of the hero's Sprite
     */
    float getPositionY(){
        return this->heroSprite->getPositionY();
    }
    /**
     * @retval bool
     * @return True if hero is dead, false otherwise
     */
    bool isDead(){
        return this->heroBody->getContactTestBitmask() == 0x0000;
    }
    
};

#endif /* Hero_h */

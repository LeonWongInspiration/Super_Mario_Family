//
//  Enemy.hpp
//  SuperMarioFamily
//
//  Created by yaets on 2017/5/30.
//
//  A basic class of enemy
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Utility.h"
#include "cocos2d.h"

class Enemy
{
    
private:
    /// To decide whether the enemy is going to move
    bool trigger;
    /// To tell the enemy it's moving direction
    Direction dir;
    /// Enemy Sprite
    cocos2d::Sprite * sprite;
    /// Enemy's physics body
    cocos2d::PhysicsBody * body;
    /// If enemy is dead, it will be true
    bool isDead;
    /// Enemy's moving speed
    float moveSpeed;
    /// Size of enemy
    float height;
    float width;
    /// To judge if the enemy sprite is removed from parent
    bool isDeleted;
    /// Count to 120 the enemy picture will be delete form the screen
    int deathCount;
    
    
public:

    enum KIND
    {
        GOOMBA,
        KOOPA,
        KOOPADEAD,
        PIRANHA,
        REDMUSHROOM,
        TOXICMUSHROOM
    };
    /**
     *
     * @param frameName get plist file
     * @param filename get the picture's name
     * @param x position int the map
     * @param y position int the map
     * @param kind enemy's kind
     * @brief A constructor for Enemy class
     */
    Enemy(const char *frameName,const char * filename,int x,int y,KIND kind);
    /**
     * @brief A destructor
     */
    ~Enemy(){};
    /// Used to identify enemy's kind
    KIND kind;
    /**
     * @retval void
     * @brief Set the isDeleted to true
     *
     * @note This will delete enemy from enemy list
     *
     */
    void deleteFromNode(){isDeleted = true;}
    /**
     * @retval bool
     * @return true if enemy is deleted
     * @brief Check whether the enemy sprite is deleted form the node
     *
     */
    bool deleted(){return isDeleted;}
    /**
     * @retval bool
     * @return
     */
    bool dead(){return isDead;}
    /**
     *
     * @param isDead used to set the member dead
     * @brief Kill the enemy
     *
     */
    void dead(bool isDead);
    /**
     * @retval void
     * @brief When the enemy die,show the dead picture
     *
     */
    void replacePic();
    /**
     * @retval cocos2d::Sprite *
     * @return A pointer point to enemy's sprite
     * @brief get the enemy's sprite
     */
    cocos2d::Sprite * getSprite(){return sprite;}
    /**
     * @retval cocos2d::PhysicBody *
     * @return A pointer point to the enemy's physic body
     * @brief get the enemy's physic body
     */
    cocos2d::PhysicsBody * getBody(){return body;}
    /**
     * @retval void
     * @param speed set enemy's moving speed
     * @brief Change the enemy's moving speed
     */
    void setMoveSpeed(float speed){moveSpeed = speed;}
    /**
     * @retval void
     * @param n used to set the deathCount
     * @brief Change the deathCount number
     */
    void setDeathCount(int n){deathCount = n;}
    /**
     * @retval float
     * @return moving speed
     * @brief Get enemy's moving speed
     *
     */
    float getMoveSpeed(){return moveSpeed;}
    /**
     * @retval float
     * @return enemy's width
     * @brief Get the enemy's size
     */
    float getWidth(){return width;}
    /**
     * @retval float
     * @return enemy's height
     * @brief Get the enemy's size
     */
    float getHeight(){return height;}
    /**
     * @retval void
     * @brief Run this function to activate the enemy
     */
    void update();
    /**
     * @retval void
     * @param dir enemy's direction of next step
     * @brief Set the enemy's direction
     */
    void setDirection(Direction dir){this->dir = dir;}
    /**
     * @brief check that whether the enemy is on action
     * @return true if the enemy is moving
     */
    bool getTrigger(){return trigger;}
    /**
     * @brief tell enemy to start moving
     */
    void setTrigger(){trigger = true;}
    /**
     * @brief change current moving direction
     */
    void switchDir();
    /**
     * @brief get the current moving direction
     * @return current direction
     */
    Direction getDir(){return dir;}
    /**
     * @brief activate the enemy
     * @return true if the enemy is moving
     */
    bool move();

};

#endif /* Enemy_hpp */

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

#pragma once

#ifndef Hero_h
#define Hero_h

#include "Goomba.h"
#include "Koopa.h"
#include "Koopa_dead.h"
#include "Piranha.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Block.h"
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
    MOVE,
    DIE,
    FALL,
};

class Hero: public Layer, implements HeroInterface{
public:
    /// Lives Count
    static int life;
    /// Sprite for hero
    Sprite* heroSprite;
    /// Hero State
    HeroState heroState;
    
    /// true if press down
    bool down;
    /// true if passive
    bool passive;
    /// true if entering tubes
    bool enterTube;
    
    /// X Position
    int posX;
    /// Y Position
    int posY;
    /// width of Sprite
    int width;
    /// height of Sprite
    int height;
    /// Sprite Direction
    bool spriteDir;
    /// true if dead
    bool dead;
    /// true if need change a picture when falling
    bool changePicIfFall;
    /// jump speed
    float jumpSpeed;
    /// fall speed
    float fallSpeed;
    /// Move speed
    float moveSpeed;
    /// height of jumping
    int jumpHeight;
    /// distanceOfJumping
    int jumpDist;
    
    /// true if jumping
    bool jumping;
    /// true if a near jump
    bool nearJump;
    /// true if change pic
    bool await;
    /// true if invincible
    bool invincible;
    
    /// Monster Position
    int monsterX;
    /// Monster Position
    int monsterY;
    
    // Inertia;
    /// Count Move Left
    int moveLeftCount;
    /// Count Move Right
    int moveRightCount;
    /// Inertia
    float moveInertia;
    /// Max Inertia
    float moveInertiaMax;
    /// Move & Jump Inertia
    float moveJumpInertia;
    
    /// Goomba List
    list<Goomba*> GoombaList;
    /// Koopa List
    list<Koopa*> KoopaList;
    /// Piranha List
    list<Piranha*> PiranhaList;
    /// Falling Blocks List
    list<Falling*> FallingList;
    
    /**
     * A constructor
     * 
     *
     */
    Hero(const string picRoute, int x, int y, int w, int h, Rect r, Node* n, bool dir);
    
    /**
     * Destructor
     */
    ~Hero();
    
    /**
     * Set Invincible Time
     */
    void setInvincibleTime(float invinTime);
    
    /**
     * Death
     */
    void death(int jumpH = 0);
    
    /**
     * Run
     */
    void run(TMXTiledMap* map, TMXLayer* layer, list<Falling*>& FallingList, list<Flag*>& FlagList, list<Tube>& TubeList);
    
    /**
     * Move
     */
    void move(bool towardLeft, TMXLayer* map, TMXLayer* layer, list<Falling*>& FallingList);
    
    /**
     * Jump
     */
    void jump(TMXLayer* map, TMXLayer* layer, list<Falling*>& FallingList);
    
    /**
     * Fall
     */
    void gravity(TMXLayer* map, TMXLayer* layer, list<Falling*>& FallingList);
    
    /**
     * Obstacle Judging
     */
    bool hindered(DIR dir, TMXLayer* map, TMXLayer* layer, list<Falling*>& FallingList);
    
    void clear();
};

#endif /* Hero_h */

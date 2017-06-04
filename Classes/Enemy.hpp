//
//  Enemy.hpp
//  SuperMarioFamily
//
//  Created by 梁永潮 on 2017/5/30.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "Utility.h"

class Enemy
{
public:
    enum KIND
    {
        COOMBA,
        KOOPA,
        KOOPADEAD,
        PIRANHA,
        REDMUSHROOM,
        TOXICMUSHROOM
        
        
    };
    
    float moveSpeed;
    float jumpSpeed;
    float fallSpeed;
    bool isDead;
    float height;
    float width;
    bool normalSpeed;
    bool isDeleted;
    bool trigger;
    bool fall;
    int moveTime;
    int setEnemyX;
    int setEnemyY;
    KIND kind;
    cocos2d::Sprite * sprite;
    cocos2d::Label * label;
    Direction dir;
    
    Enemy(const char * filename,int x,int y,KIND kind);
    ~Enemy();
    bool move(cocos2d::TMXTiledMap * tmxmap);
    void update(cocos2d::TMXTiledMap * tmxmap);
    bool gravity(cocos2d::TMXTiledMap * tmxmap);
    
    
    
};

#endif /* Enemy_hpp */

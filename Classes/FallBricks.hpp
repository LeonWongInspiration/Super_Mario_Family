//
//  FallBricks.hpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#ifndef FallBricks_hpp
#define FallBricks_hpp

#include "Enemy.hpp"

class FallBricks
{
public:
    FallBricks(int x,int y);
    ~FallBricks();
    cocos2d::Sprite * sprite;
    float fallSpeed;
    float width;
    float height;
    bool trigger;
    void fall();
    
};

#endif /* FallBricks_hpp */

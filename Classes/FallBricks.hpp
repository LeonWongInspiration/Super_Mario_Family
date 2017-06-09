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
private:
    bool above;
    bool trigger;
    bool outScene;

public:
    FallBricks(int x,int y);
    ~FallBricks();
    cocos2d::Sprite * sprite;
    float fallSpeed;
    float width;
    float height;
    
    void fall();
    void isAbove(float x,float y);
    bool isOutScene(){return outScene;}
    
    
    
};

#endif /* FallBricks_hpp */

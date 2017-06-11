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
    float fallSpeed;
    float width;
    float height;
    cocos2d::Sprite * sprite;
public:
    FallBricks(int x,int y);
    ~FallBricks();
    void setFallSpeed(float speed){fallSpeed = speed;}
    float getWidth(){return width;}
    float getHeight(){return height;}
    
    cocos2d::Sprite * getSprite(){return sprite;}
    void fall();
    void isAbove(float x,float y);
    bool isOutScene(){return outScene;}
    void run();

    
    
};

#endif /* FallBricks_hpp */

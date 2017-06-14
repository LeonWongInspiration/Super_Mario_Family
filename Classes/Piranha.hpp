//
//  Piranha.hpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#ifndef Piranha_hpp
#define Piranha_hpp

#include "Enemy.hpp"

class Piranha:public Enemy
{
public:
    Piranha(const char * frameName,const char * fileName,int x,int y);
    ~Piranha(){};
    float upSpeed;
    int upCount;
    void up(float x);
    bool isAbove(float);
};

#endif /* Piranha_hpp */

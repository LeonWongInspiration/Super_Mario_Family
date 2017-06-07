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

class Prianha:public Enemy
{
public:
    Prianha(const char * frameName,const char * fileName,int x,int y);
    ~Prianha(){};
    float upSpeed;
    int upCount;
};

#endif /* Piranha_hpp */

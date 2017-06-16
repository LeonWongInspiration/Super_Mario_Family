//
//  Goomba.hpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/7.
//
//

#ifndef Goomba_hpp
#define Goomba_hpp

#include "Enemy.hpp"

class Goomba:public Enemy
{
public:
    Goomba(const char * frameName,const char * fileName,int x,int y);
    ~Goomba(){};
    void run(float x);
    
};

#endif /* Goomba_hpp */

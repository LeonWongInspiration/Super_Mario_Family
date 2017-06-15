//
//  Koopa.hpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/4.
//
//

#ifndef Koopa_hpp
#define Koopa_hpp
#include "Enemy.hpp"

class Koopa:public Enemy
{
public:
    int count;
    bool flag;
    Koopa(const char * frameName,const char * fileName,int x,int y);
    ~Koopa(){};
    cocos2d::Animate * moveAcition;
    void action(cocos2d::TMXTiledMap * tmxmap);
    
    void addCount(){++ count;}
};

#endif /* Koopa_hpp */

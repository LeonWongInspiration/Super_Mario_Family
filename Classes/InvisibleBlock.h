#pragma once

#include "cocos2d.h"
#include "Utility.h"

using namespace cocos2d;

class InvisibleBlock
{
private:
	Sprite* nowsprite;
	PhysicsBody* body;
	float width;
	float height;
    bool added;


public:
    InvisibleBlock(cocos2d::Sprite* sprite);
	~InvisibleBlock(){};

	Sprite* getSprite() { return nowsprite; }
	PhysicsBody* getBody() { return body; }
    void collideHero(Vec2 & hero);
    void show();
    bool add(){return added;}
};

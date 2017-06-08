#include "fakePrincess.h"

fakePrincess::fakePrincess(const char* fileName,float x,float y):Block(fileName,x,y)
{
	nowSprite->setTextureRect(Rect(0, 0, 200, 256));
	nowSprite->setScaleX(0.16f);
	nowSprite->setScaleY(0.25f);
}

fakePrincess::~fakePrincess()
{}

void fakePrincess::killMario(Hero* hero)
{

}
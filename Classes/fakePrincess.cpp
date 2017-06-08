#include "fakePrincess.h"

FakePrincess::FakePrincess(const char* fileName,float x,float y):Block(fileName,x,y)
{
	nowSprite->setTextureRect(Rect(0, 0, 200, 256));
	nowSprite->setScaleX(0.16f);
	nowSprite->setScaleY(0.25f);
}

FakePrincess::~FakePrincess()
{}

void FakePrincess::killMario(Hero* hero)
{

}
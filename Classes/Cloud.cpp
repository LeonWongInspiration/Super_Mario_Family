#include "Cloud.h"


Cloud::Cloud(const char* fileName,float x,float y):Block(fileName,x,y)
{
	nowSprite->setTextureRect(Rect(0, 0, 826, 480));
	nowSprite->setScaleX(0.15f);
	nowSprite->setScaleY(0.11f);
}

Cloud::~Cloud()
{}

void Cloud::killMario(Hero* hero)
{
	if(collideHero(hero,width,height))
	{ 
		
	}
}
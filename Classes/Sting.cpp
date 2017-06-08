#include "Sting.h"

Sting::Sting(const char* fileName,float x,float y):Block(fileName,x,y)
{
	nowSprite->setTextureRect(Rect(0,0, 55, 40));
	nowSprite->setScale(0.5f);
	
}

Sting::~Sting()
{}

void Sting::killMario(Hero* hero)
{
	if (collideHero(hero,width,height))
	{

	}
}
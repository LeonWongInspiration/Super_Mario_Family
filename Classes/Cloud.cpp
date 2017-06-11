#include "Cloud.h"


Cloud::Cloud(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setTextureRect(Rect(0, 0, 826, 480));
	this->getSprite()->setScaleX(0.15f);
	this->getSprite()->setScaleY(0.11f);

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::cloud);
}

Cloud::~Cloud()
{}

void Cloud::killMario(Hero* hero)
{
	if(collideHero(hero,width,height))
	{ 
		changeSprite();
		hero->death(0);
	}
}

void Cloud::changeSprite()
{
	
}
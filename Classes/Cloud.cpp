#include "Cloud.h"


Cloud::Cloud(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setScaleX(0.15f);
	this->getSprite()->setScaleY(0.11f);

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::cloud);
    body->setContactTestBitmask(0xFFFF);
	body->setDynamic(false);
}

Cloud::~Cloud()
{}

void Cloud::killMario(Hero* hero)
{
		changeSprite();
		hero->death(0);
}


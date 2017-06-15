#include "Sting.h"

Sting::Sting(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setScale(0.5f);
	//this->getSprite()->setVisible(false);

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::sting);
    body->setContactTestBitmask(0xFFFF);
	body->setDynamic(false);
}

Sting::~Sting()
{}

void Sting::killMario(Hero* hero)
{
		this->getSprite()->setVisible(true);
		hero->death(0);
}

#include "Sting.h"

Sting::Sting(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setTextureRect(Rect(0,0, 55, 40));
	this->getSprite()->setScale(0.5f);
	this->getSprite()->setVisible(false);

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::sting);
}

Sting::~Sting()
{}

void Sting::killMario(Hero* hero)
{
	if (collideHero(hero,width,height))
	{
		nowSprite->setVisible(true);
		hero->death(0);
	}
}
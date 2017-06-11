#include "fakePrincess.h"

FakePrincess::FakePrincess(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setTextureRect(Rect(0, 0, 200, 256));
	this->getSprite()->setScaleX(0.16f);
	this->getSprite()->setScaleY(0.25f);

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::fakePrincess);
}

FakePrincess::~FakePrincess()
{}

void FakePrincess::killMario(Hero* hero)
{
	if (collideHero(hero, width, height))
	{
		hero->death(0);
	}
}
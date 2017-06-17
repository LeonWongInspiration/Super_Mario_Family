#include "fakePrincess.h"

FakePrincess::FakePrincess(const char* fileName,float x,float y):Block(fileName,x,y)
{
	this->getSprite()->setScaleX(0.16);
	this->getSprite()->setScaleY(0.25);

	width = this->getSprite()->getContentSize().width;
	height = this->getSprite()->getContentSize().height;

	body = PhysicsBody::createBox(this->getSprite()->getContentSize());
	this->getSprite()->setPhysicsBody(body);
	body->setCollisionBitmask(SpriteBitmask::fakePrincess);
    body->setContactTestBitmask(0xFFFF);
	body->setDynamic(false);
}

FakePrincess::~FakePrincess()
{}


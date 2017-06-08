#include "Sting.h"

Sting::Sting()
{
	nowSprite = Sprite::create("Block//Sting.png");
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	nowSprite->setTextureRect(Rect(0,0, 55, 40));
	nowSprite->setScale(0.5f);
	
}

Sting::~Sting()
{}

void Sting::collideHero(Hero* hero)
{
	setRect blockRect, heroRect;


	blockRect.bottom = nowSprite->getPositionY();
	blockRect.top = nowSprite->getPositionY() + 32;
	blockRect.left = nowSprite->getPositionX();
	blockRect.right = nowSprite->getPositionX() + 32;

	heroRect.bottom = hero->getSprite()->getPositionX();
	heroRect.top = hero->getSprite()->getPositionY() + hero->getSprite()->getTextureRect().size.height;
	heroRect.left = hero->getSprite()->getPositionX();
	heroRect.right = hero->getSprite()->getPositionX() + hero->getSprite()->getTextureRect().size.width;

	if (rectIntersect(&blockRect, &heroRect))
		hero->death(0);
}
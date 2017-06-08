#include "Sting.h"

Sting::Sting()
{
	nowSprite = Sprite::create("Block//Sting.png");
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	nowSprite->setTextureRect(Rect(0,0, 60, 40));
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

	heroRect.bottom = hero->heroSprite->getPositionX();
	heroRect.top = hero->heroSprite->getPositionY() + hero->heroSprite->getTextureRect().size.height;
	heroRect.left = hero->heroSprite->getPositionX();
	heroRect.right = hero->heroSprite->getPositionX() + hero->heroSprite->getTextureRect().size.width;

	if (rectIntersect(&blockRect, &heroRect))
	{

		HeroState heroState = DIE;
	}
}
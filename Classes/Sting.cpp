#include "Sting.h"

Sting::Sting()
{
	Sprite* sting = Sprite::create("tile//Sting.png");
	nowSprite->setTextureRect(Rect(0, 0, 32, 32));
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
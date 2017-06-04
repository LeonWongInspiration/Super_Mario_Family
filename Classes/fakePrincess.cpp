#include "fakePrincess.h"

fakePrincess::fakePrincess()
{
	nowSprite->setTextureRect(Rect(0, 0, 32, 64));
	blockHeight = nowSprite->getTextureRect().size.height;
	blockWidth = nowSprite->getTextureRect().size.width;
}

fakePrincess::~fakePrincess()
{}

void fakePrincess::collideHero(Hero* hero)
{
	setRect blockRect, heroRect;

	blockRect.bottom = nowSprite->getPositionY();
	blockRect.top = nowSprite->getPositionY() + 64;
	blockRect.left = nowSprite->getPositionX();
	blockRect.right = nowSprite->getPositionX() + 32;

	heroRect.bottom = hero->heroSprite->getPositionX();
	heroRect.top = hero->heroSprite->getPositionY() + hero->heroSprite->getTextureRect().size.height;
	heroRect.left = hero->heroSprite->getPositionX();
	heroRect.right = hero->heroSprite->getPositionX() + hero->heroSprite->getTextureRect().size.width;

	if (rectIntersect(&blockRect, &heroRect))
	{
		Sprite* knife = Sprite::create("tile//knife.png");
		HeroState heroState = DIE;
	}
}
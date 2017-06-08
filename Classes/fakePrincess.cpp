#include "fakePrincess.h"

fakePrincess::fakePrincess()
{
	nowSprite=Sprite::create("Block//fakePrincess.png");
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	nowSprite->setTextureRect(Rect(0, 0, 200, 256));
	nowSprite->setScaleX(0.16f);
	nowSprite->setScaleY(0.32f);
	
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
		HeroState heroState = DIE;
	}
}
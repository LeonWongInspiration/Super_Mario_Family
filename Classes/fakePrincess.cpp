#include "fakePrincess.h"

fakePrincess::fakePrincess()
{
	nowSprite=Sprite::create("Block//fakePrincess.png");
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	nowSprite->setTextureRect(Rect(0, 0, 200, 256));
	nowSprite->setScaleX(0.16f);
	nowSprite->setScaleY(0.25f);
	
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

	heroRect.bottom = hero->getSprite()->getPositionX();
	heroRect.top = hero->getSprite()->getPositionY() + hero->getSprite()->getTextureRect().size.height;
	heroRect.left = hero->getSprite()->getPositionX();
	heroRect.right = hero->getSprite()->getPositionX() + hero->getSprite()->getTextureRect().size.width;

	if (rectIntersect(&blockRect, &heroRect))
	{
		hero->death(0);
	}
}
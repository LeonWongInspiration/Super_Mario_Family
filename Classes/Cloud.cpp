#include "Cloud.h"


Cloud::Cloud()
{
	nowSprite = Sprite::create("Block//normalCloud.png");
	nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	nowSprite->setTextureRect(Rect(0, 0, 826, 480));
	nowSprite->setScaleX(0.15f);
	nowSprite->setScaleY(0.17f);
}

Cloud::~Cloud()
{}

void Cloud::collideHero(Hero* hero)
{
	setRect blockRect, heroRect;
	

	blockRect.bottom = nowSprite->getPositionY();
	blockRect.top = nowSprite->getPositionY() + 64;
	blockRect.left = nowSprite->getPositionX();
	blockRect.right = nowSprite->getPositionX() + 128;

	heroRect.bottom = hero->heroSprite->getPositionX();
	heroRect.top = hero->heroSprite->getPositionY() + hero->heroSprite->getTextureRect().size.height;
	heroRect.left = hero->heroSprite->getPositionX();
	heroRect.right = hero->heroSprite->getPositionX() + hero->heroSprite->getTextureRect().size.width;

	if (rectIntersect(&blockRect, &heroRect))
	{
		nowSprite = Sprite::create("Enemy//hurtfulCloud.png");
		nowSprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
		nowSprite->setTextureRect(Rect(0, 0, 826, 480));
		nowSprite->setScaleX(0.15f);
		nowSprite->setScaleY(0.17f);
		HeroState heroState = DIE;
	}
}
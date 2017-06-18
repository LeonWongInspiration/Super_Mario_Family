#include "GameOver.h"

Scene * GameOver::createScene()
{
	auto scene = Scene::create();


	auto layer = GameOver::create();

	scene->addChild(layer);

	return scene;
}


void GameOver::menuCallBack(Ref * pSender)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGroundImage = Sprite::create("GameOver.jpg");

	// set it to be the background
	backGroundImage->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	backGroundImage->setPosition(Vec2(0, 0));
	this->addChild(backGroundImage);

	//add a GameOver lable
	auto lableOver = Label::createWithTTF("Game Over", "fonts/SuperMario256.ttf", 80);
	CCLOG("create lable");

	lableOver->setPosition(Vec2(visibleSize.width / 3, visibleSize.height-80));

	lableOver->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	this->addChild(lableOver);

	//set a label back to menu
	auto lableBack = Label::createWithTTF("Back To Menu", "fonts/SuperMario256.ttf", 35);
	CCLOG("create lable");

	auto itemBack = MenuItemLabel::create(lableBack, CC_CALLBACK_1(GameOver::menuCallBack, this));

	itemBack->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	itemBack->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	//add lable into menu
	auto menu = cocos2d::Menu::create(itemBack, NULL);

	menu->setAnchorPoint(cocos2d::Point::ANCHOR_BOTTOM_LEFT);

	menu->setPosition(cocos2d::Point::ZERO);

	this->addChild(menu);
}
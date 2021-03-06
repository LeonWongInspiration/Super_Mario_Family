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

void GameOver::backtoGame(Ref* pSender)
{
	if (Hero::getLevelState() == 1)
		Director::getInstance()->replaceScene(Level1::createScene());
	else if (Hero::getLevelState() == 2)
		Director::getInstance()->replaceScene(Level2::createScene());
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
	auto lableOver = Label::createWithTTF("Game Over", "Fonts//SuperMario256.ttf", 80);
	CCLOG("create lable");

	lableOver->setPosition(Vec2(visibleSize.width / 3, visibleSize.height-80));

	lableOver->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	this->addChild(lableOver);

	//set a label show lifecount
    char buffer[10];
    sprintf(buffer, "%d",Hero::getLifeCount());
    string info = "Mario X ";
    info += buffer;
	auto showLife = Label::createWithTTF(info, "Fonts//SuperMario256.ttf", 50);
	CCLOG("create lable");

	showLife->setPosition(Vec2(visibleSize.width / 2+100, visibleSize.height*2 / 3));
    CCLOG("%d",Hero::getLifeCount());
    this->addChild(showLife);

	//add a button back to menu
	auto lableBack = Label::createWithTTF("Back To Menu", "Fonts//SuperMario256.ttf", 35);
	CCLOG("create lable");

	auto itemBack = MenuItemLabel::create(lableBack, CC_CALLBACK_1(GameOver::menuCallBack, this));

	itemBack->setPosition(Vec2(visibleSize.width / 3+340, visibleSize.height - 500));

	itemBack->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);

	//add continue button
	auto continueGame = Label::createWithTTF("Continue", "Fonts//SuperMario256.ttf", 40);
	CCLOG("create lable");

	

	auto itemContinue = MenuItemLabel::create(continueGame, CC_CALLBACK_1(GameOver::backtoGame, this));

	itemContinue->setPosition(Vec2(visibleSize.width / 3, visibleSize.height - 500));

	itemContinue->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);


	//add lable into menu
	auto menu = cocos2d::Menu::create(itemBack,itemContinue, NULL);

	menu->setAnchorPoint(cocos2d::Point::ANCHOR_BOTTOM_LEFT);

	menu->setPosition(cocos2d::Point::ZERO);

	this->addChild(menu);
    return true;
}

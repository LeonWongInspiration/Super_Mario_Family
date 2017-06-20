#include "GamePause.h"

bool GamePause::init()
{
	//Continue Button
	auto Continue = MenuItemImage::create(
		"Button//Play_Button.png",
		"Button//Play_Button.png",
		"Button//Play_Button.png",
		CC_CALLBACK_1(GameOver::menuCallBack, this));
	Continue->setAnchorPoint(Point(Point::ANCHOR_BOTTOM_LEFT));
	Continue->setScale(0.3f);
	Continue->setPosition(Point(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 + origin.y - 150)));


	//Restart Button
	auto Restart = MenuItemImage::create(
		"Button//Reload.png",
		"Button//Reload.png",
		"Button//Reload.png",
		CC_CALLBACK_1(GameOver::backtoGame, this));
	Restart->setAnchorPoint(Point(Point::ANCHOR_BOTTOM_LEFT));
	Restart->setScale(0.3f);
	Restart->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height / 2 - 150)));


	//Stop Button
	auto Stop = MenuItemImage::create(
		"Button//Stop.png",
		"Button//Stop.png",
		"Button//Stop.png",
		CC_CALLBACK_1(GameOver::menuCallback, this));
	Stop->setAnchorPoint(Point(Point::ANCHOR_BOTTOM_LEFT));
	Stop->setScale(0.3f);
	Stop->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x * 2 + 200, origin.y + visibleSize.height / 2 - 150)));

	auto menu = Menu::create(Continue, Restart, Stop, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}
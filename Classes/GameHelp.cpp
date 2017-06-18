/**
 * @brief GameHelp class used to show a help and about for this game
 * @file Classes/GameHelp.cpp
 * @Author Yates Liang
 *
 * This is a game helper which can show detailed information about this game
 * The information includes the instructions of this game, the about info for this game, etc.
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
 * |201705102128 |   Leon Wong  | Introducing Doxygen for this file.                             |
 * |             |              |                                                                |
 * |             |              |                                                                |
 * -----------------------------------------------------------------------------------------------
 */

#include "GameHelp.hpp"

using namespace cocos2d;

/**
 * Initialization of this Layer
 * @return bool: true if initialization succeed, false otherwise.
 */
bool GameHelp::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
        
    }
    
	Size winSize = Director::getInstance()->getWinSize();
	float winw = winSize.width;
	float winh = winSize.height;
	

	// set the background
	auto backGroundImage = Sprite::create("HelpScene.jpg");
	backGroundImage->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	backGroundImage->setPosition(Vec2(0, 0));
	float backw = backGroundImage->getTextureRect().getMaxX();
	float backh = backGroundImage->getTextureRect().getMaxY();

	backGroundImage->setScaleX(winw / backw);
	backGroundImage->setScaleY(winh / backh);

	this->addChild(backGroundImage);


    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto lableBack = cocos2d::Label::createWithTTF("Back To Menu","fonts//SuperMario256.ttf",50);
    CCLOG("create lable");
    
	lableBack->setTextColor(Color4B::YELLOW);

    auto lableHelp = cocos2d::Label::createWithTTF("Help","fonts//SuperMario256.ttf",50);
    
	lableHelp->setTextColor(Color4B::YELLOW);

    lableHelp->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
    
    lableHelp->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height-lableBack->getContentSize().height));
    
	this->addChild(lableHelp);

	//add contents of help

	auto keyHelp = cocos2d::Label::createWithTTF("UP:JUMP LEFT:MOVE LEFT RIGHT:MOVE RIGHT F:FLY", "fonts//Mario and Luigi.ttf", 50);

	keyHelp->setDimensions(500, 500);

	keyHelp->setTextColor(Color4B::YELLOW);

	keyHelp->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);

	keyHelp->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height/2-50));

	this->addChild(keyHelp);


    auto itemBack = cocos2d::MenuItemLabel::create(lableBack, CC_CALLBACK_1(GameHelp::menuCallBack, this));
    
    itemBack->setPosition(cocos2d::Vec2(visibleSize.width/2-180,visibleSize.height/2-200));
    
    itemBack->setAnchorPoint(cocos2d::Point::ANCHOR_BOTTOM_LEFT);
    
    ///add a Sprite below to introduce the game
    
    auto menu = cocos2d::Menu::create(itemBack,NULL);
    
    menu->setAnchorPoint(cocos2d::Point::ANCHOR_BOTTOM_LEFT);
    
    menu->setPosition(cocos2d::Point::ZERO);
    
    this->addChild(menu);
    auto map = cocos2d::TMXTiledMap::create("Level1.tmx");
    this->addChild(map);
    
    return true;
    
}

/**
 * Show this scene
 * @param pSender TODO 描述一下pSender是什么
 */
void GameHelp::menuCallBack(cocos2d::Ref * pSender)
{
    
    cocos2d::Director::getInstance()->replaceScene(HelloWorld::createScene());
    
}

/**
 * TODO 把这里描述一下
 * @return TODO 写一下这个return了什么
 */
cocos2d::Scene * GameHelp::createScene()
{
    auto scene = cocos2d::Scene::create();

    
    auto layer = GameHelp::create();
    
    scene->addChild(layer);
    
    return scene;
}



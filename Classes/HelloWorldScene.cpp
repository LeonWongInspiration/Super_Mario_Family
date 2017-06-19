#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "GameHelp.hpp"
//#include "GameScene.hpp"
#include "Level1.hpp"
#include "Level2.hpp"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backGroundImage = Sprite::create("Welcome_BackGround_1024_728.png");
    
    // set it to be the background
    backGroundImage->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    backGroundImage->setPosition(Vec2(0, 0));
    this->addChild(backGroundImage);
    
    // add a Sprite Sheet to the Scene
    SpriteFrameCache* MenuSpriteSheet = SpriteFrameCache::getInstance();
    MenuSpriteSheet->addSpriteFramesWithFile("Buttons.plist", "Buttons.png");
    
    //Put three buttons on the startScene
    
    //SinglePlayer Button
    auto Single = MenuItemImage::create(
                                        "SinglePlayer_Normal.png",
                                        "SinglePlayer_Clicked.png",
                                        "SinglePlayer_Activate.png",
                                        CC_CALLBACK_1(HelloWorld::menuCallback,this));
    Single->setTag(SINGLE);
    Single->setAnchorPoint(Point(cocos2d::Point::ANCHOR_MIDDLE));
    Single->setScaleX(0.3f);
    Single->setScaleY(0.3f);
    Single->setPosition(Point(Vec2(visibleSize.width/2-200,visibleSize.height/2+origin.y-150)));
    
    
    //MultiPlayer Button
    auto Multi = MenuItemImage::create(
                                       "MultiPlayer_Normal.png",
                                       "MultiPlayer_Clicked.png",
                                       "MultiPlayer_Activate.png",
                                       CC_CALLBACK_1(HelloWorld::menuCallback,this));
    Multi->setTag(MULTI);
    Multi->setAnchorPoint(Point(cocos2d::Point::ANCHOR_MIDDLE));
    Multi->setScaleX(0.3f);
    Multi->setScaleY(0.3f);
    Multi->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height / 2 - 150)));
    
    
    //Help&About Button
    auto Help = MenuItemImage::create(
                                      "Help&About_Normal.png",
                                      "Help&About_Clicked.png",
                                      "Help&About_Activate.png",
                                      CC_CALLBACK_1(HelloWorld::menuCallback,this));
    Help->setTag(HELP);
    Help->setAnchorPoint(Point(cocos2d::Point::ANCHOR_MIDDLE));
    Help->setScaleX(0.3f);
    Help->setScaleY(0.3f);
    Help->setPosition(Point(Vec2(visibleSize.width / 2 + origin.x*2 + 200, origin.y + visibleSize.height / 2 - 150)));
    
    
    
    auto menu = Menu::create(Single,Multi,Help, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    
    return true;
}


void HelloWorld::menuCallback(Ref* pSender)
{
    switch(((Node*)pSender)->getTag())
    {
            //open SinglePlayer Scene
        case SINGLE:
            CCLOG("start game");
            Director::getInstance()->replaceScene(Level1::createScene());
            break;
            
            //open MultiPlayer Scene
        case MULTI:
            break;
            
            //open Help&About Scene
        case HELP:
            CCLOG("go to help");
            Director::getInstance()->replaceScene(GameHelp::createScene());
            break;
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
#endif
            

    
    
}

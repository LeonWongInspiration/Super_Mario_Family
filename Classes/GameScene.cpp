/**
 * @brief GameScene
 * @file Classes/GameScene.cpp
 * @Author Yates Liang
 *
 * This is a game helper which can show detailed information about this game
 * The information includes the instructions of this game, the about info for this game, etc.
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
 * |201705102133 |   Leon Wong  | Introducing Doxygen for this file.                             |
 * |             |              |                                                                |
 * |             |              |                                                                |
 * -----------------------------------------------------------------------------------------------
 */
#include <string>
#include "GameScene.hpp"
#include "HelloWorldScene.h"

using namespace cocos2d;
using namespace std;

/**
 * TODO 潮潮在这里加上描述
 * @return
 */
bool GameScene::init()
{
    if(!cocos2d::Layer::init())
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    //loading start scene and player
    
	TMXTiledMap* map = TMXTiledMap::create("Level1.tmx");
	addChild(map, 10);
    mapMe = map;
    mapMoveCount = 0.0;
	auto blockLayer = map->getLayer("Blocks");
	auto hiddenLayer = map->getLayer("Hidden");
	auto fakeLayer = map->getLayer("Fake");
    
    
    
    auto meta = map->getLayer("Meta");
    
    meta->setVisible(false);
    
	hiddenLayer->setVisible(false);
    
	enemy = map->getObjectGroup("Enemy");

	ValueMap sting = enemy->getObject("Stingtest");
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    
    //add player
    
    hero = new Hero;
    
    
    
    //add koopa list
    
    char buffer[30];
    
    string k = "Koopa";
    
    for(int i = 1;i <= 2;++i)
    {
        sprintf(buffer, "%d",i);
        ValueMap koo = enemy->getObject(k+buffer);
        Koopa * koopa = new Koopa("Enemy_256.plist","Koopa_256.png",koo.at("x").asFloat(),koo.at("y").asFloat());
        
        this->addChild(koopa->sprite);
        
        koopaList.push_back(koopa);
        
    }
    
    //add goomba list
    
    string g = "Goomba";
    
    for(int i = 1;i <= 7;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto goo = enemy->getObject(g + buffer);
        
        Goomba * goomba = new Goomba("Enemy_256.plist","Goomba_256.png",goo.at("x").asFloat(),goo.at("y").asFloat());
        
        
        this->addChild(goomba->sprite);
        
        goombaList.push_back(goomba);
        

    }
    
    //add piranha list
    
    string p = "Piranha";
    
    for(int i = 1;i <= 4;++i)
    {
        sprintf(buffer, "%d",i);
        CCLOG("%s",buffer);
        auto pir = enemy->getObject(p + buffer);
        
        Piranha * piranha = new Piranha("Enemy_256.plist","Piranha_open_256.png",pir.at("x").asFloat(),pir.at("y").asFloat());
        
        this->addChild(piranha->sprite);
        
        piranhaList.push_back(piranha);
    
        
    }
    
    //add fallBricks list
    
    string f = "Falling1";
    
    auto fall = enemy->getObject(f);
    
    FallBricks * fallBricks = new FallBricks(fall.at("x").asFloat(),fall.at("y").asFloat());
    
    this->addChild(fallBricks->sprite,0);
    
    fallbricksList.push_back(fallBricks);
    
    
    //add Cloud list
    
    string c = "stingCloud";
    
    auto sCloud = enemy->getObject(c);
    
    Cloud * stingCloud = new Cloud("normalCloud.png",sCloud.at("x").asFloat(),sCloud.at("y").asFloat());
    
    this->addChild(stingCloud->nowSprite);
    
    cloudList.push_back(stingCloud);
    
    //add sting list
    
    string s = "Sting";
    
    for(int i = 1; i <= 4;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto stingValue = enemy->getObject(s + buffer);
        auto stingX = stingValue.at("x").asFloat();
        auto stingY = stingValue.at("y").asFloat();
        
        Sting * sting = new Sting("Sting.png",stingX,stingY);
        
        this->addChild(sting->nowSprite);
        
        if(i == 3)
        {
            Sting * sting2 = new Sting("Sting.png",stingX+32,stingY);
            this->addChild(sting->nowSprite);
            
            
            stingList.push_back(sting2);
            
            
            
            
            
        }
        
        if(i == 4)
        {
            for(int j = 1;j <= 3;++j)
            {
                sting = new Sting("Sting.png",stingX+(float)j*32,stingY);
                this->addChild(sting->nowSprite);
                stingList.push_back(sting);
            }
        }
        
        
        
    }
    
    //add fake princess list
    
    auto princessValue = enemy->getObject("fakePrincess");
    
    FakePrincess* fakePrincess = new FakePrincess("fakePrincess.png",princessValue.at("x").asFloat(),princessValue.at("y").asFloat());
    
    this->addChild(fakePrincess->nowSprite);
    
    fakePrincessList.push_back(fakePrincess);
    
    
    
   

    
    
    
    
    
    
    
   
    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event)
    {
        keyCode[KeyCode] = true;
        CCLOG("Press");
    };
    keyboardListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event)
    {
        keyCode[KeyCode] = false;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    this->scheduleUpdate();
    return true;
};

void GameScene::update(float dt)
{
    
    //CCLOG("update");
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    auto heroPositionX = hero->getSprite()->getPositionX();
    
    auto heroPositionY = hero->getSprite()->getPositionY();
    
    mapMe->setPositionX(mapMe->getPositionX()+mapMoveCount);
    
    //CCLOG("%f %f",mapMe->getPositionX(),mapMe->getPositionY());
    
    for(auto item:piranhaList)
    {
        
        item->judge(mapMe, heroPositionX, heroPositionY);
        item->sprite->setPositionX(item->sprite->getPositionX() + mapMoveCount);
        item->update(mapMe);
    }
    
    for(auto item:goombaList)
    {
        item->judge(mapMe, heroPositionX, heroPositionY);
        item->sprite->setPositionX(item->sprite->getPositionX() + mapMoveCount);
        item->update(mapMe);
    }
    
    for(auto item:koopaList)
    {
        item->judge(mapMe, heroPositionX, heroPositionY);
        item->sprite->setPositionX(item->sprite->getPositionX() + mapMoveCount);
        item->update(mapMe);
    }
    
    for(auto item:fallbricksList)
    {
        
        item->sprite->setPositionX(item->sprite->getPositionX() + mapMoveCount);
        item->isAbove(heroPositionX, heroPositionY);
        item->fall();
    }
    
    for(auto item:stingList)
    {
        item->nowSprite->setPositionX(item->nowSprite->getPositionX() + mapMoveCount);
    }
    
    for(auto item:cloudList)
    {
        item->nowSprite->setPositionX(item->nowSprite->getPositionX() + mapMoveCount);
    }
    for(auto item:fakePrincessList)
    {
        item->nowSprite->setPositionX(item->nowSprite->getPositionX() + mapMoveCount);
    }
    
    
    
    
    
    
    
    
    
    
    
    //use isKeyPressed to judge the keyboard event
    
    
    
    
}

//deal with some menu incidents

void GameScene::menuCallBack(cocos2d::Ref *pSender)
{
    
}

cocos2d::Scene * GameScene::createScene()
{
    auto scene = cocos2d::Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    scene->getPhysicsWorld()->setGravity(Vec2(0,-6));
	
    auto layer = GameScene::create();
	
    scene->addChild(layer);

    return scene;
}

bool GameScene::isKeyPressed(cocos2d::EventKeyboard::KeyCode KeyCode)
{
    if(keyCode[KeyCode])
        return true;
    else
        return false;
}

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
    if(!cocos2d::Scene::init())
    {
        return false;
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    //loading start scene and player
    
    this->enemyLayer = Layer::create();
    
    this->addChild(enemyLayer);
    
	TMXTiledMap* map = TMXTiledMap::create("Level1.tmx");
    
	addChild(map, 10);
    
    mapMe = map;
    
    mapMoveCount = -0.5;
    
	auto blockLayer = map->getLayer("Blocks");
    
	auto hiddenLayer = map->getLayer("Hidden");
    
	auto fakeLayer = map->getLayer("Fake");
    
    auto animation = cocos2d::Animation::create();
    
    animation->addSpriteFrameWithFile("Koopa_256.png");
    animation->addSpriteFrameWithFile("Koopa_Run_256.png");
    animation->setRestoreOriginalFrame(true);
    animation->setDelayPerUnit(5.0f/38);
    koopaMove = cocos2d::Animate::create(animation);
    
    meta = map->getLayer("Meta");
    
    metaLayer = cocos2d::Layer::create();
    
    this->addChild(metaLayer);
    
    
    
    
    
    
    for (int i = 0; i < mapMe->getMapSize().width; ++i)
    {
        for (int j = 0; j < mapMe->getMapSize().height; ++j)
        {
            if (meta->getTileGIDAt(Vec2(i, j)) != 0)
            {
                Sprite* tile = Sprite::create("Blocks.png");
                tile->setScale(mapMe->getTileSize().width / tile->getContentSize().width,
                               mapMe->getTileSize().height / tile->getContentSize().height);
                PhysicsBody* tileBody = PhysicsBody::createBox(tile->getContentSize());
                tile->setPhysicsBody(tileBody);
                tile->setVisible(false);
                tileBody->setDynamic(false);
                tileBody->getShape(0)->setRestitution(0.0f);
                tileBody->getShape(0)->setFriction(0.5f);
                tile->setPosition(Vec2(i * mapMe->getTileSize().width + 16, (mapMe->getMapSize().height - j) * mapMe->getTileSize().height - 16));
                metaLayer->addChild(tile);
            }
        }
    }

    
    
    meta->setVisible(false);
    
	hiddenLayer->setVisible(false);
    
	enemy = map->getObjectGroup("Enemy");

	ValueMap sting = enemy->getObject("Stingtest");
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    
    //add player
    
    hero = new Hero(&keyCode);
    hero->getSprite()->setPosition(Vec2(64, 256));
    
    this->addChild(hero->getSprite());
    
    
    
    //add koopa list
    
    char buffer[30];
    
    string k = "Koopa";
    
    for(int i = 1;i <= 2;++i)
    {
        CCLOG("Koopa");
        sprintf(buffer, "%d",i);
        ValueMap koo = enemy->getObject(k+buffer);
        Koopa * koopa = new Koopa("Enemy_256.plist","Koopa_256.png",koo.at("x").asFloat(),koo.at("y").asFloat());
        koopa->getSprite()->runAction(cocos2d::RepeatForever::create(koopaMove));
        
        this->enemyLayer->addChild(koopa->getSprite());
        
        koopaList.push_back(koopa);
        
    }
    
    //add goomba list
    
    string g = "Goomba";
    
    for(int i = 1;i <= 7;++i)
    {
        CCLOG("Goomba");
        
        sprintf(buffer, "%d",i);
        
        auto goo = enemy->getObject(g + buffer);
        
        Goomba * goomba = new Goomba("Enemy_256.plist","Goomba_256.png",goo.at("x").asFloat(),goo.at("y").asFloat());
        
        
        this->enemyLayer->addChild(goomba->getSprite());
        
        goombaList.push_back(goomba);
        

    }
    
    //add piranha list
    
    string p = "Piranha";
    
    for(int i = 1;i <= 4;++i)
    {
        
        CCLOG("Piranha");
        sprintf(buffer, "%d",i);
        CCLOG("%s",buffer);
        auto pir = enemy->getObject(p + buffer);
        
        Piranha * piranha = new Piranha("Enemy_256.plist","Piranha_open_256.png",pir.at("x").asFloat(),pir.at("y").asFloat());
        
        piranha->setMoveSpeed(0.0f);
        
        this->enemyLayer->addChild(piranha->getSprite());
        
        piranhaList.push_back(piranha);
    
        
    }
    
    //add fallBricks list
    
    string f = "Falling1";
    
    CCLOG("fallbricks");
    
    auto fall = enemy->getObject(f);
    
    FallBricks * fallBricks = new FallBricks(fall.at("x").asFloat(),fall.at("y").asFloat());
    
    this->enemyLayer->addChild(fallBricks->getSprite(),0);
    
    fallbricksList.push_back(fallBricks);
    
    
    //add Cloud list
    
    string c = "stingCloud";
    
    CCLOG("stingCloud");
    
    auto sCloud = enemy->getObject(c);
    
    Cloud * stingCloud = new Cloud("normalCloud.png",sCloud.at("x").asFloat(),sCloud.at("y").asFloat());
    
    this->addChild(stingCloud->nowSprite);
    
    cloudList.push_back(stingCloud);
    
    //add sting list
    
    string s = "Sting";
    
    CCLOG("Sting");
    
    for(int i = 1; i <= 8;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto stingValue = enemy->getObject(s + buffer);
        auto stingX = stingValue.at("x").asFloat();
        auto stingY = stingValue.at("y").asFloat();
        
        Sting * sting = new Sting("Sting.png",stingX,stingY);
        
        this->enemyLayer->addChild(sting->nowSprite);
        
        stingList.push_back(sting);
        
    }
    
    //add fake princess list
    
    CCLOG("fake");
    
    auto princessValue = enemy->getObject("fakePrincess");
    
    FakePrincess* fakePrincess = new FakePrincess("fakePrincess.png",princessValue.at("x").asFloat(),princessValue.at("y").asFloat());
    
    this->enemyLayer->addChild(fakePrincess->nowSprite);
    
    fakePrincessList.push_back(fakePrincess);
    
    // add pass point
    
    auto pass = enemy->getObject("Pass");
    
    
   

    
    
    
    
    
    
    
   
    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event)
    {
        keyCode[KeyCode] = true;
        CCLOG("Press");
    };
    keyboardListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event)
    {
        keyCode[KeyCode] = false;
        CCLOG("Release");
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    this->scheduleUpdate();
    return true;
};

void GameScene::update(float dt)
{
    
    //CCLOG("update");
    
    
    
  /*  auto heroPositionX = hero->getSprite()->getPositionX();
    
    auto heroPositionY = hero->getSprite()->getPositionY();*/
    
    auto formerX = mapMe->getPositionX();
    
    
    //mapMe->setPositionX(mapMe->getPositionX()-1);
    
    auto nowX = mapMe->getPositionX();
    
    auto d = nowX - formerX;
    
   // CCLOG("%f %f",hero->getPositionX(),hero->getPositionY());
    
  /*  for(auto item = piranhaList.begin();item != piranhaList.end();)
    {
        
        //item->judge(mapMe, heroPositionX, heroPositionY);
        if((*item)->deleted())
        {
            auto del = item;
            ++item;
            piranhaList.erase(del);
            delete *del;
            continue;
        }
        ++item;
    }
    
    for(auto item = goombaList.begin();item != goombaList.end();)
    {
        //item->judge(mapMe, heroPositionX, heroPositionY);
        
    }
    
    for(auto item = koopaList.begin();item != koopaList.end();)
    {
        if((*item)->deleted())
        {
            auto del = item;
            ++item;
            koopaList.erase(del);
            delete *del;
            continue;
        }
        if(!(*item)->getTrigger())
        {
            
            
        }
        
        
        (*item)->update(mapMe);
        ++item;
    }
    
    for(auto item = fallbricksList.begin();item!=fallbricksList.end();)
    {
        if((*item)->isOutScene())
        {
            auto del = item;
            ++item;
            fallbricksList.erase(del);
            delete *del;
            continue;
        }
    }
    
    for(auto item:stingList)
    {
        
    }
    
    for(auto item:cloudList)
    {
       
    }
    for(auto item:fakePrincessList)
    {
        
    }
   */
    
    
    hero->run();
    
    
    
    
    
    
    
    
    
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
    
    scene->getPhysicsWorld()->setGravity(Vec2(0,-400));
	
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

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
#include "GameScene.hpp"


/**
 * TODO 潮潮在这里加上描述
 * @return
 */
bool GameScene::init()
{
    if(!cocos2d::Layer::init())
    {
        CCLOG("error");
        return false;
        
    }
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    //loading start scene and player
    map = new cocos2d::TMXTiledMap();
    map->initWithTMXFile("Level1.tmx");
    
    CCLOG("OK");
    this->addChild(map,0);
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy_256.plist");
    
   Enemy * enemy1 = new Enemy("Koopa_256.png",200,200,Enemy::KOOPA);
   this->addChild(enemy1->sprite,0);
   enemyTest.push_back(enemy1);
    
    
    
    return true;
};

//deal with some menu incidents

void GameScene::menuCallBack(cocos2d::Ref *pSender)

{
    
}
void GameScene::update(float dt)
{
    for(auto item:enemyTest)
    {
        if(!item->isDead)
        {
            item->update(map);
        }
    }
}

cocos2d::Scene * GameScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

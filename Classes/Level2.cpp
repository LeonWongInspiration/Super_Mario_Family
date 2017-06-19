//
//  Level2.cpp
//  MyCppGame
//
//  Created by 梁永潮 on 2017/6/18.
//
//

#include "Level2.hpp"


//
//  Level1.cpp
//  Physics
//
//  Created by Leon Wong on 15/6月.
//
//

#include "Level2.hpp"

#include "SimpleAudioEngine.h"

#include "Utility.h"

USING_NS_CC;

void Level2::setupMetaLayer(){
    const int mapW = map->getMapSize().width;
    const int mapH = map->getMapSize().height;
    
    const int tileW = map->getTileSize().width;
    const int tileH = map->getTileSize().height;
    
    this->mapSize = map->getMapSize();
    this->screenSize = Director::getInstance()->getWinSize();
    this->mapTileSize = map->getTileSize();
    
    for (int i = 0; i < mapW; ++i){
        for (int j = 0; j < mapH; ++j){
            if (meta->getTileGIDAt(Vec2(i, j)) != 0){
                Sprite* tile = Sprite::create("Blocks.png");
                //Sprite* tile = meta->getTileAt(Vec2(i, j));
                tile->setScale(this->mapTileSize.width / tile->getContentSize().width, this->mapTileSize.height / tile->getContentSize().height);
                PhysicsBody* tileBody = PhysicsBody::createBox(tile->getContentSize());
                tile->setPhysicsBody(tileBody);
                tile->setVisible(false);
                tileBody->setDynamic(false);
                tileBody->getShape(0)->setRestitution(0.0f);
                tileBody->getShape(0)->setFriction(0.5f);
                tile->setPosition(Vec2(i * tileW + 16, (mapH - j) * tileH - 16));
                this->metaLayer->addChild(tile);
            }
        }
    }
}

void Level2::setupHiddenLayer()
{
    const int mapW = map->getMapSize().width;
    const int mapH = map->getMapSize().height;
    
    const int tileW = map->getTileSize().width;
    const int tileH = map->getTileSize().height;
    
    this->mapSize = map->getMapSize();
    this->screenSize = Director::getInstance()->getWinSize();
    this->mapTileSize = map->getTileSize();
    
    for (int i = 0; i < mapW; ++i) {
        for (int j = 0; j < mapH; ++j) {
            if (hidden->getTileGIDAt(Vec2(i, j)) != 0) {
                Sprite* tile = Sprite::create("3.png");
                //Sprite* tile = hidden->getTileAt(Vec2(i, j));
                tile->setScale(this->mapTileSize.width / tile->getContentSize().width, this->mapTileSize.height / tile->getContentSize().height);
                tile->setVisible(false);
                tile->setPosition(Vec2(i * tileW + 16, (mapH - j) * tileH - 16));
                InvisibleBlock* block = new InvisibleBlock(tile);
                
                block->getSprite()->setTag(100);
                this->hiddenLayer->addChild(block->getSprite());
                invisibleList.push_back(block);
            }
        }
    }
}

void Level2::keepHeroInLimitedRange(){
    if(this->heroManager->getPositionX() >= 400){
        CCLOG("Limit Hero PositionX from %f to 400", this->heroManager->getPositionX());
        float moveLen = this->heroManager->getPositionX() - 400;
        this->map->setPositionX(this->map->getPositionX() - moveLen);
        this->metaLayer->setPositionX(this->metaLayer->getPositionX() - moveLen);
        this->enemyLayer->setPositionX(this->metaLayer->getPositionX());
        this->hiddenLayer->setPositionX(this->hiddenLayer->getPositionX() - moveLen);
        this->heroManager->getSprite()->setPositionX(this->heroManager->getPositionX() - moveLen);
    }
    
    if (this->heroManager->getPositionX() < 0)
        this->heroManager->getSprite()->setPositionX(0);
    
}

void Level2::update(float dt)
{
    //physic world
    
    this->heroManager->run();
    
    this->keepHeroInLimitedRange();
    
    auto heroWorldPositon = heroManager->getSprite()->getParent()->convertToWorldSpace(heroManager->getSprite()->getPosition());
    //    CCLOG("Hero VelocityX: %f", this->heroManager->getPhysicsBody()->getVelocity().x);
    
    
    
    //koopa list
    
    for(auto item = koopaList.begin(); item!=koopaList.end();)
    {
        if((*item)->deleted())
        {
            auto del = item;
            item++;
            koopaList.erase(del);
            continue;
        }
        if((*item)->getSprite()->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::dead &&
           !(*item)->dead())
        {
            (*item)->addCount();
        }
        
        
        auto koopaNodePosition = (*item)->getSprite()->getPosition();
        
        auto heroNodePositon = heroManager->getSprite()->getPosition();
        
        auto koopaWorldPosition = (*item)->getSprite()->getParent()->convertToWorldSpace(koopaNodePosition);
        
        auto heroWorldPositon = heroManager->getSprite()->getParent()->convertToWorldSpace(heroNodePositon);
        
        auto heroInKoopa = (*item)->getSprite()->getParent()->convertToNodeSpace(heroWorldPositon);
        
        auto koopaInHero = heroManager->getSprite()->getParent()->convertToNodeSpace(koopaWorldPosition);
        
        
        (*item)->action(heroInKoopa.x);
        
        auto x = (*item)->getSprite()->getPositionX();
        switch ((*item)->getSprite()->getTag())
        {
            case 1:
                if(x < 980 && (*item)->getDir() == LEFT)
                {
                    (*item)->switchDir();
                }
                if(x > 1285 &&!(*item)->flag && (*item)->getDir() == RIGHT)
                {
                    (*item)->switchDir();
                }
                break;
            case 2:
                if((x < 4400 &&(*item)->getDir() == LEFT)|| (x > 4675 && (*item)->getDir() == RIGHT))
                {
                    (*item)->switchDir();
                }
                break;
            case 3:
                if((x < 6858 &&(*item)->getDir() ==LEFT) || (x > 6885 && (*item)->getDir() == RIGHT))
                {
                    (*item)->switchDir();
                }
                
            default:
                break;
        }
        CCLOG("koopa'X: %f",(*item)->getSprite()->getPositionX());
        
        
        
        
        
        item++;
    }
    
    //goomba list
    
    for(auto item = goombaList.begin(); item!=goombaList.end();)
    {
        if((*item)->deleted())
        {
            auto del = item;
            item++;
            goombaList.erase(del);
            continue;
        }
        if((*item)->getSprite()->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::dead &&
           !(*item)->dead())
        {
            (*item)->dead(true);
        }
        
        
        auto heroInGoomba = (*item)->getSprite()->getParent()->convertToNodeSpace(heroWorldPositon);
        

        if((*item)->getSprite()->getPhysicsBody()->getVelocity().x > 0 &&(*item)->getDir() == LEFT)
        {
            (*item)->switchDir();
        }
        else if((*item)->getSprite()->getPhysicsBody()->getVelocity().x < 0 && (*item)->getDir() ==RIGHT)
        {
            (*item)->switchDir();
        }
        
        
        
        (*item)->run(heroInGoomba.x);
        item++;
        
    }
    
    
    //piranha list
    
    for(auto item = piranhaList.begin(); item!=piranhaList.end();)
    {
        if((*item)->deleted())
        {
            auto del = item;
            item++;
            piranhaList.erase(del);
            continue;
        }
        //CCLOG("heroY %f",heroManager->getPositionY());
        CCLOG("piranha %d",(*item)->getSprite()->getTag());
        CCLOG("%f",(*item)->getSprite()->getPositionY());
        
        
        auto heroInPiranha = (*item)->getSprite()->getParent()->convertToNodeSpace(heroWorldPositon);
        
        
        
        (*item)->up(heroInPiranha.x);
        item++;
    }
    
    //fallbricks list
    for (auto item = fallBricksList.begin(); item != fallBricksList.end(); )
    {
        if((*item)->isOutScene())
        {
            auto del = item;
            item++;
            fallBricksList.erase(del);
            continue;
        }
        
        
        // CCLOG("%f",(*item)->getSprite()->getPositionX());
        // CCLOG("%f",enemyLayer->getPositionX());
        
        auto HeroInBricks = (*item)->getSprite()->getParent()->convertToNodeSpace(heroWorldPositon);
        
        (*item)->run(HeroInBricks.x);
        if((*item)->getSprite()->getPositionY() < 112 && (*item)->getSprite()->getTag() == 1)
        {
            (*item)->setSpeed(Vec2(0,0));
            auto del = item;
            item++;
            fallBricksList.erase(del);
            continue;
        }

        
        CCLOG(" fallbricks Y: %f",(*item)->getSprite()->getPositionY());
        
        item++;
    }
    
    //invisible blocks
    for(auto item = invisibleList.begin();item != invisibleList.end();++item)
    {
        auto heroInVisible = (*item)->getSprite()->getParent()->convertToNodeSpace(heroWorldPositon);
        (*item)->collideHero(heroInVisible);
        
        if((*item)->add()&&(*item)->getSprite()->getTag() == 70)
        {
            (*item)->show();
        }
    }
    
    for(auto item :staticEnemyList)
    {
        if(item->getSprite()->getTag() == 60)
            item->changeSprite();
    }
    
}

Scene* Level2::createScene(){
    auto scene = Level2::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -400));
    
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    
    auto layer = Level2::create();
    scene->addChild(layer);
    return scene;
    
}

// on "init" you need to initialize your instance
bool Level2::init(){
    // Super init first
    if ( !Scene::init() ){
        return false;
    }
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Level2.mp3", true);
    
    // First save the map in the scene
    this->map = TMXTiledMap::create("Level2.tmx");
    
    // Get the layers needed
    this->meta = this->map->getLayer("Meta");
    meta->setVisible(false);
    
    // Get enemies
    this->enemyObjectGroup = map->getObjectGroup("Enemy");
    
    // Get flags
    
    this->flagObjectGroup = map->getObjectGroup("Flag");
    
    //Get Hidden blocks
    
    this->hidden = this->map->getLayer("Hidden");
    
    hidden->setVisible(false);
    
    
    this->hiddenLayer = Layer::create();
    
    this->hiddenLayer->setVisible(true);// hero need to set the visible to false to hide the blocks!
    
    
    // Add the map to this scene
    this->addChild(this->map,10);
    
    // Init Layers
    this->metaLayer = Layer::create();
    this->enemyLayer = Layer::create();
    
    // Set up meta Layer to include bodies
    this->setupMetaLayer();
    this->addChild(this->metaLayer);
    
    // Set up enemy Layer to include enemies
    
    this->setupEnemyLayer();
    
    
    this->addChild(this->enemyLayer);
    
    
    this->setupHiddenLayer();
    
    this->addChild(hiddenLayer);
    
    
    
    
    // Set up hero
    this->heroManager = new Hero(&(this->keyCode));
    // Get hero in the Scene
    this->heroManager->getSprite()->setPosition(Vec2(64, 256));
    this->heroManager->getSprite()->setAnchorPoint(Vec2(0, 0));
    this->heroManager->getSprite()->setTag(50);
    this->addChild(this->heroManager->getSprite());
    
    scheduleUpdate();
    
    
    
    
    
    return true;
    
    
    
}



void Level2::setupEnemyLayer()
{
    auto enemy = map->getObjectGroup("Enemy");
    char buffer[20] ;
    std::string enemyName;
    int enemyNumber;
    
    // Add koopa to enemy layer
    
    enemyName = "Koopa";
    enemyNumber = 3;
    
    for(int i = 1;i <= enemyNumber;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto koopaValue = flagObjectGroup->getObject(enemyName + buffer);
        Koopa * koopa = new Koopa("Enemy_256.plist","Koopa_256.png",koopaValue.at("x").asFloat(),koopaValue.at("y").asFloat());
        
        koopa->getSprite()->setTag(i);
        
        this->enemyLayer->addChild(koopa->getSprite());
        
        
        
        koopaList.push_back(koopa);
    }
    
    
    //Add goomba to enemy layer
    
    enemyName = "Goomba";
    enemyNumber = 4;
    
    for (int i = 1; i <= enemyNumber; ++i)
    {
        sprintf(buffer, "%d",i);
        
        auto goombaValue = flagObjectGroup->getObject(enemyName + buffer);
        
        Goomba * goomba = new Goomba("Enemy_256.plist","Goomba_256.png",goombaValue.at("x").asFloat(),goombaValue.at("y").asFloat());
        
        goomba->getSprite()->setTag(i);
        
        this->enemyLayer->addChild(goomba->getSprite());
        
        goombaList.push_back(goomba);
    }
    
    //Add piranha to enemy layer
    
    enemyName = "Piranha";
    enemyNumber = 6;
    
    for(int i = 1; i <= enemyNumber; ++i)
    {
        sprintf(buffer, "%d",i);
        
        auto piranhaValue = enemy->getObject(enemyName + buffer);
        
        Piranha * piranha = new Piranha("Enemy_256.plist","Piranha_open_256.png",piranhaValue.at("x").asFloat(),piranhaValue.at("y").asFloat());
        
        piranha->setMoveSpeed(0.0f);
        
        piranha->getSprite()->setTag(i);
        
        this->enemyLayer->addChild(piranha->getSprite());
        
        piranhaList.push_back(piranha);
    }
    
    //Add fallbricks to the enemy layer
    
    enemyName = "Falling";
    enemyNumber = 2;
    for(int i = 1; i <= enemyNumber;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto fallBricksValue = enemy->getObject(enemyName + buffer);
    
        FallBricks * fallBricks = new FallBricks(fallBricksValue.at("x").asFloat(),fallBricksValue.at("y").asFloat());
        
        fallBricks->getSprite()->setTag(i);
        
        this->enemyLayer->addChild(fallBricks->getSprite(),0);
    
        fallBricksList.push_back(fallBricks);
    }
    
    
    
    //Add static enemy to the enemy layer
    
    //add sting cloud
    
    enemyName = "Cloud";
    
    enemyNumber = 3;
    
    for(int i = 1;i  < enemyNumber;++i)
    {
        sprintf(buffer, "%d",i);
        auto stingCloudValue = enemy->getObject(enemyName + buffer);
    
        Cloud * stingCloud = new Cloud("normalCloud.png",stingCloudValue.at("x").asFloat(),stingCloudValue.at("y").asFloat());
        
        stingCloud->getSprite()->setTag(120);
    
        this->enemyLayer->addChild(stingCloud->getSprite());
    
        staticEnemyList.push_back(stingCloud);
    }
    
    //add sting(on the ground)
    
    enemyName = "Sting";
    enemyNumber = 4;
    for(int i = 1; i <= enemyNumber;++i)
    {
        sprintf(buffer, "%d",i);
        
        auto stingValue = enemy->getObject(enemyName + buffer);
        auto stingX = stingValue.at("x").asFloat();
        auto stingY = stingValue.at("y").asFloat();
        
        Sting * sting = new Sting("Sting.png",stingX,stingY);
        
        this->enemyLayer->addChild(sting->getSprite());
        
        staticEnemyList.push_back(sting);
        
    }
    
    //add fake princess
    
}

void Level2::onEnter(){
    
    Scene::onEnter();
    
    // Listen the keyboard
    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event){
        if (KeyCode != EventKeyboard::KeyCode::KEY_UP_ARROW)
            this->keyCode[KeyCode] = true;
        else {
            heroManager->jump();
        }
        CCLOG("Press");
    };
    keyboardListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode KeyCode,cocos2d::Event * event){
        if (KeyCode != EventKeyboard::KeyCode::KEY_UP_ARROW)
            this->keyCode[KeyCode] = false;
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    
    // Listen the collisions
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Level2::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}

bool Level2::onContactBegin(const cocos2d::PhysicsContact& contact){
    cocos2d::Sprite* spriteA = static_cast<cocos2d::Sprite*>(contact.getShapeA()->getBody()->getNode());
    cocos2d::Sprite* spriteB = static_cast<cocos2d::Sprite*>(contact.getShapeB()->getBody()->getNode());
    int bitMaskA = spriteA->getPhysicsBody()->getCollisionBitmask();
    int bitMaskB = spriteB->getPhysicsBody()->getCollisionBitmask();
    
    CCLOG("%d %d contact", bitMaskA, bitMaskB);
    
    auto tag1 = spriteA->getTag();
    auto tag2 = spriteB->getTag();
    
    
    if((tag1 == 50 &&tag2 == 100)||(tag1 == 100&&tag2 == 50))
    {
        if(tag1 == 100 )
        {
            spriteA->setTag(70);
        }
        else if(tag2 == 100)
        {
            spriteB->setTag(70);
        }
        return true;
    }
    if(tag1 == 70 ||tag2 == 70)
    {
        return true;
    }
    if(tag1 == 120 && tag2 == 50)
    {
        spriteA->setTag(60);
        spriteB->getPhysicsBody()->setContactTestBitmask(0x0000);
    }
    if(tag2 == 120 && tag1 == 50)
    {
        spriteB->setTag(60);
        spriteA->getPhysicsBody()->setContactTestBitmask(0x0000);
    }
    
    if (spriteA->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero
        || spriteB->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero){
        cocos2d::Sprite* heroSprite =
        spriteA->getPhysicsBody()->getCollisionBitmask() == SpriteBitmask::hero ? spriteA : spriteB;
        cocos2d::Sprite* enemySprite =
        spriteA->getPhysicsBody()->getCollisionBitmask() != SpriteBitmask::hero ? spriteA : spriteB;
        
        int heroBitmask = heroSprite->getPhysicsBody()->getCollisionBitmask();
        int spriteBitmask = enemySprite->getPhysicsBody()->getCollisionBitmask();
        
        if (spriteBitmask == SpriteBitmask::piranha ||
            spriteBitmask == SpriteBitmask::cloud ||
            spriteBitmask == SpriteBitmask::sting ||
            spriteBitmask == SpriteBitmask::fakePrincess){
            heroSprite->getPhysicsBody()->setContactTestBitmask(0x0000);
        }
        
        if (spriteBitmask == SpriteBitmask::goomba ||
            spriteBitmask == SpriteBitmask::koopa){
            if (heroSprite->getPositionY() + 1 >= enemySprite->getPositionY() + 32){
                enemySprite->getPhysicsBody()->setContactTestBitmask(0x0000);
                enemySprite->getPhysicsBody()->setCollisionBitmask(SpriteBitmask::dead);
                
                CCLOG("Enemy DIED");
                
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("StepOn.mp3");
                heroSprite->getPhysicsBody()->applyImpulse(cocos2d::Vec2(0, 1000));
            }
        }
    }
    
    
    return true;
}





























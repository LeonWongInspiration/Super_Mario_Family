/**
 * @brief GameScene class
 * @file Classes/GameScene.cpp
 * @Author Yates Liang
 *
 * TODO 潮潮在这里加一下描述
 *
 * <ChangeLog>
 * -----------------------------------------------------------------------------------------------
 * |   <Build>   |   <Author>   | <Description>                                                  |
 * -----------------------------------------------------------------------------------------------
 * |201705102131 |   Leon Wong  | Introducing Doxygen for this file.                             |
 * |             |              |                                                                |
 * |             |              |                                                                |
 * -----------------------------------------------------------------------------------------------
 */

#ifndef GameScene_hpp
#define GameScene_hpp

#include "HelloWorldScene.h"
#include "Box2D/Box2D.h"
#include "Block.h"
#include "Piranha.hpp"
#include "Koopa.hpp"
#include "Goomba.hpp"
#include "FallBricks.hpp"
#include "Hero.h"
#include "Cloud.h"
#include "Sting.h"
#include "fakePrincess.h"
#include <list>
#include <map>



/**
 * @brief an enum used to
 * TODO 潮潮把这里描述一下
 */
typedef enum
{
    PAUSE=20,
    CONTINUE,
    EXIT
}MENU_INCIDENT;

/**
 * @brief TODO 潮潮在这里加上简介, 参考GameHelp的样式
 */
class GameScene:public cocos2d::Layer
{
private:
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keyCode;
    
    float mapMoveCount;
    
    Hero * hero;
    
public:
    virtual bool init();
    
    static cocos2d::Scene * createScene();
    
    void menuCallBack(cocos2d::Ref * pSender);
    
    void gamePause();
    
    void gameContinue();
    
    void update(float dt);
    
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode KeyCode);
    
    std::list<Koopa*> koopaList;
    
    std::list<Goomba*> goombaList;
    
    std::list<Piranha*> piranhaList;
    
    std::list<FallBricks*> fallbricksList;
    
    std::list<Cloud*> cloudList;
    
    std::list<Sting*> stingList;
    
    std::list<FakePrincess * > fakePrincessList;

    
    TMXTiledMap * mapMe;
    
    TMXObjectGroup * enemy;
    
    cocos2d::Animate * koopaMove;
    
	CREATE_FUNC(GameScene);

	
};





#endif /* GameScene_hpp */

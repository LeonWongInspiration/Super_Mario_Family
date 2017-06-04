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

#include <vector>
#include "Enemy.hpp"

USING_NS_CC;
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
    
    cocos2d::TMXTiledMap * map;
    
   std::vector<Enemy*> enemyTest;
public:
    virtual bool init();
    
    static cocos2d::Scene * createScene();
    
    void menuCallBack(cocos2d::Ref * pSender);
    
    void gamePause();
    
    void gameContinue();
    
    void update(float dt);
    

    CREATE_FUNC(GameScene);
    
};





#endif /* GameScene_hpp */

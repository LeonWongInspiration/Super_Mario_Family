//
//  Level1.hpp
//  Physics
//
//  Created by Leon Wong on 15/6月.
//
//

#ifndef Level1_hpp
#define Level1_hpp

#include "cocos2d.h"
#include "Hero.h"
#include "Piranha.hpp"
#include "InvisibleBlock.h"
#include "Cloud.h"
#include "Koopa.hpp"
#include "FallBricks.hpp"
#include "Goomba.hpp"
#include "Sting.h"
#include "fakePrincess.h"
#include "Level2.hpp"
#include "GameOver.h"




class Level1 : public cocos2d::Scene{
private:
    /// The TMX Map
    TMXTiledMap* map;
    
    /// "Meta" Layer in the map
    TMXLayer* meta;
    
	/// "Hidden" Layer in the map
	TMXLayer* hidden;

    /// "Enemy" Object Goup in the map
    TMXObjectGroup* enemyObjectGroup;
    
    /// A layer used to contain all the physics bodies to form the map
    Layer* metaLayer;
    
    /// A layer used to contain all the enemies' Sprites
    Layer* enemyLayer;
    
	/// A layer used to contain all the hidden blocks
	Layer* hiddenLayer;

    /// Size of the screen
    Size screenSize;
    
    /// Size of the map (tiles)
    Size mapSize;
    
    /// Size of the tiles in this map (pixels)
    Size mapTileSize;
    
    /// A map used to keep the information of keys
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keyCode;
    
    /// A list used to store koopa
    std::list<Koopa *> koopaList;
    
    /// A list used to store goomba
    std::list<Goomba *> goombaList;
    
    /// A list used to store piranha
    std::list<Piranha *> piranhaList;
    
    /// A list used to store fallbricks
    std::list<FallBricks *> fallBricksList;
    
    /// A list to store static enemy
    std::list<Block *> staticEnemyList;
    
    /// A list to store invisible blocks
    
    std::list<InvisibleBlock *> invisibleList;
    
    Hero* heroManager;

    /**
     * @brief Create a series of physicsbodies to form the map
     */
    void setupMetaLayer();
    
	/**
	* @brief Create a Hidden Layer
	*/
	void setupHiddenLayer();

    /**
     * @brief Keep hero in the limited range of the screen
     */
    void keepHeroInLimitedRange();
    
    /**
     * @brief Set up a Layer containing all the Sprites of enemies
     */
    void setupEnemyLayer();
    
    
    

    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    
    void update(float dt) override;
    
    void setPosition(Point p);
    // implement the "static create()" method manually
    CREATE_FUNC(Level1);
    
    void onEnter() override;
    
    bool onContactBegin(const cocos2d::PhysicsContact& contact);
    
    //Detect Pass Point
    
    bool isPass(Vec2 heroPosition);
    
    
    
};

#endif /* Level1_hpp */

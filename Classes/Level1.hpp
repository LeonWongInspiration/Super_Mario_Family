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

class Level1 : public cocos2d::Scene{
private:
    /// The TMX Map
    TMXTiledMap* map;
    
    /// "Meta" Layer in the map
    TMXLayer* meta;
    
    /// "Enemy" Object Goup in the map
    TMXObjectGroup* enemyObjectGroup;
    
    /// A layer used to contain all the physics bodies to form the map
    Layer* metaLayer;
    
    /// A layer used to contain all the enemies' Sprites
    Layer* enemyLayer;
    
    /// Size of the screen
    Size screenSize;
    
    /// Size of the map (tiles)
    Size mapSize;
    
    /// Size of the tiles in this map (pixels)
    Size mapTileSize;
    
    /// A map used to keep the information of keys
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keyCode;
    
    Hero* heroManager;

    /**
     * @brief Create a series of physicsbodies to form the map
     */
    void setupMetaLayer();
    
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
    
    virtual bool init();
    
    void update(float delta);
    
    void setPosition(Point p);
    // implement the "static create()" method manually
    CREATE_FUNC(Level1);
};

#endif /* Level1_hpp */
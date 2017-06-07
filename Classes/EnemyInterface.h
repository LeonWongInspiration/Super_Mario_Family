#pragma once

#define Interface class

#ifndef ENEMYINTERFACE_ENEMYINTERFACE_H
#define ENEMYINTERFACE_ENEMYINTERFACE_H

/**
 * An interface for enemies.
 */

Interface EnemyInterface{
    /**
     * @brief Get the pointer to the Sprite.
     * @return The pointer to the Sprite of this enemy
     */
    virtual cocos2d::Sprite* getSprite() = 0;

    /**
     * @brief Get the size of the Sprite.
     * @return A Vec2 containing the size of this Sprite
     */
    virtual cocos2d::Vec2 getSize() = 0;

    /**
     * @brief Get the Position of the Sprite
     * @return A vec2 containing the position of this Sprite
     */
    virtual cocos2d::Vec2 getPosition() = 0;
};

#endif //ENEMYINTERFACE_ENEMYINTERFACE_H

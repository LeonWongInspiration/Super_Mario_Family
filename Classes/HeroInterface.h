#pragma once

#ifndef Interface
    #define Interface class
#endif

#ifndef implements
    #define implements virtual
#endif

#ifndef HEROINTERFACE_HEROINTERFACE_H
#define HEROINTERFACE_HEROINTERFACE_H

Interface HeroInterface{
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

#endif //HEROINTERFACE_HEROINTERFACE_H

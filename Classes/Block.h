#pragma once
#include "Hero.h"
#include "Utility.h"

USING_NS_CC;

/**
* @author Feng
* @file Block.h
* @brief An abstract class for all static enemies. 
*
* This is a class which can create a Sprite for Block. 
*
*/
class Block
{
private:
	///The sprite of Block
	Sprite* nowSprite;
public:
	/**
	* @retval cocos2d::Sprite*
	* @return The Sprite of block. 
	*
	*/
	Sprite* getSprite()
	{
		return nowSprite;
	}

	/**
	* @retval void
	* @brief Change the picture when hero collide cloud.
	*
	*/
	void changeSprite()
	{
		nowSprite->setTexture("Block//hurtfulCloud.png");
	}
	/**
	* @brief A constructor for Block.
	* @param filename of Block
	* @param position X Block
	* @param position Y Block
	*/
	Block(const char * fileName,float x,float y);
	/**
	* @brief default destructor.
	*
	*/
	~Block();
};
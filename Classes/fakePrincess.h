#pragma once
#include "Hero.h"
#include "Block.h"

/**
* @author Feng
* @file fakePrincess.h
* @brief A class for Enemy FakePrincess.
*
* This is a class which can create a Sprite with its PhysicsBody for fakePrincess. 
*
*/
class FakePrincess : public Block
{
public:
	/**
	* @brief A constructor for this.
	* @param filename of fakePrincess
	* @param position X of fakePrincess
	* @param position Y of fakePrincess
	*/
	FakePrincess(const char* fileName,float x,float y);
	/**
	* @brief default destructor.
	*
	*/
	~FakePrincess();
private:
	///The Physicbody of fakePrincess
	PhysicsBody* body;
	///The width of fakePrincess
	float width = 32;
	///The height of fakePrincess
	float height = 64;
};
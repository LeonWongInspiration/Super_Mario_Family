#pragma once
#include "Block.h"

/**
* @author Feng
* @file Sting.h
* @brief A class for Enemy Sting.
*
* This is a class which can create a Sprite with its PhysicsBody for Sting.
*
*/
class Sting :public Block
{
public:
	/**
	* @brief A constructor for this.
	* @param filename of Sting
	* @param position X of Sting
	* @param position Y of Sting
	*/
	Sting(const char* fileName,float x,float y);
	/**
	* @brief default destructor.
	*
	*/
	~Sting();
private:
	///The Physicbody of Sting
	PhysicsBody * body;
	///The width of Sting
	float width = 32;
	///The height of Sting
	float height = 32;
};
#pragma once

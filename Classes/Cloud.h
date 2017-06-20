#pragma once
#include "Block.h"
using namespace std;

/**
* @author Feng
* @file Cloud.h
* @brief A class for Enemy Cloud. 
*
* This is a class which can create a Sprite with its PhysicsBody for Cloud,
*
*/
class Cloud : public Block
{
public:
	/**
	* @brief A constructor for this. 
	* @param filename of the cloud
	* @param position X of the cloud
	* @param position Y of the cloud
	*/
	Cloud(const char* filename,float x,float y);
	/**
	* @brief default destructor. 
	*
	*/
	~Cloud();

private:
	///The Physicbody of the cloud
	PhysicsBody * body;
	///The width of the cloud
	float width=128;
	///The height of the cloud
	float height=64;
};

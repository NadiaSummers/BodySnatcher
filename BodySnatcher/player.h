/**
* @class player extends object
* @brief controls the player and his movements
*
* @author Daniel Manganaro
* @version 1
* @date 13/04/2014 Daniel Manganaro - Basic Implementation
*/

#ifndef __PLAYER_H
#define __PLAYER_H

#include <string>
using namespace std;

#include "gameObject.h"
#include "vector.h"

class player:public gameObject{
private:
	vector3D model[8];

public:
	/*
	* @brief Default Constructor
	*/
	player():gameObject(){};

	/*
	* @brief Alternate Constructor
	* @param vector3D location - location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision sphere
	*/
	player(vector3D location, float sSize, float obScale):gameObject(location, sSize, obScale){};

	/*
	* @brief Alternate Constructor
	* @param float x - x location of the object in the world
	* @param float y - y location of the object in the world
	* @param float z = z location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision box
	*/
	player(float x, float y, float z, float sSize, float obScale):gameObject(x,y,z,sSize,obScale){};

	/*
	* @brief loads the model of the player from file
	* @param string filename - name of the file
	* @return bool - true if file loads else false
	*/
	bool loadModel(string filename);

	/*
	* @brief renders the player
	* @return void
	*/
	void render();

	/*
	* @brief performs actions when player collides with another object
	* @param gameObject &collisionObject - reference to object player is colliding with
	* @return void
	*/
	void onCollision(gameObject &collisionObject);
};

#endif
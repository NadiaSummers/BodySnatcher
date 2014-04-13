/**
* @class enemy extends object
* @brief controls the enemies in the game
*
* @author Daniel Manganaro
* @version 1
* @date 13/04/2014 Daniel Manganaro - Basic Implementation
*/

#ifndef __ENEMY_H
#define __ENEMY_H

#include <string>
using namespace std;

#include "gameObject.h"
#include "vector.h"

class enemy:public gameObject{
private:
	vector3D model[8];

public:
	/*
	* @brief Default Constructor
	*/
	enemy():gameObject(){};

	/*
	* @brief Alternate Constructor
	* @param vector3D location - location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision sphere
	*/
	enemy(vector3D location, float sSize, float obScale):gameObject(location, sSize, obScale){};

	/*
	* @brief Alternate Constructor
	* @param float x - x location of the object in the world
	* @param float y - y location of the object in the world
	* @param float z = z location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision box
	*/
	enemy(float x, float y, float z, float sSize, float obScale):gameObject(x,y,z,sSize,obScale){};

	/*
	* @brief loads the model of the enemy from file
	* @param string filename - name of the file
	* @return bool - true if file loads else false
	*/
	bool loadModel(string filename);

	/*
	* @brief renders the enemy
	* @return void
	*/
	void render();

	/*
	* @brief performs actions when enemy collides with another object
	* @param gameObject &collisionObject - reference to object enemy is colliding with
	* @return void
	*/
	void onCollision(gameObject &collisionObject);
};

#endif
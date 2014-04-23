/**
* @class gameObject
* @brief represents anything the engine can draw. All objects are derived from this class.
*/

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include <iostream>
#include "vector.h"
#include "collision.h"
#include "AABB.h"

using namespace std;

class gameObject
{
protected:
	virtual void render(){};
	virtual void onCollision(gameObject &collisionObject){};
	AABB boundingBox;			//axis aligned bounding box
	//virtual void animate(){};
public:
	/*
	* @brief Default Constructor
	*/
	gameObject();

	/*
	* @brief Alternate Constructor
	* @param vector3D location - location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision sphere
	*/
	gameObject(vector3D location, float obScale, float sSize);

	/*
	* @brief Alternate Constructor
	* @param float x - x location of the object in the world
	* @param float y - y location of the object in the world
	* @param float z = z location of the object in the world
	* @param float obScale - scale of the object
	* @param float sSize - size of the collision box
	*/
	gameObject(float x, float y, float z, float obScale, float sSize);

	/*
	* @brief determines whether this object is colliding with another
	* @param gameObject &obj - reference to another object
	* @return void
	*/
	void processCollision(gameObject &obj);

	/*
	* @brief sets the position of the object using a vector
	* @param vector3D pos - position of the object
	* @return void
	*/
	void setPosition(vector3D pos);

	/*
	* @brief sets the position of the object using x, y and z coordinates 
	* @param float x - x position of the object
	* @param float y - y position of the object
	* @param float z - z position of the object
	* @return void
	*/
    void setPosition(float x, float y, float z);

	/*
	* @brief sets the size of the collision sphere
	* @param unsigned short size - size of the sphere
	* @return void
	*/
	void setSphereSize(unsigned short size);
	
	/*
	* @brief set the scale of the object
	* @param float obScale - scale of the object
	* @return void
	*/
	void setScale(float obScale);
	
	/*
	* @brief gets the position of the object
	* @return vector3D - position of the object
	*/
	vector3D getPosition(){return position;}

	/*
	* @brief gets the x position of the object
	* @return float - x position of the object
	*/
	float getPositionX(){return position.getX();}
	
	/*
	* @brief gets the y position of the object
	* @return float - y position of the object
	*/
	float getPositionY(){return position.getY();}
    
	/*
	* @brief gets the z position of the object
	* @return float - z position of the object
	*/
	float getPositionZ(){return position.getZ();}
	
	/*
	* @brief gets the sphere size of the object
	* @return unsigned short - sphere size of the object
	*/
	unsigned short getSphereSize(){return sphereSize;}
	
	/*
	* @brief gets the scale of the object
	* @return float - scale of the object
	*/
	float getScale(){return scale;}
	
	/*
	* @brief increments the position of the object by a vector
	* @param vector3D - vector object's position is incremented by
	* @return void
	*/
	void setPositionInc(vector3D pos);
	
	/*
	* @brief sets the x position of the object
	* @param vector3D - position of the object
	* @return void
	*/
	void setPositionX(float x);
	
	/*
	* @brief sets the y position of the object
	* @param vector3D - position of the object
	* @return void
	*/
	void setPositionY(float y);
	
	/*
	* @brief sets the z position of the object
	* @param vector3D - position of the object
	* @return void
	*/
	void setPositionZ(float z);

private:
	vector3D position;           //position vector
	float scale;                //scaling factor
	float sphereSize;			//size of bounding sphere
};

#endif
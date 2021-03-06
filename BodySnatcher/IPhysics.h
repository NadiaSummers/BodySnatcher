/**
 * @class IPhysics
 * @brief The IPhysics facades the third party Bullet Physics and Collision Engine.
 * @brief It creates a new "world" then lets you add objects to that "world" and update the world each frame.
 * @brief Bullet will take care of collisions for you.
 *
 * @author Daniel Manganaro
 * @version 01
 * @date 10/04/2014 Daniel Manganaro - Basic Implementation
 */

#include "BulletPhysics.h" 

#ifndef IPHYSICS_H
#define IPHYSICS_H

class IPhysics{
public:
	/**
	* @brief create a collision box 
	* @param float sx - x scale of box 
	* @param float sy - y scale of box
	* @param float sz - z scale of box 
	* @oaram float xPoz - x position of box
	* @param float yPos - y position of box
	* @oaram float zPos - z position of box
	* @param float mass - mass of the box
	* @return btRigigBody* - a pointer to the new box
	*/
	virtual btRigidBody* createBox(float sx, float sy, float sz, float xPos, float yPos, float zPos, float mass) = 0;
	/**
	* @brief sets the gravity of the world
	* @param float - gravity of the world
	* @return void
	*/
	virtual void setGravity(float g) = 0;
	/**
	* @brief creates the ground plane of the world
	* @param float sx - x scale of ground plane 
	* @param float sy - y scale of ground plane
	* @param float sz - z scale of ground plane
	* @oaram float xPoz - x position of ground plane
	* @param float yPos - y position of ground plane
	* @oaram float zPos - z position of ground plane
	* @return btCollisionShape* - a pointer to the new ground plane
	*/
	virtual btCollisionShape* createGroundPlane(float xSize, float ySize, float zSize, float xPos, float yPos, float zPos) = 0;
	/**
	* @brief deletes all collision shapes created
	* @return void
	*/
	virtual void deleteCollisionShapes() = 0;
	/**
	* @brief simulares a single frame, goes in an Update function
	* @param float timeStep - time between each step
	* @return void
	*/
	virtual void simulate(float timeStep) = 0;
};

#endif
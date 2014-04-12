/**
 * @class IPhysics
 * @brief The IPhysics facades the Physics and Collision Engine
 *
 * @author Daniel Manganaro
 * @version 01
 * @date 10/04/2014 Daniel Manganaro - Basic Implementation
 */

#include "Physics\src\btBulletDynamicsCommon.h"

#ifndef IPHYSICS_H
#define IPHYSICS_H

class IPhysics{
private:
	btDefaultCollisionConfiguration* collisionConfiguration; //collision configuration contains default setup for memory
	btCollisionDispatcher* dispatcher; //use the default collision dispatcher
	btBroadphaseInterface* overlappingPairCache; 
	btSequentialImpulseConstraintSolver* solver; //the default constraint solver
	btDiscreteDynamicsWorld* dynamicsWorld;
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
public:
	/*
	* @brief Constructor
	*/
	IPhysics();
	/*
	* @brief Deconstructor
	*/
	~IPhysics();
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
	btRigidBody* createBox(float sx, float sy, float sz, float xPos, float yPos, float zPos, float mass);
	/**
	* @brief sets the gravity of the world
	* @param float - gravity of the world
	* @return void
	*/
	void setGravity(float g);
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
	btCollisionShape* createGroundPlane(float xSize, float ySize, float zSize, float xPos, float yPos, float zPos);
	/**
	* @brief deletes all collision shapes created
	* @return void
	*/
	void deleteCollisionShapes();
	/**
	* @brief simulares a single frame, goes in an Update function
	* @param float timeStep - time between each step
	* @return void
	*/
	void simulate(float timeStep);
};

#endif
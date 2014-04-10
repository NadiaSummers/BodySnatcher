/**
 * @class IPhysics
 * @brief The IPhysics facades the Physics and Collision Engine
 *
 * @author Daniel Manganaro
 * @version 01
 * @date 10/04/2014 Johanna Wald - Basic Implementation
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
	* Constructor
	*/
	IPhysics();
	/*
	* Deconstructor
	*/
	~IPhysics();
	void createBoundingBox(float, float, float);
	void transformBoundingBox(btCollisionShape*);
	void setGravity(float);
	void createGroundPlane(float, float, float, float, float, float);
	void addRigidBody();
	void deleteCollisionShapes();
	bool collision(btManifoldPoint&, const btCollisionObject*);

	
};

#endif
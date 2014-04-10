/*


*/

#include "Physics\src\btBulletDynamicsCommon.h"
#include "Physics\src\btBulletCollisionCommon.h"

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
	IPhysics();
	~IPhysics();
	void createBoundingBox(float, float, float);
	void setGravity(float);
	void createBoundingSphere(float);
	void deleteCollisionShapes();
};

#endif
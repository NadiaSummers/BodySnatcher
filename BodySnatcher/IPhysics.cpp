#include "IPhysics.h"

IPhysics::IPhysics(){
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0,-10,0));		
}

IPhysics::~IPhysics(){
	//delete dynamics world
	delete dynamicsWorld;
	//delete solver
	delete solver;
	//delete broadphase
	delete overlappingPairCache;
	//delete dispatcher
	delete dispatcher;
	//delete collistion configuration
	delete collisionConfiguration;
}
void IPhysics::setGravity(float g){
	dynamicsWorld->setGravity(btVector3(0, -g, 0));
}

void IPhysics::createBoundingBox(float x, float y, float z){
	btCollisionShape* boxShape = new btBoxShape(btVector3(btScalar(x),btScalar(y),btScalar(z)));
	collisionShapes.push_back(boxShape);
}

void IPhysics::deleteCollisionShapes(){
	for(int i = 0; i < collisionShapes.size(); i++){
		btCollisionShape* shape = collisionShapes[i];
		collisionShapes[i] = 0;
		delete shape;
	}
}

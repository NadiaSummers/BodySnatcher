#include "IPhysics.h"

IPhysics::IPhysics(){
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	overlappingPairCache = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0,-9.81f,0));		
}

IPhysics::~IPhysics(){
	delete dynamicsWorld;
	delete solver;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfiguration;
}
void IPhysics::setGravity(float g){
	dynamicsWorld->setGravity(btVector3(0, -g, 0));
}

btCollisionShape* IPhysics::createGroundPlane(float xSize, float ySize, float zSize, float xPos, float yPos, float zPos){
	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(xSize,ySize,zSize),1);
	collisionShapes.push_back(groundShape);

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(xPos, yPos, zPos));

	return groundShape;
}

btRigidBody* IPhysics::createBox(float sx, float sy, float sz, float xPos, float yPos, float zPos, float mass){
	btCollisionShape* boxShape = new btBoxShape(btVector3(btScalar(sx),btScalar(sy),btScalar(sz)));
	collisionShapes.push_back(boxShape);

	btTransform startTransform;
	startTransform.setIdentity();

	btScalar tMass(mass);

	//rigidBody is dynamic if and only if mass is non zero otherwise state
	bool isDynamic = (tMass != 0.f);

	btVector3 localInertia(0,0,0);
	if(isDynamic)
		boxShape->calculateLocalInertia(tMass,localInertia);

	startTransform.setOrigin(btVector3(xPos,yPos,xPos));

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(tMass, myMotionState, boxShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);
	dynamicsWorld->addRigidBody(body);
	return body;
}

void IPhysics::deleteCollisionShapes(){
	for(int i = 0; i < collisionShapes.size(); i++){
		btCollisionShape* shape = collisionShapes[i];
		collisionShapes[i] = 0;
		delete shape;
	}
}

void IPhysics::simulate(float timeStep){
	dynamicsWorld->stepSimulation(btScalar(timeStep), 10);
}


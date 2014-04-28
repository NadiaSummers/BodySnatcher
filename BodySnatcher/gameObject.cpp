#include "gameObject.h"	

unsigned int gameObject::numObjects = 0;

void gameObject::processCollision(gameObject &obj)
{
	if(boundingBox.checkCollison(position,obj.boundingBox,obj.position))
	{
		onCollision(obj);
	}
}

gameObject::gameObject(vector3D location, float obScale, float sSize, string modelID)
{
	mID = numObjects;
	numObjects++;
	position=location;
	sphereSize = sSize;
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0;
	  mModelID = modelID;
}

gameObject::gameObject(float x,float y,float z, float obScale, float sSize, string modelID)
{
	position.x=x;
	position.y=y;
	position.z=z;
	sphereSize = sSize;
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0; 
	mModelID = modelID;
}

gameObject::gameObject()
{
    position.x=position.y=position.z=0.0;
	sphereSize = 0;
	scale=1.0;
	mModelID = "";
}

void gameObject::setPosition(vector3D pos){
 position=pos;
}

void gameObject::setPositionInc(vector3D pos){
	position+=pos;
}

void gameObject::setPosition(float x, float y, float z){
	position.x=x;
	position.y=y;
	position.z=z;
}

void gameObject::setSphereSize(unsigned short size){
	if(size>0)
		sphereSize = size;
}


void gameObject::setScale(float obScale){
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0; 
}

void gameObject::setPositionX(float x){
	position.x=x;
}

void gameObject::setPositionY(float y){
	position.y=y;
}

void gameObject::setPositionZ(float z){
	position.z=z;
}

void gameObject::setModelID(string modelID)
{
	mModelID = modelID;
}

string gameObject::getModelID()
{
	return mModelID;
}


unsigned int gameObject::getID()
{
	return mID;
}


void gameObject::setID(unsigned int id)
{
	mID = id;
}
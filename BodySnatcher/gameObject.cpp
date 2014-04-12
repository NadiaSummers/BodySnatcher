#include "gameObject.h"	

void gameObject::processCollision(gameObject &obj){
	if(boundingBox.checkCollison(position,obj.boundingBox,obj.position)){
		onCollision(obj);
	}
}

gameObject::gameObject(vector3D location, float obScale, float sSize){
	position=location;
	sphereSize = sSize;
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0;
}

gameObject::gameObject(float x,float y,float z, float obScale, float sSize){
	position.x=x;
	position.y=y;
	position.z=z;
	sphereSize = sSize;
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0;    
}

gameObject::gameObject(){
    position.x=position.y=position.z=0.0;
	sphereSize = 0;
	scale=1.0;
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
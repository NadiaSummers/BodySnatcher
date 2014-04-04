#include "gameObject.h"	



gameObject::gameObject(vector3D location, float obScale)
{
	position=location;
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0;
}

gameObject::gameObject(float x,float y,float z, float obScale)
{
	position.x=x;
	position.y=y;
	position.z=z;

	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0;    
}

gameObject::gameObject()
{
    position.x=position.y=position.z=0.0;
	scale=1.0;
}

void gameObject::setPosition(vector3D pos)
{
 position=pos;
}

void gameObject::setPositionInc(vector3D pos)
{
	position+=pos;
}

void gameObject::setPosition(float x, float y, float z)
{
	position.x=x;
	position.y=y;
	position.z=z;
}


void gameObject::setScale(float obScale)
{
	  if(obScale>0.0)
		  scale=obScale;
	  else
		  scale=1.0; 
}

void gameObject::setPositionX(float x)
{
	position.x=x;
}

void gameObject::setPositionY(float y)
{
	position.y=y;
}

void gameObject::setPositionZ(float z)
{
	position.z=z;
}
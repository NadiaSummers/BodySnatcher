//represents anything the engine can draw. all objects are derived from this class

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

#include <iostream>
using namespace std;

#include "vector.h"


class gameObject
{
protected:
	virtual void render(){};

	//virtual void animate(){};
public:

	gameObject(vector3D location, float obScale);
	gameObject(float x, float y, float z, float obScale);
	gameObject();
	void setPosition(vector3D pos);
    void setPosition(float x, float y, float z);
	void setScale(float obScale);
	vector3D getPosition(){return position;}
	float getPositionX(){return position.getX();}
	float getPositionY(){return position.getY();}
    float getPositionZ(){return position.getZ();}

	float getScale(){return scale;}
	void setPositionInc(vector3D pos);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);

private:
	vector3D position;           //position vector
	float scale;                //scaling factor
};

#endif
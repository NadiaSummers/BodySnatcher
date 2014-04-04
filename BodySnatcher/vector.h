#ifndef __VECTOR_H
#define __VECTOR_H

#include <math.h>
//#include "myMath.h"

class vector3D
{
	public:
		float x;
		float y;
		float z;    // x,y,z coordinates
	public:
		 vector3D();
		 vector3D(float xpos, float ypos, float zpos);
		 vector3D(const vector3D &vec);

		 void set(const vector3D &v2);
		 void set(float xpos, float ypos, float zpos);
		 void setX(float xpos);
		 void setY(float ypos);
		 void setZ(float zpos);
		 float getX();
		 float getY();
		 float getZ();

		 // vector assignment
		 const vector3D &operator = (const vector3D &vec);
		 void operator += (const vector3D &vec);
};

#endif
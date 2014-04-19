#ifndef __VECTOR3D_H
#define __VECTOR3D_H

#include <math.h>
//#include "myMath.h"

class Vector3D
{
	public:
		float x;
		float y;
		float z;    // x,y,z coordinates
	public:
		 Vector3D();
		 Vector3D(float xpos, float ypos, float zpos);
		 Vector3D(const Vector3D &vec);

		 void set(const Vector3D &v2);
		 void set(float xpos, float ypos, float zpos);
		 void setX(float xpos);
		 void setY(float ypos);
		 void setZ(float zpos);
		 float getX();
		 float getY();
		 float getZ();

		 // vector assignment
		 const Vector3D &operator = (const Vector3D &vec);
		 void operator += (const Vector3D &vec);
};

#endif
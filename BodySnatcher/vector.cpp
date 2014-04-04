#include "vector.h"

vector3D::vector3D()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

vector3D::vector3D(float xpos, float ypos, float zpos)
{
 set(xpos,ypos,zpos);
}

vector3D::vector3D(const vector3D &vec)
 {
	 set(vec);
 }

 void vector3D::set(const vector3D &v2)
 {
    x=v2.x;
	y=v2.y;
	z=v2.z;
 }

 void vector3D::set(float xpos, float ypos, float zpos)
 {
	x=xpos;
	y=ypos;
	z=zpos;
 }

 const vector3D &vector3D::operator=(const vector3D &vec)
 {
	x = vec.x;
    y = vec.y;
    z = vec.z;
  return *this;
 }

  void vector3D::operator+=(const vector3D &vec)
 {
	x += vec.x;
    y += vec.y;
    z += vec.z;
 }

 void vector3D::setX(float xpos)
 {
	 x=xpos;
 }

  void vector3D::setY(float ypos)
 {
	 y=ypos;
 }

  void vector3D::setZ(float zpos)
 {
	 z=zpos;
 }

float vector3D::getX()
{
	return x;
}

float vector3D::getY()
{
	return y;
}

float vector3D::getZ()
{
	return z;
}
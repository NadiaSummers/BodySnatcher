#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3D::Vector3D(float xpos, float ypos, float zpos)
{
 set(xpos,ypos,zpos);
}

Vector3D::Vector3D(const Vector3D &vec)
 {
	 set(vec);
 }

 void Vector3D::set(const Vector3D &v2)
 {
    x=v2.x;
	y=v2.y;
	z=v2.z;
 }

 void Vector3D::set(float xpos, float ypos, float zpos)
 {
	x=xpos;
	y=ypos;
	z=zpos;
 }

 const Vector3D &Vector3D::operator=(const Vector3D &vec)
 {
	x = vec.x;
    y = vec.y;
    z = vec.z;
  return *this;
 }

  void Vector3D::operator+=(const Vector3D &vec)
 {
	x += vec.x;
    y += vec.y;
    z += vec.z;
 }

 void Vector3D::setX(float xpos)
 {
	 x=xpos;
 }

  void Vector3D::setY(float ypos)
 {
	 y=ypos;
 }

  void Vector3D::setZ(float zpos)
 {
	 z=zpos;
 }

float Vector3D::getX()
{
	return x;
}

float Vector3D::getY()
{
	return y;
}

float Vector3D::getZ()
{
	return z;
}
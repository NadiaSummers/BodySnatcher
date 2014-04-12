#ifndef __VECTOR2D_H
#define __VECTOR2D_H


class vector2D
{
private:
 float x;
 float y;

public:
 vector2D()
 {
	 x=y=0.0;
 }
 
 vector2D(int xpos, int ypos)
 {
  setVector(xpos,ypos);
 }

 void setVector(int xpos, int ypos)
 {
	 x=xpos;
	 y=ypos;
 }

 void setVector(const vector2D &v2)
 {
	 x=v2.x;
	 y=v2.y;
 }

 float getX()
 {
	 return x;
 }

 float getY()
 {
	 return y;
 }

};

#endif
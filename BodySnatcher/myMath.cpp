#include "myMath.h"

inline double degToRad(double radians)
{
	return (piOver180 * radians); 
}

//convert from radians to degrees
inline double radToDeg(double radians)
{
 radians*= (180.0 / PI);
 return radians;
}

//converts from cartesian to polar coords
point cartToPolar(double x, double y)
{
 point2D polar;

   polar.x=sqrt((x*x) + (y*y));
   polar.y= radToDeg((double)atan(y/x));
 return polar;
}

point polarToCart(point2D polar)
{
 point2D cart;
   cart.x=polar.x*cos(polar.y);
   cart.y=polar.x*sin(polar.y);
 return cart;
}


void movePolar2D(double moveDist,point2D& cartCoords, double& angle,int dir)
{
    if(moveDist>0)
	{
	 double a=cos(degToRad(angle));
	 double b=sin(degToRad(angle));
     cartCoords.x += moveDist*cos(degToRad(angle))*dir; 
     cartCoords.y += moveDist*sin(degToRad(angle))*dir; 
	}
}


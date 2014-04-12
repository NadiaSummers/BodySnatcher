#ifndef __MYMATH_H
#define __MYMATH_H

#include <math.h>
#include "vector.h"

#define PI 3.14159265358979323846
#define piOver180 PI/180

typedef struct point{double x; double y;}point2D;

inline double degToRad(double radians);
//convert from radians to degrees
inline double radToDeg(double radians);
//converts from cartesian to polar coords
point cartToPolar(double x, double y);
point polarToCart(point2D polar);
void movePolar2D(double moveDist,point2D& cartCoords, double& angle,int dir);
void changeSign(double &val);

#endif

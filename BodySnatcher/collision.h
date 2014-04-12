#ifndef __COLLISION_H
#define __COLLISION_H

#include "vector2D.h"
#include "vector.h"
#include <math.h>

bool sphereCollisionTest(vector2D obj1Centre, vector2D obj2Centre, float obj1Radius, float obj2Radius);
void getObjectCentre(vector2D /* in */ vertices[], int /* in */ numVertices, vector2D /* out */ &centre);
float getBoundingSphereRadius(vector2D /* in */ vertices[], int /* in */ numVertices, vector2D /* out */ centre);

#endif
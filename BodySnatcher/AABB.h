#ifndef __AABB_H
#define __AABB_H
#include "vector.h"

class AABB
{
private:
   vector3D min;
   vector3D max;
   AABB createWorldAABB(AABB aabb,vector3D worldXYZ);
   bool checkCollisonWithPoint(vector3D &point,AABB &aabb);

public:
	AABB();
	AABB(vector3D minVals, vector3D maxVals);
	void createAABB(vector3D vertices[], int numVertices);
	bool checkCollisonWithPoint(vector3D &point,vector3D worldXYZ);
    bool checkCollison(vector3D worldXYZ,AABB &aabb2,vector3D worldXYZ2);
	const AABB &operator=(const AABB &aabb2);
};

#endif
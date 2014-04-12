#include "collision.h"
#include <iostream>
using namespace std;

bool sphereCollisionTest(vector2D obj1Centre, vector2D obj2Centre, float obj1Radius, float obj2Radius){
  float dist;

   dist=(abs(obj1Centre.getX()-obj2Centre.getX())*abs(obj1Centre.getX()-obj2Centre.getX()))
				  +(abs(obj1Centre.getY()-obj2Centre.getY())*abs(obj1Centre.getY()-obj2Centre.getY()));
     if( ((obj1Radius+obj2Radius)*(obj1Radius+obj2Radius)) >= dist)
	 {
		 return true;
	 }
 return false;
}

void getObjectCentre(vector2D /* in */ vertices[], int /* in */ numVertices, vector2D /* out */ &centre){
		float largestX=0;
		float largestY=0;
		float smallestX=1000000;
		float smallestY=1000000;

       if(vertices==NULL)
		   return ;
          //loop through all vertices and find largest and smallest x and y values.
	      for(int counter=0;counter<numVertices;counter++)
		  {
			  if(vertices[counter].getX()>largestX)
			  {
				  largestX=vertices[counter].getX();
			  }
			  if(vertices[counter].getX()<smallestX)
			  {
				  smallestX=vertices[counter].getX();
			  }
			  if(vertices[counter].getY()>largestY)
			  {
				  largestY=vertices[counter].getY();
			  }
			  if(vertices[counter].getY()<smallestY)
			  {
				  smallestY=vertices[counter].getY();
			  }
		  }
	  //calculate largest x and y distances
	  float xSize=largestX-smallestX;
	  float ySize=largestY-smallestY;

	        //calculate centre of object
      centre.setVector(smallestX+(xSize/2),smallestY+(ySize/2));
}

	/*------------------------------------------------------------------------------
	|
	|Params:
	|vertices - array of vertice points representing the object
	|numVertices - number of vertices for the object
	|centre - the centre of the objects bounding sphere 
	|returns: radius of a bounding sphere surrounding the object
	*-----------------------------------------------------------------------------*/
float getBoundingSphereRadius(vector2D /* in */ vertices[], int /* in */ numVertices, vector2D /* out */ centre){
	float dist;
	float maxDist=0;
	//loop through again and calculate largest distance from centre of object
	for(int counter=0;counter<numVertices;counter++)
	{
		dist=((vertices[counter].getX()-centre.getX())*(vertices[counter].getX()-centre.getX()))
		+((vertices[counter].getY()-centre.getY())*(vertices[counter].getY()-centre.getY()));
		//check max distance
		if(dist>maxDist){
			maxDist=dist;
		}
	}
	return sqrt(maxDist);
}
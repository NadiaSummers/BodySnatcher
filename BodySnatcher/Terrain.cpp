
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <glut.h>
#include "Terrain.h"


using namespace std;

Terrain::Terrain()
{
	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
}





bool Terrain::generateTerrain(char *filename, const int newSize)
{
	size = newSize;
	
	ifstream infile(filename, ios::binary);
	if (!infile)
	{
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}
	else
		cout << "Terrain: " << filename << " loaded..." << endl;

	if (size > 0)
		terrainData = new unsigned char[size * size];
	if (terrainData == NULL)
		return false;
	
	infile.seekg(0, ios::end);
	int length = infile.tellg();

	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(terrainData), length);
	infile.close();
	
	return true;
}


void Terrain::render(void)
{
	unsigned char heightColor;
	float texLeft, texBottom, texTop;

	//Should call function(s) in rendering engine?

	for (int z = 0; z < getSize() -1; z++)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (int x = 0; x < getSize(); x++)
			{
				texLeft = (float)x / getSize();
				texBottom = (float)z / getSize();
				texTop = (float)(z + 1) / getSize();


				heightColor = getHeightColor(x, z);
				glColor3ub(heightColor, heightColor, heightColor);
				glTexCoord2f(texLeft, texBottom);
				glVertex3f((float)x * scaleX, getHeight(x, z), (float)z * scaleZ);
				
				heightColor = getHeightColor(x, z + 1);
				glColor3ub(heightColor, heightColor, heightColor);
				glTexCoord2f(texLeft, texTop);
				glVertex3f((float)x * scaleX, getHeight(x, z + 1), (float)(z + 1) * scaleZ);
			}
		glEnd();
	}
}

void Terrain::setScalingFactor(float xScale, float yScale, float zScale)
{
	scaleX = xScale;
	scaleY = yScale;
	scaleZ = zScale;
}

int Terrain::getSize()
{
	return size;
}

float Terrain::getHeight(int xPos, int zPos)
{
	if (inbounds(xPos, zPos))
	{
		return ((float)(terrainData[(zPos * size) + xPos]) * scaleY);
	}
	else
		return 1;
}

unsigned char Terrain::getHeightColor(int xPos, int zPos)
{
	if (inbounds(xPos, zPos))
	{
		return terrainData[zPos * size + xPos];
	}
	else
		return 1;
}

bool Terrain::inbounds(int xPos, int zPos)
{
	if (xPos <= size && zPos <= size)
		return true;
	else
		return false;
}
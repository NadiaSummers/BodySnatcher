
#include <iostream>
#include <fstream>
#include <glut.h>

#include "Terrain.h"

using namespace std;

Terrain::Terrain()
{
	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
}



bool Terrain::generateTerrain(GLuint *texture, char *filename, const int newSize)
{
	baseTexture = texture;
	size = newSize;
	
	ifstream infile(filename, ios::binary);
	if (!infile)
	{
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}
	else
		cout << "Terrain: " << filename << " created." << endl;

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

//NS -temp
bool Terrain::addMapLayer(GLuint *texture, char *filename)
{
	//add texture to end of vector
	textures.push_back(*texture);


	ifstream infile(filename, ios::binary);
	if (!infile)
	{
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}
	else
		cout << "Terrain Layer Added: " << filename << " [" <<  (int)textures.size() << "]" << endl;
	

	unsigned char *thisMap = new unsigned char[size * size];

	infile.seekg(0, ios::end);
	int length = infile.tellg();

	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(thisMap), length);
	infile.close();

	textureMaps.push_back(thisMap);

	return true;
}


void Terrain::render(void)
{
	//unsigned char heightColor;
	float texLeft, texBottom, texTop;

	glColor4f(1.0, 1.0, 1.0, 1);
	glBindTexture(GL_TEXTURE_2D, *baseTexture);

	for (int i = -1; i < (int)textures.size(); i++)
	{

		if (i > -1)
		glBindTexture(GL_TEXTURE_2D, textures[i]);

		for (int z = 0; z < getSize() -1; z++)
		{
			
			glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < getSize(); x++)
				{

					texLeft = (float)x / getSize() * textureScale;
					texBottom = (float)z / getSize() * textureScale;
					texTop = (float)(z + 1) / getSize() * textureScale;


					if (i > -1)
						glColor4f(1.0, 1.0, 1.0, getTextureMapHeight(x, z, i));


					//heightColor = getHeightColor(x, z);
					//glColor3ub(heightColor, heightColor, heightColor);
					glTexCoord2f(texLeft, texBottom);
					glVertex3f((float)x * scaleX, getHeight(x, z), (float)z * scaleZ);


					//heightColor = getHeightColor(x, z + 1);
					//glColor3ub(heightColor, heightColor, heightColor);
					glTexCoord2f(texLeft, texTop);
					glVertex3f((float)x * scaleX, getHeight(x, z + 1), (float)(z + 1) * scaleZ);
				}
			glEnd();
		}
	}
}

//NS - should probably also scale the texture coord mapping here too. (TEMP?)
void Terrain::setScalingFactor(float xScale, float yScale, float zScale)
{
	scaleX = xScale;
	scaleY = yScale;
	scaleZ = zScale;

	textureScale = scaleX / 2;
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


float Terrain::getTextureMapHeight(int xPos, int zPos, int mapNum)
{
	if (inbounds(xPos, zPos))
	{
		//return textureMapData[(zPos * size) + xPos] / 255.0f;
		return textureMaps[mapNum][(zPos * size) + xPos] / 255.0f;
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

float Terrain::GetScaleX()
{
	return scaleX;
}

float Terrain::GetScaleY()
{
	return scaleY;
}

float Terrain::GetScaleZ()
{
	return scaleZ;
}
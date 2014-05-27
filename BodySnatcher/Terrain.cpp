
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


bool Terrain::generateTerrain(string texture, char *filename, int newSize)
{
	textures.push_back(texture);
	size = newSize;
	
	ifstream infile(filename, ios::binary);
	if (!infile)
	{
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}

	unsigned char *thisMap = new unsigned char[size * size];

	
	infile.seekg(0, ios::end);
	int length = infile.tellg();

	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(thisMap), length);
	infile.close();

	terrainData.push_back(thisMap);
	cout << "Terrain Added: " << filename << endl;
	return true;
}


bool Terrain::addMapLayer(string texture, char *filename)
{
	//add texture to end of vector
	textures.push_back(texture);


	ifstream infile(filename, ios::binary);
	if (!infile)
	{
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}	

	unsigned char *thisMap = new unsigned char[size * size];

	infile.seekg(0, ios::end);
	int length = infile.tellg();

	infile.seekg(0, ios::beg);
	infile.read(reinterpret_cast<char *>(thisMap), length);
	infile.close();

	terrainData.push_back(thisMap);

	cout << "Terrain Layer [" <<  (int)terrainData.size() << "] Added: " << filename << endl;
	return true;
}


///***************************//
// TODO: FIX DRAW ORDER		//
//*****************************//
/*
void Terrain::render(void)
{
	//unsigned char heightColor;
	float texLeft, texBottom, texTop;

	glColor4f(1.0, 1.0, 1.0, 1);

	//need to render each terrain layer - 0 should be base and is treated differently
	for (int i = 0; i < (int)textures.size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, mEngineCore->GetTextureManager().getTexture(textures[i]));			//FIX SYNTAX !!!//

		for (int z = 0; z < getSize() -1; z++)
		{
			
			glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < getSize(); x++)
				{
					//dont render mapLayers triangles with an alpha of 0 - invisible anyways!
					if (i > 0 && getTextureMapHeight(x, z , i) == 0)
						break;

					texLeft = (float)x / getSize() * textureScale;
					texBottom = (float)z / getSize() * textureScale;
					texTop = (float)(z + 1) / getSize() * textureScale;

					//only want to set this for subsequent layers
					if (i > 0)
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
*/

//NS - should probably also scale the texture coord mapping here too.

void Terrain::setScalingFactor(float xScale, float yScale, float zScale)
{
	scaleX = xScale;
	scaleY = yScale;
	scaleZ = zScale;
	textureScale = scaleX;
}

int Terrain::getSize()
{
	return size;
}

float Terrain::getTextureScale()
{
	return textureScale;
}

float Terrain::getHeight(int xPos, int zPos)
{
	if (inbounds(xPos, zPos))
	{
		//always want to look at the base height [0]
		return ((float)(terrainData[0][(zPos * size) + xPos]) * scaleY);
	}
	else
		return 1;
}

unsigned char Terrain::getHeightColor(int xPos, int zPos)
{
	if (inbounds(xPos, zPos))
	{
		return terrainData[0][zPos * size + xPos] * 255;
	}
	else
		return 1;
}


float Terrain::getTextureMapHeight(int xPos, int zPos, int mapNum)
{
	if (inbounds(xPos, zPos))
	{
		return terrainData[mapNum][(zPos * size) + xPos] / 255.0f;
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

int Terrain::getNumLayers()
{
	return textures.size();
}

string Terrain::getTextureName(int pos)
{
	return textures[pos];
}
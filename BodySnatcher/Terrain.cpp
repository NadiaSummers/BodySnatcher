
#include <iostream>
#include <fstream>
#include <glut.h>
#include <lua.hpp>

#include "Terrain.h"

using namespace std;

Terrain::Terrain()
{
	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
	doLua();
}

bool Terrain::doLua()
{
	lua_State* luaState = lua_open();
    if (luaState == NULL)
	{
       cout << "Error Initializing lua." << endl;
       return false;
    }

    //load lua functions
    luaL_openlibs(luaState);

	luaL_dofile(luaState, "lua/levelone-terraingen.lua");

    lua_settop(luaState, 0);
    lua_getglobal(luaState, "baseTexture");
    lua_getglobal(luaState, "heightmap");
	lua_getglobal(luaState, "size");
	lua_getglobal(luaState, "scaleX");
	lua_getglobal(luaState, "scaleY");
	lua_getglobal(luaState, "scaleZ");

	//check if numbers are actually numbers etc
    if((lua_isnumber(luaState, 1)) && (lua_isstring(luaState, 2)) && (lua_isnumber(luaState, 3)) && (lua_isnumber(luaState, 4)) && (lua_isnumber(luaState, 5)) && (lua_isnumber(luaState, 6)))
	{
		int baseTexture = (int)lua_tonumber(luaState, 1);
		string heightmap = (string)lua_tostring(luaState, 2);
		int size = (int)lua_tonumber(luaState, 3);
		int scaleX = (int)lua_tonumber(luaState, 4);
		int scaleY = (int)lua_tonumber(luaState, 5);
		int scaleZ = (int)lua_tonumber(luaState, 6);
		cout << "Terrain Lua loaded." << endl;
	}
	else
	{
		cout << "Error loading data." << endl;
		return false;
	}

	//generateTerrain(texManager.getTextureID(baseTexture), heightmap, size);
	setScalingFactor(scaleX, scaleY, scaleZ);
  
    lua_close(luaState);
	return true;
}

bool Terrain::generateTerrain(GLuint texture, char *filename, int newSize)
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


bool Terrain::addMapLayer(GLuint texture, char *filename)
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


void Terrain::render(void)
{
	//unsigned char heightColor;
	float texLeft, texBottom, texTop;

	glColor4f(1.0, 1.0, 1.0, 1);


	for (int i = 0; i < (int)textures.size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, textures[i]);

		for (int z = 0; z < getSize() -1; z++)
		{
			
			glBegin(GL_TRIANGLE_STRIP);
				for (int x = 0; x < getSize(); x++)
				{

					texLeft = (float)x / getSize() * textureScale;
					texBottom = (float)z / getSize() * textureScale;
					texTop = (float)(z + 1) / getSize() * textureScale;


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
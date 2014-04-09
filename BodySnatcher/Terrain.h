#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
public:
	Terrain();
	void render();
	bool generateTerrain(char *filename, const int size);
	//int cpp_generateTerrain(lua_State *luaVM);
	
	void setScalingFactor(float scaleX, float scaleY, float scaleZ);
	int getSize();
	float getHeight(int xPos, int zPos);
	unsigned char getHeightColor(int xPos, int zPos);
	bool inbounds(int xPos, int zPos);
	
protected:
	
	int size;
	unsigned char *terrainData;
	float scaleX;
	float scaleY;
	float scaleZ;
};

#endif
/**
* @class Terrain
* @brief Class containing functions relevant to the creation and upkeep of a terrain.
*
* @version 1
* @date 23/04/2014 Nadia Summers
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain
{
public:

	/*
	* @brief Default Constructor
	*/
	Terrain();
	
	/*
	* @brief Method for rendering the terrain, given respect to heightmaps/textures/texturemaps.
	*/
	void render();
	
	/*
	* @brief Used during initialization, reads in heightmap.
	* @param GLuint *texture - The base (lowest) texture of the terrain.
	* @param char *filename - The path/filename of the heightmap.
	* @param const int size - The width/length of the heightmap image.
	* @return Returns true if successful.
	*/
	bool generateTerrain(GLuint texture, char *filename, int size);
	

	/*
	* @brief Adds a new texture layer to the terrain, along with it's alpha map.
	* @param GLuint texture - The texture associated with this map layer.
	* @param char *filename - The path/filename of the texture's alpha map.
	* @return Returns true if successful.
	*/
	bool addMapLayer(GLuint texture, char *filename);
	
	/*
	* @brief Sets the scale of the terrain.
	* @ Also sets the textureScale based off scaleX.
	* @param float scaleX - The amount to scale the X dimension.
	* @param float scaleY - The amount to scale the Y dimension.
	* @param float scaleZ - The amount to scale the Z dimension.
	*/
	void setScalingFactor(float scaleX, float scaleY, float scaleZ);
	
	float GetScaleX(); //added by Raymond Forster
	float GetScaleY(); //added by Raymond Forster
	float GetScaleZ(); //added by Raymond Forster

	/*
	* @brief Returns the size (dimension) of the terrain.
	* @return The size.
	*/
	int getSize();

	/*
	* @brief Returns the texture scale of the terrain's textures.
	* @return The scale.
	*/
	float getTextureScale();

	/*
	* @brief Returns the height of the terrain at x, z coords.
	* @param int xPos The x position to be tested.
	* @param int zPos The z position to be tested.
	* @return The height (0-255).
	*/
	float getHeight(int xPos, int zPos);
	unsigned char getHeightColor(int xPos, int zPos);
	float getTextureMapHeight(int xPos, int zPos, int mapNum);
	bool inbounds(int xPos, int zPos);
	
private:
	bool doLua();


	int size;
	//GLuint baseTexture;
	//unsigned char *terrainData;
	float scaleX;
	float scaleY;
	float scaleZ;
	float textureScale;
	std::vector <GLuint> textures;
	std::vector <unsigned char*> terrainData;
};

#endif
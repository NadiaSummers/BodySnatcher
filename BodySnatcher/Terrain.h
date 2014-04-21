/**
* @class Terrain
* @brief Class containing functions relevant to the creation and upkeep of a terrain.
*/


#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>

class Terrain
{
public:
	/**
	* @brief Default Constructor
	*/
	Terrain();
	
	/**
	* @brief Method for rendering the terrain, given respect to heightmaps/textures/texturemaps.
	*/
	void render();
	
	/**
	* @brief Used during initialization, reads in heightmap.
	* @param GLuint *baseTexture - The lowest level texture of the terrain.
	* @param char *filename - The path/filename of the heightmap.
	* @param const int size - The width/length of the heightmap image.
	* @return Returns true if successful.
	*/
	bool generateTerrain(GLuint *texture, char *filename, const int size);
	

	/**
	* @brief Adds a new texture layer to the terrain, along with it's alpha map.
	* @param GLuint *texture - The texture associated with this map layer.
	* @param char *filename - The path/filename of the texture's alpha map.
	* @return Returns true if successful.
	*/
	bool addMapLayer(GLuint *texture, char *filename);
	
	/**
	* @brief Sets the scale multiplier for the dimensions of the terrain.
	* Also adjusts the texture scale.
	* @param float scaleX
	* @param float scaleY
	* @param float scaleZ
	*/
	void setScalingFactor(float scaleX, float scaleY, float scaleZ);

	/**
	*
	* @brief Returns the dimensions of the terrain.
	* @return The dimensions of the terrain.
	*/
	int getSize();

	/**
	*
	* @brief Returns the height of the terrain at a specific point.
	* @param int xPos - The X position.
	* @param int zPos - The Z position.
	* @return The height.
	*/
	float getHeight(int xPos, int zPos);

	/**
	*
	* @brief Returns the height map's colour at a specific point.
	* Used for rendering the terrain heights on the terrain, very basic shading.
	* @param int xPos - The X position.
	* @param int zPos - The Z position.
	* @return The colour (Grayscale).
	*/
	unsigned char getHeightColor(int xPos, int zPos);

	/**
	*
	* @brief Returns the height of the texture map at a specific point.
	* Used to determine the blending alpha.
	* @param int xPos - The X position.
	* @param int zPos - The Z position.
	* @param int mapNum - the texture map to look at.
	* @return The height.
	*/
	float getTextureMapHeight(int xPos, int zPos, int mapNum);

	/**
	*
	* @brief Checks if the value given is in bounds for the terrain data.
	* @param int xPos - The X position.
	* @param int zPos - The Z position.
	* @return True if in bounds.
	*/
	bool inbounds(int xPos, int zPos);
	
	float GetScaleX(); //added by Raymond Forster
	float GetScaleY(); //added by Raymond Forster
	float GetScaleZ(); //added by Raymond Forster
	
private:
	
	int size;
	GLuint *baseTexture;
	unsigned char *terrainData;
	float scaleX;
	float scaleY;
	float scaleZ;
	float textureScale;
	std::vector <GLuint> textures;
	std::vector <unsigned char*> textureMaps;
};

#endif
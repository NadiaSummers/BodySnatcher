/**
 * @class TextureManager
 * @brief Class to create and store textures.
 *
 *
 * @author Daniel Manganaro, Nadia Summers
 * @version 03
*  @date 11/04/2014 Daniel Manganaro - Basic Implementation
 * @date 23/04/2014 Nadia Summers - Updated to use a vector, removed crap, added openGL tex settings.
 * @date 06/05/2014 Nadia Summers - Updated to use a map.
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <SOIL.h>
#include <string>
#include <map>

#include "GameEngineCore.h"

class GameEngineCore;
class TextureManager {

private:
	std::map <std::string, GLuint> mTextures;
	GameEngineCore* mEngineCore;

public:	

	TextureManager(GameEngineCore* engineCore);
	~TextureManager();

	/**
		* @brief clear the memory / free the loaded textures
        * @param none
		* @return void
	*/
	void clearMemory();

	/**
		* @brief Returns the Texture by matching with the ID in the map.
        * @param string - The ID of the requested texture in the array.
		* @return GLuint - The Texture.
	*/
	GLuint getTexture(std::string ID) const;

	/**
	* @brief Loads the specified image into the mTexture map.
	* @param string - The ID to be assigneed to this texture.
	* @param const char * filename - The filename of the image to be loaded.
	*/
	void loadTexture(std::string ID, const char* filename);

};

#endif
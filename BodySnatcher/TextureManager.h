/**
 * @class TextureManager
 * @brief Controller class for the texture assets
 *
 * Implements the basic functions to work with texture files: init(), reload(), clearMemory(), getTextureID and a List to manage them
 *
 * @author Daniel Manganaro
 * @version 03
 * @date 11/04/2014 Daniel Manganaro - Basic Implementation
 */

#pragma once

#include "IAssetManager.h"
#include <GL/freeglut.h>
#include "include\SOIL.h"

enum eTextures { 
				 TEXTURE_SIZE };

class TextureManager: public IAssetManager {
private:
	GLuint mTextures[TEXTURE_SIZE]; 	
	GLuint Loadimage(const char* filename);
public:	
	TextureManager();
	~TextureManager();	
	/**
		* @brief loads the texture files
        * @param none
		* @return void
	*/
	void init();
	/**
		* @brief reload the texture files
        * @param none
		* @return void
	*/
	void reload();
	/**
		* @brief clear the memory / free the loaded textures
        * @param none
		* @return void
	*/
	void clearMemory();
	/**
		* @brief Returns the Texture ID of the textures stored at position "texture" in the list the class holds 
        * @param eTextures texture - represents the position / index of the requested texture in the array
		* @return GLuint - the Texture ID, you can pass to the BindTexture()-function
	*/
	GLuint getTextureID(const eTextures texture) const;
};

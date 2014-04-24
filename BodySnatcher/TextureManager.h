/**
 * @class TextureManager
 * @brief Controller class for the texture assets
 *
 * Implements the basic functions to work with texture files: init(), reload(), clearMemory(), getTextureID and a List to manage them
 *
 * @author Daniel Manganaro
 * @version 04
 * @date 11/04/2014 Daniel Manganaro - Basic Implementation
 * @date 23/04/2014 Nadia Summers - Updated to use a vector, removed crap, added openGL tex settings.
 */

#pragma once

#include <stdlib.h>
#include <glut.h>
#include <SOIL.h>
#include <vector>



class TextureManager {

private:
	std::vector <GLuint> mTextures;

public:	

	TextureManager();
	~TextureManager();	

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
	GLuint getTexture(int position) const;

	/**
	* @brief Loads the specified image into the mTexture vector.
	* @param int position - Dummy, used for external lua housekeeping.
	* @param const char * filename - The filename of the image to be loaded.
	*/
	void loadTexture(int position, const char* filename);

};

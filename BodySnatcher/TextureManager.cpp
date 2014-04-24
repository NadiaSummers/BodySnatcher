#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	clearMemory();
}

void TextureManager::loadTexture(int position, const char* filename)
{
	GLuint texture =	SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 
						SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB |
						SOIL_FLAG_COMPRESS_TO_DXT);

	mTextures.push_back(texture);

	std::cout << "Loaded: " << filename << "." << std::endl;

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

GLuint TextureManager::getTexture(int position) const
{
	return mTextures[position];
}

void TextureManager::clearMemory() 
{
	mTextures.clear();
}
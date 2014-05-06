#include "TextureManager.h"



TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	clearMemory();
}



void TextureManager::loadTexture(const std::string ID, const char* filename)
{
	GLuint texture =	SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 
						SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB |
						SOIL_FLAG_COMPRESS_TO_DXT);

	mTextures.insert(std::pair<std::string, GLuint>(ID, texture));

	std::cout << "Loaded: " << ID << " - " << filename << "." << std::endl;

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

GLuint TextureManager::getTexture(std::string ID) const
{
	return mTextures.find(ID)->second;
}

void TextureManager::clearMemory() 
{
	mTextures.clear();
}
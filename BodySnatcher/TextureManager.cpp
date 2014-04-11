#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager()
{
	init();
}

TextureManager::~TextureManager()
{
	clearMemory();
}

GLuint TextureManager::Loadimage(const char* filename)
{
	return SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 
				  SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB |
				  SOIL_FLAG_COMPRESS_TO_DXT);
}

void TextureManager::init()
{




	std::cout << "Textures Loaded." << std::endl;
}

void TextureManager::reload()
{
	clearMemory();
	init();
}

GLuint TextureManager::getTextureID(const eTextures texture) const
{
	return mTextures[texture];
}

void TextureManager::clearMemory() 
{
}
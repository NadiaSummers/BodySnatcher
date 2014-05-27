#include "TextureManager.h"

using namespace std;


TextureManager::TextureManager(GameEngineCore* engineCore):mEngineCore(engineCore)
{
}

TextureManager::~TextureManager()
{
	clearMemory();
}



void TextureManager::loadTexture(const string ID, const char* filename)
{
	GLuint texture =	SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 
						SOIL_FLAG_MIPMAPS | SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_NTSC_SAFE_RGB |
						SOIL_FLAG_COMPRESS_TO_DXT);

	mTextures.insert(pair<string, GLuint>(ID, texture));

	cout << "Tex: " << ID << " - " << filename << "." << endl;

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

GLuint TextureManager::getTexture(string ID) const
{
	return mTextures.find(ID)->second;
}

void TextureManager::clearMemory() 
{
	mTextures.clear();
}
#include "ModelManager.h"
#include "ModelLoader.h"
#include <iostream>

ModelManager::ModelManager()
{
	init();
}

ModelManager::~ModelManager()
{
	clearMemory();
}

void ModelManager::init()
{
	for (int i = 0; i < MODELS_SIZE; i++) 
		mModels[i] = new ModelLoader;

	mModels[mDog]->load("models/german_shepard/dog.obj");

	std::cout << "Models Loaded." << std::endl;
}

void ModelManager::reload()
{
	clearMemory();
	init();
}

void ModelManager::drawModel(const eModels model, const GLuint texture) const
{
	glEnable(GL_TEXTURE_2D);
	if (texture>0)
		glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
		mModels[model]->draw();
		glBindTexture(GL_TEXTURE_2D, -1);
	glPopMatrix();
}

void ModelManager::clearMemory()
{
}

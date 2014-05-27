#include "GameEngineCore.h"

GameEngineCore* GameEngineCore::mInstance = NULL;

GameEngineCore::GameEngineCore()
{
	mGameObjectDatabase = new GameObjectDatabase();
	mCamera = new FirstPersonCamera(this);
	mGraphicsEngine = new OpenGLGraphics(this);
	mIOSystem = new IOSystem(this);
	mTerrainEngine = new Terrain();
	mModelDatabase = new ModelDatabase();
}


GameEngineCore::~GameEngineCore()
{
}


GameEngineCore* GameEngineCore::GetInstance()
{
	if (GameEngineCore::mInstance == NULL)
		mInstance = new GameEngineCore();
    return mInstance;
}


void GameEngineCore::Initialise()
{
	mGraphicsEngine->Initialise();
	mCamera->Initialise();
<<<<<<< HEAD
	//mLuaManager->doLuaFile("lua/levelone.lua");
	
	mTextureManager->loadTexture("dirt", "textures/dirt.png");
	
	//because loadign via lua crashes in addMapLayer :S
	mTerrainEngine->generateTerrain("dirt", "textures/1024-heightmap.raw", 1024);
	
	//mTerrainEngine->addMapLayer("grass", "textures/1024-grass.raw");
	//mTerrainEngine->addMapLayer("cobble", "textures/1024-graveyardpath.raw");
	//mTerrainEngine->addMapLayer("stone", "textures/1024-road.raw");
	
=======

>>>>>>> parent of 94baa49... Stuffs
}


void GameEngineCore::Update()
{
}


void GameEngineCore::Draw()
{
<<<<<<< HEAD
	glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluPerspective(40, 1, 0, 10000);

	gluLookAt(512, 1024, -256, 768, 512, 256, 0, 1, 0);

	mGraphicsEngine->RenderTerrain(mTerrainEngine);

	/*
	glBegin(GL_QUADS);
		glTexCoord2f (0.0, 0.0);		glVertex3f (0.0, 0.0, 0.0);
		glTexCoord2f (1.0, 0.0);		glVertex3f (1000.0, 0.0, 0.0);
		glTexCoord2f (1.0, 1.0);		glVertex3f (1000.0, 0, 1000.0);
		glTexCoord2f (0.0, 1.0);		glVertex3f (0.0, 0, 1000.0);
	glEnd();*/

	glFlush();
	glutSwapBuffers();
=======
>>>>>>> parent of 94baa49... Stuffs
}

GameObjectDatabase GameEngineCore::GetGameObjectDatabase()
{
	return *mGameObjectDatabase;
}


FirstPersonCamera GameEngineCore::GetCamera()
{
	return *mCamera;
}


OpenGLGraphics GameEngineCore::GetGraphicsEngine()
{
	return *mGraphicsEngine;
}


IOSystem GameEngineCore::GetIOSystem()
{
	return *mIOSystem;
}


Terrain GameEngineCore::GetTerrainEngine()
{
	return *mTerrainEngine;
}


ModelDatabase GameEngineCore::GetModelDatabase()
{
	return *mModelDatabase;
}


void GameEngineCore::SpecialKey(int key, int x, int y)
{
}
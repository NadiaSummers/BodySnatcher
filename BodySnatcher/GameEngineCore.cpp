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
	mTextureManager = new TextureManager(this);
	mLuaManager = new LuaManager(this);

	Initialise();
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
	mLuaManager->doLuaFile("lua/levelone.lua");
	//mTerrainEngine->generateTerrain("dirt", "textures/1024-heightmap.raw", 1024);
	//mTerrainEngine->addMapLayer("grass", "textures/1024-grass.raw");
	//mTerrainEngine->addMapLayer("cobble", "textures/1024-graveyardpath.raw");

}


void GameEngineCore::Update()
{
}


void GameEngineCore::Draw()
{
	glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluPerspective(40, 1, 0, 10000);

	gluLookAt(512, 1024, -256, 768, 512, 256, 0, 1, 0);

	glBindTexture(GL_TEXTURE_2D, GetTextureManager().getTexture("grass"));	
	
	glBegin(GL_QUADS);
		glTexCoord2f (0.0, 0.0);		glVertex3f (0.0, 0.0, 0.0);
		glTexCoord2f (1.0, 0.0);		glVertex3f (1000.0, 0.0, 0.0);
		glTexCoord2f (1.0, 1.0);		glVertex3f (1000.0, 0, 1000.0);
		glTexCoord2f (0.0, 1.0);		glVertex3f (0.0, 0, 1000.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
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

TextureManager GameEngineCore::GetTextureManager()
{
	return *mTextureManager;
}

LuaManager GameEngineCore::GetLuaManager()
{
	return *mLuaManager;
}

void GameEngineCore::SpecialKey(int key, int x, int y)
{
}
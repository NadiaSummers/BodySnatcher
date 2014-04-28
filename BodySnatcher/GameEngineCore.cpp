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

}


void GameEngineCore::Update()
{
}


void GameEngineCore::Draw()
{
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
#include "GameEngineCore.h"


GameEngineCore::GameEngineCore()
{
	mCamera = new FirstPersonCamera(this);
	mGraphicsEngine = new OpenGLGraphics();
	mTerrainEngine = new Terrain();
	mModelLoader = new ModelLoader();
}


GameEngineCore::~GameEngineCore()
{
}


void GameEngineCore::Initialise()
{
	
}


void GameEngineCore::Update()
{
}


void GameEngineCore::Draw()
{
}


FirstPersonCamera* GameEngineCore::GetCamera()
{
	return mCamera;
}


OpenGLGraphics* GameEngineCore::GetGraphicsEngine()
{
	return mGraphicsEngine;
}


IOSystem* GameEngineCore::GetIOSystem()
{
	return mIOSystem;
}


Terrain* GameEngineCore::GetTerrainEngine()
{
	return mTerrainEngine;
}


ModelLoader* GameEngineCore::GetModelLoader()
{
	return mModelLoader;
}


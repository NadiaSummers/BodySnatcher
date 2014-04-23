#include "GameEngineCore.h"


GameEngineCore::GameEngineCore()
{
	mCamera = new FirstPersonCamera(this);
	mGraphicsEngine = new OpenGLGraphics(this);
	mIOSystem = new IOSystem(this);
	mTerrainEngine = new Terrain();
	mModels = new Model3D();
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


Model3D GameEngineCore::GetModels()
{
	return *mModels;
}


#pragma once

#include "GameEngineCore.h"
#include "FirstPersonCamera.h"
#include "IOSystem.h"
#include "OpenGLGraphics.h"
#include "Terrain.h"
#include "ModelLoader.h"

class GameEngineCore
{
	private:
		FirstPersonCamera* mCamera;
		OpenGLGraphics* mGraphicsEngine;
		IOSystem* mIOSystem;
		Terrain* mTerrainEngine;
		ModelLoader* mModelLoader;

	public:
		GameEngineCore();
		~GameEngineCore();

		void Initialise();
		void Update();
		void Draw();

		// Get Methods
		FirstPersonCamera* GetCamera();
		OpenGLGraphics* GetGraphicsEngine();
		IOSystem* GetIOSystem();
		Terrain* GetTerrainEngine();
		ModelLoader* GetModelLoader();
};


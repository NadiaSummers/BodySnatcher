#ifndef GAMEENGINECORE_H
#define GAMEENGINECORE_H

#include "FirstPersonCamera.h"
#include "IOSystem.h"
#include "OpenGLGraphics.h"
#include "Terrain.h"
#include "Model3D.h"

class FirstPersonCamera;
class IOSystem;
class OpenGLGraphics;
class GameEngineCore
{
	private:
		FirstPersonCamera* mCamera;
		OpenGLGraphics* mGraphicsEngine;
		IOSystem* mIOSystem;
		Terrain* mTerrainEngine;
		Model3D* mModels;

	public:
		GameEngineCore();
		~GameEngineCore();

		void Initialise();
		void Update();
		void Draw();

		// Get Methods
		FirstPersonCamera GetCamera();
		OpenGLGraphics GetGraphicsEngine();
		IOSystem GetIOSystem();
		Terrain GetTerrainEngine();
		Model3D GetModels();
};
#endif

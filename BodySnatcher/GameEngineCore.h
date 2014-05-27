#ifndef GAMEENGINECORE_H
#define GAMEENGINECORE_H

#include <stdlib.h> 
#include <glut.h>
#include "GameObjectDatabase.h"
#include "FirstPersonCamera.h"
#include "IOSystem.h"
#include "ModelDatabase.h"
#include "OpenGLGraphics.h"
#include "Terrain.h"

class GameObjectDatabase;
class FirstPersonCamera;
class IOSystem;
class ModelDatabase;
class OpenGLGraphics;
<<<<<<< HEAD
class TextureManager;
class LuaManager;
class Terrain;
=======
>>>>>>> parent of 94baa49... Stuffs
class GameEngineCore
{
	private:
		GameEngineCore();

		static GameEngineCore* mInstance;
		GameObjectDatabase* mGameObjectDatabase;
		FirstPersonCamera* mCamera;
		ModelDatabase* mModelDatabase;
		OpenGLGraphics* mGraphicsEngine;
		IOSystem* mIOSystem;
		Terrain* mTerrainEngine;

	public:
		static GameEngineCore* GetInstance();
		~GameEngineCore();

		void Initialise();
		void Update();
		void Draw();

		// Get Methods
		GameObjectDatabase GetGameObjectDatabase();
		FirstPersonCamera GetCamera();
		OpenGLGraphics GetGraphicsEngine();
		IOSystem GetIOSystem();
		ModelDatabase GetModelDatabase();
		Terrain GetTerrainEngine();

		void SpecialKey(int key, int x, int y);
};
#endif

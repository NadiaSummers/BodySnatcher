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
#include "TextureManager.h"
#include "LuaManager.h"

class GameObjectDatabase;
class FirstPersonCamera;
class IOSystem;
class ModelDatabase;
class OpenGLGraphics;

class TextureManager;
class LuaManager;
class Terrain;
class LuaManager;

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
		TextureManager* mTextureManager;
		LuaManager* mLuaManager;

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
		TextureManager GetTextureManager();
		LuaManager GetLuaManager();

		void SpecialKey(int key, int x, int y);
};
#endif

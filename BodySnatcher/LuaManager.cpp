#include "LuaManager.h"

using namespace std;

LuaManager::LuaManager(GameEngineCore* engineCore):mEngineCore(engineCore)
{
	init();
}

LuaManager::~LuaManager()
{
	lua_close(luaState);
}


bool LuaManager::init()
{
	//create lua state
	luaState = lua_open();
	if (luaState == NULL)
	{
		cout << "Error Initializing lua." << endl;
		return false;
	}

	//load lua functions
	luaL_openlibs(luaState);
	return true;
}


bool LuaManager::doLuaFile(char *filename)
{
	if (luaL_dofile(luaState, filename))
	{
		cout << "Lua: Problem with " << filename << endl;
		return false;
	}

	doTextures();		cout << "-----------------------" << endl;
	doTerrain();		cout << "-----------------------" << endl;
	doTerrainLayers();		cout << "-----------------------" << endl;
	
	cout << "Lua: " << filename << " successful." << endl;
	return true;
}

int LuaManager::getLuaNumber(const char *key)
{
	int result;
	lua_pushstring(luaState, key);
	lua_gettable(luaState, -2);

	result = (int)lua_tonumber(luaState, -1);
	lua_pop(luaState, 1);
	return result;
}


string LuaManager::getLuaString(const char *key)
{
	string result;
	lua_pushstring(luaState, key);
	lua_gettable(luaState, -2);

	result = (string)lua_tostring(luaState, -1);
	lua_pop(luaState, 1);
	return result;
}

char * LuaManager::convertToChar(string inputString)
{
	char * cString = new char[inputString.size() + 1];
	copy(inputString.begin(), inputString.end(), cString);
	cString[inputString.size()] = '\0';
	return cString;
}

bool LuaManager::doTextures()
{
	lua_getglobal(luaState, "textures");

	if (lua_istable(luaState, -1))
	{
		lua_pushnil(luaState);

		//*NS Not a great way to do this, but does work. Has to store mutliple sets of 2. [a][1] [b][2] etc.
		vector <string> textureNames;
		vector <string> textureFilenames;
		bool flipflop = true;

			while(lua_next(luaState, -2))
			{
				if (lua_isstring(luaState, -1))
				{
					if (flipflop)
						textureNames.push_back((string)lua_tostring(luaState, -1));
					else
						textureFilenames.push_back((string)lua_tostring(luaState, -1));

					flipflop = ! flipflop;
				}
				lua_pop(luaState, 1);
			}
		lua_pop(luaState, 1);

		if (textureNames.size() != textureFilenames.size())
			cout << "Lua Error: Texture Sets Mismatch!" << endl;

		for (int i = 0; i < textureNames.size(); i++)
		{
			mEngineCore->GetTextureManager().loadTexture(textureNames[i], convertToChar(textureFilenames[i]));
		}
		return true;
	}
	else
		return false;
}

bool LuaManager::doTerrain()
{
	lua_getglobal(luaState, "terrain");
	if (lua_istable(luaState, -1))
	{
		mEngineCore->GetTerrainEngine().generateTerrain(getLuaString("baseTexture"), convertToChar(getLuaString("heightMap")), getLuaNumber("size"));
		mEngineCore->GetTerrainEngine().setScalingFactor(getLuaNumber("scaleX"), getLuaNumber("scaleY"), getLuaNumber("scaleZ"));
		return true;
	}
	else
		return false;
}

bool LuaManager::doTerrainLayers()
{
	lua_getglobal(luaState, "terrainLayers");

	if (lua_istable(luaState, -1))
	{
		lua_pushnil(luaState);

		vector <string> textures;
		vector <string> filenames;
		bool flipflop = true;

			while(lua_next(luaState, -2))
			{
				if (lua_isstring(luaState, -1))
				{
					if (flipflop)
						textures.push_back((string)lua_tostring(luaState, -1));
					else
						filenames.push_back((string)lua_tostring(luaState, -1));
					
					flipflop = ! flipflop;
				}
				lua_pop(luaState, 1);

			}
		lua_pop(luaState, 1);

		if (textures.size() != filenames.size())
			cout << "Lua Error: Terrain Layers Mismatch!" << endl;

		for (int i = 0; i < textures.size(); i++)
		{
			cout << "Lua: " << i << " " << textures[i] << ", " << convertToChar(filenames[i]) << endl;
			mEngineCore->GetTerrainEngine().addMapLayer(textures[i], convertToChar(filenames[i]));
		}
		//mEngineCore->GetTerrainEngine().addMapLayer("grass", "textures/1024-grass.raw");
		return true;
	}
	else
		return false;
}
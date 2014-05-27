#include "LuaManager.h"

using namespace std;

LuaManager::LuaManager()
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

<<<<<<< HEAD
	doTextures();		cout << "-----------------------" << endl;
	//doTerrain();		cout << "-----------------------" << endl;
	//doTerrainLayers();		cout << "-----------------------" << endl;
	
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
=======
	//*********************//
	//		TEXTURES	   //
	//*********************//
>>>>>>> parent of 94baa49... Stuffs
	lua_getglobal(luaState, "textures");

	if (lua_istable(luaState, -1))
	{
		lua_pushnil(luaState);

		//should expand or use dynamic container - needs to be twice the amount of textures
		vector <string> texStrings;

			while(lua_next(luaState, -2))
			{
				if (lua_isstring(luaState, -1))
				{
					texStrings.push_back((string)lua_tostring(luaState, -1));
				}
				lua_pop(luaState, 1);

			}
		lua_pop(luaState, 1);

		for (int j = 0; j < texStrings.size(); j = j + 2)
		{
			cout << texStrings[j] << " - " << texStrings[j + 1] << endl;
			//texManager.loadTexture(texName[j], texName[j + 1]);
			//CALL TEXTURE MANAGER LOAD METHOD HERE.
		}

		cout << "-----------------------" << endl;
	}

	//*********************//
	//		TERRAIN		   //
	//*********************//
	lua_getglobal(luaState, "terrain");
	if (lua_istable(luaState, -1))
	{
		cout << getLuaNumber("size") << endl;
		cout << getLuaString("baseTexture") << endl;
		cout << getLuaString("heightMap") << endl;
		cout << "scale: " << getLuaNumber("scaleX") << ", " << getLuaNumber("scaleY") << ", " << getLuaNumber("scaleZ") << endl;

		//TERRAIN GENERATION CALL HERE
		cout << "-----------------------" << endl;
	}
	

	//*********************//
	//		MAPLAYERS	   //
	//*********************//
	lua_getglobal(luaState, "terrainLayers");

	if (lua_istable(luaState, -1))
	{
		lua_pushnil(luaState);

		//should expand or use dynamic container - needs to be twice the amount of textures
		vector <string> layerStrings;

			while(lua_next(luaState, -2))
			{
				if (lua_isstring(luaState, -1))
				{
					layerStrings.push_back((string)lua_tostring(luaState, -1));
				}
				lua_pop(luaState, 1);

			}
		lua_pop(luaState, 1);

		for (int j = 0; j < layerStrings.size(); j = j + 2)
		{
			cout << layerStrings[j] << " - " << layerStrings[j + 1] << endl;
			//terrain.addMapLayer(layerStrings[j], layerStrings[j + 1]);
			//TERRAIN ADD MAP LAYERS HERE
		}

		cout << "-----------------------" << endl << endl;
	}


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


/**
* @class LuaManager
* @brief Contains lua importing functions and the operations nescessary to deal with lua stuffs.
*
* @version 1
* @date 06/05/2014 Nadia Summers - Inital implementation.
*/

#ifndef LUAMANAGER_H
#define LUAMANAGER_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <lua.hpp>
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
#include "GameEngineCore.h"



class GameEngineCore;
class LuaManager
{
public:
	LuaManager(GameEngineCore* engineCore);
	~LuaManager();
	bool doLuaFile(char *filename);

private:
	GameEngineCore* mEngineCore;

	bool init();

	int getLuaNumber(const char *key, lua_State* luaState);
	std::string getLuaString(const char *key, lua_State* luaState);
	char * convertToChar(string inputString);

	bool doTextures(lua_State* luaState);
	bool doTerrain(lua_State* luaState);
	bool doTerrainLayers(lua_State* luaState);
};

#endif 
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

#include "TextureManager.h"

class LuaManager
{
public:
	LuaManager();
	~LuaManager();
	bool doLuaFile(char *filename);

private:
	bool init();
	lua_State* luaState;

	int getLuaNumber(const char *key);
	std::string getLuaString(const char *key);
};

#endif 
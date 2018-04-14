#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include <iostream>
#include <string>
#include <sstream>

///## Lua headers ###

#include "LuaBridge.h"
extern "C"
{
    # include "lua.h"
    # include "lauxlib.h"
    # include "lualib.h"
}

/// ################

///#### CONVERSION FROM STRING TO VARS AND FROM VARS TO STR #######

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

///##############################################

using namespace luabridge;

class LuaScript
{
    public:

        void ScriptInit(std::string dir)  /// OPEN A FILE BY FULL PATH
        {
            L = luaL_newstate();
            luaL_dofile(L, dir.c_str());
            luaL_openlibs(L);
            lua_pcall(L, 0, 0, 0);
        }

        template<class T>
        T getVariable(std::string varName)   /// NEED TO KNOW THE NAME OF VARIABLE
        {
            LuaRef var = getGlobal(L, varName.c_str());
            T out = var.cast<T>();
            return out;
        }

        template<class T>
        T getTableVar(std::string tabName, std::string varName)   /// SAME AS TOP PLUS NEED KNOW NAME OF TABLE
        {
            LuaRef mainTab = getGlobal(L, tabName.c_str());
            LuaRef var = mainTab[varName.c_str()];
            T out = var.cast<T>();

            return out;
        }

        template<class T>
        T getVarFromTableInTable(std::string tabName1, std::string tabName2, std::string varName)  /// GET VARS FROM SHEET IN SHEET
        {
            LuaRef firstTab = getGlobal(L, tabName1.c_str());
            LuaRef secondTab = firstTab[tabName2.c_str()];

            LuaRef var = secondTab[varName.c_str()];

            T out = var.cast<T>();

            return out;
        }

        void CloseScript()  /// USE FOR CLOSE CURRENT SCRIPT
        {
            lua_close(L);
        }

    private:

        lua_State* L;

};

#endif // LUASCRIPT_H

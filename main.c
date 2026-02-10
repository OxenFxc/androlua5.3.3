#include "lua.h"
#include "lauxlib.h"

/*
** A simple Lua module for testing the Android build workflow.
**
** To use this module in Lua:
**   local mylib = require "mylib"
**   print(mylib.hello())
*/

static int l_hello(lua_State *L) {
    lua_pushstring(L, "Hello from Android module!");
    return 1;
}

static const struct luaL_Reg mylib [] = {
    {"hello", l_hello},
    {NULL, NULL}
};

/*
** The main entry point.
** Note: The function name must match the library name.
** If you compile this as 'libmylib.so', Lua expects 'luaopen_mylib'.
*/
int luaopen_mylib(lua_State *L) {
    luaL_newlib(L, mylib);
    return 1;
}

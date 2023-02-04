#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int native_pythagoras(lua_State *L) {
  // returns how many return values are there

  // get args from stack
  lua_Number b = lua_tonumber(L, -1);
  lua_Number a = lua_tonumber(L, -2);

  lua_Number result = (a*a) + (b*b);
  lua_pushnumber(L, result);
  return 1;
}

int main(int argc, char const *argv[]) {
  // Create a Lua state variable
  lua_State *L = luaL_newstate();

  // Load Lua libraries
  luaL_openlibs(L);

  // push c function to stack
  lua_pushcfunction(L, native_pythagoras);

  // set global variable so lua can call it
  lua_setglobal(L, "native_pythagoras");

  // load & run file
  if (luaL_dofile(L, "./main.lua") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}

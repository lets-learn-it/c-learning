#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char const *argv[]) {
  // Create a Lua state variable
  lua_State *L = luaL_newstate();

  // Load Lua libraries
  luaL_openlibs(L);

  fprintf(stderr, "Loading file...\n");

  // load & execute file
  if (luaL_dofile(L, "./main.lua") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // get global function/variable
  lua_getglobal(L, "GetHypotenus");
  
  // check GetHypotenus is function
  if (lua_isfunction(L, -1)) {
    // push args to stack so GetHypotenus can get those
    lua_pushnumber(L, 3);
    lua_pushnumber(L, 4);

    const int NUM_ARGS = 2;
    const int NUM_RETURNS = 1;

    if (lua_pcall(L, NUM_ARGS, NUM_RETURNS, 0) != LUA_OK) {
      luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    // get result
    lua_Number num = lua_tonumber(L, -1);
    fprintf(stderr, "Result from Lua: %d", (int) num);
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}
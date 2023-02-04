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

  // get global variable
  lua_getglobal(L, "GlobalNumber");
  lua_Number num = lua_tonumber(L, -1);  // get from stack

  // get global variable
  lua_getglobal(L, "GlobalString");
  char * str = (char *) lua_tostring(L, -1);  // get from stack

  fprintf(stderr, "Values from Lua: %d %s", (int) num, str);

  // Close the Lua state variable
  lua_close(L);
  return 0;
}
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

  // load & run file
  if (luaL_dofile(L, "./main.lua") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // run string
  if (luaL_dostring(L, "print('This is fun')") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}
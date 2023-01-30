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
  luaL_dofile(L, "/home/parikshit/github/c-learning/28-JIT-with-lua/00-lua-learning/10-embedding-lua-in-c/00-intro/main.lua");

  // Close the Lua state variable
  lua_close(L);
  return 0;
}
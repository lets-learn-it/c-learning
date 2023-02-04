#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char const *argv[]) {
  // Create a Lua state variable
  lua_State *L = luaL_newstate();

  // Load Lua libraries
  luaL_openlibs(L);

  // load & run file
  if (luaL_dofile(L, "./main.lua") == LUA_OK) {
    lua_getglobal(L, "SimpleTable");
    if (lua_istable(L, -1)) {
      lua_getfield(L, -1, "age");
      lua_getfield(L, -2, "name");

      fprintf(stderr, "Name = %s, age = %d", lua_tostring(L, -1), (int) lua_tonumber(L, -2));
    }
  } else {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}

#include <stdio.h>
#include <string.h>
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

      fprintf(stderr, "From C: { Name = %s, age = %d }\n", lua_tostring(L, -1), (int) lua_tonumber(L, -2));

      // set field of table
      // https://www.lua.org/manual/5.1/manual.html#lua_setfield
      // now table is at -3
      const char *str = "PARIKSHIT";

      // push to stack
      lua_pushlstring(L, str, strlen(str));

      // now table is at -4
      lua_setfield(L, -4, "name");

      // call function printTable so it can print table
      lua_getglobal(L, "printTable");
      
      // check printTable is function
      if (lua_isfunction(L, -1)) {
        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
          luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
        }
      }
    }
  } else {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}

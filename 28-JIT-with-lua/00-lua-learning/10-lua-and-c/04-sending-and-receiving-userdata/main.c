#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

typedef struct {
  int x, y;
  int width, height;
} rectangle;

int create_rectangle(lua_State *L) {
  rectangle *rect = (rectangle*) lua_newuserdata(L, sizeof(rectangle));
  rect->x = 0;
  rect->y = 0;
  rect->height = 0;
  rect->width = 0;
  return 1;  // return own type as new userdata
}

int change_rectangle_size(lua_State *L) {
  // get args from stack (userdata, height, width)
  rectangle *rect = (rectangle *) lua_touserdata(L, -3);
  rect->width = (int) lua_tonumber(L, -1);
  rect->height = (int) lua_tonumber(L, -2);
  
  return 0;
}

int main(int argc, char const *argv[]) {
  // Create a Lua state variable
  lua_State *L = luaL_newstate();

  // Load Lua libraries
  luaL_openlibs(L);

  // push c function to stack & set global
  lua_pushcfunction(L, create_rectangle);
  lua_setglobal(L, "create_rectangle");

  // push c function to stack & set global
  lua_pushcfunction(L, change_rectangle_size);
  lua_setglobal(L, "change_rectangle_size");

  // load & run file
  if (luaL_dofile(L, "./main.lua") != LUA_OK) {
    luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
  }

  lua_getglobal(L, "rectangle");

  if (lua_isuserdata(L, -1)) {
    rectangle *rect = (rectangle *) lua_touserdata(L, -1);
    fprintf(stderr, "x = %d, y = %d, height = %d, width = %d", rect->x, rect->y, rect->height, rect->width);
  }

  // Close the Lua state variable
  lua_close(L);
  return 0;
}

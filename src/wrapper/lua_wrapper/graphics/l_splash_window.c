/*-------------------------------------------------------------------------*/
/**
   @file    l_Splash_window.h
   @author  P. Batty
   @brief   The LUA window structs

   This module implements the creation and manipulations of the 
   lua window structure in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_window.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "splash/splash_lua_wrapper.h"
#include "l_splash_window.h"

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

static int l_splash_window_create(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 3) {
    luaL_error (l, "Invalid argument count got %d expected 3\n", argc);
  } 

  if (!lua_isstring(l, 1)) {
    luaL_error (l, "Invalid argument 'title' should be a string\n");
  }
  if (!lua_isnumber(l, 2)) {
    luaL_error (l, "Invalid argument 'width' should be a string\n");
  }
  if (!lua_isnumber(l, 3)) {
    luaL_error (l, "Invalid argument 'hight' should be a string\n");
  }


  char *title = luaL_checklstring(l, 1, NULL);
  int width = luaL_checkinteger(l, 2);
  int height = luaL_checkinteger(l, 3);

  Splash_window *window = splash_window_create(title, width, height);
  lua_pushlightuserdata(l, window);
 return 1;
}


static int l_splash_window_destroy(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  splash_window_destroy(window);

 return 0;
}

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

void l_splash_window_register(lua_State *l) {
  const struct luaL_Reg module[] = {
    {"create", l_splash_window_create},
    {"destroy", l_splash_window_destroy},
    {NULL, NULL}
  };
  luaL_newlib(l, module);
  lua_setglobal(l, "splash_window");
}
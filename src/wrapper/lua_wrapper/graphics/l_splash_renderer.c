/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_renderer.c
   @author  P. Batty
   @brief   The renderer

   This module implements the renderer lua bindings

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_renderer.h"
#include "SDL2/SDL.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "splash/splash_lua_wrapper.h"
#include "l_splash_renderer.h"

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/
/*!--------------------------------------------------------------------------
  @brief    Clears the window
  @param  window  the window to clear
  @param  red   red value ( 0- 255 )
  @param  green green value ( 0- 255 )
  @param  blue  blue value ( 0- 255 )
  @return   Void

  Clears the window with the colors provided

\-----------------------------------------------------------------------------*/
static int l_splash_renderer_clear(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 4) {
    luaL_error (l, "Invalid argument count got %d expected 4\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isnumber(l, 2)) {
    luaL_error (l, "Invalid argument 'red' should be a string\n");
  }
  if (!lua_isnumber(l, 3)) {
    luaL_error (l, "Invalid argument 'green' should be a string\n");
  }
  if (!lua_isnumber(l, 4)) {
    luaL_error (l, "Invalid argument 'blue' should be a string\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int32_t red = luaL_checkinteger(l, 2);
  int32_t green = luaL_checkinteger(l, 3);
  int32_t blue = luaL_checkinteger(l, 4);

  splash_renderer_clear(window, red, green, blue);
 return 0;
}

/*!--------------------------------------------------------------------------
  @brief    registers the window functions to lua
  @param    the state to register to
  @return   Void

  Registers the window functions to lua

\-----------------------------------------------------------------------------*/
void l_splash_renderer_register(lua_State *l) {
  const struct luaL_Reg module[] = {
    {"clear", l_splash_renderer_clear},
    {NULL, NULL}
  };
  luaL_newlib(l, module);
  lua_setglobal(l, "splash_renderer");
}
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
#include "SDL2/SDL.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "splash/splash_lua_wrapper.h"
#include "l_splash_window.h"

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_window
  @param  title   The window title
  @param  width   The width of the window
  @param  hight   The height of the window
  @return   New Splash_window otherwise NULL.

  Creates a new Splash_window object destroy with splash_window_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
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

  const char *title = luaL_checklstring(l, 1, NULL);
  int32_t width = luaL_checkinteger(l, 2);
  int32_t height = luaL_checkinteger(l, 3);

  Splash_window *window = splash_window_create(title, width, height);
  lua_pushlightuserdata(l, window);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window title
  @param  window   The window to modify
  @param  title    The new title
  @return  Void

  Changes the title on the window to the one passed in.

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_title(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isstring(l,2)) {
    luaL_error (l, "Invalid argument 'title' should be a string\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  const char *title = luaL_checklstring(l, 2, NULL);

  splash_window_set_title(window, title);
 return 0;
}


 /*!--------------------------------------------------------------------------
  @brief    Sets the window brightness
  @param  window      The window to modify
  @param  brightness  The new brightness
  @return  Void

  Changes the brightness on the window to the one passed in.

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_brightness(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'brightness' should be a number\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  float brightness = luaL_checknumber(l, 2);

  splash_window_set_brightness(window, brightness);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window positon
  @param  window       The window to modify
  @param  x_position   The x cooridnate to move the window to
  @param  y_position   The y cooridnate to move the window to
  @return  Void

  Move the window to the coordinates passed in.

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_position(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 3) {
    luaL_error (l, "Invalid argument count got %d expected 3\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'x_position' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'y_position' should be a number\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int32_t x_position = luaL_checkint(l, 2);
  int32_t y_position = luaL_checkint(l, 3);

  splash_window_set_position(window, x_position, y_position);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window size
  @param  window  The window to modify
  @param  width   The width of the window
  @param  hight   The height of the window
  @return  Void

  Changes the windows size to the size passed in.

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_size(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 3) {
    luaL_error (l, "Invalid argument count got %d expected 3\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'width' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'height' should be a number\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int32_t width = luaL_checkint(l, 2);
  int32_t height = luaL_checkint(l, 3);

  splash_window_set_size(window, width, height);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window fullscreen
  @param  window      The window to modify
  @param  fullscreen  Should we go fullscreen
  @return  Void

  if true is passed in and possible the window will be made fullscreen
  if false is passed in the window will be made windowed

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_fullscreen(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isboolean(l, 2)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type boolean\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int8_t fullscreen = lua_toboolean(l, 2);

  splash_window_set_fullscreen(window, fullscreen);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window borders
  @param  window      The window to modify
  @param  borderless  Should we have borderless
  @return  Void

  if true is passed in and possible the window will be made borderless
  if false is passed in the window will be made bordered

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_borderless(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isboolean(l, 2)) {
    luaL_error (l, "Invalid argument 'borderless' should be a user data of type boolean\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int8_t borderless = lua_toboolean(l, 2);

  splash_window_set_borderless(window, borderless);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window visiblity
  @param  window    The window to modify
  @param  visible   Should we be visible
  @return  Void

  if true is passed in and possible the window will be made visible
  if false is passed in the window will be made hidden

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_visible(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isboolean(l, 2)) {
    luaL_error (l, "Invalid argument 'visable' should be a user data of type boolean\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int8_t visible = lua_toboolean(l, 2);

  splash_window_set_visible(window, visible);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window resizable
  @param  window      The window to modify
  @param  resizable   Should we be resizable
  @return  Void

  if true is passed in and possible the window will be made resizable
  if false is passed in the window will be made fixed size

\-----------------------------------------------------------------------------*/
static int l_splash_window_set_resizable(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }
  if (!lua_isboolean(l, 2)) {
    luaL_error (l, "Invalid argument 'resizable' should be a user data of type boolean\n");
  }

  Splash_window *window = lua_touserdata(l, 1);
  int8_t resizable = lua_toboolean(l, 2);

  splash_window_set_visible(window, resizable);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window title
  @param  window      The window to get
  @return  The window title

  Gets the current window title

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_title(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  char *title = splash_window_get_title(window);
  lua_pushstring(l, title);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window brightness
  @param  window      The window to get
  @return  The window brightness

  Gets the current window brightness

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_brightness(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  float brightness = splash_window_get_brightness(window);
  lua_pushnumber(l, brightness);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window position
  @param  window      The window to get
  @return  The window positon inside a point

  Gets the current window position

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_position(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  SDL_Point point = splash_window_get_position(window);
    lua_createtable(l, 0 , 2);

    lua_pushnumber(l, point.x);
    lua_setfield(l, -2, "x");
    
    lua_pushnumber(l, point.y);
    lua_setfield(l, -2, "y");
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window size
  @param  window      The window to get
  @return  The window size inside a point

  Gets the current window size

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_size(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  SDL_Point point = splash_window_get_size(window);
    lua_createtable(l, 0 , 2);

    lua_pushnumber(l, point.x);
    lua_setfield(l, -2, "w");
    
    lua_pushnumber(l, point.y);
    lua_setfield(l, -2, "h");
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window fullscreen
  @param  window      The window to get
  @return  1 if fullscreen else 0

  Gets the whether the window is currenly fullscreen

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_fullscreen(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  int fullscreen = splash_window_get_fullscreen(window);
  lua_pushboolean(l, fullscreen);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window borderless
  @param  window      The window to get
  @return  1 if borderless else 0

  Gets the whether the window is currenly borderless

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_borderless(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  int borderless = splash_window_get_borderless(window);
  lua_pushboolean(l, borderless);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window visible
  @param  window      The window to get
  @return  1 if visible else 0

  Gets the whether the window is currenly visible

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_visible(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  int visible = splash_window_get_visible(window);
  lua_pushboolean(l, visible);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window resizable
  @param  window      The window to get
  @return  1 if resizable else 0

  Gets the whether the window is currenly resizable

\-----------------------------------------------------------------------------*/
static int l_splash_window_get_resizable(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'window' should be a user data of type splash.window\n");
  }

  Splash_window *window = lua_touserdata(l, 1);

  int resizable = splash_window_get_resizable(window);
  lua_pushboolean(l, resizable);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Destroy's the window
  @param  window      The window to destroy
  @return  Void

  Destroy's the window

\-----------------------------------------------------------------------------*/
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

/*!--------------------------------------------------------------------------
  @brief    registers the window functions to lua
  @param    the state to register to
  @return   Void

  Registers the window functions to lua

\-----------------------------------------------------------------------------*/
void l_splash_window_register(lua_State *l) {
  const struct luaL_Reg module[] = {
    {"create", l_splash_window_create},
    {"setTitle", l_splash_window_set_title},
    {"setBrightness", l_splash_window_set_brightness},
    {"setPosition", l_splash_window_set_position},
    {"setSize", l_splash_window_set_size},
    {"setFullscreen", l_splash_window_set_fullscreen},
    {"setBorderless", l_splash_window_set_borderless},
    {"setVisible", l_splash_window_set_visible},
    {"setResizable", l_splash_window_set_resizable},
    {"getTitle", l_splash_window_get_title},
    {"getBrightness", l_splash_window_get_brightness},
    {"getPosition", l_splash_window_get_position},
    {"getSize", l_splash_window_get_size},
    {"getFullscreen", l_splash_window_get_fullscreen},
    {"getBorderless", l_splash_window_get_borderless},
    {"getVisible", l_splash_window_get_visible},
    {"getResizable", l_splash_window_get_resizable},
    {"destroy", l_splash_window_destroy},
    {NULL, NULL}
  };
  luaL_newlib(l, module);
  lua_setglobal(l, "splash_window");
}
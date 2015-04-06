/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_camera.c
   @author  P. Batty
   @brief   The renderer

   This module implements the renderer lua bindings

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_camera.h"
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
  @brief    Creates a new Splash_camera
  @return   New Splash_camera otherwise NULL.

  Creates a new Splash_camera object destroy with splash_camera_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
static int l_splash_camera_ortho_create(lua_State *l) {
  
  Splash_camera *camera = splash_camera_ortho_create();
  lua_pushlightuserdata(l, camera);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the position of the camera
  @param    camera The camera to change
  @param    x      The x position to move to
  @param    y      The y position to move to
  @param    z      The z position to move to
  @return    Void

  Sets the position of the camera

\-----------------------------------------------------------------------------*/
static int l_splash_camera_set_position(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 4) {
    luaL_error (l, "Invalid argument count got %d expected 4\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'x' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'y' should be a number\n");
  }
  if (!lua_isnumber(l,4)) {
    luaL_error (l, "Invalid argument 'z' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float x = luaL_checknumber(l, 2);
  float y = luaL_checknumber(l, 3);
  float z = luaL_checknumber(l, 4);

  splash_camera_set_position(camera, x, y, z);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the size of the camera
  @param    camera   The camera to change
  @param    width    The new width
  @param    height   The new height
  @return    Void

  Sets the size of the camera

\-----------------------------------------------------------------------------*/
static int l_splash_camera_set_size(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 3) {
    luaL_error (l, "Invalid argument count got %d expected 3\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'width' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'height' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float width = luaL_checknumber(l, 2);
  float height = luaL_checknumber(l, 3);

  splash_camera_set_size(camera, width, height);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The new zoom
  @return    Void

  Sets the zoom of the camera

\-----------------------------------------------------------------------------*/
static int l_splash_camera_set_zoom(lua_State *l) {
  
  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'width' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float zoom = luaL_checknumber(l, 2);

  splash_camera_set_zoom(camera, zoom);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the roation of the camera
  @param    camera   The camera to change
  @param    yaw     The new yaw of the camera
  @param    pitch   The new pitch of the camera
  @param    roll    The new roll of the camera
  @return    Void

  Sets the rotation of the camera

\-----------------------------------------------------------------------------*/
static int l_splash_camera_set_rotation(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 4) {
    luaL_error (l, "Invalid argument count got %d expected 4\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'yaw' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'pitch' should be a number\n");
  }
  if (!lua_isnumber(l,4)) {
    luaL_error (l, "Invalid argument 'roll' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float yaw = luaL_checknumber(l, 2);
  float pitch = luaL_checknumber(l, 3);
  float roll = luaL_checknumber(l, 4);

  splash_camera_set_rotation(camera, yaw, pitch, roll);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Moves the camera
  @param    camera   The camera to change
  @param    x        The x amount to move by
  @param    y        The y amount to move by
  @param    z        The z amount to move by
  @return    Void

  Move the camera by the amount passed in

\-----------------------------------------------------------------------------*/
static int l_splash_camera_translate(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 4) {
    luaL_error (l, "Invalid argument count got %d expected 4\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'x' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'y' should be a number\n");
  }
  if (!lua_isnumber(l,4)) {
    luaL_error (l, "Invalid argument 'z' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float x = luaL_checknumber(l, 2);
  float y = luaL_checknumber(l, 3);
  float z = luaL_checknumber(l, 4);

  splash_camera_translate(camera, x, y, z);

 return 0;
}
  

/*!--------------------------------------------------------------------------
  @brief    Changes the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The zoom amount to change by
  @return    Void

  Changes the zoom amout by the amount passed in

\-----------------------------------------------------------------------------*/
static int l_splash_camera_zoom(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 2) {
    luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'zoom' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float zoom = luaL_checknumber(l, 2);

  splash_camera_zoom(camera, zoom);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Rotates the camera
  @param    camera   The camera to change
  @param    yaw     The yaw amount to move by
  @param    pitch   The pitch amount to move by
  @param    roll    The roll amount to move by
  @return    Void

  Rotates the camera by the amount passed in

\-----------------------------------------------------------------------------*/
static int l_splash_camera_rotate(lua_State *l) {

  int argc = lua_gettop(l);
  if (argc != 4) {
    luaL_error (l, "Invalid argument count got %d expected 4\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camrea\n");
  }
  if (!lua_isnumber(l,2)) {
    luaL_error (l, "Invalid argument 'yaw' should be a number\n");
  }
  if (!lua_isnumber(l,3)) {
    luaL_error (l, "Invalid argument 'pitch' should be a number\n");
  }
  if (!lua_isnumber(l,4)) {
    luaL_error (l, "Invalid argument 'roll' should be a number\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  float yaw = luaL_checknumber(l, 2);
  float pitch = luaL_checknumber(l, 3);
  float roll = luaL_checknumber(l, 4);

  splash_camera_rotate(camera, yaw, pitch, roll);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera positition
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras position

\-----------------------------------------------------------------------------*/
static int l_splash_camera_get_position(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camera\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);

  Splash_vector3 pos = splash_camera_get_position(camera);
    lua_createtable(l, 0 , 3);

    lua_pushnumber(l, pos.x);
    lua_setfield(l, -2, "x");
    
    lua_pushnumber(l, pos.y);
    lua_setfield(l, -2, "y");

    lua_pushnumber(l, pos.z);
    lua_setfield(l, -2, "z");
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera positition
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras position

\-----------------------------------------------------------------------------*/
static int l_splash_camera_get_size(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camera\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);

  Splash_vector3 pos = splash_camera_get_size(camera);
    lua_createtable(l, 0 , 3);

    lua_pushnumber(l, pos.x);
    lua_setfield(l, -2, "w");
    
    lua_pushnumber(l, pos.y);
    lua_setfield(l, -2, "h");

    lua_pushnumber(l, pos.z);
    lua_setfield(l, -2, "l");
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera positition
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras position

\-----------------------------------------------------------------------------*/
static int l_splash_camera_get_rotation(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camera\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);

  Splash_vector3 pos = splash_camera_get_rotation(camera);
    lua_createtable(l, 0 , 3);

    lua_pushnumber(l, pos.x);
    lua_setfield(l, -2, "x");
    
    lua_pushnumber(l, pos.y);
    lua_setfield(l, -2, "y");

    lua_pushnumber(l, pos.z);
    lua_setfield(l, -2, "z");
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera zoom
  @param    camera  The camera to get 
  @return    Double with the camera  zoom

  Gets the cameras zoom

\-----------------------------------------------------------------------------*/
static int l_splash_camera_get_zoom(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camera\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);

  float zoom = splash_camera_get_zoom(camera);
  lua_pushnumber(l, zoom);
    
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Destorys a camera
  @param    camera  The camera to destory
  @return    Void

  Destroy's a camera

\-----------------------------------------------------------------------------*/
static int l_splash_camera_destroy(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 1) {
    luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
  } 

  if (!lua_isuserdata(l,1)) {
    luaL_error (l, "Invalid argument 'camrea' should be a user data of type splash.camera\n");
  }

  Splash_camera *camera = lua_touserdata(l, 1);
  splash_camera_destroy(camera);
    
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    registers the camera functions to lua
  @param    the state to register to
  @return   Void

  Registers the camera functions to lua

\-----------------------------------------------------------------------------*/
void l_splash_camera_register(lua_State *l) {
  const struct luaL_Reg module[] = {
    {"orthoCreate", l_splash_camera_ortho_create},
    {"setPosition", l_splash_camera_set_position},
    {"setSize", l_splash_camera_set_size},
    {"setZoom", l_splash_camera_set_zoom},
    {"setRotation", l_splash_camera_set_rotation},
    {"translate", l_splash_camera_translate},
    {"zoom", l_splash_camera_zoom},
    {"rotate", l_splash_camera_rotate},
    {"getPosition", l_splash_camera_get_position},
    {"getSize", l_splash_camera_get_size},
    {"getRotation", l_splash_camera_get_rotation},
    {"getZoom", l_splash_camera_get_zoom},
    {"destroy", l_splash_camera_destroy},
    {NULL, NULL}
  };
  luaL_newlib(l, module);
  lua_setglobal(l, "splash_camera");
}
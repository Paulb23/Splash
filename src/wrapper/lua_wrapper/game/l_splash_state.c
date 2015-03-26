/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_state.h
   @author  P. Batty
   @brief   The lua state

   This module implements the creation and manipulations of the 
   lua game state structs in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_state.h"
#include "SDL2/SDL.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "splash/splash_lua_wrapper.h"
#include "l_splash_state.h"
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash state
  @param  name    The state name
  @param  init    function that takes a char * and a void *
  @param  update  function that takes a float
  @param  event   function that takes a and Sdl_event
  @param  render  function that takes a no args
  @param  cleanup function that takes a char *
  @return   New Splash_state otherwise NULL.

  Creates a new Splash_window object destroy with splash_state_destroy();
  return a new object else null if unsuccessful

  init
    @param char *    The state that we are switiching to
    @param void *    Any data you want to pass in

  update
    @param float    The delta time

  event
    @param Sdl_event The event

  render

  cleanup
    @param  char *   The state that we are switiching to

\-----------------------------------------------------------------------------*/
static int l_splash_state_create(lua_State *l) {
  int argc = lua_gettop(l);
  if (argc != 6) {
    luaL_error (l, "Invalid argument count got %d expected 6\n", argc);
  } 

  if (!lua_isstring(l, 1)) {
    luaL_error (l, "Invalid argument 'name' should be a string\n");
  }
  if (!lua_isfunction(l, 2)) {
    luaL_error (l, "Invalid argument 'init' should be a function\n");
  }
  if (!lua_isfunction(l, 3)) {
    luaL_error (l, "Invalid argument 'update' should be a function\n");
  }
  if (!lua_isfunction(l, 4)) {
    luaL_error (l, "Invalid argument 'event' should be a function\n");
  }
  if (!lua_isfunction(l, 5)) {
    luaL_error (l, "Invalid argument 'render' should be a function\n");
  }
  if (!lua_isfunction(l, 6)) {
    luaL_error (l, "Invalid argument 'cleanup' should be a function\n");
  }

  Splash_state *state = malloc(sizeof(Splash_state));

  if (!state) {
  	return 0;
  }

  state->name = luaL_checklstring(l, 1, NULL);
  state->l_init = luaL_ref(l,LUA_REGISTRYINDEX);
  state->l_update = luaL_ref(l,LUA_REGISTRYINDEX);
  state->l_event = luaL_ref(l,LUA_REGISTRYINDEX);
  state->l_render = luaL_ref(l,LUA_REGISTRYINDEX);
  state->l_cleanup = luaL_ref(l,LUA_REGISTRYINDEX);

  lua_pushlightuserdata(l, state);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Adds a state to the machine
  @param    state       The state to add
  @return   Void

  Adds a state to the machine

\-----------------------------------------------------------------------------*/
static int l_splash_state_add(lua_State *l) {
 int argc = lua_gettop(l);
 if (argc != 1) {
   luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
 } 

 if (!lua_isuserdata(l, 1)) {
   luaL_error (l, "Invalid argument 'state' should be a user data of type splash_state\n");
 }
 
 Splash_state *state = lua_touserdata(l, 1);
 splash_state_add(state);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Remove a state from the machine
  @param    state_name  The state name
  @return   Void

  Removes a state from the machine

\-----------------------------------------------------------------------------*/
static int l_splash_state_remove(lua_State *l) {
 int argc = lua_gettop(l);
 if (argc != 1) {
   luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
 } 

 if (!lua_isstring(l, 1)) {
    luaL_error (l, "Invalid argument 'state name' should be a string\n");
 }
 
 char *state_name = luaL_checklstring(l, 1, NULL);
 splash_state_remove(state_name);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Starts the splash state
  @param    state_name  The state name to start with
  @param    data        Any data to pass in to the init
  @return   Void

  Starts the splash state machine

\-----------------------------------------------------------------------------*/
static int l_splash_state_start(lua_State *l) {
   int argc = lua_gettop(l);
   if (argc != 2) {
     luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
   } 

   if (!lua_isstring(l, 1)) {
     luaL_error (l, "Invalid argument 'state name' should be a string\n");
   }

   char *state_name = luaL_checklstring(l, 1, NULL);
   void *data = lua_topointer(l , 2);

   splash_state_start(state_name, data);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Switchs the current state
  @param    state_name  The state name to switch to
  @param    data        Any data to pass in to the init
  @return   Void

  Switches the state machine

\-----------------------------------------------------------------------------*/
static int l_splash_state_switch(lua_State *l) {
   int argc = lua_gettop(l);
   if (argc != 2) {
     luaL_error (l, "Invalid argument count got %d expected 2\n", argc);
   } 

   if (!lua_isstring(l, 1)) {
     luaL_error (l, "Invalid argument 'state name' should be a string\n");
   }

   char *state_name = luaL_checklstring(l, 1, NULL);
   void *data = lua_topointer(l , 2);

   splash_state_switch(state_name, data);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Stops the splash state
  @return   Void

  Stops the splash state machine

\-----------------------------------------------------------------------------*/
static int l_splash_state_stop(lua_State *l) {
   splash_state_stop();

 return 0;
}

/*!--------------------------------------------------------------------------
  @brief    Set the ticks
  @return   Void

  Sets current ticks

\-----------------------------------------------------------------------------*/
static int l_splash_state_set_ticks(lua_State *l) {
   int argc = lua_gettop(l);
   if (argc != 1) {
     luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
   } 

   if (!lua_isstring(l, 1)) {
     luaL_error (l, "Invalid argument 'ticks' should be a number\n");
   }

   int32_t ticks = luaL_checkinteger(l, 1);

   splash_state_set_ticks(ticks);

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Gets a state
  @return   Splash_state object else NULL

  Gets the splash state else returns NULL

\-----------------------------------------------------------------------------*/
static int l_splash_state_get_state(lua_State *l) {
   int argc = lua_gettop(l);
   if (argc != 1) {
     luaL_error (l, "Invalid argument count got %d expected 1\n", argc);
   } 

   if (!lua_isstring(l, 1)) {
     luaL_error (l, "Invalid argument 'state name' should be a string\n");
   }

   char *state_name = luaL_checklstring(l, 1, NULL);
   Splash_state *state = splash_state_get_state(state_name);

   lua_pushlightuserdata(l, state);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the state macine uptime
  @return   Current state machine uptime

  Current state machine uptime

\-----------------------------------------------------------------------------*/
static int l_splash_state_get_uptime(lua_State *l) {
	int uptime = splash_state_get_uptime();
	lua_pushnumber(l, uptime);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the state uptime
  @return   Current state uptime

  Current state uptime

\-----------------------------------------------------------------------------*/
static int l_splash_state_get_state_uptime(lua_State *l) {
	int uptime = splash_state_get_state_uptime();
	lua_pushnumber(l, uptime);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the fps
  @return   Current current fps

  Current current fps

\-----------------------------------------------------------------------------*/
static int l_splash_state_get_fps(lua_State *l) {
	int frames = splash_state_get_fps();
	lua_pushnumber(l, frames);
 return 1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the ticks
  @return   Current current ticks

  Current current ticks

\-----------------------------------------------------------------------------*/
static int l_splash_state_get_ticks(lua_State *l) {
	int ticks = splash_state_get_ticks();
	lua_pushnumber(l, ticks);
 return 1;
}


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    registers the state functions to lua
  @param    the state to register to
  @return   Void

  Registers the state functions to lua

\-----------------------------------------------------------------------------*/
void l_splash_state_register(lua_State *l) {
  const struct luaL_Reg module[] = {
    {"create", l_splash_state_create},
    {"add", l_splash_state_add},
    {"remove", l_splash_state_remove},
    {"start", l_splash_state_start},
    {"switch", l_splash_state_switch},
    {"stop", l_splash_state_stop},
    {"setTicks", l_splash_state_set_ticks},
    {"getState", l_splash_state_get_state},
    {"getUptime", l_splash_state_get_uptime},
    {"getStateUptime", l_splash_state_get_state_uptime},
    {"getFps", l_splash_state_get_fps},
    {"getTicks", l_splash_state_get_ticks},
    {NULL, NULL}
  };
  luaL_newlib(l, module);
  lua_setglobal(l, "splash_state");
}


/*!--------------------------------------------------------------------------
  @brief    Calls the init
  @param    state     the state to call
  @param    new_state The state that we are switiching to
  @param    data      Any data to pass in
  @return   Void

  Calls the init function ties to the state

\-----------------------------------------------------------------------------*/
void l_splash_state_call_init(Splash_state *state, char *new_state, void *data) {
	lua_rawgeti(splash_lua_state ,LUA_REGISTRYINDEX, state->l_init);
	lua_pushstring(splash_lua_state, new_state);
	lua_pushlightuserdata(splash_lua_state, data);
	lua_pcall(splash_lua_state, 2, 0, 0);
}


/*!--------------------------------------------------------------------------
  @brief    Calls the update
  @param    state     the state to call
  @param    delta     delta time
  @return   Void

  Calls the update function ties to the state

\-----------------------------------------------------------------------------*/
void l_splash_state_call_update(Splash_state *state, float delta) {
	lua_rawgeti(splash_lua_state ,LUA_REGISTRYINDEX, state->l_update);
	lua_pushnumber(splash_lua_state, delta);
	lua_pcall(splash_lua_state, 1, 0, 0);
}


/*!--------------------------------------------------------------------------
  @brief    Calls the event
  @param    state     the state to call
  @param    event     the event
  @return   Void

  Calls the event function tied to the state

\-----------------------------------------------------------------------------*/
void l_splash_state_call_event(Splash_state *state, SDL_Event event) {
	lua_rawgeti(splash_lua_state ,LUA_REGISTRYINDEX, state->l_event);
	lua_pushlightuserdata(splash_lua_state, &event);
	lua_pcall(splash_lua_state, 1, 0, 0);
}


/*!--------------------------------------------------------------------------
  @brief    Calls the render
  @param    state     the state to call
  @return   Void

  Calls the render function tied to the state

\-----------------------------------------------------------------------------*/
void l_splash_state_call_render(Splash_state *state) {
	lua_rawgeti(splash_lua_state ,LUA_REGISTRYINDEX, state->l_render);
	lua_pcall(splash_lua_state, 0, 0, 0);
}


/*!--------------------------------------------------------------------------
  @brief    Calls the cleanup
  @param    state     the state to call
  @param    new_state The state that we are switiching to
  @return   Void

  Calls the cleanup function tied to the state

\-----------------------------------------------------------------------------*/
void l_splash_state_call_cleanup(Splash_state *state, char *new_state) {
	lua_rawgeti(splash_lua_state ,LUA_REGISTRYINDEX, state->l_cleanup);
	lua_pushstring(splash_lua_state, new_state);
	lua_pcall(splash_lua_state, 1, 0, 0);
}
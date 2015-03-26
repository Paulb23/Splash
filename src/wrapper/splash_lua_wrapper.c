/*-------------------------------------------------------------------------*/
/**
   @file    Splash_lua_wrapper.h
   @author  P. Batty
   @brief   The lua wrapper

   This module implements the wrapper for lua

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_lua_wrapper.h"
#include "lua_wrapper/lua_wrappers.h"
#include "lua/lua.h"


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

lua_State *splash_lua_state; /**< Global lua state */

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Registrars structs and functions with lua
  @param    the state to register to
  @return   Void

  Registrars all functions and structs with lua.

\-----------------------------------------------------------------------------*/
void splash_lua_register_all(lua_State *l) {
	l_splash_window_register(l);
  l_splash_state_register(l);
}
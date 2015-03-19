/*-------------------------------------------------------------------------*/
/**
   @file    Splash_lua_wrapper.h
   @author  P. Batty
   @brief   The lua wrapper

   This module implements the wrapper for lua

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_LUA_WRAPPER_H_
#define SPLASH_LUA_WRAPPER_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include <stdint.h>

#include "splash_begin_code.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/

extern DLL_EXPORT lua_State *splash_lua_state; /**< Global lua state */

/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Registrars structs and functions with lua
  @return   Void

  Registrars all functions and structs with lua.

\-----------------------------------------------------------------------------*/
extern void splash_lua_register_all();


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

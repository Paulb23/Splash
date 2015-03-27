/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_renderer.h
   @author  P. Batty
   @brief   The renderer

   This module implements the renderer lua bindings

*/
/*--------------------------------------------------------------------------*/

#ifndef L_SPLASH_RENDERER_H_
#define L_SPLASH_RENDERER_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_renderer.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    registers the renderer functions to lua
  @param    the state to register to
  @return   Void

  Registers the renderer functions to lua

\-----------------------------------------------------------------------------*/
extern void l_splash_renderer_register(lua_State *l);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

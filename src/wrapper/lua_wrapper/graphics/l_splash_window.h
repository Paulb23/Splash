/*-------------------------------------------------------------------------*/
/**
   @file    l_Splash_window.h
   @author  P. Batty
   @brief   The lua window structs

   This module implements the creation and manipulations of the 
   lua window structure in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef L_SPLASH_WINDOW_H_
#define L_SPLASH_WINDOW_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_window.h"
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
  @brief    registers the window functions to lua
  @param    the state to register to
  @return   Void

  Registers the window functions to lua

\-----------------------------------------------------------------------------*/
extern void l_splash_window_register(lua_State *l);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

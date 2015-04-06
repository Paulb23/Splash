/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_camera.h
   @author  P. Batty
   @brief   The renderer

   This module implements the camera lua bindings

*/
/*--------------------------------------------------------------------------*/

#ifndef L_SPLASH_CAMERA_H_
#define L_SPLASH_CAMERA_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_camera.h"
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
  @brief    registers the camera functions to lua
  @param    the state to register to
  @return   Void

  Registers the camera functions to lua

\-----------------------------------------------------------------------------*/
extern void l_splash_camera_register(lua_State *l);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

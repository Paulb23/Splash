/*-------------------------------------------------------------------------*/
/**
   @file    Splash.h
   @author  P. Batty
   @brief   initialise and shutdown of the framework

   This module implements the initialise and shutdown of the framework

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_H_
#define SPLASH_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "Splash_window.h"
#include "Splash_list.h"
#include "Splash_hashmap.h"
#include "Splash_state.h"
#include "Splash_renderer.h"
#include "Splash_vector.h"
#include "Splash_camera.h"
#include "Splash_vertex.h"

                                
#include "Splash_lua_wrapper.h"

#include "splash_begin_code.h"
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
  @brief    Starts the splash framework
  @return 	0 on success else -1

  Starts the splash framework and all libaries needed to fuctions.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_init();


/*!--------------------------------------------------------------------------
  @brief    Quits the splash framework
  @return 	void

  Quits the splash framework and all libaries used.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_quit();


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

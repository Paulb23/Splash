/*-------------------------------------------------------------------------*/
/**
   @file    Splash_renderer.h
   @author  P. Batty
   @brief   The renderer

   This module implements the renderer

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_RENDERER_H_
#define SPLASH_RENDERER_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash_window.h"
#include <stdint.h>

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
  @brief    Clears the window
  @param	window	the window to clear
  @param	red		red value ( 0- 255 )
  @param	green	green value ( 0- 255 )
  @param	blue	blue value ( 0- 255 )
  @return 	Void

  Clears the window with the colors provided

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_renderer_clear(Splash_window *window, int16_t red, int16_t green, int16_t blue);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif
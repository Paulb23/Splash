/*-------------------------------------------------------------------------*/
/**
   @file    Splash_renderer.c
   @author  P. Batty
   @brief   The renderer

   This module implements the renderer

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_renderer.h"
#include "GL/glew.h"
#include <stdint.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Clears the window
  @param  window  the window to clear
  @param  red   red value ( 0- 255 )
  @param  green green value ( 0- 255 )
  @param  blue  blue value ( 0- 255 )
  @return   Void

  Clears the window with the colors provided

\-----------------------------------------------------------------------------*/
void splash_renderer_clear(Splash_window *window, int16_t red, int16_t green, int16_t blue) {
    glClearColor( (float)red / 255, (float)green / 255, (float)blue / 255, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    SDL_GL_SwapWindow(window->window);
}
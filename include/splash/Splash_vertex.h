/*-------------------------------------------------------------------------*/
/**
   @file    Splash_vertex.h
   @author  P. Batty
   @brief   OpenGL vertex object

   This module implements the openGL vertex object

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_VERTEX_H_
#define SPLASH_VERTEX_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "SDL2/SDL.h"
#include "Splash_vector.h"

#include "splash_begin_code.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Splash_vertex

  The Splash vertex structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_vertex {
  SDL_Color color;    /**< The colour of the vertex */
  Splash_vector2 pos; /**< The position of the vertex */
  Splash_vector2 uv;  /**< The UV coords of the vertex */
} Splash_vertex;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vertex
  @param    color   The color of the vertex
  @param    pos     The pos of the vertex
  @param    uv      The uv of the vertex
  @return   returns a Splash_vertex

  Creates and returns a Splash_vertex

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vertex SPLASHCALL splash_vertex_create(SDL_Color color, Splash_vector2 pos, Splash_vector2 uv);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

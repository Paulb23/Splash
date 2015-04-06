/*-------------------------------------------------------------------------*/
/**
   @file    Splash_vertex.c
   @author  P. Batty
   @brief   OpenGL vertex object

   This module implements the openGL vertex object

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_vertex.h"
#include "SDL2/SDL.h"
#include "Splash/Splash_vector.h"


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

 
/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vertex
  @param    color   The color of the vertex
  @param    pos     The pos of the vertex
  @param    uv      The uv of the vertex
  @return   returns a Splash_vertex

  Creates and returns a Splash_vertex

\-----------------------------------------------------------------------------*/
Splash_vertex splash_vertex_create(SDL_Color color, Splash_vector2 pos, Splash_vector2 uv) {
  return ( Splash_vertex ) { color, pos, uv };
}
/*-------------------------------------------------------------------------*/
/**
   @file    Splash_glyph.h
   @author  P. Batty
   @brief   OpenGL glyph object

   This module implements the openGL glyph object

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_GLYPH_H_
#define SPLASH_GLYPH_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash_vertex.h"
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
  @brief    Splash_glyph

  The Splash glyph structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_glyph {
  SDL_Color color;            /**<  The color of the glyph */
  float depth;                /**< The depth of the glyph */

  Splash_vertex topLeft;      /**< The top left of the info about the glyph */
  Splash_vertex topRight;     /**< The top right of the info about the glyph */
  Splash_vertex bottomLeft;   /**< The bottom left of the info about the glyph */
  Splash_vertex bottomRight;  /**< The bottom right of the info about the glyph */
} Splash_glyph;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

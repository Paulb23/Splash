/*-------------------------------------------------------------------------*/
/**
   @file    Splash_texture.h
   @author  P. Batty
   @brief   The texture structs

   This module implements the creation and manipulations of the 
   texture structs in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_TEXTURE_H_
#define SPLASH_TEXTURE_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "GL/glew.h"
#include <stdint.h>

#include "splash_begin_code.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Splash_texture

  The texture struct
\----------------------------------------------------------------------------*/
typedef struct Splash_texture {
  GLuint  texture;        /**< The texture */
  int32_t texture_width;  /**< The texture width */
  int32_t texture_height; /**< The texture height */
} Splash_texture;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_texture
  @param  path    Path to the texture including extention
  @return   New Splash_texture otherwise NULL.

  Creates a new Splash_texture object destroy with splash_texture_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_texture SPLASHCALL *splash_texture_create(char *path);


/*!--------------------------------------------------------------------------
  @brief    Destroy's the texture
  @param  texture      The texture to destroy
  @return  Void

  Destroy's the texture

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_texture_destroy(Splash_texture *texture);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif
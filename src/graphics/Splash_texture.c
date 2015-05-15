/*-------------------------------------------------------------------------*/
/**
   @file    Splash_texture.c
   @author  P. Batty
   @brief   The texture structs

   This module implements the creation and manipulations of the 
   texture structs in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_texture.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

 
/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_texture
  @param  path    Path to the texture including extention
  @return   New Splash_texture otherwise NULL.

  Creates a new Splash_texture object destroy with splash_texture_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
Splash_texture *splash_texture_create(char *path) {
  Splash_texture *texture = malloc(sizeof(Splash_texture));

  if (!texture) {
    return NULL;
  }
 
  GLenum texture_format;
  GLint nOfColors;
  SDL_Surface *surface = IMG_Load(path);

  if (surface != NULL) {
     nOfColors = surface->format->BytesPerPixel;
     if (nOfColors == 4) {
        if (surface->format->Rmask == 0x000000ff) {
          texture_format = GL_RGBA;
        } else {
          texture_format = GL_BGRA;
        }
     } else if (nOfColors == 3) {
        if (surface->format->Rmask == 0x000000ff) {
          texture_format = GL_RGB;
        } else {
          texture_format = GL_BGR;  
        }
     }

     glEnable(GL_TEXTURE_2D);
     glGenTextures( 1, &texture->texture);
     glBindTexture( GL_TEXTURE_2D, texture->texture );
     glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
     glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );

     texture->texture_height = surface->h;
     texture->texture_width = surface->w;

    SDL_FreeSurface(surface);
  } else {
    free(texture);
    return NULL;
  }

  return texture;
}


/*!--------------------------------------------------------------------------
  @brief    Destroy's the texture
  @param  texture      The texture to destroy
  @return  Void

  Destroy's the texture

\-----------------------------------------------------------------------------*/
void splash_texture_destroy(Splash_texture *texture) {
  free(texture);
}
/*-------------------------------------------------------------------------*/
/**
   @file    Splash_window.h
   @author  P. Batty
   @brief   The window structions

   This module implements the creation and manipulations of the 
   window structure in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_WINDOW_H_
#define SPLASH_WINDOW_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "SDL2/SDL.h"
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
  @brief    Splash_window

  The window Splash window structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_window {
  SDL_Window *window;         /**< The SDL window */
  SDL_Point position;         /**< The x,y of the window */
  SDL_Point size;             /**< The w,h of the window */
  char *title;                /**< The title on the window */
  float brightness;            /**< The brightness of the window*/
  int8_t fullscreen;          /**< are we fullscreen */
  int8_t borderless;          /**< are we borderless */
  int8_t visible;             /**< are we visible */
  int8_t resizable;           /**< are we resizable */
} Splash_window;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_window
  @param  title   The window title
  @param  width   The width of the window
  @param  hight   The height of the window
  @return   New Splash_window otherwise NULL.

  Creates a new Splash_window object destroy with splash_window_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_window SPLASHCALL *splash_window_create(char *title, int32_t width, int32_t height);


/*!--------------------------------------------------------------------------
  @brief    Sets the window title
  @param  window   The window to modify
  @param  title    The new title
  @return  Void

  Changes the title on the window to the one passed in.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_title(Splash_window *window, char *title);


/*!--------------------------------------------------------------------------
  @brief    Sets the window brightness
  @param  window      The window to modify
  @param  brightness  The new brightness
  @return  Void

  Changes the brightness on the window to the one passed in.
  0.0 is dark
  1.0 is bright

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_brightness(Splash_window *window, float brightness);


/*!--------------------------------------------------------------------------
  @brief    Sets the window positon
  @param  window       The window to modify
  @param  x_position   The x cooridnate to move the window to
  @param  y_position   The y cooridnate to move the window to
  @return  Void

  Move the window to the coordinates passed in.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_position(Splash_window *window, int32_t x_position, int32_t y_position);


/*!--------------------------------------------------------------------------
  @brief    Sets the window size
  @param  window  The window to modify
  @param  width   The width of the window
  @param  hight   The height of the window
  @return  Void

  Changes the windows size to the size passed in.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_size(Splash_window *window, int32_t width, int32_t height);


/*!--------------------------------------------------------------------------
  @brief    Sets the window fullscreen
  @param  window      The window to modify
  @param  fullscreen  Should we go fullscreen
  @return  Void

  if true is passed in and possible the window will be made fullscreen
  if false is passed in the window will be made windowed

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_fullscreen(Splash_window *window, int8_t fullscreen);


/*!--------------------------------------------------------------------------
  @brief    Sets the window borders
  @param  window      The window to modify
  @param  borderless  Should we have borderless
  @return  Void

  if true is passed in and possible the window will be made borderless
  if false is passed in the window will be made bordered

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_borderless(Splash_window *window, int8_t borderless);


/*!--------------------------------------------------------------------------
  @brief    Sets the window visiblity
  @param  window    The window to modify
  @param  visible   Should we be visible
  @return  Void

  if true is passed in and possible the window will be made visible
  if false is passed in the window will be made hidden

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_visible(Splash_window *window, int8_t visible);


/*!--------------------------------------------------------------------------
  @brief    Sets the window resizable
  @param  window      The window to modify
  @param  resizable   Should we be resizable
  @return  Void

  if true is passed in and possible the window will be made resizable
  if false is passed in the window will be made fixed size

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_set_resizable(Splash_window *window, int8_t resizable);


/*!--------------------------------------------------------------------------
  @brief    Gets the window title
  @param  window      The window to get
  @return  The window title

  Gets the current window title

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT char SPLASHCALL *splash_window_get_title(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Gets the window brightness
  @param  window      The window to get
  @return  The window brightness

  Gets the current window brightness

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT float SPLASHCALL splash_window_get_brightness(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Gets the window position
  @param  window      The window to get
  @return  The window positon inside a point

  Gets the current window position

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT SDL_Point SPLASHCALL splash_window_get_position(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Gets the window size
  @param  window      The window to get
  @return  The window size inside a point

  Gets the current window size

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT SDL_Point SPLASHCALL splash_window_get_size(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Is the window fullscreen
  @param  window      The window to get
  @return  1 if fullscreen else 0

  Gets the whether the window is currenly fullscreen

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_window_get_fullscreen(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Is the window borderless
  @param  window      The window to get
  @return  1 if borderless else 0

  Gets the whether the window is currenly borderless

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_window_get_borderless(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Is the window visible
  @param  window      The window to get
  @return  1 if visible else 0

  Gets the whether the window is currenly visible

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_window_get_visible(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Is the window resizable
  @param  window      The window to get
  @return  1 if resizable else 0

  Gets the whether the window is currenly resizable

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_window_get_resizable(Splash_window *window);


/*!--------------------------------------------------------------------------
  @brief    Destroy's the window
  @param  window      The window to get
  @return  Void

  Destroy's the window and sets its pointer to null

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_window_destroy(Splash_window *window);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

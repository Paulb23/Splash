/*-------------------------------------------------------------------------*/
/**
   @file    Splash_window.h
   @author  P. Batty
   @brief   The window structs

   This module implements the creation and manipulations of the 
   window structure in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_window.h"
#include "SDL2/SDL.h"
#include <stdint.h>
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
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
Splash_window *splash_window_create(char *title, int32_t width, int32_t height) {
	Splash_window *window = malloc(sizeof(Splash_window));

	if (!window) {
		return NULL;
	}

	window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

	if (!window->window) {
		free(window);
		return NULL;
	}

	splash_window_set_title(window, title);
	splash_window_set_size(window, width, height);

	return window;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window title
  @param  window   The window to modify
  @param  title    The new title
  @return  Void

  Changes the title on the window to the one passed in.

\-----------------------------------------------------------------------------*/
 void splash_window_set_title(Splash_window *window, char *title) {
 	SDL_SetWindowTitle(window->window, title);
 	window->title = title;
 }


 /*!--------------------------------------------------------------------------
  @brief    Sets the window brightness
  @param  window      The window to modify
  @param  brightness  The new brightness
  @return  Void

  Changes the brightness on the window to the one passed in.

\-----------------------------------------------------------------------------*/
void splash_window_set_brightness(Splash_window *window, float brightness) {
	if (brightness >= 0.0 && brightness <= 1.0) {
		SDL_SetWindowBrightness(window->window, brightness);
		window->brightness = brightness;
	}
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window positon
  @param  window       The window to modify
  @param  x_position   The x cooridnate to move the window to
  @param  y_position   The y cooridnate to move the window to
  @return  Void

  Move the window to the coordinates passed in.

\-----------------------------------------------------------------------------*/
void splash_window_set_position(Splash_window *window, int32_t x_position, int32_t y_position) {
	window->position.x = abs(x_position);
	window->position.y = abs(y_position);
	SDL_SetWindowPosition(window->window, window->position.x, window->position.y);
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window size
  @param  window  The window to modify
  @param  width   The width of the window
  @param  hight   The height of the window
  @return  Void

  Changes the windows size to the size passed in.

\-----------------------------------------------------------------------------*/
void splash_window_set_size(Splash_window *window, int32_t width, int32_t height) {
	window->size.x = abs(width);
	window->size.y = abs(height);
	SDL_SetWindowSize(window->window, window->size.x, window->size.y);
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window fullscreen
  @param  window      The window to modify
  @param  fullscreen  Should we go fullscreen
  @return  Void

  if true is passed in and possible the window will be made fullscreen
  if false is passed in the window will be made windowed

\-----------------------------------------------------------------------------*/
void splash_window_set_fullscreen(Splash_window *window, int8_t fullscreen) {
	window->fullscreen = (fullscreen) ? 1 : 0; 
	if (window->fullscreen) {
		if (SDL_SetWindowFullscreen(window->window, SDL_WINDOW_FULLSCREEN) == 0) {
			window->fullscreen = 1; 
		} else {
			window->fullscreen = 0;
		}
	} else {
		if (SDL_SetWindowFullscreen(window->window, 0) == 0) {
			window->fullscreen = 0; 
		} else {
			window->fullscreen = 1; 
		}
	}
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window borders
  @param  window      The window to modify
  @param  borderless  Should we have borderless
  @return  Void

  if true is passed in and possible the window will be made borderless
  if false is passed in the window will be made bordered

\-----------------------------------------------------------------------------*/
void splash_window_set_borderless(Splash_window *window, int8_t borderless) {
	window->borderless = (borderless) ? 1 : 0; 
	SDL_SetWindowBordered(window->window, window->borderless);
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window visiblity
  @param  window    The window to modify
  @param  visible   Should we be visible
  @return  Void

  if true is passed in and possible the window will be made visible
  if false is passed in the window will be made hidden

\-----------------------------------------------------------------------------*/
void splash_window_set_visible(Splash_window *window, int8_t visible) {
	window->visible = (visible) ? 1 : 0; 
	if (window->visible) {
		SDL_ShowWindow(window->window);
	} else {
		SDL_HideWindow(window->window);
	}
}


/*!--------------------------------------------------------------------------
  @brief    Sets the window resizable
  @param  window      The window to modify
  @param  resizable   Should we be resizable
  @return  Void

  if true is passed in and possible the window will be made resizable
  if false is passed in the window will be made fixed size

\-----------------------------------------------------------------------------*/
void splash_window_set_resizable(Splash_window *window, int8_t resizable) {
	window->resizable = (resizable) ? 1 : 0; 
	SDL_DestroyWindow(window->window);
	if (window->resizable) {
		window->window = SDL_CreateWindow(window->title, window->position.x, window->position.y, window->size.x, window->size.y, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	} else {
		window->window = SDL_CreateWindow(window->title, window->position.x, window->position.y, window->size.x, window->size.y, SDL_WINDOW_OPENGL);
	}

	splash_window_set_visible(window, window->visible);
	splash_window_set_borderless(window, window->borderless);
	splash_window_set_fullscreen(window, window->fullscreen);
	splash_window_set_brightness(window, window->brightness);
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window title
  @param  window      The window to get
  @return  The window title

  Gets the current window title

\-----------------------------------------------------------------------------*/
char *splash_window_get_title(Splash_window *window) {
	return window->title;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window brightness
  @param  window      The window to get
  @return  The window brightness

  Gets the current window brightness

\-----------------------------------------------------------------------------*/
float splash_window_get_brightness(Splash_window *window) {
	return window->brightness;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window position
  @param  window      The window to get
  @return  The window positon inside a point

  Gets the current window position

\-----------------------------------------------------------------------------*/
SDL_Point splash_window_get_position(Splash_window *window) {
	return window->position;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the window size
  @param  window      The window to get
  @return  The window size inside a point

  Gets the current window size

\-----------------------------------------------------------------------------*/
SDL_Point splash_window_get_size(Splash_window *window) {
	return window->size;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window fullscreen
  @param  window      The window to get
  @return  1 if fullscreen else 0

  Gets the whether the window is currenly fullscreen

\-----------------------------------------------------------------------------*/
int8_t splash_window_get_fullscreen(Splash_window *window) {
	return window->fullscreen;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window borderless
  @param  window      The window to get
  @return  1 if borderless else 0

  Gets the whether the window is currenly borderless

\-----------------------------------------------------------------------------*/
int8_t splash_window_get_borderless(Splash_window *window) {
	return window->borderless;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window visible
  @param  window      The window to get
  @return  1 if visible else 0

  Gets the whether the window is currenly visible

\-----------------------------------------------------------------------------*/
int8_t splash_window_get_visible(Splash_window *window) {
	return window->visible;
}


/*!--------------------------------------------------------------------------
  @brief    Is the window resizable
  @param  window      The window to get
  @return  1 if resizable else 0

  Gets the whether the window is currenly resizable

\-----------------------------------------------------------------------------*/
int8_t splash_window_get_resizable(Splash_window *window) {
	return window->resizable;
}


/*!--------------------------------------------------------------------------
  @brief    Destroy's the window
  @param  window      The window to destroy
  @return  Void

  Destroy's the window

\-----------------------------------------------------------------------------*/
void splash_window_destroy(Splash_window *window) {
	SDL_DestroyWindow(window->window);
	free(window);
}
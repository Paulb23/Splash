/*-------------------------------------------------------------------------*/
/**
   @file    Splash.c
   @author  P. Batty
   @brief   ...

   This module implements...

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Starts the splash framework
  @return 	0 on success else -1

  Starts the splash framework and all libaries needed to fuctions.

\-----------------------------------------------------------------------------*/
int8_t splash_init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL 2", "FATAL: Could not start SDL 2!", NULL);
			return -1;
		}
		if (IMG_Init(IMG_INIT_PNG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Image", "FATAL: Could not start SDL Image!", NULL);
			return -1;
		}
		if (TTF_Init() == -1) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL TTF", "FATAL: Could not start SDL TTF!", NULL);
			return -1;
		}
		if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 1024)) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Mixer", "FATAL: Could not start SDL Mixer!", NULL);
			return -1;
		}
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Quits the splash framework
  @return 	void

  Quits the splash framework and all libaries used.

\-----------------------------------------------------------------------------*/
int8_t splash_quit() {
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
 return 0;
}

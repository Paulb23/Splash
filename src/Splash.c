/*-------------------------------------------------------------------------*/
/**
   @file    Splash.c
   @author  P. Batty
   @brief   initialise and shutdown of the framework

   This module implements the initialise and shutdown of the framework

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
#include "Splash/Splash_lua_wrapper.h"
#include "lua/lua.h"

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
		if (splash_state_init() == -1) {
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Splash", "FATAL: Could not start Splash State!", NULL);
			return -1;
		}

		splash_lua_state = luaL_newstate();
		luaL_openlibs(splash_lua_state);
		splash_lua_register_all(splash_lua_state);
 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Quits the splash framework
  @return 	void

  Quits the splash framework and all libaries used.

\-----------------------------------------------------------------------------*/
int8_t splash_quit() {
 	lua_close(splash_lua_state);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
 return 0;
}

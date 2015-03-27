/*-------------------------------------------------------------------------*/
/**
   @file    SplashTest.c
   @author  P. Batty
   @brief   Unit test
	
*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash.h"
#include "SDL2/SDL.h"                          
#include <assert.h>

static Splash_window *window;

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
	splash_init();
		window = splash_window_create("Title", 800, 600);

		while(1) {
			splash_renderer_clear(window, 255, 0, 0);
		}
	splash_quit();
	return 0;
}

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
#include <string.h>
#include <assert.h>

static Splash_window *window;


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void window_create_test() {
	window = splash_window_create("This is the title", 800, 600);
	assert(window != NULL && "Failed to create window");
	window = NULL;

	window = splash_window_create("This is the title", 8000, 6000);
	assert(window != NULL && "Failed to create window");
	window = NULL;

	window = splash_window_create("This is the title", -800, -600);
	assert(window != NULL && "Failed to create window");
	window = NULL;

	window = splash_window_create("This is the title", -8000, -6000);
	assert(window != NULL && "Failed to create window");
	window = NULL;

	window = splash_window_create("This is the title", 800, 600);
}


static void window_title_test() {
	splash_window_set_title(window, "This is a diffrent title");
	assert(strcmp(window->title, "This is a diffrent title") == 0  && "Failed to set window title");

	char *title = "This is going to be a very very very very very very very very long string in order to see if i can set a title to a window that is this long without any errors or crashing and if i can it will be \
				   amazing since this is going to possible the longest title for a window ever made in teh entire world hahahaha now how much longer can i make thsi title before i get annoyed at having to type a \
				   string that is this long just to test my set window title fuction";

	splash_window_set_title(window, title);
	assert(strcmp(window->title, title) == 0  && "Failed to set window title");

	splash_window_set_title(window, "");
	assert(strcmp(window->title, "") == 0  && "Failed to set window title");

	splash_window_set_title(window, "title");
	assert(strcmp(window->title, "title") == 0  && "Failed to set window title");
}


static void window_position_test() {
	splash_window_set_position(window, 10, 10);
	assert(window->position.x == 10 && window->position.y == 10 &&  "Failed to re-position window");

	splash_window_set_position(window, 9999, 9999);
	assert(window->position.x == 9999 && window->position.y == 9999 && "Failed to re-position window");

	splash_window_set_position(window, -10, -10);
	assert(window->position.x == 10 && window->position.y == 10 &&  "Failed to re-position window");

	splash_window_set_position(window, -9999, -9999);
	assert(window->position.x == 9999 && window->position.y == 9999 && "Failed to re-position window");

	splash_window_set_position(window, 50, 50);
	assert(window->position.x == 50 && window->position.y == 50 &&  "Failed to re-position window");
}


static void window_size_test() {
	splash_window_set_size(window, 800, 600);
	assert(window->size.x == 800 && window->size.y == 600 &&  "Failed to re-size window");

	splash_window_set_size(window, 8000, 6000);
	assert(window->size.x == 8000 && window->size.y == 6000 &&  "Failed to re-size window");

	splash_window_set_size(window, -8000, -6000);
	assert(window->size.x == 8000 && window->size.y == 6000 &&  "Failed to re-size window");

	splash_window_set_size(window, -800, -600);
	assert(window->size.x == 800 && window->size.y == 600 &&  "Failed to re-size window");
}


static void window_brightness_test() {
	splash_window_set_brightness(window, 0);
	assert(window->brightness == 0 &&  "Failed to set window brightness");

	splash_window_set_brightness(window, 1);
	assert(window->brightness == 1 &&  "Failed to set window brightness");

	splash_window_set_brightness(window, -10);
	assert(window->brightness == 1 &&  "Failed to set window brightness");

	splash_window_set_brightness(window, 10);
	assert(window->brightness == 1 &&  "Failed to set window brightness");
}


static void window_settings_test() {
	//splash_window_set_fullscreen(window, 1);
	//assert(window->fullscreen == 1 &&  "Failed to go full screen");

	//splash_window_set_fullscreen(window, 0);
	//assert(window->fullscreen == 0 &&  "Failed to go windowed");

	splash_window_set_borderless(window, 1);
	assert(window->borderless == 1 &&  "Failed to go borderless");

	splash_window_set_borderless(window, 0);
	assert(window->borderless == 0 &&  "Failed to go borderless");


	splash_window_set_visible(window, 1);
	assert(window->visible == 1 &&  "Failed to show window");

	splash_window_set_visible(window, 0);
	assert(window->visible == 0 &&  "Failed to hide window");


	splash_window_set_resizable(window, 1);
	assert(window->resizable == 1 &&  "Failed to turn on resizing window");

	splash_window_set_resizable(window, 0);
	assert(window->resizable == 0 &&  "Failed to turn off resizing window");
}


static void window_getters_test() {
	assert(strcmp(splash_window_get_title(window), "title") == 0  && "Failed to get window title");

	SDL_Point position = splash_window_get_position(window);
	assert(position.x == 50 && position.y == 50 && "Failed to get window position");

	SDL_Point size = splash_window_get_size(window);
	assert(size.x == 800 && size.y == 600 && "Failed to get window size");

	//assert(splash_window_get_fullscreen(window) == 0 && "Failed to get fullscreen");
	assert(splash_window_get_borderless(window) == 0 && "Failed to get borderless");
	assert(splash_window_get_visible(window) == 0 && "Failed to get visible");
	assert(splash_window_get_resizable(window) == 0 && "Failed to get resizable");
	assert(splash_window_get_brightness(window) == 1 && "Failed to get brightness");
}


int main(int argc, char *argv[]) {
	splash_init();
		window_create_test();
		window_title_test();
		window_position_test();
		window_size_test();
		window_brightness_test();
		window_settings_test();
		window_getters_test();

		splash_window_destroy(window);
	splash_quit();

	splash_init();
		if(luaL_dofile(splash_lua_state, "../scripts/test/window_test.lua")){
			printf("Could not load file: %s\n", lua_tostring(splash_lua_state, -1));
		}
	splash_quit();
 return 0;
}

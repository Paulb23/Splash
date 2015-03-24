/*-------------------------------------------------------------------------*/
/**
   @file    SplashStateTest.c
   @author  P. Batty
   @brief   Unit test
	
*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash.h"                          
#include <assert.h>


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void init(char *new_state, void *data) {}
static void update(double delta) {}
static void events(char *window, SDL_Event e) {}
static void render(char *window_name) {}
static void cleanup(char *new_state) {}


static void test_state_creation() {
	Splash_state *state = splash_state_create("Test state", init, update, events, render, cleanup);
	assert(state != NULL && "Failed to create state!");
}


int main(int argc, char *argv[]) {
	splash_init();

		test_state_creation();
	
	splash_quit();
  return 0;
}
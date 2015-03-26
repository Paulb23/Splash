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

static void test_init(char *new_state, void *data) {}
static void test_update(float delta) {splash_state_switch("The", NULL);}
static void test_events(SDL_Event e) {}
static void test_render() {}
static void test_cleanup(char *new_state) {}

static void the_init(char *new_state, void *data) {}
static void the_update(float delta) {splash_state_switch("Code", NULL);}
static void the_events(SDL_Event e) {}
static void the_render() {}
static void the_cleanup(char *new_state) {}

static void code_init(char *new_state, void *data) {}
static void code_update(float delta) {splash_state_stop();}
static void code_events(SDL_Event e) {}
static void code_render() {}
static void code_cleanup(char *new_state) {}


static void test_state_creation() {
	Splash_state *state = splash_state_create("Test", test_init, test_update, test_events, test_render, test_cleanup);
	assert(state != NULL && "Failed to create state!");
	splash_state_add(state);

	state = splash_state_create("The", the_init, the_update, the_events, the_render, the_cleanup);
	splash_state_add(state);
	state = splash_state_create("Code", code_init, code_update, code_events, code_render, code_cleanup);
	splash_state_add(state);

	splash_state_remove("Code");
	splash_state_add(state);
}

static void test_state_machine() {
	splash_state_start("Test", NULL);
}

int main(int argc, char *argv[]) {
	splash_init();

		test_state_creation();
		test_state_machine();
	
	splash_quit();
	splash_init();
		if(luaL_dofile(splash_lua_state, "../scripts/test/state_test.lua")){
			printf("Could not load file: %s\n", lua_tostring(splash_lua_state, -1));
		}
	splash_quit();
  return 0;
}
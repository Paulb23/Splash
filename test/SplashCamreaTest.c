/*-------------------------------------------------------------------------*/
/**
   @file    SplashcameraTest.c
   @author  P. Batty
   @brief   Unit test
	
*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash.h"                          
#include <assert.h>

static Splash_camera *camera;

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void test_camrea_creation() {
		camera = splash_camera_ortho_create();
		assert(camera != NULL && "Failed to create camera");
}

static void test_camrea_set() {
			splash_camera_set_position(camera, 0, 0, 0);
			assert(camera->position.x == 0 && camera->position.y == 0 && camera->position.z == 0 && "Failed to set position");

			splash_camera_set_size(camera, 800, 600);
			assert(camera->size.x == 800 && camera->size.y == 600 && "Failed to set size");

			splash_camera_set_rotation(camera, 0, 0, 0);
			assert(camera->rotation.x == 0 && camera->rotation.y == 0 && camera->rotation.z == 0 && "Failed to set rotation");
}

static void test_camrea_translation() {
			splash_camera_translate(camera, 0, 0, 0);
			assert(camera->position.x == 0 && camera->position.y == 0 && camera->position.z == 0 && "Failed to set position");

			splash_camera_rotate(camera, 0, 0, 0);
			assert(camera->rotation.x == 0 && camera->rotation.y == 0 && camera->rotation.z == 0 && "Failed to set rotation");
}

int main(int argc, char *argv[]) {

			test_camrea_creation();
			test_camrea_set();
			test_camrea_translation();

			splash_init();
				if(luaL_dofile(splash_lua_state, "../scripts/test/camera_test.lua")){
					printf("Could not load file: %s\n", lua_tostring(splash_lua_state, -1));
				}
			splash_quit();

		splash_camera_destroy(camera);
	return 0;
}

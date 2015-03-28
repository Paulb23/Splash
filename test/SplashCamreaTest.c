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



int main(int argc, char *argv[]) {
		camera = splash_camera_ortho_create();
		assert(camera != NULL && "Failed to create camera");

			splash_camera_set_position(camera, 0, 0, 0);
			splash_camera_set_size(camera, 800, 600);
			splash_camera_set_rotation(camera, 0, 0, 0);

			splash_camera_translate(camera, 0, 0, 0);
			splash_camera_rotate(camera, 0, 0, 0);

		splash_camera_destroy(camera);
	return 0;
}

/*-------------------------------------------------------------------------*/
/**
   @file    SplashTextureTest.c
   @author  P. Batty
   @brief   Unit test
	
*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash.h"                      
#include <assert.h>


Splash_texture *texture;

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void test_texture_creation() {
	texture = splash_texture_create("../res/test/test_image.png");
}


static void test_texture_destory() {
	splash_texture_destroy(texture);
}


int main(int argc, char *argv[]) {
	splash_init();
	
		test_texture_creation();
		test_texture_destory();

	splash_quit();
	return 0;
}

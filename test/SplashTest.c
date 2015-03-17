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
#include <assert.h>


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

void init_test() {
	assert(splash_init() == 0 && "splash failed to initialise");
}

void shutdown_test() {
	assert(splash_quit() == 0 && "splash failed to exit");
}


int main(int argc, char *argv[]) {

	init_test();
	shutdown_test();

	return 0;
}

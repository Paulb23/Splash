/*-------------------------------------------------------------------------*/
/**
   @file    Splash_vector.h
   @author  P. Batty
   @brief   Vector objects

   This module implements the vector objects

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_vector.h"
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector2
  @return 	returns a Splash_vector2

  Creates and returns a Splash_vector3

\-----------------------------------------------------------------------------*/
Splash_vector2 splash_vector2_create(double x, double y) {
	return ( Splash_vector2 ) { x, y };
}


/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector3
  @return   returns a Splash_vector3

  Creates and returns a Splash_vector3

\-----------------------------------------------------------------------------*/
Splash_vector3 splash_vector3_create(double x, double y, double z) {
  return ( Splash_vector3 ) { x, y, z };
}


/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector4
  @return   returns a Splash_vector4

  Creates and returns a Splash_vector4

\-----------------------------------------------------------------------------*/
Splash_vector4 splash_vector4_create(double x, double y, double z, double w) {
  return ( Splash_vector4 ) { x, y, z, w };
}
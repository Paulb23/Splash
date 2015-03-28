/*-------------------------------------------------------------------------*/
/**
   @file    Splash_vector.h
   @author  P. Batty
   @brief   Vector objects

   This module implements the vector objects

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_VECTOR_H_
#define SPLASH_VECTOR_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include <stdint.h>

#include "splash_begin_code.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Splash_vector3

  The Splash vector3 structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_vector3 {
  double x; /**< The x in the vector */
  double y; /**< The y in the vector */
  double z; /**< The z in the vector */
} Splash_vector3;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector3
  @return 	returns a Splash_vector3

  Creates and returns a Splash_vector3

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector3 SPLASHCALL splash_vector3_create(double x, double y, double z);



/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

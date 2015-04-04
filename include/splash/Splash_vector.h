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
  @brief    Splash_vector2

  The Splash vector2 structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_vector2 {
  double x; /**< The x in the vector */
  double y; /**< The y in the vector */
} Splash_vector2;


/*!--------------------------------------------------------------------------
  @brief    Splash_vector3

  The Splash vector3 structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_vector3 {
  double x; /**< The x in the vector */
  double y; /**< The y in the vector */
  double z; /**< The z in the vector */
} Splash_vector3;


/*!--------------------------------------------------------------------------
  @brief    Splash_vector4

  The Splash vector4 structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_vector4 {
  double x; /**< The x in the vector */
  double y; /**< The y in the vector */
  double z; /**< The z in the vector */
  double w; /**< The w in the vector */
} Splash_vector4;

/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector2
  @return 	returns a Splash_vector2

  Creates and returns a Splash_vector2

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector2 SPLASHCALL splash_vector2_create(double x, double y);


/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector3
  @return   returns a Splash_vector3

  Creates and returns a Splash_vector3

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector3 SPLASHCALL splash_vector3_create(double x, double y, double z);


/*!--------------------------------------------------------------------------
  @brief    Creates a Splash_vector4
  @return   returns a Splash_vector4

  Creates and returns a Splash_vector4

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector4 SPLASHCALL splash_vector4_create(double x, double y, double z, double w);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

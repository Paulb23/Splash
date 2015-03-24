/*-------------------------------------------------------------------------*/
/**
   @file    Splash_State.h
   @author  P. Batty
   @brief   The Game state

   This module implements the creation and manipulations of the 
   game state structs in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_STATE_H_
#define SPLASH_STATE_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "SDL2/SDL.h"

#include "splash_begin_code.h"
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Splash_state

  The Splash state structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_state {
  const char *name;                     /**< The state name */
  void (* init)(char *, void *);        /**< The states initlization function */
  void (* update)(double);              /**< The states update function */
  void (* event)(char *, SDL_Event);    /**< The states event haneler */
  void (* render)(char *);              /**< The states render function */
  void (* cleanup)(char *);             /**< The states cleanup function */
} Splash_state;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Inits Splash state
  @return   0 on success else -1

  Inits the splash state

\-----------------------------------------------------------------------------*/
extern int splash_state_init();


/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash state
  @param  name    The state name
  @param  init    function that takes a char * and a void *
  @param  update  function that takes a char * and double
  @param  event   function that takes a char * and Sdl_event
  @param  render  function that takes a char *
  @param  cleanup function that takes a char *
  @return   New Splash_state otherwise NULL.

  Creates a new Splash_window object destroy with splash_state_destroy();
  return a new object else null if unsuccessful

  init
    @param char *    The state that we are switiching to
    @param void *    Any data you want to pass in

  update
    @param double    The delta time

  event
    @param char *    The window name
    @param Sdl_event The event

  render
    @param  char *   The window name

  cleanup
    @param  char *   The state that we are switiching to

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_state SPLASHCALL *splash_state_create(const char *name, void (* init)(char *, void *), void (* update)(double), void (* event)(char *, SDL_Event), void (* render)(char *), void (* cleanup)(char *) );


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

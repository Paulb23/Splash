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
  @brief    Splash_state

  The Splash state structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_state {
  const char *name;                     /**< The state name */
  void (* init)(char *, void *);        /**< The states initlization function */
  void (* update)(float);               /**< The states update function */
  void (* event)(SDL_Event);            /**< The states event haneler */
  void (* render)();                    /**< The states render function */
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
extern int8_t splash_state_init();


/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash state
  @param  name    The state name
  @param  init    function that takes a char * and a void *
  @param  update  function that takes a float
  @param  event   function that takes a and Sdl_event
  @param  render  function that takes a no args
  @param  cleanup function that takes a char *
  @return   New Splash_state otherwise NULL.

  Creates a new Splash_window object destroy with splash_state_destroy();
  return a new object else null if unsuccessful

  init
    @param char *    The state that we are switiching to
    @param void *    Any data you want to pass in

  update
    @param float    The delta time

  event
    @param Sdl_event The event

  render

  cleanup
    @param  char *   The state that we are switiching to

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_state SPLASHCALL *splash_state_create(const char *name, void (* init)(char *, void *), void (* update)(float), void (* event)(SDL_Event), void (* render)(), void (* cleanup)(char *) );


/*!--------------------------------------------------------------------------
  @brief    Starts the splash state
  @param    state_name  The state name to start with
  @param    data        Any data to pass in to the init
  @return   Void

  Starts the splash state machine

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_start(char *state_name, void *data);


/*!--------------------------------------------------------------------------
  @brief    Switchs the current state
  @param    state_name  The state name to switch to
  @param    data        Any data to pass in to the init
  @return   Void

  Switches the state machine

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_switch(char *state_name, void *data);


/*!--------------------------------------------------------------------------
  @brief    Stops the splash state
  @return   Void

  Stops the splash state machine

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_stop();


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

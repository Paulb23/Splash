/*-------------------------------------------------------------------------*/
/**
   @file    Splash_State.c
   @author  P. Batty
   @brief   The Game state

   This module implements the creation and manipulations of the 
   game state structs in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_state.h"
#include <stdlib.h>

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash state
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
    @param char *    The window name
    @param double    The delta time

  event
    @param char *    The window name
    @param Sdl_event The event

  render
    @param  char *   The window name

  cleanup
    @param  char *   The state that we are switiching to

\-----------------------------------------------------------------------------*/
Splash_state *splash_state_create(const char *name, void (* init)(char *, void *), void (* update)(char *, double delta), void (* event)(char *, SDL_Event e), void (* render)(char *), void (* cleanup)(char *)) {
    Splash_state *state = malloc(sizeof(Splash_state));

    if (!state) {
      return NULL;
    }

    state->name = name;
    state->init = init;
    state->update = update;
    state->event = event;
    state->render = render;
    state->cleanup = cleanup;

    return state;
}

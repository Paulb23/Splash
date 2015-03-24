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
#include "Splash/Splash_list.h"
#include "Splash/Splash_hashmap.h"
#include <stdlib.h>

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

static Splash_list *windows;
static Splash_hashmap *window_id;
static Splash_hashmap *states;
static char *current_state;

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Inits Splash state
  @return   0 on success else -1

  Inits the splash state

\-----------------------------------------------------------------------------*/
int splash_state_init() {
  windows = splash_list_create();
  if (windows == NULL) {
    return -1;
  }

  window_id = splash_hashmap_create();
  if (window_id == NULL) {
    return -1;
  }

  states = splash_hashmap_create();
  if (states == NULL) {
    return -1;
  }

  current_state = NULL;

 return 0;
}


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
Splash_state *splash_state_create(const char *name, void (* init)(char *, void *), void (* update)(double), void (* event)(char *, SDL_Event), void (* render)(char *), void (* cleanup)(char *)) {
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

    splash_hashmap_add(states, name, state);

    return state;
}

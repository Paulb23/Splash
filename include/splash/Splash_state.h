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
  char *name;                           /**< The state name */
  void (* init)(char *, void *);        /**< The states initlization function */
  void (* update)(float);               /**< The states update function */
  void (* event)(SDL_Event);            /**< The states event haneler */
  void (* render)();                    /**< The states render function */
  void (* cleanup)(char *);             /**< The states cleanup function */
  int lua;                              /**< is it a lua callback? */
  int l_init;                           /**< lua init refrance */
  int l_update;                         /**< lua update refrance */
  int l_event;                          /**< lua event refrance */
  int l_render;                         /**< lua render refrance */
  int l_cleanup;                        /**< lua cleanup refrance */
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
  @brief    Quits Splash state
  @return   Void

  Quits the splash state

\-----------------------------------------------------------------------------*/
extern void splash_state_quit();


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
extern DLL_EXPORT Splash_state SPLASHCALL *splash_state_create(char *name, void (* init)(char *, void *), void (* update)(float), void (* event)(SDL_Event), void (* render)(), void (* cleanup)(char *) );


/*!--------------------------------------------------------------------------
  @brief    Adds a state to the machine
  @param    state       The state to add
  @return   Void

  Adds a state to the machine

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_add(Splash_state *state);


/*!--------------------------------------------------------------------------
  @brief    Remove a state from the machine
  @param    state_name  The state name
  @return   Void

  Removes a state from the machine

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_remove(char *state_name);


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


/*!--------------------------------------------------------------------------
  @brief    Set the ticks
  @return   Void

  Sets current ticks

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_state_set_ticks(int32_t ticks);


/*!--------------------------------------------------------------------------
  @brief    Gets a state
  @return   Splash_state object else NULL

  Gets the splash state else returns NULL

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_state SPLASHCALL *splash_state_get_state(char *state_name);


/*!--------------------------------------------------------------------------
  @brief    Gets the state macine uptime
  @return   Current state machine uptime

  Current state machine uptime

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_state_get_uptime();


/*!--------------------------------------------------------------------------
  @brief    Gets the state uptime
  @return   Current state uptime

  Current state uptime

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_state_get_state_uptime();


/*!--------------------------------------------------------------------------
  @brief    Gets the fps
  @return   Current current fps

  Current current fps

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_state_get_fps();


/*!--------------------------------------------------------------------------
  @brief    Gets the ticks
  @return   Current current ticks

  Current current ticks

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_state_get_ticks();


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

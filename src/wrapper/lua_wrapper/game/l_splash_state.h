/*-------------------------------------------------------------------------*/
/**
   @file    l_splash_state.h
   @author  P. Batty
   @brief   The lua state

   This module implements the creation and manipulations of the 
   lua game state structs in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef L_SPLASH_STATE_H_
#define L_SPLASH_STATE_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash_state.h"
                                
/* Set up for C definitions */
#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
                                New types
 ---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    registers the state functions to lua
  @param    the state to register to
  @return   Void

  Registers the state functions to lua

\-----------------------------------------------------------------------------*/
extern void l_splash_state_register(lua_State *l);


/*!--------------------------------------------------------------------------
  @brief    Calls the init
  @param    state     the state to call
  @param    new_state The state that we are switiching to
  @param    data      Any data to pass in
  @return   Void

  Calls the init function ties to the state

\-----------------------------------------------------------------------------*/
extern void l_splash_state_call_init(Splash_state *state, char *new_state, void *data);


/*!--------------------------------------------------------------------------
  @brief    Calls the update
  @param    state     the state to call
  @param    delta     delta time
  @return   Void

  Calls the update function ties to the state

\-----------------------------------------------------------------------------*/
extern void l_splash_state_call_update(Splash_state *state, float delta);


/*!--------------------------------------------------------------------------
  @brief    Calls the event
  @param    state     the state to call
  @param    event     the event
  @return   Void

  Calls the event function tied to the state

\-----------------------------------------------------------------------------*/
extern void l_splash_state_call_event(Splash_state *state, SDL_Event event);


/*!--------------------------------------------------------------------------
  @brief    Calls the render
  @param    state     the state to call
  @return   Void

  Calls the render function tied to the state

\-----------------------------------------------------------------------------*/
extern void l_splash_state_call_render(Splash_state *state);


/*!--------------------------------------------------------------------------
  @brief    Calls the cleanup
  @param    state     the state to call
  @param    new_state The state that we are switiching to
  @return   Void

  Calls the cleanup function tied to the state

\-----------------------------------------------------------------------------*/
extern void l_splash_state_call_cleanup(Splash_state *state, char *new_state);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

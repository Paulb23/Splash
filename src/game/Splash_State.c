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
#include "Splash/Splash_hashmap.h"
#include "lua/lua.h"
#include "../wrapper/lua_wrapper/game/l_splash_state.h"
#include <stdlib.h>
#include <stdint.h>

/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

static Splash_hashmap *states;        /**< hashmap if states */
static Splash_state *current_state;   /**< the current state */

static int8_t state_running;          /**< is the state machine running */
static int32_t max_ticks;             /**< number of ticks per second */
static double ns;                     /**< nanoseconds */

static int32_t uptime;                /**< how long has it been running*/
static int32_t state_uptime;          /**< how long have we been in this state */
static int32_t frames;                /**< our fps */


/*!--------------------------------------------------------------------------
  @brief    The state machine
  @return   Void

  The state machine 

\-----------------------------------------------------------------------------*/
static void splash_state_run() {
   SDL_Event event;

    long lastTime = SDL_GetTicks();
    ns = 1000.0 / max_ticks;
    Uint32 timer = SDL_GetTicks();
    float delta = 0;
    double fps = 0;
    double tick = 0;
    uptime = 0;
    state_uptime = 0;

    state_running = 1;
    while (state_running) {
        Uint32 now = SDL_GetTicks();
        delta += (now - lastTime) / ns;
        lastTime = now;

        while (delta >= 1) {

            if (current_state->lua) {
                l_splash_state_call_update(current_state, delta);
            } else {
              current_state->update(delta);
            }

            while(SDL_PollEvent(&event)) {
              if (current_state->lua) {
                  l_splash_state_call_event(current_state, event);
              } else {
                  current_state->event(event);
              }
            }

          tick++;
          delta--;
        }
        fps++;

        if (current_state->lua) {
            l_splash_state_call_render(current_state);
        } else {
           current_state->render();
        }

        if (SDL_GetTicks() - timer > 1000) {
          timer += 1000;
          uptime++;
          state_uptime++;
          frames = fps;
          fps = 0;
          tick = 0;
        }
    }
}


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/


/*!--------------------------------------------------------------------------
  @brief    Inits Splash state
  @return   0 on success else -1

  Inits the splash state

\-----------------------------------------------------------------------------*/
int8_t splash_state_init() {
  states = splash_hashmap_create();
  if (states == NULL) {
    return -1;
  }

  state_running = 0;
  max_ticks = 60;

  uptime = 0;
  state_uptime = 0;
  frames = 0;
  ns = 0;

 return 0;
}


/*!--------------------------------------------------------------------------
  @brief    Quits Splash state
  @return   Void

  Quits the splash state

\-----------------------------------------------------------------------------*/
void splash_state_quit() {
  splash_hashmap_destory(states);
  state_running = 0;
  max_ticks = 60;

  uptime = 0;
  state_uptime = 0;
  frames = 0;
  ns = 0;
}


/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash state
  @param  name    The state name
  @param  init    function that takes a char * and a void *
  @param  update  function that takes a float
  @param  event   function that takes a Sdl_event
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
Splash_state *splash_state_create(char *name, void (* init)(char *, void *), void (* update)(float), void (* event)(SDL_Event), void (* render)(), void (* cleanup)(char *)) {
    Splash_state *state = malloc(sizeof(Splash_state));

    if (!state) {
      return NULL;
    }

    state->name = name;
    state->lua = 0;
    state->init = init;
    state->update = update;
    state->event = event;
    state->render = render;
    state->cleanup = cleanup;

  return state;
}


/*!--------------------------------------------------------------------------
  @brief    Adds a state to the machine
  @param    state       The state to add
  @return   Void

  Adds a state to the machine

\-----------------------------------------------------------------------------*/
void splash_state_add(Splash_state *state) {
    splash_hashmap_add(states, state->name, state);
}


/*!--------------------------------------------------------------------------
  @brief    Remove a state from the machine
  @param    state_name  The state name
  @return   Void

  Removes a state from the machine

\-----------------------------------------------------------------------------*/
void splash_state_remove(char *state_name) {
  splash_hashmap_remove(states, state_name);
}


/*!--------------------------------------------------------------------------
  @brief    Starts the splash state
  @param    state_name  The state name to start with
  @param    data        Any data to pass in to the init
  @return   Void

  Starts the splash state machine

\-----------------------------------------------------------------------------*/
void splash_state_start(char *state_name, void *data) {

    current_state = splash_hashmap_get(states, state_name);

    if (current_state == (void *)-1) {
      return;
    }

    if (current_state->lua) {
        l_splash_state_call_init(current_state, state_name, data);
    } else {
        current_state->init(state_name, data);
    }
    splash_state_run();
}


/*!--------------------------------------------------------------------------
  @brief    Switchs the current state
  @param    state_name  The state name to switch to
  @param    data        Any data to pass in to the init
  @return   Void

  Switches the state machine

\-----------------------------------------------------------------------------*/
void splash_state_switch(char *state_name, void *data) {
    Splash_state *next = splash_hashmap_get(states, state_name);

    if (next == (void *)-1) {
      return;
    }

    if (next->lua) {
        l_splash_state_call_init(next, state_name, data);
    } else {
        next->init(state_name, data);
    }

    if (current_state->lua) {
        l_splash_state_call_cleanup(current_state, state_name);
    } else {
        current_state->cleanup(state_name);
    }

    current_state = next;
    state_uptime = 0;
}


/*!--------------------------------------------------------------------------
  @brief    Stops the splash state
  @return   Void

  Stops the splash state machine

\-----------------------------------------------------------------------------*/
void splash_state_stop() {
  if (current_state->lua) {
    l_splash_state_call_cleanup(current_state, "");
  } else {
    current_state->cleanup("");
  }
  state_running = 0;
}


/*!--------------------------------------------------------------------------
  @brief    Set the ticks
  @return   Void

  Sets current ticks

\-----------------------------------------------------------------------------*/
void splash_state_set_ticks(int32_t ticks) {
  max_ticks = ticks;
  ns = 1000.0 / max_ticks;
}


/*!--------------------------------------------------------------------------
  @brief    Gets a state
  @return   Splash_state object else NULL

  Gets the splash state else returns NULL

\-----------------------------------------------------------------------------*/
Splash_state *splash_state_get_state(char *state_name) {
  return splash_hashmap_get(states, state_name);
}


/*!--------------------------------------------------------------------------
  @brief    Gets the state macine uptime
  @return   Current state machine uptime

  Current state machine uptime

\-----------------------------------------------------------------------------*/
int32_t splash_state_get_uptime() {
  return uptime;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the state uptime
  @return   Current state uptime

  Current state uptime

\-----------------------------------------------------------------------------*/
int32_t splash_state_get_state_uptime() {
  return state_uptime;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the fps
  @return   Current current fps

  Current current fps

\-----------------------------------------------------------------------------*/
int32_t splash_state_get_fps() {
  return frames;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the ticks
  @return   Current current ticks

  Current current ticks

\-----------------------------------------------------------------------------*/
int32_t splash_state_get_ticks() {
  return max_ticks;
}
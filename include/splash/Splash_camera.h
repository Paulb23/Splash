/*-------------------------------------------------------------------------*/
/**
   @file    Splash_camera.h
   @author  P. Batty
   @brief   The camera structs

   This module implements the creation and manipulations of the 
   camera structure in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_CAMERA_H_
#define SPLASH_CAMERA_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "SDL2/SDL.h"
#include "Splash_vector.h"
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
  @brief    Splash_camera

  The window Splash camera structure.
\----------------------------------------------------------------------------*/
typedef struct Splash_camera {
  int8_t ortho;                  /**< Is the camera othographic */
  float zoom;                    /**< The current camera zoom */
  Splash_vector3 position;       /**< The position of the camera */
  Splash_vector3 rotation;       /**< The rotation of the camera */
  Splash_vector3 size;           /**< The size of the camera */
} Splash_camera;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_camera
  @return   New Splash_camera otherwise NULL.

  Creates a new Splash_camera object destroy with splash_camera_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_camera SPLASHCALL *splash_camera_ortho_create();


/*!--------------------------------------------------------------------------
  @brief    Sets the position of the camera
  @param    camera The camera to change
  @param    x      The x position to move to
  @param    y      The y position to move to
  @param    z      The z position to move to
  @return    Void

  Sets the position of the camera

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_set_position(Splash_camera *camera, double x, double y, double z);


/*!--------------------------------------------------------------------------
  @brief    Sets the size of the camera
  @param    camera   The camera to change
  @param    width    The new width
  @param    height   The new height
  @return    Void

  Sets the size of the camera

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_set_size(Splash_camera *camera, double width, double height);


/*!--------------------------------------------------------------------------
  @brief    Sets the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The new zoom
  @return    Void

  Sets the zoom of the camera

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_set_zoom(Splash_camera *camera, double zoom);


/*!--------------------------------------------------------------------------
  @brief    Sets the roation of the camera
  @param    camera   The camera to change
  @param    yaw     The new yaw of the camera
  @param    pitch   The new pitch of the camera
  @param    roll    The new roll of the camera
  @return    Void

  Sets the rotation of the camera

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_set_rotation(Splash_camera *camera, double yaw, double pitch, double roll);


/*!--------------------------------------------------------------------------
  @brief    Moves the camera
  @param    camera   The camera to change
  @param    x        The x amount to move by
  @param    y        The y amount to move by
  @param    z        The z amount to move by
  @return    Void

  Move the camera by the amount passed in

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_translate(Splash_camera *camera, double x, double y, double z);


/*!--------------------------------------------------------------------------
  @brief    Changes the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The zoom amount to change by
  @return    Void

  Changes the zoom amout by the amount passed in

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_zoom(Splash_camera *camera, double zoom);


/*!--------------------------------------------------------------------------
  @brief    Rotates the camera
  @param    camera   The camera to change
  @param    yaw     The yaw amount to move by
  @param    pitch   The pitch amount to move by
  @param    roll    The roll amount to move by
  @return    Void

  Rotates the camera by the amount passed in

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_rotate(Splash_camera *camera, double yaw, double pitch, double roll);


/*!--------------------------------------------------------------------------
  @brief    Gets the camera positition
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras position

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector3 SPLASHCALL splash_camera_get_position(Splash_camera *camera);


/*!--------------------------------------------------------------------------
  @brief    Gets the camera size
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras size

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector3 SPLASHCALL splash_camera_get_size(Splash_camera *camera);


/*!--------------------------------------------------------------------------
  @brief    Gets the camera rotation
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras rotation

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_vector3 SPLASHCALL splash_camera_get_rotation(Splash_camera *camera);


/*!--------------------------------------------------------------------------
  @brief    Gets the camera zoom
  @param    camera  The camera to get 
  @return    Double with the camera  zoom

  Gets the cameras zoom

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT double SPLASHCALL splash_camera_get_zoom(Splash_camera *camera);


/*!--------------------------------------------------------------------------
  @brief    Destorys a camera
  @param    camera  The camera to destory
  @return    Void

  Destroy's a camera

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_camera_destroy(Splash_camera *camera);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

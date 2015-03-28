/*-------------------------------------------------------------------------*/
/**
   @file    Splash_camera.c
   @author  P. Batty
   @brief   The camera structs

   This module implements the creation and manipulations of the 
   camera structure in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_camera.h"
#include "Splash/Splash_vector.h"
#include <stdint.h>
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_camera
  @return   New Splash_camera otherwise NULL.

  Creates a new Splash_camera object destroy with splash_camera_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
Splash_camera *splash_camera_ortho_create() {
    Splash_camera *camera = malloc(sizeof(Splash_camera));

    if (!camera) {
      return NULL;
    }

    camera->ortho = 1;
    camera->zoom = 0;
    camera->position = splash_vector3_create(0, 0, 0);
    camera->rotation = splash_vector3_create(0, 0, 0);
    camera->size = splash_vector3_create(1, 1, 1);

  return camera;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the position of the camera
  @param    camera The camera to change
  @param    x      The x position to move to
  @param    y      The y position to move to
  @param    z      The z position to move to
  @return    Void

  Sets the position of the camera

\-----------------------------------------------------------------------------*/
void splash_camera_set_position(Splash_camera *camera, double x, double y, double z) {
    camera->position.x = x;
    camera->position.y = y;
    camera->position.z = z;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the size of the camera
  @param    camera   The camera to change
  @param    width    The new width
  @param    height   The new height
  @return    Void

  Sets the size of the camera

\-----------------------------------------------------------------------------*/
void splash_camera_set_size(Splash_camera *camera, double width, double height) {
  camera->size.x = width;
  camera->size.y = height;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The new zoom
  @return    Void

  Sets the zoom of the camera

\-----------------------------------------------------------------------------*/
void splash_camera_set_zoom(Splash_camera *camera, double zoom) {
  camera->zoom = zoom;
}


/*!--------------------------------------------------------------------------
  @brief    Sets the roation of the camera
  @param    camera   The camera to change
  @param    yaw     The new yaw of the camera
  @param    pitch   The new pitch of the camera
  @param    roll    The new roll of the camera
  @return    Void

  Sets the rotation of the camera

\-----------------------------------------------------------------------------*/
void splash_camera_set_rotation(Splash_camera *camera, double yaw, double pitch, double roll) {
    camera->rotation.x = yaw;
    camera->rotation.y = pitch;
    camera->rotation.z = roll;
}


/*!--------------------------------------------------------------------------
  @brief    Moves the camera
  @param    camera   The camera to change
  @param    x        The x amount to move by
  @param    y        The y amount to move by
  @param    z        The z amount to move by
  @return    Void

  Move the camera by the amount passed in

\-----------------------------------------------------------------------------*/
void splash_camera_translate(Splash_camera *camera, double x, double y, double z) {
    camera->position.x += x;
    camera->position.y += y;
    camera->position.z += z;
}


/*!--------------------------------------------------------------------------
  @brief    Changes the zoom of the camera
  @param    camera   The camera to change
  @param    zoom     The zoom amount to change by
  @return    Void

  Changes the zoom amout by the amount passed in

\-----------------------------------------------------------------------------*/
void splash_camera_zoom(Splash_camera *camera, double zoom) {
  camera->zoom += zoom;
}


/*!--------------------------------------------------------------------------
  @brief    Rotates the camera
  @param    camera   The camera to change
  @param    yaw     The yaw amount to move by
  @param    pitch   The pitch amount to move by
  @param    roll    The roll amount to move by
  @return    Void

  Rotates the camera by the amount passed in

\-----------------------------------------------------------------------------*/
void splash_camera_rotate(Splash_camera *camera, double yaw, double pitch, double roll) {
    camera->rotation.x += yaw;
    camera->rotation.y += pitch;
    camera->rotation.z += roll;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera positition
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras position

\-----------------------------------------------------------------------------*/
Splash_vector3 splash_camera_get_position(Splash_camera *camera) {
  return camera->position;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera size
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras size

\-----------------------------------------------------------------------------*/
Splash_vector3 splash_camera_get_size(Splash_camera *camera) {
  return camera->size;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera rotation
  @param    camera  The camera to get 
  @return    Splash_vector3

  Gets the cameras rotation

\-----------------------------------------------------------------------------*/
Splash_vector3 splash_camera_get_rotation(Splash_camera *camera) {
  return camera->rotation;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the camera zoom
  @param    camera  The camera to get 
  @return    Double with the camera  zoom

  Gets the cameras zoom

\-----------------------------------------------------------------------------*/
double splash_camera_get_zoom(Splash_camera *camera) {
  return camera->zoom;
}


/*!--------------------------------------------------------------------------
  @brief    Destorys a camera
  @param    camera  The camera to destory
  @return    Void

  Destroy's a camera

\-----------------------------------------------------------------------------*/
void splash_camera_destroy(Splash_camera *camera) {
  free(camera);
}
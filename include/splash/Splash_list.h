/*-------------------------------------------------------------------------*/
/**
   @file    Splash_list.h
   @author  P. Batty
   @brief   The list structs

   This module implements the creation and manipulations of the 
   list structs in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_LIST_H_
#define SPLASH_LIST_H_

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
  @brief    _splash_list_node_

  The node in the list
\----------------------------------------------------------------------------*/
struct _splash_list_node_ {
  void *data;        /**< The data in this element */
  struct _splash_list_node_ *next; /**< pointer to the next element */
} _splash_list_node_;


/*!--------------------------------------------------------------------------
  @brief    Splash_list

  The Splash_list struct, forming a standered linked list pattern.
\----------------------------------------------------------------------------*/
typedef struct Splash_list {
  int32_t size; /**< The size of the list */
  struct _splash_list_node_ *next; /**< pointer to the first element */
} Splash_list;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_list
  @return   New Splash_List otherwise NULL.

  Creates a new Splash_list object destroy with splash_list_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_list SPLASHCALL *splash_list_create();


/*!--------------------------------------------------------------------------
  @brief    Adds a item to the list
  @param  list      The list to add to
  @param  data       The data to add
  @return  Void

  Adds a item to the end of the list

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_list_add(Splash_list *list, void *data);


/*!--------------------------------------------------------------------------
  @brief    Checks if an item is in the list
  @param  list      The list to check
  @param  data       The data to search for
  @return  1 if it contains the item else 0

  Performs a liniar search on the list to search for the data.
  return 1 if it finds it else 0

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int8_t SPLASHCALL splash_list_contains(Splash_list *list, void *data);


/*!--------------------------------------------------------------------------
  @brief    Gets the position of the data in the list
  @param  list      The list to check
  @param  data       The data to search for
  @return  Position of the data, -1 if not found

  Performs a liniar search on the list to search for the data.
  returns the position in the list when it finds it else -1

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_list_get_position(Splash_list *list, void *data);


/*!--------------------------------------------------------------------------
  @brief    Gets the element at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Data at the position in the list, -1 if not found

  Gets the data in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL *splash_list_get(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Gets the string at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  String at the position in the list, -1 if not found

  Gets the string in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT char SPLASHCALL *splash_list_get_string(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Gets the int at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Int at the position in the list, -1 if not found

  Gets the int in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int SPLASHCALL splash_list_get_int(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Gets the float at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Float at the position in the list, -1 if not found

  Gets the float in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT float SPLASHCALL splash_list_get_float(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Gets the double at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Double at the position in the list, -1 if not found

  Gets the double in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT double SPLASHCALL splash_list_get_double(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Removes the data from the list
  @param  list      The list to search
  @param  pos       The position to remove
  @return  Void

  Removes the data at the position, and shuffles the list up by one.
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_list_remove_position(Splash_list *list, int32_t pos);


/*!--------------------------------------------------------------------------
  @brief    Removes the data from the list
  @param  list      The list to search
  @param  data      The data to remove
  @return  Void

  Removes the data at the position, and shuffles the list up by one.
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_list_remove(Splash_list *list, void *data);


/*!--------------------------------------------------------------------------
  @brief    Removes everything in the list
  @param  list      The list to empty
  @return  Void

  Empties the list.
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_list_remove_all(Splash_list *list);


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the list
  @param  list      The list to count
  @return  Size of the list

  Gets the size of the list
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_list_get_size(Splash_list *list);


/*!--------------------------------------------------------------------------
  @brief    Destroy's the list
  @param  list      The list to destroy
  @return  Void

  Destroy's the list

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_list_destroy(Splash_list *list);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif
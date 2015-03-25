/*-------------------------------------------------------------------------*/
/**
   @file    Splash_hashmap.h
   @author  P. Batty
   @brief   The hashmap structs

   This module implements the creation and manipulations of the 
   hashmap structs in the framework.

*/
/*--------------------------------------------------------------------------*/

#ifndef SPLASH_HASHMAP_H_
#define SPLASH_HASHMAP_H_

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "../src/ect/dictionary.h"
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
  @brief    Splash_hashmap

  Basic hashmap implementation using a dictionary

\----------------------------------------------------------------------------*/
typedef struct Splash_hashmap {
  dictionary *map;
  int32_t size;
} Splash_hashmap;


/*---------------------------------------------------------------------------
                            Function prototypes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new hashmap object
  @return   New hashmap object else NULL

  Creates a new Splash_hashmap object destroy with splash_hashmap_destroy();
  On success will return a new Splash_object else NULL.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT Splash_hashmap SPLASHCALL *splash_hashmap_create();


/*!--------------------------------------------------------------------------
  @brief    Adds a element to the Splash_hashmap
  @param    hashmap     The hashmap to add the data to
  @param    key         The key to add the data to
  @param    value       The value to tie to the key
  @return    void

  Adds the data passed in to the key inside the hashmap

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_hashmap_add(Splash_hashmap *hashmap, const void *key, const void *value);


/*!--------------------------------------------------------------------------
  @brief    Gets a element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location. NOTE: DOES NOTE CAST TO A TYPE.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL *splash_hashmap_get(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Gets a string element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a string.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT char SPLASHCALL *splash_hashmap_get_string(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Gets a int element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a int.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int SPLASHCALL splash_hashmap_get_int(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Gets a float element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a float.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT float SPLASHCALL splash_hashmap_get_float(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Gets a double element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a double.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT double SPLASHCALL splash_hashmap_get_double(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Removes a element in the hashmap
  @param    hashmap     The hashmap to remove the data from
  @param    key     The key to search for
  @return    void

  remove the value in the SSL_Hashmap.

\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_hashmap_remove(Splash_hashmap *hashmap, const void *key);


/*!--------------------------------------------------------------------------
  @brief    Removes everything in the hashmap
  @param  hashmap      The hashmap to empty
  @return  Void

  Empties the hashmap.
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_hashmap_remove_all(Splash_hashmap *hashmap);


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  list      The list to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT int32_t SPLASHCALL splash_hashmap_get_size(Splash_hashmap *hashmap);


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  hashmap      The hashmap to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
extern DLL_EXPORT void SPLASHCALL splash_hashmap_destory(Splash_hashmap *hashmap);


/* end C definitions */
#ifdef __cplusplus
}
#endif
#endif

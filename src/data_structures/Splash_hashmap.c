/*-------------------------------------------------------------------------*/
/**
   @file    Splash_hashmap.c
   @author  P. Batty
   @brief   The hashmap structs

   This module implements the creation and manipulations of the 
   hashmap structs in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_hashmap.h"
#include <stdint.h>
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new hashmap object
  @return   New hashmap object else NULL

  Creates a new Splash_hashmap object destroy with splash_hashmap_destroy();
  On success will return a new Splash_object else NULL.

\-----------------------------------------------------------------------------*/
Splash_hashmap *splash_hashmap_create() {
	Splash_hashmap *hashmap = malloc(sizeof(Splash_hashmap));

	if (!hashmap) {
		return NULL;
	}

	hashmap->map = dictionary_new(0);

	if (!hashmap->map) {
		free(hashmap);
		return NULL;
	}

	hashmap->size = 0;

 return hashmap;
}


/*!--------------------------------------------------------------------------
  @brief    Adds a element to the Splash_hashmap
  @param    hashmap     The hashmap to add the data to
  @param    key         The key to add the data to
  @param    value       The value to tie to the key
  @return    void

  Adds the data passed in to the key inside the hashmap

\-----------------------------------------------------------------------------*/
void splash_hashmap_add(Splash_hashmap *hashmap, const void *key, const void *value) {
  if (dictionary_get(hashmap->map, key, (void *)-1) == (void *)-1) {
    hashmap->size++;
  }
	dictionary_set(hashmap->map, key, value);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location. NOTE: DOES NOTE CAST TO A TYPE.

\-----------------------------------------------------------------------------*/
void *splash_hashmap_get(Splash_hashmap *hashmap, const void *key) {
	return dictionary_get(hashmap->map, key, (void *)-1);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a string element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a string.

\-----------------------------------------------------------------------------*/
char *splash_hashmap_get_string(Splash_hashmap *hashmap, const void *key) {
	return (char *) splash_hashmap_get(hashmap, key);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a int element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a int.

\-----------------------------------------------------------------------------*/
int splash_hashmap_get_int(Splash_hashmap *hashmap, const void *key) {
  void *value = splash_hashmap_get(hashmap, key);
  if (value == (void *)-1) {
    return -1;
  }
	return strtol(value, NULL, 10);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a float element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a float.

\-----------------------------------------------------------------------------*/
float splash_hashmap_get_float(Splash_hashmap *hashmap, const void *key) {
	void *value = splash_hashmap_get(hashmap, key);
  if (value == (void *)-1) {
    return -1;
  }
  return strtof(value, NULL);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a double element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a double.

\-----------------------------------------------------------------------------*/
double splash_hashmap_get_double(Splash_hashmap *hashmap, const void *key) {
	void *value = splash_hashmap_get(hashmap, key);
  if (value == (void *)-1) {
    return -1;
  }
 return strtod(value, NULL);
}


/*!--------------------------------------------------------------------------
  @brief    Removes a element in the hashmap
  @param    hashmap     The hashmap to remove the data from
  @param    key     The key to search for
  @return    void

  remove the value in the SSL_Hashmap.

\-----------------------------------------------------------------------------*/
void splash_hashmap_remove(Splash_hashmap *hashmap, const void *key) {
	dictionary_unset(hashmap->map, key);

	if (hashmap->size != 0) {
		hashmap->size--;
	}
}


/*!--------------------------------------------------------------------------
  @brief    Removes everything in the hashmap
  @param  hashmap      The hashmap to empty
  @return  Void

  Empties the hashmap.
  
\-----------------------------------------------------------------------------*/
void splash_hashmap_remove_all(Splash_hashmap *hashmap) {
	dictionary_del(hashmap->map);
  hashmap->map = dictionary_new(0);
  hashmap->size = 0;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  list      The list to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
int32_t splash_hashmap_get_size(Splash_hashmap *hashmap) {
  return hashmap->size;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  hashmap      The hashmap to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
void splash_hashmap_destory(Splash_hashmap *hashmap) {
	dictionary_del(hashmap->map);
}

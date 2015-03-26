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
#include <string.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new hashmap element
  @return   New hashmap element

  Creates a new hashmap element

\-----------------------------------------------------------------------------*/
static struct _Splash_hashmap_element_ *create_element(void *key, void *value) {
  struct _Splash_hashmap_element_ *element = malloc(sizeof(struct _Splash_hashmap_element_));
  element->key = key;
  element->value = value;
  return element;
}


/*!--------------------------------------------------------------------------
  @brief    Hashing function
  @return   Hash

  Hashes

\-----------------------------------------------------------------------------*/
static int hash(void * key, int size) {
    char *p = key;
    int len = strlen(p);
    int h = 0;
    int g;
    int i;

    for (i = 0; i < len; i++) {
        h = (h << 4) + p[i];
        g = h & 0xf0000000L;

        if (g != 0) {
            h ^= g >> 24;
        }

        h &= ~g;
    }

    return h % size;
}


/*!--------------------------------------------------------------------------
  @brief    Re-Hashing function
  @return   Void

  Re-Hashes

\-----------------------------------------------------------------------------*/
static void rehash(Splash_hashmap * hm) {
  struct _Splash_hashmap_element_ ** current;
  struct _Splash_hashmap_element_ ** buckets;

  struct _Splash_hashmap_element_ * item;
  struct _Splash_hashmap_element_ * next;
  size_t s;
  size_t size;
  int i;
  int index;

  current = hm->buckets;
  s = hm->size;
  size = s << 1;

  buckets = calloc(size, sizeof(struct _Splash_hashmap_element_));

  for (i = 0; i < s; i++) {
    for (item = current[i]; item != NULL; item = next) {
      index = hash(item->key, size);
      next = item->next;
      item->next = buckets[index];
      buckets[index] = item;
    }
  }

  free(hm->buckets);
  hm->buckets = buckets;
  hm->size = size;
}

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

	hashmap->buckets = calloc(256, sizeof(struct _Splash_hashmap_element_ *));

	if (!hashmap->buckets) {
		return NULL;
	}

  hashmap->size = 256;
	hashmap->count = 0;

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
void splash_hashmap_add(Splash_hashmap *hashmap, void *key, void *value) {
  struct _Splash_hashmap_element_ * item;
  struct _Splash_hashmap_element_ ** p;
  int index = hash(key, hashmap->size);

  p = &(hashmap->buckets[index]);

  for (item = *p; item != NULL; item = item->next) {
    if (item->key == key) {/* key already exists */
      item->value = value;
      return;
    }
  }

  item = *p;
  (*p) = create_element(key, value);
  (*p)->next = item;

  if (++hashmap->count >= hashmap->size * 3 / 4) {
    rehash(hashmap);
  }
}


/*!--------------------------------------------------------------------------
  @brief    Gets a element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location. NOTE: DOES NOTE CAST TO A TYPE.

\-----------------------------------------------------------------------------*/
void *splash_hashmap_get(Splash_hashmap *hashmap, void *key) {
	int index = hash(key, hashmap->size);
  struct _Splash_hashmap_element_ *item;

  for (item = hashmap->buckets[index]; item != NULL; item = item->next) {
    if (item->key == key) {
      return item->value;
    }
  }

  return (void *)-1;
}


/*!--------------------------------------------------------------------------
  @brief    Gets a string element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a string.

\-----------------------------------------------------------------------------*/
char *splash_hashmap_get_string(Splash_hashmap *hashmap, void *key) {
	return (char *) splash_hashmap_get(hashmap, key);
}


/*!--------------------------------------------------------------------------
  @brief    Gets a int element in the list
  @param    hashmap     The hashmap to get the data from
  @param    key         The key to search for
  @return    the value stored at that location else -1

  Returns the value at the given location as a int.

\-----------------------------------------------------------------------------*/
int splash_hashmap_get_int(Splash_hashmap *hashmap, void *key) {
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
float splash_hashmap_get_float(Splash_hashmap *hashmap, void *key) {
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
double splash_hashmap_get_double(Splash_hashmap *hashmap, void *key) {
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
void splash_hashmap_remove(Splash_hashmap *hashmap, void *key) {
  int index = hash(key, hashmap->size);
  struct _Splash_hashmap_element_ * item;
  struct _Splash_hashmap_element_ * next;

  item = hashmap->buckets[index];

  if (item == NULL)
    return;

  if (item->next == NULL) {
    free(item);
    hashmap->buckets[index] = NULL;
    hashmap->count--;
    return;
  }

  while (item != NULL) {
    next = item->next;
    if (next != NULL && next->key == key) {
      item->next = next->next;
      hashmap->count--;
      free(next);
      return;
    }
    item = next;
  }
}


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  list      The list to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
int32_t splash_hashmap_get_size(Splash_hashmap *hashmap) {
  return hashmap->count;
}


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the hashmap
  @param  hashmap      The hashmap to count
  @return  Size of the hashmap

  Gets the size of the hashmap
  
\-----------------------------------------------------------------------------*/
void splash_hashmap_destory(Splash_hashmap *hashmap) {
  int i;
  struct _Splash_hashmap_element_ * item;
  struct _Splash_hashmap_element_ *  next;

  for (i = 0; i < hashmap->size; i++) {
    for (item = hashmap->buckets[i]; item != NULL;) {
      next = item->next;
      free(item);
      item = next;
    }
  }

  free(hashmap->buckets);
  free(hashmap);
}

/*-------------------------------------------------------------------------*/
/**
   @file    Splash_list.c
   @author  P. Batty
   @brief   The list structs

   This module implements the creation and manipulations of the 
   list structs in the framework.

*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "Splash/Splash_list.h"
#include <stdint.h>
#include <stdlib.h>


/*---------------------------------------------------------------------------
                            Private functions
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_list_Node
  @return   New Splash_List_Node otherwise NULL.

  Creates a new Splash_list_node object returns  a new object else 
  null if unsuccessful

\-----------------------------------------------------------------------------*/
static struct _splash_list_node_ *splash_list_node_create() {
	struct _splash_list_node_ *node = malloc(sizeof(_splash_list_node_));

		if (!node) {
			return NULL;
		}

		node->data = 0;
		node->next = 0;

	return node;
}


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------
  @brief    Creates a new Splash_list
  @return   New Splash_List otherwise NULL.

  Creates a new Splash_list object destroy with splash_list_destroy();
  return a new object else null if unsuccessful

\-----------------------------------------------------------------------------*/
Splash_list *splash_list_create() {
	Splash_list *list = malloc(sizeof(Splash_list));

	if (!list) {
		return NULL;
	}

	list->size = 0;
	list->next = splash_list_node_create();

 return list;
}


/*!--------------------------------------------------------------------------
  @brief    Adds a item to the list
  @param  list      The list to add to
  @param  data       The data to add
  @return  Void

  Adds a item to the end of the list

\-----------------------------------------------------------------------------*/
void splash_list_add(Splash_list *list, void *data) {
	struct _splash_list_node_ *node = list->next;

	while((int)(node->next) != 0 ) node = node->next;

	struct _splash_list_node_ *tmp = splash_list_node_create();
	tmp->data = malloc(sizeof(data));

	tmp->data = data;
	tmp->next = 0;

	node->next = tmp;
	list->size++;
}


/*!--------------------------------------------------------------------------
  @brief    Checks if an item is in the list
  @param  list      The list to check
  @param  data       The data to search for
  @return  1 if it contains the item else 0

  Performs a liniar search on the list to search for the data.
  return 1 if it finds it else 0

\-----------------------------------------------------------------------------*/
int8_t splash_list_contains(Splash_list *list, void *data) {

	struct _splash_list_node_ *node = list->next;
	while(node->next != 0 && node->data != data) {
		node = node->next;
	}

  return (node->data == data) ? 1 : 0; 
}


/*!--------------------------------------------------------------------------
  @brief    Gets the position of the data in the list
  @param  list      The list to check
  @param  data       The data to search for
  @return  Position of the data, -1 if not found

  Performs a liniar search on the list to search for the data.
  returns the position in the list when it finds it else -1

\-----------------------------------------------------------------------------*/
int32_t splash_list_get_position(Splash_list *list, void *data) {
	int32_t pos = -1;

	struct _splash_list_node_ *node = list->next;
	while(node->next != 0 && node->data != data) {
		pos++;
		node = node->next;
	}

  return (node->data == data) ? pos : -1; 
}


/*!--------------------------------------------------------------------------
  @brief    Gets the element at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Data at the position in the list, -1 if not found

  Gets the data in the list as a void pointer, and -1 if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
void *splash_list_get(Splash_list *list, int32_t pos) {
	pos++;

	int32_t i = 0;
	struct _splash_list_node_ *node = list->next;
	while(node->next != 0 && i < pos) {
		i++;
		node = node->next;
	}

  return (i == pos) ? node->data : (void *)-1; 
}


/*!--------------------------------------------------------------------------
  @brief    Gets the string at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  String at the position in the list, NULL if not found

  Gets the string in the list as a void pointer, and null if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
char *splash_list_get_string(Splash_list *list, int32_t pos) {
	return (char *) splash_list_get(list, pos);
}


/*!--------------------------------------------------------------------------
  @brief    Gets the int at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Int at the position in the list, NULL if not found

  Gets the int in the list as a void pointer, and null if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
int splash_list_get_int(Splash_list *list, int32_t pos) {
	return (int) splash_list_get(list, pos);
}


/*!--------------------------------------------------------------------------
  @brief    Gets the float at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Float at the position in the list, NULL if not found

  Gets the float in the list as a void pointer, and null if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
float splash_list_get_float(Splash_list *list, int32_t pos) {
	return *(float *) splash_list_get(list, pos);
}


/*!--------------------------------------------------------------------------
  @brief    Gets the double at the given position
  @param  list      The list to search
  @param  pos       The position to get
  @return  Double at the position in the list, NULL if not found

  Gets the double in the list as a void pointer, and null if the position does not
  exist
  
\-----------------------------------------------------------------------------*/
double splash_list_get_double(Splash_list *list, int32_t pos) {
	return *(double *) splash_list_get(list, pos);
}


/*!--------------------------------------------------------------------------
  @brief    Removes the data from the list
  @param  list      The list to search
  @param  pos       The position to remove
  @return  Void

  Removes the data at the position, and shuffles the list up by one.
  
\-----------------------------------------------------------------------------*/
void splash_list_remove_position(Splash_list *list, int32_t pos) {
	pos++;
	int32_t i = 0;
	struct _splash_list_node_ *previous_node = NULL;
	struct _splash_list_node_ *node = list->next;

	while(node->next != 0 && i < pos) {
		i++;
		previous_node = node;
		node = node->next;
	}

	if (i != pos) {
		return;
	}

	previous_node->next = node->next;
	free(node);
	if (list->size > 0) {
		list->size--;
	}
}


/*!--------------------------------------------------------------------------
  @brief    Removes the data from the list
  @param  list      The list to search
  @param  data      The data to remove
  @return  Void

  Removes the data at the position, and shuffles the list up by one.
  
\-----------------------------------------------------------------------------*/
void splash_list_remove(Splash_list *list, void *data) {
	struct _splash_list_node_ *previous_node = NULL;
	struct _splash_list_node_ *node = list->next;

	while(node->next != 0 && node->data != data) {
		previous_node = node;
		node = node->next;
	}

	if (node->data != data) {
		return;
	}

	previous_node->next = node->next;
	free(node);
	if (list->size > 0) {
		list->size--;
	}
}


/*!--------------------------------------------------------------------------
  @brief    Removes everything in the list
  @param  list      The list to empty
  @return  Void

  Empties the list.
  
\-----------------------------------------------------------------------------*/
void splash_list_remove_all(Splash_list *list) {
	int32_t i;
	int32_t size = list->size;
	for (i = 0; i < size; i++) {
		splash_list_remove_position(list, 0);
	}
}


/*!--------------------------------------------------------------------------
  @brief    Gets the size of the list
  @param  list      The list to count
  @return  Size of the list

  Gets the size of the list
  
\-----------------------------------------------------------------------------*/
int32_t splash_list_get_size(Splash_list *list) {
	return list->size;
}


/*!--------------------------------------------------------------------------
  @brief    Destroy's the list
  @param  list      The list to destroy
  @return  Void

  Destroy's the list

\-----------------------------------------------------------------------------*/
void splash_list_destroy(Splash_list *list) {
	struct _splash_list_node_ *previous_node = NULL;
	struct _splash_list_node_ *node = list->next;

	while(node->next != 0) {
		previous_node = node;
		node = node->next;
		free(previous_node->data);
		free(previous_node);
	}

	free(previous_node);
	free(node);
}
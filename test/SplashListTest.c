/*-------------------------------------------------------------------------*/
/**
   @file    SplashListTest.c
   @author  P. Batty
   @brief   Unit test
	
*/
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
                                Includes
 ---------------------------------------------------------------------------*/

#include "splash/Splash.h"                          
#include <string.h>
#include <assert.h>
#include <stdlib.h>

static Splash_list *list;
static char *string = "This is another super long string much like the one in my window test to see wheather the linked list can accuraly store and very long string properly but hey at least it sais somthing \
						diffrent right? !£$%^&*()_+¬`{}@~:<>?/.,#';][/*-+|¦ see thats me encoding a secret message in side the string to make this more intresting for myself (half life 3 confmed?) ahhhhhhh how \
						much long do you think i should make this string before it become accetplble for a test after tests are the way forward just not when i have to write super long strings .. laura ipsen?";


typedef struct Object {
	int data;
} Object;


/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void list_create_test() {
	list = splash_list_create();
	assert(list != NULL && "Failed to create list");
}


static void list_add_string_test() {
	splash_list_add(list, "test");
	splash_list_add(list, string);
}


static void list_get_string_test() {
	assert(strcmp(splash_list_get_string(list, 0), "test") == 0 && "Failed to get string");
	assert(strcmp(splash_list_get_string(list, 1), string) == 0 && "Failed to get string");
	assert(strcmp(splash_list_get_string(list, 0), "ssss") != 0 && "Failed to get string");

	assert(splash_list_contains(list, string) == 1 && "Failed to find string");
	assert(splash_list_contains(list, "test") == 1 && "Failed to find string");
	assert(splash_list_contains(list, "ssss") == 0 && "Failed to find string");

	assert(splash_list_get_position(list, "test") == 0 && "Failed to find string");
	assert(splash_list_get_position(list, "ssss") == -1 && "Failed to find string");
}


static void list_remove_string_test() {
	splash_list_remove(list, "test");
	assert(strcmp(splash_list_get_string(list, 0), string) == 0 && "Failed to get string");
	assert(splash_list_contains(list, "test") == 0 && "Failed to find string");

	splash_list_remove_all(list);
}


static void list_add_num_test() {
	splash_list_add(list, (void *)1);
	splash_list_add(list, (void *)10000000);
	splash_list_add(list, (void *)-10000000);
	splash_list_add(list, (void *)-1);

	float tmp = 3.142;
	splash_list_add(list, &tmp);
	tmp = -3.142;
	splash_list_add(list, &tmp);

	double dtmp = 3.1415926535897932384626433832795028841971693993751;
	splash_list_add(list, &dtmp);
}


static void list_get_num_test() {
	assert(splash_list_get_int(list, 0) == 1 && "Failed to get int");
	assert(splash_list_get_int(list, 2) == -10000000 && "Failed to get int");
	assert((splash_list_get_float(list, 4) - 3.142) < 0.00001 && "Failed to get float");
	assert((splash_list_get_float(list, 5) - -3.142) < 0.00001 && "Failed to get float");
	assert(splash_list_get_double(list, 6) == 3.1415926535897932384626433832795028841971693993751 && "Failed to get double");

	// skip check for float and double because of equality comparisons

	assert(splash_list_contains(list, (void *)1) == 1 && "Failed to find int");
	assert(splash_list_contains(list, (void *)12345) == 0 && "Failed to find int");

	assert(splash_list_get_position(list, (void *)1) == 0 && "Failed to find int");
}


static void list_remove_num_test() {
	float tmp = 3.142;
	splash_list_remove(list, &tmp);
	assert(splash_list_get_int(list, 4 - -3.142)  < 0.00001 && "Failed to get float");

	splash_list_remove_all(list);
}


static void list_add_obj_test() {
	Object *o = malloc(sizeof(Object));
	o->data = 18;
	splash_list_add(list, o);
	Object *o2 = malloc(sizeof(Object));
	o2->data = 24;
	splash_list_add(list, o2);
	Object *o3 = malloc(sizeof(Object));
	o3->data = 52;
	splash_list_add(list, o3);
}


static void list_get_obj_test() {
	Object *o = splash_list_get(list, 0);
	assert(o->data == 18 && "Failed to get object data");

	o = splash_list_get(list, 1);
	assert(splash_list_contains(list, o) == 1 && "Failed to find object data");

	assert(splash_list_get_position(list, o) == 1 && "Failed to get object data");
}


static void list_remove_obj_test() {

	splash_list_remove_position(list, 0);

	Object *o = splash_list_get(list, 0);
	assert(o->data == 24 && "Failed to find object data");

	splash_list_remove_all(list);
}


static void size_test() {
	assert(splash_list_get_size(list) == 0 && "Faied to get list size");

	splash_list_add(list, (void *)12);
	splash_list_add(list, (void *)12);
	splash_list_add(list, (void *)12);

	assert(splash_list_get_size(list) == 3 && "Failed to get list size");

	splash_list_remove_position(list, 2);
	assert(splash_list_get_size(list) == 2 && "Failed to get list size");

	splash_list_remove(list, (void *)12);
	assert(splash_list_get_size(list) == 1 && "Failed to get list size");

	splash_list_remove_all(list);
	assert(splash_list_get_size(list) == 0 && "Failed to get list size");
}


int main(int argc, char *argv[]) {
	list_create_test();

		list_add_string_test();
		list_get_string_test();
		list_remove_string_test();

		list_add_num_test();
		list_get_num_test();
		list_remove_num_test();

		list_add_obj_test();
		list_get_obj_test();
		list_remove_obj_test();

		size_test();

	splash_list_destroy(list);
 return 0;
}

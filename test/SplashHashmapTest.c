/*-------------------------------------------------------------------------*/
/**
   @file    SplashHashmapTest.c
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
    
static Splash_hashmap *hashmap;
static char *string = "This is another super long string much like the one in my window test to see wheather the linked list can accuraly store and very long string properly but hey at least it sais somthing \
						diffrent right? !£$%^&*()_+¬`{}@~:<>?/.,#';][/*-+|¦ see thats me encoding a secret message in side the string to make this more intresting for myself (half life 3 confmed?) ahhhhhhh how \
						much long do you think i should make this string before it become accetplble for a test after tests are the way forward just not when i have to write super long strings .. laura ipsen?";

typedef struct Object {
	int data;
} Object;

/*---------------------------------------------------------------------------
                            Function codes
 ---------------------------------------------------------------------------*/

static void hashmap_create() {
	hashmap = splash_hashmap_create();
	assert(hashmap != NULL && "Error creatng hashmap");
}


static void hashmap_test_strings() {
	splash_hashmap_add(hashmap, "key", "value");
	splash_hashmap_add(hashmap, "key", "newValue");
	splash_hashmap_add(hashmap, "other", string);

	assert(strcmp(splash_hashmap_get_string(hashmap, "key"), "newValue") == 0 && "Failed override string");
	assert(strcmp(splash_hashmap_get_string(hashmap, "other"), string) == 0 && "Failed to get string");

	splash_hashmap_remove(hashmap, "key");

	assert(splash_hashmap_get_string(hashmap, "key") == (void *)-1 && "Failed remove string");

	splash_hashmap_remove_all(hashmap);
} 


static void hashmap_test_numbers() {
	splash_hashmap_add(hashmap, "key",  "8");
	splash_hashmap_add(hashmap, "key", "16");

	 float tmp = 16.7161729;
	 splash_hashmap_add(hashmap, "float", &tmp);

	 double dtmp = 3.125189816627283638339372628226827393;
	 splash_hashmap_add(hashmap, "double", &dtmp);

	 assert(splash_hashmap_get_int(hashmap, "key") == 16 && "Failed to get int");
	 assert((splash_hashmap_get_float(hashmap, "float") - 16.7161729) < 0.00001 && "Failed to get int");
	 assert((splash_hashmap_get_double(hashmap, "double") - 3.125189816627283638339372628226827393) < 0.00001 && "Failed to get double");

	 splash_hashmap_remove(hashmap, "key");

	 assert(splash_hashmap_get_int(hashmap, "key") == -1 && "Failed to remove int");

	splash_hashmap_remove_all(hashmap);
}


static void hashmap_test_objects() {
	Object *o = malloc(sizeof(Object));
	o->data = 18;
	splash_hashmap_add(hashmap,"key", o);

	Object *o1 = splash_hashmap_get(hashmap, "key");
	assert(o1->data == 18 && "Failed to get object data");

	splash_hashmap_remove_all(hashmap);
}

static void hashmap_test_size() {
	assert(splash_hashmap_get_size(hashmap) == 0 && "Failed to remove all");
	splash_hashmap_add(hashmap, "key", "item");

	assert(splash_hashmap_get_size(hashmap) == 1 && "Failed to calculate add size");

	splash_hashmap_add(hashmap, "key", "test_item");

	assert(splash_hashmap_get_size(hashmap) == 1 && "Failed to calculate size");

	splash_hashmap_add(hashmap, "key1", "item");
	splash_hashmap_add(hashmap, "key2", "item");
	splash_hashmap_add(hashmap, "key3", "item");

	assert(splash_hashmap_get_size(hashmap) == 4 && "Failed to calculate size");

	splash_hashmap_remove(hashmap, "key");
	assert(splash_hashmap_get_size(hashmap) == 3 && "Failed to calculate size");

	splash_hashmap_remove_all(hashmap);
	assert(splash_hashmap_get_size(hashmap) == 0 && "Failed to calculate size");
}



int main(int argc, char *argv[]) {
	hashmap_create();

		hashmap_test_strings();
		hashmap_test_numbers();
		hashmap_test_objects();
		hashmap_test_size();

	splash_hashmap_destory(hashmap);
 return 0;
}
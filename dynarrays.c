#include "dynarrays.h"
#include <stdlib.h>

dynarray dynarray_init(size_t data_size, size_t capacity) {
  // would be weird to allocate a 0 space pointer

  if (capacity == 0) {
	capacity++;
  }
  void *data = malloc((capacity * data_size));
  dynarray init = { data, capacity, 0, data_size};
  return init;
}

void dynarray_append(void *item, dynarray *array) {
  if (array->length == array->capacity) {
    size_t new_capacity = array->capacity << 1;
    void* new_data = malloc(new_capacity * array->size_of_data_value);
    copy_array((char*)array->data,(char*) new_data, array->length, array->size_of_data_value);
    free(array->data);
    array->data = new_data;
    array->capacity = new_capacity;
  }

  char *position_for_item =
    array->data + (array->length * array->size_of_data_value);
  copy_array(item, position_for_item, 1,
             array->size_of_data_value);
  array->length++;
}


void dynarray_pop(dynarray *array) {
  char* data_value = array->data + array->length * array->size_of_data_value;
  for (size_t i = 0; i < array->size_of_data_value; i++) {
    *data_value = 0;
  }
  array->length = array->length-1;
}

void free_dynarray(dynarray *array) {
  if (array->data != NULL) {
    free(array->data);
    array->data = NULL;
  }
}

void copy_array(char *src,char *dst, size_t src_length, size_t size_of_data_value) {
  for (size_t i = 0; i < src_length * size_of_data_value; i++) {
    dst[i] = src[i];
  }
}




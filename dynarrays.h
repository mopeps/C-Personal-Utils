#ifndef DYNARRAYS_H
#define DYNARRAYS_H 1

#include <sys/_types/_size_t.h>

#define dynarray(T, a) dynarray_init(sizeof(T), a)
#define GET_ARRAY_ELEM(T,at) *((char*)T->data + (T->size_of_data_value * at))

typedef struct dynarray_struct {
  void *data;
  size_t capacity;
  size_t length;
  size_t size_of_data_value;
} dynarray;

extern dynarray dynarray_init(size_t, size_t);
extern void dynarray_append(void *item, dynarray *array);
extern void dynarray_pop(dynarray *array);
extern void copy_array(char* src, char* dst, size_t src_length, size_t size_of_data_value);
extern void free_dynarray(dynarray *array);

#endif

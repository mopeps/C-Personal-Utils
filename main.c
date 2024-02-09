#include "dynarrays.h"
#include <stdio.h>

int main() {
  int pepe = 2;
  dynarray T = dynarray_init(sizeof(int), 0);
  dynarray_append(&pepe, &T);
  dynarray_append(&pepe, &T);
  dynarray_append(&pepe, &T);
  dynarray_append(&pepe, &T);
  dynarray_append(&pepe, &T);
  printf("Length: %d\n", T.length);
  printf("Capacity: %d\n", T.capacity);
  printf("Size of data: %d\n", T.size_of_data_value);
  for (size_t i =0; i < T.length; i++) {
	printf("%d ",*((char*)T.data + i  * (T.size_of_data_value)));
  }
  free_dynarray(&T);
  return 0;
}

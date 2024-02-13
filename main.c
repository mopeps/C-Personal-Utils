#include "dynarrays.h"
#include <stdio.h>

void test_add(dynarray *T, int *value) {
  dynarray_append(value, T);

  printf("Length: %d\n", T->length);
  printf("Capacity: %d\n", T->capacity);
  printf("Size of data: %d\n", T->size_of_data_value);
  printf("The objets of data are: ");
  for (size_t i =0; i < T->length; i++) {
	printf("%d ", GET_ARRAY_ELEM(T,i));
  }
  printf("\n");
}

void test_pop(dynarray *T) {
  dynarray_pop(T);

  printf("Length: %d\n", T->length);
  printf("Capacity: %d\n", T->capacity);
  printf("Size of data: %d\n", T->size_of_data_value);
  printf("The objets of data are: ");
  for (size_t i =0; i < T->length; i++) {
	printf("%d ", GET_ARRAY_ELEM(T,i));
  }
  printf("\n");
}

int main() {
  int pepe = 2;
  dynarray T = dynarray(int, 0);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_add(&T, &pepe);
  test_pop(&T);
  test_pop(&T);
  test_pop(&T);
  test_pop(&T);
  free_dynarray(&T);
  return 0;
}


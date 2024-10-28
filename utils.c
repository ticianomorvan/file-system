#include <stdlib.h>
#include <string.h>
#include "utils.h"

int compare_strings(const void *s1, const void *s2) {
  const char* first = *(const char **) s1;
  const char* second  = *(const char **) s2;

  return strcmp(first, second);
}

void sort_string_array (char *array[], int length) {
  qsort(array, length, sizeof (char *), compare_strings);
}

char **free_string_array(char *array[], int length) {
  for (int i = 0; i < length; ++i) {
    free(array[i]);
  }

  free(array);
  array = NULL;
  return array;
}

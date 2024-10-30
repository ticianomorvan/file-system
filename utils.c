#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

int
compare_strings (const void *s1, const void *s2)
{
  const char *first = *(const char **)s1;
  const char *second = *(const char **)s2;

  return strcmp (first, second);
}

void
sort_string_array (char *array[], int length)
{
  qsort (array, length, sizeof (char *), compare_strings);
}

char **
free_string_array (char *array[], int length)
{
  for (int i = 0; i < length; ++i)
    {
      free (array[i]);
    }

  free (array);
  array = NULL;
  return array;
}


char *
get_current_dir_name (void)
{
  char *current_dir_name = NULL;
  current_dir_name = (char *)malloc (CHAR_MAX * sizeof (char));
  getcwd (current_dir_name, CHAR_MAX);
  return current_dir_name;
}

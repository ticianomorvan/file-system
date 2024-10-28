#include <stdio.h>
#include <stdlib.h>
#include "ls.h"
#include "utils.h"

void
print_current_dir ()
{
  char *current_dir_name = get_current_dir_name ();
  int current_dir_length = get_dir_length (current_dir_name);
  char **current_dir_structure
      = get_dir_entries (current_dir_name, current_dir_length);

  for (int i = 0; i < current_dir_length; ++i)
    {
      printf ("%s\n", current_dir_structure[i]);
    }

  for (int i = 0; i < current_dir_length; ++i)
    {
      free (current_dir_structure[i]);
    }

  free (current_dir_name);
  free (current_dir_structure);
}

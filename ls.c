#include "ls.h"
#include "dir.h"
#include "utils.h"
#include <stdlib.h>

void
print_current_dir (void)
{
  char *current_dir_name = get_current_dir_name ();
  dir current_dir = generate_dir_from_path(current_dir_name);
  print_dir(current_dir);

  free (current_dir_name);
  destroy_dir(current_dir);
}

void
print_external_dir (char *path)
{
  dir external_dir = generate_dir_from_path(path);
  print_dir (external_dir);
  destroy_dir(external_dir);
}

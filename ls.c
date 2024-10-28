#include "ls.h"
#include "dir.h"
#include "print.h"
#include "utils.h"
#include <stdlib.h>

void
print_current_dir (void)
{
  char *current_dir_name = get_current_dir_name ();
  int current_dir_length = get_dir_length (current_dir_name);
  char **current_dir_entries
      = get_dir_entries (current_dir_name, current_dir_length);

  struct _print_dir_flags flags;
  flags.sort = false;
  flags.show_all = false;
  print_dir (current_dir_entries, current_dir_length, flags);

  free (current_dir_name);
  free_string_array (current_dir_entries, current_dir_length);
}

void
print_external_dir (char *dir_path)
{
  int dir_length = get_dir_length (dir_path);
  char **dir_entries = get_dir_entries (dir_path, dir_length);

  struct _print_dir_flags flags;
  flags.sort = true;
  flags.show_all = false;
  print_dir (dir_entries, dir_length, flags);

  free_string_array (dir_entries, dir_length);
}

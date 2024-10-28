#include <stdio.h>
#include "print.h"
#include "utils.h"

void print_dir(char **dir_entries, int dir_length, struct _print_dir_flags flags) {
  if (flags.sort) {
    sort_string_array(dir_entries, dir_length);
  }

  for (int i = 0; i < dir_length; ++i)
  {
    if (!flags.show_all && is_hidden_entry(dir_entries[i])) {
      continue;
    }

    printf ("%s\n", dir_entries[i]);
  }
}

bool is_hidden_entry(char *entry) {
  return entry[0] == '.';
}

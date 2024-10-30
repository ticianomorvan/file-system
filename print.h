#ifndef _PRINT_H
#define _PRINT_H

#include <stdbool.h>

struct _print_dir_flags {
  bool sort;
  bool show_all;
};

bool is_hidden_entry(char *entry);
/*
 * Checks if a given entry should be hidden.
 */

#endif // !_PRINT_H

#include "dir.h"
#include <assert.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct _s_dir {
  int length;
  char *path;
  char **entries;
};

bool invrep(dir d) {
  return d != NULL;
}

dir init_dir(void) {
  dir new_dir = NULL;
  new_dir = (struct _s_dir *) malloc(sizeof (struct _s_dir));
  new_dir->length = 0;
  new_dir->path = NULL;
  new_dir->entries = (char **) malloc(sizeof (char *));
  assert(invrep(new_dir) && new_dir->length == 0 && new_dir->path == NULL);
  return new_dir;
}

char* get_dir_path(dir d) {
  assert(invrep(d));
  char* path = d->path;
  assert(invrep(d));
  return path;
}

dir set_dir_path(dir d, char *path) {
  assert(invrep(d));
  d->path = strdup(path);
  assert(invrep(d) && d->path != NULL);
  return d;
}

int get_dir_length(dir d) {
  assert(invrep(d));
  int length = d->length;
  assert(invrep(d));
  return length;
}

dir add_dir_entry(dir d, char *entry) {
  assert(invrep(d));
  d->entries = (char **) realloc(d->entries, (d->length + 1) * sizeof (char *));
  d->entries[d->length] = strdup(entry);
  d->length++;
  assert(invrep(d) && get_dir_length(d) > 0);
  return d;
}

void print_dir(dir d) {
  assert(invrep(d));
  int length = d->length;
  char **entries = d->entries;

  for (int i = 0; i < length; ++i) {
    printf("%s\n", entries[i]);
  }

  assert(invrep(d));
}

dir destroy_dir(dir d) {
  assert(invrep(d));
  if (d->path != NULL) {
    free(d->path);
    d->path = NULL;
  }

  if (d->entries != NULL) {
    for (int i = 0; i < d->length; ++i) {
      free(d->entries[i]);
      d->entries[i] = NULL;
    }

    free(d->entries);
    d->entries = NULL;
  }

  free(d);
  d = NULL;
  assert(!invrep(d));
  return d;
}

dir generate_dir_from_path(char *path) {
  DIR *current_directory = NULL;
  struct dirent *read_result = NULL;

  current_directory = opendir(path);
  if (current_directory == NULL) {
    fprintf(stderr, "ERROR: given path is not a valid directory.");
    closedir(current_directory);
    return NULL;
  }

  dir new_dir = init_dir();
  set_dir_path(new_dir, path);
  
  while ((read_result = readdir(current_directory)) != NULL) {
    add_dir_entry(new_dir, read_result->d_name);
  }

  closedir(current_directory);
  return new_dir;
}

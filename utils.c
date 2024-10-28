#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char *
get_current_dir_name ()
{
  char *current_dir_name = NULL;
  current_dir_name = (char *)malloc (CHAR_MAX * sizeof (char));
  getcwd (current_dir_name, CHAR_MAX);
  return current_dir_name;
}

int
get_dir_length (char *dir_name)
{
  int length = 0;
  DIR *cdir = NULL;
  struct dirent *dir = NULL;

  cdir = opendir (dir_name);
  while ((dir = readdir (cdir)) != NULL)
    {
      length++;
    }

  closedir (cdir);
  return length;
}

char **
get_dir_entries (char *dir_name, int dir_length)
{
  DIR *cdir = NULL;
  struct dirent *dir = NULL;
  char **entries = NULL;

  cdir = opendir (dir_name);
  if (cdir != NULL)
    {
      entries = (char **)malloc (dir_length * sizeof (char *));
      if (entries == NULL)
        {
          fprintf (
              stderr,
              "ERROR: failed to allocate memory for directory structure.");
          return NULL;
        }

      for (int i = 0; i < dir_length; ++i)
        {
          dir = readdir (cdir);
          if (dir == NULL)
            {
              break;
            }

          entries[i] = strdup (dir->d_name);
        }
    }

  closedir (cdir);
  return entries;
}

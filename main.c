#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

typedef unsigned int uint;

char *get_current_dir_name() {
  char *current_dir_name = NULL;
  current_dir_name = (char *) malloc(CHAR_MAX * sizeof(char));
  getcwd(current_dir_name, CHAR_MAX);
  return current_dir_name;
}

int get_dir_length(char *dir_name) {
  int length = 0;
  DIR *cdir = NULL;
  struct dirent *dir = NULL;
  
  cdir = opendir(dir_name);
  while ((dir = readdir(cdir)) != NULL) {
    length++;
  }

  closedir(cdir);
  return length;
}

char **get_dir_structure(char *dir_name, int dir_length) {
  DIR *cdir = NULL;
  struct dirent *dir = NULL;
  char **current_dir_structure = NULL;

  cdir = opendir(dir_name);
  if (cdir != NULL) {
    current_dir_structure = (char **) malloc(dir_length * sizeof (char *));
    if (current_dir_structure == NULL) {
      fprintf(stderr, "ERROR: failed to allocate memory for directory structure.");
      exit(EXIT_FAILURE);
    }

   for (int i = 0; i < dir_length; ++i)  {
      dir = readdir(cdir);
      if (dir == NULL) {
        break;
      }

      current_dir_structure[i] = strdup(dir->d_name);
    }
  }

  closedir(cdir);
  return current_dir_structure;
}

void
print_current_dir ()
{
  char *current_dir_name = get_current_dir_name();
  int current_dir_length = get_dir_length(current_dir_name);
  char **current_dir_structure = get_dir_structure(current_dir_name, current_dir_length);
  for (int i = 0; i < current_dir_length; ++i) {
    printf("%s\n", current_dir_structure[i]);
  }

  for (int i = 0; i < current_dir_length; ++i) {
    free(current_dir_structure[i]);
  }

  free(current_dir_name);
  free(current_dir_structure);
}

int
main (int argc, char *argv[])
{
  if (argc <= 1)
    {
      print_current_dir ();
      exit (EXIT_SUCCESS);
    }

  if (argc >= 2)
    {
      printf ("ERROR: you provided too many arguments.\n");
      exit (EXIT_FAILURE);
    }

  printf("%s", argv[0]);
  return EXIT_SUCCESS;
}

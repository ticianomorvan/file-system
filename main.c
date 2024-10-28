#include <stdio.h>
#include <stdlib.h>
#include "ls.h"

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

  printf ("%s", argv[0]);
  return EXIT_SUCCESS;
}

#ifndef _DIR_H
#define _DIR_H

char *get_current_dir_name(void);
/*
 * Returns current directory name.
 * Caller is responsible of freeing the resulting pointer.
 */

int get_dir_length(char *dir_name);
/*
 * Returns given directory length (amount of files and subdirectories).
 */

char **get_dir_entries(char *dir_name, int dir_length);
/*
 * Returns an array of given directory's entries names.
 * Caller is responsible of freeing the resulting pointer.
 */

#endif // !_DIR_H

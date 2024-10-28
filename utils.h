#ifndef _UTILS_H
#define _UTILS_H

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

int compare_strings(const void *s1, const void *s2);
/*
 * Compares two strings, returning an integer between -1, 0 and 1
 * based on the following rules:
 *
 * Returns -1 if `s1` goes before `s2`.
 * Returns 0 if `s1` and `s2` are equal.
 * Returns 1 if `s1` goes after `s2`.
 */

void sort_dir_entries(char **dir_entries, int dir_length);
/*
 * Lexicographically sorts an array of directory entries.
 */

#endif

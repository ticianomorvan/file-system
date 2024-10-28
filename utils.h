#ifndef _UTILS_H
#define _UTILS_H

int compare_strings(const void *s1, const void *s2);
/*
 * Compares two strings, returning an integer between -1, 0 and 1
 * based on the following rules:
 *
 * Returns -1 if `s1` goes before `s2`.
 * Returns 0 if `s1` and `s2` are equal.
 * Returns 1 if `s1` goes after `s2`.
 */

void sort_string_array(char *array[], int length);
/*
 * Lexicographically sorts an array of strings.
 */

char **free_string_array(char *array[], int length);
/*
 * Correctly frees memory allocated by an array of strings.
 */

#endif

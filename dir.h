#ifndef _DIR_H
#define _DIR_H

typedef struct _s_dir * dir;

dir init_dir(void);
/*
 * Initialize a new directory struct.
 */

char* get_dir_path(dir d);
/*
 * Gets a directory path.
 * This returns a reference to the [path] field.
 */

dir set_dir_path(dir d, char *path);
/*
 * Sets a directory path.
 * This copies the string [path] instead of just referencing it.
 */

dir add_dir_entry(dir d, char *entry);
/*
 * Adds an entry to a directory.
 */

int get_dir_length(dir d);
/*
 * Count hoy many entries does a directory have.
 */

void print_dir(dir d);
/*
 * Prints a directory structure.
 */

dir destroy_dir(dir d);
/*
 * Destroys a directory structure.
 */

dir generate_dir_from_path(char* path);
/*
 * Scans a given [path] and transforms it into a directory structure.
 */
#endif // !_DIR_H

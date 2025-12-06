#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* Provided by ALX/Holberton environment */
int _putchar(char c);

/* Task 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 */
int create_file(const char *filename, char *text_content);

/* Task 2 */
int append_text_to_file(const char *filename, char *text_content);

/* Task 3 (cp) */
int _copy_file(const char *file_from, const char *file_to);

#endif /* MAIN_H */

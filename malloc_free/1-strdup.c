#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str = NULL or malloc fails
 */
char *_strdup(char *str)
{
    char *dup;
    unsigned int i, len = 0;

    if (str == NULL)
        return (NULL);

    /* find the length of the string */
    while (str[len] != '\0')
        len++;

    /* allocate memory for copy + null terminator */
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);

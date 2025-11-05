#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 *         or str = NULL
 */
char *_strdup(char *str)
{
    char *dup;
    int i, len = 0;

    if (str == NULL)
        return (NULL);

    /* Calculate the length of the string */
    while (str[len])
        len++;

    /* Allocate memory for the new string (+1 for '\0') */
    dup = malloc(sizeof(char) * (len + 1));

    if (dup == NULL)
        return (NULL);

    /* Copy the string */
    for (i = 0; i < len; i++)
        dup[i] = str[i];

    dup[len] = '\0';

    return (dup);
}

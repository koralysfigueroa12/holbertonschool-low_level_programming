#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated memory
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the newly allocated memory (may be same as ptr),
 *         or NULL on failure (or when freed because new_size == 0)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_mem, *old_mem;
	unsigned int i, limit;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_mem = malloc(new_size);
	if (new_mem == NULL)
		return (NULL);

	old_mem = (char *)ptr;
	limit = (old_size < new_size) ? old_size : new_size;
	for (i = 0; i < limit; i++)
		new_mem[i] = old_mem[i];

	free(ptr);
	return (new_mem);
}

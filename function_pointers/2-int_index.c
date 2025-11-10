#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: array to search
 * @size: number of elements in array
 * @cmp: pointer to the comparison function
 *
 * Return: index of the first element for which cmp returns non-zero,
 *         or -1 if no element matches or on error (size <= 0, array or cmp NULL)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}

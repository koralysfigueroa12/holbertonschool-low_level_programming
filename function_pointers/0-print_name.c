#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: pointer to the name to print
 * @f: pointer to function that prints a name
 *
 * Return: void
 */
 void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

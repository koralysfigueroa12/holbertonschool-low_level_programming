#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: the string to print
 */
void puts_half(char *str)
{
	int len = 0;
	int start;

	/* Find the length of the string */
	while (str[len] != '\0')
		len++;

	/* Determine starting point */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* Print from start to end */
	while (str[start] != '\0')
	{
		_putchar(str[start]);
		start++;
	}

	_putchar('\n');
}


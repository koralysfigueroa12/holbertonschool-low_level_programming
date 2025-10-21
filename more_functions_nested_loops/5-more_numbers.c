#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers from 0 to 14,
 * followed by a new line
 *
 * Return: void
 */
void more_numbers(void)
{
	int i, j;
	char n;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
				_putchar('1');
			n = j % 10 + '0';
			_putchar(n);
		}
		_putchar('\n');
	}
}


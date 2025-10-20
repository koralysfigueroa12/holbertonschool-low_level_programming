#include <unistd.h>
#include <stdio.h>
/**
 * main - Prints numbers x10
 *
 * Return: 0
 */
int main(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		putchar(digit + '0');
	}
	putchar('\n');
	return (0);
}

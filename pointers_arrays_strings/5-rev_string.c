#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int i, len = 0;
	char temp;

	/* Find the length of the string */
	while (s[len] != '\0')
		len++;

	/* Swap characters from both ends moving toward the center */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}


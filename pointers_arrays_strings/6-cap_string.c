#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: the resulting string
 */
char *cap_string(char *str)
{
	int i = 0;
	int j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32; /* capitalize first character if lowercase */
		}
		else
		{
			for (j = 0; sep[j] != '\0'; j++)
			{
				if (str[i - 1] == sep[j] && (str[i] >= 'a' && str[i] <= 'z'))
				{
					str[i] -= 32; /* capitalize after separator */
					break;
				}
			}
		}
		i++;
	}

	return (str);
}


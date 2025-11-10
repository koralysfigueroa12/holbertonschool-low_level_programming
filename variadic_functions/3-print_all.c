#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything based on the format string
 * @format: list of types of arguments passed to the function
 * 'c' = char, 'i' = int, 'f' = float, 's' = char *
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(ap, format);

	if (format != NULL)
		while (format[i] != '\0')
		{
			if (format[i] == 'c')
				printf("%s%c", sep, va_arg(ap, int));
			if (format[i] == 'i')
				printf("%s%d", sep, va_arg(ap, int));
			if (format[i] == 'f')
				printf("%s%f", sep, va_arg(ap, double));
			if (format[i] == 's')
			{
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", sep, str);
			}
			sep = ", ";
			i++;
		}

	va_end(ap);
	printf("\n");
}

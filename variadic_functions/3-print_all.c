#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct print
{
	char *symbol;
	void (*f)(va_list args);
} print_t;

static void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

static void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

static void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

static void print_string(va_list args)
{
	char *s = va_arg(args, char *);
	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything based on format string
 * @format: list of types: c = char, i = int, f = float, s = string
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *sep = "";
	print_t funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);
	if (format != NULL)
		while (format[i] != '\0')
		{
			j = 0;
			while (funcs[j].symbol)
			{
				if (format[i] == *(funcs[j].symbol))
				{
					printf("%s", sep);
					funcs[j].f(args);
					sep = ", ";
				}
				j++;
			}
			i++;
		}
	va_end(args);
	printf("\n");
}

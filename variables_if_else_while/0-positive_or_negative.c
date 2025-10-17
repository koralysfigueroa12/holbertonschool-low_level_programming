#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Prints whether the number stored in the variable n is positive or negative.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* Complete the code here */
	printf("%d ", n);
	if (n > 0)
	{
		printf("is positive\n");
	}
	else if (n < 0)
	{
		printf("is negative\n");
	}
	else
	{
		printf("is zero\n");
	}

	return (0);
}


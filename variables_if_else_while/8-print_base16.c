#include <unistd.h> // Required for putchar

int main(void)
{
    char c;

    // Print numbers 0-9
    c = '0';
    while (c <= '9')
    {
        putchar(c);
        c++;
    }

    // Print letters a-f
    c = 'a';
    while (c <= 'f')
    {
        putchar(c);
        c++;
    }

    // Print a newline character
    putchar('\n');

    return (0);
}

#include <stdarg.h>
#include "main.h"
/**
 * print_integer - prints an integer
 * @args: a list of arguments
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_integer(va_list args, int *count)
{
    int n = va_arg(args, int);
    char buffer[20];
    int i = 0, j;

    if (n == 0)
    {
        write(1, "0", 1);
        (*count)++;
        return;
    }

    if (n < 0)
    {
        write(1, "-", 1);
        (*count)++;
        n = -n;
    }

    while (n > 0)
    {
        buffer[i] = (n % 10) + '0';
        n /= 10;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        (*count)++;
    }
}

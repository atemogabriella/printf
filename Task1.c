#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_int - prints an integer
 * @args: a list of arguments
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	char buffer[12];/* max 11 digits + sign char*/
	int i = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = -num;
	}
	do {
		buffer[i++] = num % 10 + '0';
		num /= 10;
	} while (num != 0);
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
		(*count)++;
	}
}


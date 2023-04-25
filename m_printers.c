#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _print_int_binary - prints an integer converted to binary
 * @args: a list of variadic arguments
 * Return: number of printed digits
 */
int _print_int_binary(va_list args)
{
	unsigned int v = 0;
	int w = 0;
	int n = 0;

	n = va_arg(args, int);
	v = n;
	if (n < 0)
	{
		_write('1');
		n = n * -1;
		v = n;
		w += 1;
	}

	while (v > 0)
	{
		v = v / 2;
		w++;
	}
	_recursion_int_binary(n);
	return (w);
}

/**
 * _recursion_int_binary - prints a binary
 * @a: integer to print
 * Return: printed integer
 */
void _recursion_int_binary(int a)
{
	unsigned int r;

	r = a;
	if (r / 2)
		_recursion_int_binary(r / 2);
	_write(r % 2 + '0');
}

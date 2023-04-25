#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _print_a_char - prints a char
 * @args: list of variadic arguments
 * Return: character length
 */
int _print_a_char(va_list args)
{
	_write(va_arg(args, int));
	return (-1);
}

/**
 * _print_a_string - prints a string
 * @args: list of variadic arguments
 * Return: string length
 */
int _print_a_string(va_list args)
{
	char *arg = va_arg(args, char*);
	int z = 0;

	if (arg != NULL)
	{
		while (arg[z])
		{
			_write(arg[z]);
			z++;
		}

		return (z);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
 * _print_an_integer - prints an integer
 * @args: list of variadic arguments
 * Return: string length
 */
int _print_an_integer(va_list args)
{
	int count = 1;
	int p = 0;
	unsigned int q = 0;

	q = va_arg(args, int);
	p = q;

	if (p < 0)
	{
		_write('-');
		p = p * -1;
		q = p;
		count += 1;
	}

	while (q > 9)
	{
		q = q / 10;
		count++;
	}

	_recursion_integer(p);
	return (count);
}

/**
 * _recursion_integer - Prints an integer
 * @a: integer to print
 * Return: nothing
 */
void _recursion_integer(int a)
{
	unsigned int w = a;

	w = a;
	if (w / 10)
		_recursion_integer(w / 10);
	_write(w % 10 + '0');
}

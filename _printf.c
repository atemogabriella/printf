#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - improvised printf function
 * @format: string format to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int number = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);
	number = _print_format(format, args);
	va_end(args);
	return (number);
}

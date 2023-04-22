#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * _printf - improvised printf function
 * @format: string containing whta is to be displayed
 * Return: number of parametrs printed
 */
int _printf(const char *format, ...)
{
	int number = 0;

	va_list params;

	if (format == NULL)
		return (-1);

	va_start(params, format);
	number = _display_format(format, params);
	va_end(params);
	return (number);
}

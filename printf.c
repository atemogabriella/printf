#include "main.h"
#include "stdlib.h"
/**
 * _print_format - prints format
 * @format: the format to be printed
 * @args: list of  variadic arguments
 * Return: format length
 */
int _print_format(const char *format, va_list args)
{
	int count = 0;
	int x = 0;

	while (format && format[x])
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0')
				return (-1);
			x++;

			while (format[x] == ' ')
				x++;

			if (format[x] == '%')
				count += _write(format[x]);

			if (_validate_char(format[x]) == 0)
			{
				count += _print_invalid_spec(format[x - 1], format[x], count);
			}
			else
			{
				count += _print_spec(format[x], args);
			}
		}
		else
		{
			count += _write(format[x]);
		}

		x++;
	}

	return (count);
}

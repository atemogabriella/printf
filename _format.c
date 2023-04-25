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

/**
 * _print_spec - Prints valid specifier
 * @format: the specifier to be printed
 * @args: a list of variadic arguments
 * Return: length of specifier
 */
int _print_spec(char format, va_list args)
{
	int x = 0;

	int number = 0;
	spc_dt _types[] = {
		{"c", _print_a_char},
		{"s", _print_a_string},
		{"d", _print_an_integer},
		{"i", _print_an_integer},
		{"b", _print_int_binary},
		{NULL, NULL}
	};

	while (_types[x].specifier)
	{
		if (*_types[x].specifier == format)
			number = _types[x].f(args);

		x++;
	}

	return (number);
}

/**
 * _print_invalid_spec - prints invalid specifier
 * @prev_format: previous specifier of current specifier
 * @format: prints specifier
 * @count: count before invalid specifiers are printed
 * Return: count after invalid specifiers are printed
 */
int _print_invalid_spec(char prev_format, char format, int count)
{
	count += _write('%');

	if (prev_format == ' ')
	{
		count += _write(' ');
		count += _write(format);
	}
	else
	{
		count += _write(format);
	}

	return (count);
}

/**
 * _validate_char - validates the type
 * @_type: character in comparison
 * Return: 1 if character is same as the type
 */
int _validate_char(char _type)
{
	char _types[] = {'c', 's', 'd', 'i', '%'};
	int x = 0;

	while (_types[x] == _type)
	{
		if (_types[x] == _type)
			return (-1);
		x++;
	}
	return (0);
}


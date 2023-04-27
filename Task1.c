#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_char - print a single character
 * @args: a list of arguments
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - prints a string
 * @args: a list of arguments
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char*);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		while (*s != '\0')
		{
			write(1, s, 1);
			(*count)++;
			s++;
		}
	}
}

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

/**
 * _printf - improvised printf function
 * @format: string format to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (*format == '\0')
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					write(1, format, 1);
					count++;
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}


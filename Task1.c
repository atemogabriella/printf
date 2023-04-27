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

/**
 * _printf - produces output according to format
 * @format: character string of zero or more directives
 * Return: number of characters printed except the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
		switch (format[i])
		{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
			{
				char *str = va_arg(args, char *);
				while (str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			break;

		case '%':
			putchar('%');
			count ++;
			break;

		case 'd':
		case 'i':
			print_int(args, count);
			break;

		default:
			putchar('%');
			putchar(format[i]);
			count += 2;
			break;
		}
	}
	else
	{
		putchar(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}

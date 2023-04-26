#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - improvised printf function
 * @format: string format to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;

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
				{
					c = va_arg(args, int);

					write(1, &c, 1);
					count++;
					break;
				}
				case 's':
				{
					s = va_arg(args, char*);

					if  (s == NULL)
					{
						write(1, "(null)", 6);
						count = count + 6;
						break;
					}
					while (*s != '\0')
					{
						write(1, s, 1);
						count++;
						s++;
					}
					break;
				}
				case '%':
				{
					write(1, format, 1);
					count++;
					break;
				}
				default:
				{
				c = '%';
				write(1, &c, 1);
				write(1, format, 1);
				count = count + 2;
				break;
				}
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


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

	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = (char) va_arg(args, int);

					fwrite(c);
					count++;
					break;
				}
				case 's':
				{
					char s = (char) va_arg(args, char*);

					while (s != '\0')
					{
						write(*s);
						count++;
						s++;
					}
					break;
				}
				case '%':
				{
					write('%');
					count++;
					break;
				}
				default:
				break;
			}
		}
		else
		{
			write(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);

}


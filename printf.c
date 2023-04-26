#include "main.h"
<<<<<<< HEAD
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - improvised printf function
 * @format: string format to be printed
 * Return: number of characters printed
=======
/**
 * _printf - printf function
 * @format: variadic parameter
 *
 * Return: count if successful
>>>>>>> 27f9d46118ab643558fc59e2888f8be986044f7b
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

<<<<<<< HEAD
	while (*format != '\0')
	{
		if (*format == '%')
=======
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			number = write(1, &format[i], 1);
			count = count + number;
			i++;
			continue;
		}
	
		if (format[i] == '%')
>>>>>>> 27f9d46118ab643558fc59e2888f8be986044f7b
		{
			format++;
			switch (*format)
			{
<<<<<<< HEAD
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
=======
				number = f(args);
				count = count + number;
				i = 1 + 2;
			}
		}
		if (format[i + 1] == '\0')
		{
			break;
		}
		if (format[i + 1] != '\0')
		{
			number = write(1, &format[i + 1], 1);
			count = count + number;
			i = i + 2;
			continue;
>>>>>>> 27f9d46118ab643558fc59e2888f8be986044f7b
		}
		format++;
	}
	va_end(args);
	return (count);

}


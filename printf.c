#include "main.h"
/**
 * _printf - printf function
 * @format: variadic parameter
 *
 * Return: count if successful
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int number = 0;
	va_list args;
	int (*f)(va_list)

	va_start(args. format);

	if (format == NULL)

		return (-1);

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
		{
			f = _specifier (&format[i + 1]);

			if (f != NULL)
			{
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
		}
	}
	return (count);

}

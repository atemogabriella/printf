#include <stdio.h>
/**
 * _printf - function my printf
 * @format: string format to print be printedi
 *
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	int i, count, number = 0;
	va_list args;
	int f = 0;

	if (format == NULL)

		return (-1);

	va_start(args, format);

    /*print each character of the string*/
	while (format[i])
	{
		if (format[i] != '%')
		{
			/*number of output char sent to the standard output*/
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
				i++;
			}
		}
		if (format[i + 1] == '\0')
		{
			break;
		}
		else
		{
			number = fwrite(1, &format[i + 1], 1);
			count = count + number;
			i++;
			continue;
		}
	}
	return (count);

}

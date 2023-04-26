#include "main.h"
/**
 * _specifier - check if there is a specifier
 * @format: format specifier for char
 *
 *
 * Return: pointer to the function if successful
 * NULL otherwise
 */
int (*_specifier(const char *format))(va_list)
{
	int i;

	spc_dt arr[] = {
		{"c", print_a_char},
		{"s", print_a_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	for (i = 0 ; arr[i].specifier != NULL ; i++)
	{
		if (arr[i].specifier == *format)
			return (arr[i].f);
	}
	return (NULL);
}

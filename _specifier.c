#include "main.h"
/**
 * _secifier - check if there is a specifier
 * @format: format specifier for char
 *
 *
 * Return: pointer to the function if successful
 * NULL otherwise
 */
int (*_specifier(const char *format))(va_list)
{
	int i;

	cnd_dt arr[] = {
		{"c", print_char}
		{"s", print_str}
		{"%", print_prc}
		{NULL, NULL}
	};

	for (i = 0 ; arr[i].condition != NULL ; i++)
	{
		if (arr[].condition == *format)
		{
			return (arr[i].f);
		}
	}
	return (NULL);
}

#include "main.h"
/**
 * _specifier - check if char is a format specifier
 * @format: specifier for char
 *
 * Return: pointer to a function if succesfull
 * null otherwise
 */
int (*_specifier(const char *format))(va_list)
{
	int i = 0;

	cnd_dt arr[] = {
		{"c", print_char},
		{"s", print_a_str},
		{"d", print_dec},
		{"i", print_int},
		{NULL, NULL} };
	while (arr[i].condition != NULL)
	{
		if (*(arr[i].condition) == *format)
		{
			return (arr[i].f);
		}
		else
			return (NULL);
		i++;
	}
	return (0);
}

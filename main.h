#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct specifiers - describe a particular type of struct
 * @specifier: the operator
 * @f: the pointer of the function
 */
typedef struct specifiers
{
	char *specifier;

	int (*f)(va_list args);
} spc_dt;
int _write(char c);
int _printf(const char *format, ...);
int _print_a_char(va_list args);
int _print_a_string(va_list args);
int _print_format(const char *format, va_list args);
#endif

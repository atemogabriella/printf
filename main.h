#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * struct conditions - describe a particular type of struct
 * @conditions: the operator
 * @f: the pointer of the function
 */
typedef struct conditions
{
	char *conditions;
	
	int(*f)(va_list params);
} cnd_dt;
int _write(char c);
int _printf(const char *format, ...);
#endif

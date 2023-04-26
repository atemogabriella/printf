#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
<<<<<<< HEAD
#include <unistd.h>
int _printf(const char *format, ...);
=======


int _printf(const char *format, ...);
int (*_specifier(const char *format))(va_list);
/**
 * struct cnd - conditions to be printed
 * @condition: condition of the character to compare
 * @f: function that stores the string to be printed
 */ 
typedef struct cnd
{
	char * condition;
	int (*f) (va_list);
}cnd_dt;
>>>>>>> 27f9d46118ab643558fc59e2888f8be986044f7b
#endif
